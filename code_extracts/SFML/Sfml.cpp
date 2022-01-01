/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:51:07 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/11 14:51:07 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sfml.hpp"

[...]

void	Sfml::gridToPixels()
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


void Sfml::init()
{
	SFMLwindow.create(sf::VideoMode(m_winDim.x, m_winDim.y), "SFML Window"); // windows
	SFMLwindow.setVerticalSyncEnabled(false);
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	SFMLwindow.setPosition(sf::Vector2i(desktop.width/2 - SFMLwindow.getSize().x/2, desktop.height/2 - SFMLwindow.getSize().y/2));

	SFMLbytePixels = new sf::Uint8[m_winDim.x * m_winDim.y * 4];
	pixels = reinterpret_cast<unsigned int*>(SFMLbytePixels); // manual creation and cast for pixels

	if (SFMLtexture.create(m_winDim.x, m_winDim.y) == false) // texture
		throw std::range_error("Error during SFML texture creation");
	SFMLsprite.setTexture(SFMLtexture); // init sprite and link it to texture

	for (int i(0); i < m_winDim.x * m_winDim.y; i++)
		pixels[i] = 0xff333300; //  manual clean
	colorMargin(); // color borders
	initScore();
}

std::vector<bool>& Sfml::getEvents()
{
	std::vector<bool>::iterator it(m_keyState.begin());
	for (; it != m_keyState.end(); it++)
		*it = false; // all false
	while (SFMLwindow.pollEvent(SFMLevent))
	{
		if (SFMLevent.type == sf::Event::KeyPressed)
		{
			std::map<int, int>::iterator it;
			for(it = m_keymap.begin(); it != m_keymap.end(); ++it)
				if (SFMLevent.key.code == it->first)
					m_keyState[it->second] = true;
		}
		if (SFMLevent.type == sf::Event::Closed)
			m_keyState[0] = true;
	}
	return m_keyState;
}

void Sfml::draw()
{
	if (!pixels)
		throw std::range_error("Error during SFML drawing");
	for (int j(m_grid.offset.y + THICK); j < m_winDim.y - m_grid.offset.y - THICK - SQUARE; j++)
		for (int i(m_grid.offset.x + THICK); i < m_winDim.x - m_grid.offset.x - THICK; i++)
			pixels[j * m_winDim.x + i] = 0xff333300; //  manual clean
	gridToPixels();
	SFMLtexture.update(SFMLbytePixels); // update pixels of texture
	SFMLwindow.draw(SFMLsprite); // send sprite to windows
	SFMLwindow.display(); // update windows
}

void Sfml::Iexit()
{
	delete[] SFMLbytePixels;
	SFMLwindow.close();
}


IGraphic	*LibConstructor(sGrid& grid, IntVec const& winDim)
{
	return new Sfml(grid, winDim);
}

void		LibDestructor(IGraphic* lib)
{
	delete lib;
}