/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntVec.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <gbianco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:19:32 by gbianco           #+#    #+#             */
/*   Updated: 2021/01/04 16:19:32 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTVEC_HPP
#define INTVEC_HPP

#include <iostream>

class IntVec
{
public:
	IntVec(int vx = 0, int vy = 0);
	IntVec(IntVec const& copy);
	IntVec& operator=(IntVec const& copy);
	virtual ~IntVec();

	void	print(std::ostream& flux) const;

	int x;
	int y;
};

IntVec operator+(IntVec const& a, IntVec const& b);
IntVec operator-(IntVec const& a, IntVec const& b);
IntVec operator*(IntVec const& a, int const& b);
IntVec operator/(IntVec const& a, int const& b);
bool operator==(IntVec const& a, IntVec const& b);
std::ostream& operator<<(std::ostream& flux, IntVec const& object);

#endif //!INTVEC_HPP