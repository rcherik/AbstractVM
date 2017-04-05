/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Emulator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:50:06 by rcherik           #+#    #+#             */
/*   Updated: 2016/10/14 16:50:09 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMULTAOR_HPP
# define EMULTAOR_HPP

#include <stdexcept>
#include <string>

#include "VmStack.hpp"

class Emulator
{
   private:
      VmStack<const IOperand*> *_vm;
      std::string               _colorBegin;
      std::string               _colorEnd;
      bool                      _rainbow;
      int   _a;
      int   _b;

      void 				  _Push(std::string str) const;
      void 				  _Assert(std::string str) const;
      void 				  _Add() const;
      void 				  _Sub() const;
      void 				  _Mul() const;
      void 				  _Div() const;
      void 				  _Mod() const;
      void 				  _Dump();
      void 				  _Print();
      void 				  _ChangeColor();

      eOperandType     _getType(std::string val) const;
      std::string      _getValue(std::string val) const;

      Emulator &		operator=(Emulator const & src);
      Emulator(Emulator const *src);

   public:
      Emulator();
      Emulator(bool rainbow);
      ~Emulator();

      void				  Execute(t_StrPair ins);

      class EmulatorException : public std::runtime_error
      {
         public :
            EmulatorException(std::string error) throw();
            ~EmulatorException() throw();
            virtual const char* what() const throw();

         private :
            EmulatorException &		operator=(EmulatorException const & src);
      };
};

#endif
