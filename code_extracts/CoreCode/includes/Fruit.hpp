/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fruit.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:58:33 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/04 15:58:33 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <iostream>
#include <string>
#include <deque>
#include "IntVec.hpp"

class SnakePart;
struct sGrid;

#define SUPER_FRUIT_DELAY 65

class Fruit
{
public:
	Fruit();
	Fruit(sGrid* grid, bool arcade);
	Fruit(Fruit const& copy);
	Fruit& operator=(Fruit const& copy);
	virtual ~Fruit();

	void newFruit();
	bool const& isSuper() const;
	void superFruitTimer();
	IntVec const& getPos() const;

private:
	sGrid*	m_grid;
	IntVec	m_pos;
	int		m_generatedN;
	bool	m_super;
	bool	m_arcade;
	int		m_superTimer;
};

#endif //!FRUIT_HPP