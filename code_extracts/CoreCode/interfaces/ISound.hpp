/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISound.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:01:04 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/23 16:01:04 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISOUND_HPP
#define ISOUND_HPP

class ISound
{
    public:
        virtual void init() = 0;
	    virtual void PlaySound(int idx) = 0;
        virtual void Iexit() = 0;
        virtual ~ISound(){}
};

#endif //!ISOUND_HPP