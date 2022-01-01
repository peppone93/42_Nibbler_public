/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:58:19 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/04 15:58:19 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Snake.hpp"

Snake::Snake(sGrid* grid, bool arcade) :
	m_part(),
	m_alive(true),
	m_arcade(arcade),
	m_dir(Right),
	m_grid(grid),
	m_score(&grid->score)
{
	IntVec temp(grid->dim.x / 2, grid->dim.y / 2);
	SnakePart snakePart(temp, m_dir);
	m_part.push_back(snakePart);
	temp.x -= 1;

	for (int i(1); i < INITSIZE; i++)
	{
		snakePart.m_pos.x = temp.x;
		m_part.push_back(snakePart);
		temp.x -= 1;
	}
	m_score = &grid->score;
	*m_score = INITSIZE;
}

[...]

Snake::Snake(Snake const& copy)
{
	*this = copy;
}

Snake& Snake::operator=(Snake const& copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}

Snake::~Snake()
{}

void Snake::move()
{
	SnakePart part = m_part[0];

	if (m_dir == Up)
		part.m_pos.y -= 1;
	else if (m_dir == Down)
		part.m_pos.y += 1;
	else if (m_dir == Right)
		part.m_pos.x += 1;
	else
		part.m_pos.x -= 1;
	part.m_dir = m_dir;
	m_part.push_front(part);
	m_part.pop_back();
}

[...]

void Snake::updateDir(int direction)
{
	int absolute(abs(m_dir - direction));
	if (absolute == 0 || absolute == 2)
		return;
	m_dir = eDirection(direction);
}

bool Snake::eat(Fruit& fruit)
{
	if (fruit.getPos() == m_part[0].m_pos)
	{
		SnakePart snakePart(m_part.back());
		if (snakePart.m_dir == Up)
			snakePart.m_pos.y += 1;
		else if (snakePart.m_dir == Down)
			snakePart.m_pos.y -= 1;
		else if (snakePart.m_dir == Right)
			snakePart.m_pos.x -= 1;
		else
			snakePart.m_pos.x += 1;
		m_part.push_back(snakePart);
		if (fruit.isSuper())
			(*m_score) += 2; //
		fruit.newFruit();
		(*m_score)++;
		return 1;
	}
	return 0;
}

std::deque<SnakePart>& Snake::getParts()
{
	return m_part;
}

bool const& Snake::isAlive()
{
	return m_alive;
}