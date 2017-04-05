/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:50:14 by rcherik           #+#    #+#             */
/*   Updated: 2016/10/14 16:50:16 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>

typedef std::pair<std::string, std::string> t_StrPair;
typedef std::list<t_StrPair> t_instruct;

enum eOperandType
{
	e_int_8 = 0,
	e_int_16,
	e_int_32,
	e_float,
	e_double,
	e_typeNb,
	e_typeError
};

class IOperand
{
	public:
		virtual int getPrecision( void ) const = 0;
		virtual eOperandType getType( void ) const = 0;
		virtual IOperand const * operator+(IOperand const & rhs) const = 0;
		virtual IOperand const * operator-(IOperand const & rhs) const = 0;
		virtual IOperand const * operator*(IOperand const & rhs) const = 0;
		virtual IOperand const * operator/(IOperand const & rhs) const = 0;
		virtual IOperand const * operator%(IOperand const & rhs) const = 0;
		virtual bool operator==(IOperand const & rhs) const = 0;
		virtual std::string const & toString(void) const = 0;
		virtual ~IOperand(void) {}
};

#endif
