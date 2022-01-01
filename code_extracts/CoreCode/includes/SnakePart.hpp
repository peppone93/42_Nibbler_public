/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakePart.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:41:19 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/07 22:41:19 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKEPART_HPP
#define SNAKEPART_HPP

#include <iostream>
#include <string>
#include "IntVec.hpp"

enum eDirection
{
	Up,
	Right,
	Down,
	Left
};

class SnakePart
{
public:
	SnakePart();
	SnakePart(IntVec pos, eDirection dir = Right);
	SnakePart(SnakePart const& copy);
	SnakePart& operator=(SnakePart const& copy);
	virtual ~SnakePart();

	IntVec		m_pos;
	eDirection	m_dir;
};

#endif //!SNAKEPART_HPP