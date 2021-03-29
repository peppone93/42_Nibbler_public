/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:51:07 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/11 14:51:07 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_HPP
#define SDL_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <SDL2/SDL.h>
#include "IGraphic.hpp"
#include "IntVec.hpp"
#include "grid.hpp"

#define THICK 5

class Sdl : public IGraphic
{
public:
	Sdl();
	Sdl(sGrid& grid, IntVec const& winDim);
	Sdl(Sdl const& copy);
	Sdl& operator=(Sdl const& copy);
	virtual ~Sdl();

	void			   	init();
    std::vector<bool>&	getEvents();
    void				draw();
    void				Iexit();

private:
	void initScore();
	void gridToPixels();
	void scoreToPixels();
	void drawFruit(int x, int y);
	void drawSuperFruit(int x, int y);
	void drawObstacle(int x, int y);
	void drawSnake(int x, int y, int Case);
	void colorMargin();
	void colorSquare(int x, int y);
	void defaultChunk(int x, int y);
	void headChunk(int& x, int& y, int& Case);
	void queueChunk(int& x, int& y, int& Case);
	void directionChunk(int& x, int& y, int& Case);
	void cornerChunk(int& x, int& y, int Case);

	sGrid&				m_grid;
	IntVec const&		m_winDim;
	std::map<int, int>	m_keymap;
	std::vector<bool>	m_keyState;

	SDL_Surface*		SDLsurface;
	SDL_Window*			SDLwindow;
	SDL_Event			event;
	int*				pixels;
	int					m_score[2];
};

extern "C"
{
        IGraphic	*LibConstructor(sGrid& grid, IntVec const& winDim);
        void		LibDestructor(IGraphic* lib);      
}

#endif //!SDL_HPP