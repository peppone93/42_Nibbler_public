/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mixer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:51:07 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/26 14:51:07 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mixer.hpp"

Mixer::Mixer():
    pick(NULL),
    lose(NULL)
{}

Mixer::Mixer(Mixer const& copy) :
    pick(NULL),
    lose(NULL)
{
    if (copy.lose)
        return ;
}

Mixer& Mixer::operator=(Mixer const& copy)
{
    if (this != &copy)
    {
        pick = copy.pick;
        lose = copy.lose;
    }
	return (*this);
}

Mixer::~Mixer()
{}


void Mixer::init()
{ 
	if (SDL_AudioInit("alsa") == -1) // Initialize Audio.
		throw std::range_error("Error during SDL Audio initialization");			
	//Initialize SDL_mixer 
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 256) == -1) 
		throw std::range_error("Error during SDL Mixer initialization");
    pick = Mix_LoadWAV("./CoreCode/wavAudio/pick.wav");
    if (!pick)
        throw std::range_error("Error loading wav sound");
    lose = Mix_LoadWAV("./CoreCode/wavAudio/lose.wav");
    if (!lose)
        throw std::range_error("Error loading wav sound");
}

void Mixer::PlaySound(int idx)
{
    if (!idx)
    {
        Mix_Volume(1, 128);
        if (Mix_PlayChannel(1, pick, 0) == -1)
		    throw std::range_error("Error playing sound" + std::string(Mix_GetError()));
    }
    else if (idx == 1)
    {
        Mix_Volume(1, 64);
        if (Mix_PlayChannel(1, lose, 0) == -1)
		    throw std::range_error("Error playing sound" + std::string(Mix_GetError()));
    }
}

void Mixer::Iexit()
{
    Mix_FreeChunk(pick);
    Mix_FreeChunk(lose);
    Mix_CloseAudio();
    SDL_AudioQuit();
}

ISound  *LibConstructor()
{
    return new Mixer();
}

void    LibDestructor(ISound* sound)
{
    delete sound;
}
