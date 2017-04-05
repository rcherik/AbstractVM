/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:50:11 by rcherik           #+#    #+#             */
/*   Updated: 2016/10/14 16:50:12 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
# define FACTORY_HPP

#include <stdexcept>
#include <climits>
#include <cfloat>
#include <cfenv>
#include <math.h>

class Factory
{
private:
	static IOperand const * createInt8(std::string const & value);
	static IOperand const * createInt16(std::string const & value);
	static IOperand const * createInt32(std::string const & value);
	static IOperand const * createFloat(std::string const & value);
	static IOperand const * createDouble(std::string const & value);

	Factory &		operator=(Factory const & src);
	Factory(Factory const & src);

public:
	Factory();
	~Factory();

	static IOperand const * createOperand(eOperandType type, std::string const & value );

	class OverflowError : public std::runtime_error
	{
		public :
			OverflowError(std::string error) throw();
			~OverflowError() throw();
			virtual const char* what() const throw();

		private :
			OverflowError &		operator=(OverflowError const & src);
	};

	class UnderflowError : public std::runtime_error
	{
		public :
			UnderflowError(std::string error) throw();
			~UnderflowError() throw();
			virtual const char* what() const throw();

		private :
			UnderflowError &		operator=(UnderflowError const & src);
	};
};

#endif
