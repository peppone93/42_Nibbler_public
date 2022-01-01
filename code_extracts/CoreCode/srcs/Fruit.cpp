/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fruit.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:58:33 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/04 15:58:33 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"

Fruit::Fruit(sGrid* grid, bool arcade) :
	m_grid(grid),
	m_pos(0, 0),
	m_generatedN(1),
	m_super(false),
	m_arcade(arcade),
	m_superTimer(0)
{
	srand(time(NULL));
	m_pos.x = rand() % m_grid->dim.x;
	m_pos.x = m_pos.x < 1 ? 1 : m_pos.x;
	m_pos.y = rand() % (m_grid->dim.y - 1);
	m_pos.y = m_pos.y < 1 ? 1 : m_pos.y;
}

Fruit::Fruit(Fruit const& copy)
{
	*this = copy;
}

Fruit& Fruit::operator=(Fruit const& copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}

Fruit::~Fruit()
{}

void Fruit::newFruit()
{
	m_pos.x = rand() % m_grid->dim.x;
	m_pos.x = m_pos.x < 1 ? 1 : m_pos.x;
	m_pos.y = rand() % (m_grid->dim.y - 1);
	m_pos.y = m_pos.y < 1 ? 1 : m_pos.y;

	if (m_grid->square[m_pos.y * m_grid->dim.x + m_pos.x] >= OBSTACLE)
		newFruit();
	m_generatedN++;
	m_super = false;
	m_superTimer = 0;
	if (m_arcade && m_generatedN % 5 == 0)
	{
		m_super = true;
		m_superTimer = SUPER_FRUIT_DELAY;
	}
}

bool const& Fruit::isSuper() const
{
	return m_super;
}

void Fruit::superFruitTimer()
{
	m_superTimer--;
	if (m_superTimer == 0)
		newFruit();
}

IntVec const& Fruit::getPos() const
{
	return m_pos;
}