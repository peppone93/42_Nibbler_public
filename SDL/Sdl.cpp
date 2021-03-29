/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:51:07 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/11 14:51:07 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sdl.hpp"

Sdl::Sdl(sGrid& grid, IntVec const& winDim) :
	m_grid(grid),
	m_winDim(winDim),
	pixels(NULL),
	m_score{}
{
	m_keymap.insert(std::make_pair(SDLK_ESCAPE, 0));
	m_keymap.insert(std::make_pair(SDLK_UP, 1));
	m_keymap.insert(std::make_pair(SDLK_RIGHT, 2));
	m_keymap.insert(std::make_pair(SDLK_DOWN, 3));
	m_keymap.insert(std::make_pair(SDLK_LEFT, 4));
	m_keymap.insert(std::make_pair(SDLK_w, 5));
	m_keymap.insert(std::make_pair(SDLK_d, 6));
	m_keymap.insert(std::make_pair(SDLK_s, 7));
	m_keymap.insert(std::make_pair(SDLK_a, 8));
	m_keymap.insert(std::make_pair(SDLK_1, 9));
	m_keymap.insert(std::make_pair(SDLK_2, 10));
	m_keymap.insert(std::make_pair(SDLK_3, 11));
	m_keyState.resize(m_keymap.size());
	m_score[0] = m_grid.score;
	if (m_grid.Mscore)
		m_score[1] = m_grid.Mscore;
}

Sdl::Sdl(Sdl const& copy) :
	m_grid(copy.m_grid),
	m_winDim(copy.m_winDim)
{}

Sdl& Sdl::operator=(Sdl const& copy)
{
	m_grid = copy.m_grid;
	return (*this);
}

Sdl::~Sdl()
{}

[...]

void	Sdl::drawSnake(int x, int y, int Case)
{
	x = x - 10 + m_grid.offset.x;
	y = y - 10 + m_grid.offset.y;
	if (Case < SNAKE_UR)
		directionChunk(x, y, Case);
	else if (Case >= SNAKE_H_U && Case <= SNAKE_H_L)
		headChunk(x, y, Case);
	else if (Case >= SNAKE_Q_U && Case <= SNAKE_Q_L)
		queueChunk(x, y, Case);
	else
		cornerChunk(x, y, Case);
}

void	Sdl::drawSuperFruit(int x, int y)
{
	static bool flipFlop(false);

	if (!flipFlop)
	{
		x = x - 10 + m_grid.offset.x;
		y = y - 10 + m_grid.offset.y;
		colorSquare(x + 3, y + 5); // up L
		colorSquare(x + 10, y + 5); // up R
		colorSquare(x + 7, y + 8); // center
		colorSquare(x + 3, y + 11); // down L
		colorSquare(x + 10, y + 11); // down R
		flipFlop = true;
	}
	else
		flipFlop = false;
}

void	Sdl::drawFruit(int x, int y)
{
	x = x - 10 + m_grid.offset.x;
	y = y - 10 + m_grid.offset.y;
	colorSquare(x + 7, y + 3);
	colorSquare(x + 3, y + 7);
	colorSquare(x + 11, y + 7);
	colorSquare(x + 7, y + 11);
}

void	Sdl::drawObstacle(int x, int y)
{
	x = x - 10 + m_grid.offset.x;
	y = y - 10 + m_grid.offset.y;
	defaultChunk(x, y);
}

void	Sdl::gridToPixels()
{
	for(int y(0); y < m_grid.dim.y; y++)
		for (int x(0); x < m_grid.dim.x; x++)
		{
			int Case(m_grid.square[y * m_grid.dim.x + x]);
			if (Case == FRUIT)
				drawFruit(x * SQUARE, y * SQUARE);
			else if (Case == SUPER_FRUIT)
				drawSuperFruit(x * SQUARE, y * SQUARE);
			else if (Case == OBSTACLE)
				drawObstacle(x * SQUARE, y * SQUARE);
			else if (Case >= SNAKE_U)
				drawSnake(x * SQUARE, y * SQUARE, Case);
		}
	scoreToPixels();
}

void Sdl::init()
{
	SDLsurface = NULL;
	SDLwindow = NULL;
	
	if (SDL_VideoInit(0) == -1) // Initialize Video.
		throw std::range_error("Error during SDL initialization");				
	SDLwindow = SDL_CreateWindow("SDL Window", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_winDim.x, m_winDim.y, 0); // Create the window
	if (!SDLwindow)
		throw std::range_error("Error during SDL window creation" + std::string(SDL_GetError()));	
	SDLsurface = SDL_GetWindowSurface(SDLwindow); // Get the surface from the window
	if (!SDLsurface)
		throw std::range_error("Error during SDL surface creation" + std::string(SDL_GetError()));
	
	pixels = static_cast<int*>(SDLsurface->pixels);
	for (int i(0); i < m_winDim.x * m_winDim.y; i++)
		pixels[i] = 0x8ced24; //  manual clean
	colorMargin(); // color borders
	initScore();
}

std::vector<bool>& Sdl::getEvents()
{
	std::vector<bool>::iterator it(m_keyState.begin());
	for (; it != m_keyState.end(); it++)
		*it = false; // all false
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			std::map<int, int>::iterator it;
			for(it = m_keymap.begin(); it != m_keymap.end(); ++it)
				if (event.key.keysym.sym == it->first)
					m_keyState[it->second] = true;
		}
		if (event.type == SDL_QUIT)
			m_keyState[0] = true;
	}
	return m_keyState;
}

void Sdl::draw()
{
	if (!pixels)
		throw std::range_error("Error during SDL drawing");
	for (int j(m_grid.offset.y + THICK); j < m_winDim.y - m_grid.offset.y - THICK - SQUARE; j++)
		for (int i(m_grid.offset.x + THICK); i < m_winDim.x - m_grid.offset.x - THICK; i++)
			pixels[j * m_winDim.x + i] = 0x8ced24; //  manual clean
	gridToPixels();
	SDL_UpdateWindowSurface(SDLwindow);
}

void Sdl::Iexit()
{
	SDL_FreeSurface(SDLsurface); // to be sure
	SDL_DestroyWindow(SDLwindow); // Destroy the m_window. This will also destroy the surface
	SDL_VideoQuit();

	/*	conflict with SDL Mixer, VideoQuit is enough
	* 	SDL_Quit(); 
	*/
}

IGraphic	*LibConstructor(sGrid& grid, IntVec const& winDim)
{
	return new Sdl(grid, winDim);
}

void		LibDestructor(IGraphic*  lib)
{
	delete lib;
}