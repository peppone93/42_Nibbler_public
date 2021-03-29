/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:04:14 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/07 18:04:14 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <string>
#include "IntVec.hpp"

class Window
{
public:
	Window();
	Window(IntVec dim);
	Window(Window const& copy);
	Window& operator=(Window const& copy);
	virtual ~Window();

	IntVec const& getDim() const;
	unsigned int const& getSize() const;

private:
	IntVec			m_dim;
	unsigned int	m_size;
};

#endif //!WINDOW_HPP