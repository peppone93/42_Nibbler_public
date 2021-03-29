/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Glfw.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:51:07 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/11 14:51:07 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLFW_HPP
#define GLFW_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unistd.h>

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include "IGraphic.hpp"
#include "IntVec.hpp"
#include "grid.hpp"

#define THICK 5

class Glfw : public IGraphic
{
public:
	Glfw();
	Glfw(sGrid& grid, IntVec const& winDim);
	Glfw(Glfw const& copy);
	Glfw& operator=(Glfw const& copy);
	virtual ~Glfw();

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
	void drawSnake(int x, int y, int& Case);
	void drawObstacle(int x, int y);
	void colorMargin();
	void colorCircle(int x, int y);
	void defaultChunk(int x, int y);
	void specialColorCircle(int x, int y);
	void headChunk(int& x, int& y, int& Case);
	void queueChunk(int& x, int& y, int& Case);
	void directionChunk(int& x, int& y, int& Case);
	void cornerChunk(int& x, int& y, int& Case);

	sGrid&				m_grid;
	IntVec const&		m_winDim;
	std::map<int, int>	m_keymap;
	std::vector<bool>	m_keyState;
	std::vector<IntVec>	m_circleTable;

	GLFWwindow*			GLFW_Window;
	__UINT32_TYPE__*	pixels; // int : problem with glDrawPixels
	int					m_score[2];
};

extern "C"
{
        IGraphic	*LibConstructor(sGrid& grid, IntVec const& winDim);
        void		LibDestructor(IGraphic* lib);      
}

#endif //!GLFW_HPP