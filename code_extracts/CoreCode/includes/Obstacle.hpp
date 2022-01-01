/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:16:13 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/30 16:16:13 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "IntVec.hpp"
#include "Fruit.hpp"
#include "grid.hpp"

class Obstacle
{
public:
    Obstacle();
	Obstacle(sGrid* grid, Fruit& fruitPos);
	Obstacle(Obstacle const& copy);
	Obstacle& operator=(Obstacle const& copy);
	virtual ~Obstacle();

    std::vector<IntVec>& getPart();
    void setOnScreen();
    bool const& getOnScreen();

private:
    void caseOne();
    void caseTwo();
    void caseThree();
    void caseFour();
    void caseFive();

private:
    sGrid                   *m_grid;
	std::vector<IntVec>     m_block;
    bool                    m_onScreen;
};

#endif // !OBSTACLE_HPP