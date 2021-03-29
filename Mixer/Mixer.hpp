/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mixer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:51:07 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/26 14:51:07 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIXER_HPP
#define MIXER_HPP

#include <iostream>
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "ISound.hpp"

class Mixer : public ISound
{
public:
	Mixer();
	Mixer(Mixer const& copy);
	Mixer& operator=(Mixer const& copy);
	virtual ~Mixer();

    void init();
	void PlaySound(int idx);
    void Iexit();

private:
    Mix_Chunk *pick;
    Mix_Chunk *lose;
};

extern "C"
{
        ISound  *LibConstructor();
        void    LibDestructor(ISound* lib);      
}

#endif //!MIXER_HPP
