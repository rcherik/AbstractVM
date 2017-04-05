/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VmStack.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:50:32 by rcherik           #+#    #+#             */
/*   Updated: 2016/10/14 16:50:34 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VMSTACK_HPP
#define VMSTACK_HPP

#include <stack>

template <typename T>
class VmStack : public std::stack<T>
{
   private:
      typedef std::stack<T> base;

      VmStack &		operator=(VmStack const & src);

    public:
    VmStack(void) {}
    ~VmStack(void) {}
    VmStack(VmStack const & o): base(o) {}

    typedef typename base::container_type::iterator    iterator;
    using            base::operator=;
    iterator        begin() { return base::c.begin(); }
    iterator        end() { return base::c.end() ; }

};

#endif
