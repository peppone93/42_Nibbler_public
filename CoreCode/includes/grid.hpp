/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:53:38 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/25 14:53:38 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HPP
#define GRID_HPP

#define SQUARE 20
#define SNAKEOFFSET 4
#define HEADOFFSET 16
#define QUEUEOFFSET 20

#include "IntVec.hpp"

enum eSquareName
{
    EMPTY,
    FRUIT,
    SUPER_FRUIT,
    OBSTACLE,
    SNAKE_U,
    SNAKE_R,
    SNAKE_D,
    SNAKE_L,
    SNAKE_UR,
    SNAKE_UL,
    SNAKE_RU,
    SNAKE_RD,
    SNAKE_DR,
    SNAKE_DL,
    SNAKE_LU,
    SNAKE_LD,
    SNAKE_H_U,
    SNAKE_H_R,
    SNAKE_H_D,
    SNAKE_H_L,
    SNAKE_Q_U,
    SNAKE_Q_R,
    SNAKE_Q_D, 
    SNAKE_Q_L
};

struct sGrid
{
    IntVec dim;
    IntVec offset;
    int*    square;
    int     score;
    int     Mscore;
};

#endif // GRID_HPP