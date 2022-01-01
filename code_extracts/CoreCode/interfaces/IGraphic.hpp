/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphic.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:01:04 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/23 16:01:04 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGRAPHIC_HPP
#define IGRAPHIC_HPP

class IGraphic
{
    public:
        virtual void                    init() = 0;
        virtual std::vector<bool>&      getEvents() = 0;
        virtual void                    draw() = 0;
        virtual void                    Iexit() = 0;
        virtual ~IGraphic(){}
};

#endif //!IGRAPHIC_HPP