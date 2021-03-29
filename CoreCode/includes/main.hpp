/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 22:53:38 by gbianco           #+#    #+#             */
/*   Updated: 2021/02/02 14:51:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdint>
#include <dlfcn.h>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include "Window.hpp"
#include "Snake.hpp"
#include "Obstacle.hpp"
#include "IGraphic.hpp"
#include "ISound.hpp"

typedef IGraphic	*(*GraphicConstrPTR)(sGrid& grid, IntVec const& winDim);
typedef	void		(*GraphicDestrPTR)(IGraphic*);
typedef ISound		*(*SoundConstrPTR)();
typedef	void		(*SoundDestrPTR)(ISound*);

typedef std::chrono::milliseconds ms;

#define LIB_DELAY 94
#define LIB_MIN_DELAY 50
#define END_DELAY 2300

#define DIR_OFFSET 1
#define DIR2_OFFSET 5
#define LIB_OFFSET 9

enum eKey
{
	KExit,
	KUp,
	KRight,
	KDown,
	KLeft,
	Kw,
	Kr,
	Kd,
	Kl,
	K_1,
	K_2,
	K_3
};

struct sGrid;

struct sGameElement
{
	Window*		window;
	Snake*		snake;
	Snake*		Msnake;
	Fruit*		fruit;
	Obstacle*	obstacle;
    sGrid*		grid;

	std::string	libpath[3];
	int			libIdx;

	bool		multiplayer;
	bool		arcade;
	int			delay;
};

void singlePlayer(sGameElement& gameElement);
void multiPlayer(sGameElement& gameElement);
void initGame(sGameElement& gameElement);
void singlePlayerLoop(sGameElement& gameElement, IGraphic *lib, ISound *sound);
void multiPlayerLoop(sGameElement& gameElement, IGraphic *lib, ISound *sound);
void updateGrid(sGameElement& gameElement);
void wait(int delay);

#endif // MAIN_HPP
