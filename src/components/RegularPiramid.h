/*
*    OOML : Object Oriented Mechanics Library
*    Copyright (C) 2012  Alberto Valero Gomez, Juan González Gómez, Rafael Treviño
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License (LGPL) as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License (LGPL) for more details.
*
*    You should have received a copy of the GNU Lesser General Public License (LGPL)
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#ifndef REGULARPIRAMID_H_INCLUDED
#define REGULARPIRAMID_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include <components/PolygonalPrism.h>
#include <core/Math.h>
#include <core/Point2D.h>
#include <core/Polygon.h>

#include <math.h>

/**
 * \brief Regular base piramid primitive object
 *
 * This class provides a piramid with a regular base.
 */
class OOMLComponents_EXP_DEC RegularPiramid: public Component
{
public:
	/**
	 * \brief Constructor
	 *
	 * Creates a regular piramid with the given regular n-side polygon.
	 *
	 * \param n Number of sides of the base regular polygon.
	 * \param s Length of every side of the base regular polygon.
	 * \param height Height over the z=0 plane of the apex.
	 *
	 *
	 */
	RegularPiramid(unsigned int n, double s, double height) :
		Component()
	{
		if (n < 3)
			n = 3;

		double angle = 2 * M_PI / n;
		double radius = s / 2 / sin(M_PI / 4);

		Polygon<Point2D> base;
		for (unsigned int i = 0; i < n; ++i)
		{
			double a = angle * i;
			base.addPoint(Point2D(radius * cos(a), radius * sin(a)));
		}

		set(PolygonalPrism(base, height).get());
	}
};

#endif // REGULARPIRAMID_H_INCLUDED
