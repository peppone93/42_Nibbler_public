/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:04:14 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/07 18:04:14 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

Window::Window(IntVec dim) :
	m_dim(dim),
	m_size(dim.x * dim.y)
{}

Window::Window(Window const& copy)
{
	*this = copy;
}

Window& Window::operator=(Window const& copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}

Window::~Window()
{}

IntVec const& Window::getDim() const
{
	return m_dim;
}

unsigned int const& Window::getSize() const
{
	return m_size;
}