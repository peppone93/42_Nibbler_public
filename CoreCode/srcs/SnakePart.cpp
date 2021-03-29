/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakePart.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:41:19 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/07 22:41:19 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SnakePart.hpp"

SnakePart::SnakePart(IntVec pos, eDirection dir) :
	m_pos(pos),
	m_dir(dir)
{}

SnakePart::SnakePart(SnakePart const& copy)
{
	*this = copy;
}

SnakePart& SnakePart::operator=(SnakePart const& copy)
{
	m_pos = copy.m_pos;
	m_dir = copy.m_dir;
	return (*this);
}

SnakePart::~SnakePart()
{}