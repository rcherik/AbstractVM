/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:51:07 by rcherik           #+#    #+#             */
/*   Updated: 2016/10/14 16:51:08 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"
#include "Emulator.hpp"

void  emulate(t_instruct instruct, bool rainbow) {

   Emulator fac = Emulator(rainbow);
   for(auto& ins : instruct)
      fac.Execute(ins);
}

int   main(int ac, char **av) {

   bool rainbow = false;
   bool info = false;

   if (ac < 2)
   {
      try {
         t_instruct instruct = Parse::getInstructions(info);
         std::cout << std::endl;
         emulate(instruct, rainbow);
      } catch (std::runtime_error &e) {
         std::cout << e.what() << std::endl;
      }
   }
   else
   {
      for (int i = 1; i < ac; i++)
      {
         if (std::string(av[i]) == "-rainbow")
            rainbow = true;
         if (std::string(av[i]) == "-info")
            info = true;
      }

      if (ac == 2 && std::string(av[1]) == "-rainbow")
      {
         try {
            t_instruct instruct = Parse::getInstructions(info);
            emulate(instruct, rainbow);
         } catch (std::runtime_error &e) {
            std::cout << e.what() << std::endl;
         }
      }

      for (int i = 1; i<ac; i++)
      {
         if (std::string(av[i]) == "-rainbow" || std::string(av[i]) == "-info")
            continue;
         try {
            t_instruct instruct = Parse::getInstructions(std::string(av[i]), info);
            emulate(instruct, rainbow);
         } catch (std::runtime_error &e) {
            std::cout << av[i] << " : " << e.what() << std::endl;
         }
      }
   }
   return 0;
}
