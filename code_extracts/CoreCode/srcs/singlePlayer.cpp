/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singlePlayer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:53:13 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/06 15:53:13 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static bool updateEvents(sGameElement& gameElement, std::vector<bool>& KeyState)
{
	if (KeyState[KExit] == true)
		throw std::range_error("Exit Game"); // exit game
	for (int i(KUp); i <= KLeft; i++)
		if (KeyState[i] == true)
		{
			gameElement.snake->updateDir(i - DIR_OFFSET); // update the snake position
			break ;
		}
	for (int i(K_1); i <= K_3; i++)
		if (KeyState[i] == true && i - LIB_OFFSET != gameElement.libIdx)
		{
			gameElement.libIdx = i - LIB_OFFSET;
			return false;
		}
	return true;
}

static void updateGame(sGameElement& gameElement, ISound *sound)
{
	gameElement.snake->move();
	if (gameElement.snake->eat(*(gameElement.fruit)))
	{
		sound->PlaySound(0);
		if (gameElement.arcade && gameElement.delay > LIB_MIN_DELAY)
			gameElement.delay -= 2;
	}
	if (!(gameElement.snake->validHeadPos(gameElement.obstacle)))
	{
		sound->PlaySound(1);
		std::this_thread::sleep_for(ms(END_DELAY));
		throw std::logic_error("You lost!");
	}
	if (gameElement.fruit->isSuper())
		gameElement.fruit->superFruitTimer();
}

void singlePlayerLoop(sGameElement& gameElement, IGraphic *lib, ISound *sound)
{
	std::vector<bool>& KeyState(lib->getEvents());

	lib->init();
	while(1)
	{
		lib->getEvents();
		if (updateEvents(gameElement, KeyState) == false)
			break ;
		updateGame(gameElement, sound);
		updateGrid(gameElement);
		lib->draw();
		wait(gameElement.delay);
	}
}

void singlePlayer(sGameElement& gameElement)
{
	try {
		Snake	snake(gameElement.grid, gameElement.arcade);
		Fruit	fruit(gameElement.grid, gameElement.arcade);
		Obstacle obstacle(gameElement.grid, fruit);

		gameElement.snake = &snake;
		gameElement.fruit = &fruit;
		if (gameElement.arcade)
			gameElement.obstacle = &obstacle;
		initGame(gameElement);
	}
	catch(const std::exception& e) {
		delete[] gameElement.grid->square;
		if (e.what()[0])
			std::cerr << e.what() << std::endl;
		throw std::runtime_error("");
	}
}