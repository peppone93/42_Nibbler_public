/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:58:19 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/04 15:58:19 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
#include <string>
#include <deque>
#include "IntVec.hpp"
#include "SnakePart.hpp"
#include "Fruit.hpp"
#include "Obstacle.hpp"

#define INITSIZE 4

struct sGrid;

class Snake
{
public:
	Snake();
	Snake(sGrid* grid, bool arcade);
	Snake(sGrid* grid, bool multyplayer, bool arcade);
	Snake(Snake const& copy);
	Snake& operator=(Snake const& copy);
	virtual ~Snake();

	bool eat(Fruit& fruit);
	bool validHeadPos(Obstacle* obastacle);
	void updateDir(int direction);
	void move();

	std::deque<SnakePart>& getParts();
	bool const& isAlive();

private:
	std::deque<SnakePart>	m_part;
	bool					m_alive;
	bool					m_arcade;
	eDirection				m_dir;
	sGrid*					m_grid;
	int*					m_score;
};

#endif //!SNAKE_HPP