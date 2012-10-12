/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Trevio
 *
 * OOML is licenced under the Common Creative License,
 * Attribution-ShareAlike 3.0
 *
 * You are free:
 *   - to Share - to copy, distribute and transmit the work
 *   - to Remix - to adapt the work
 *
 * Under the following conditions:
 *   - Attribution. You must attribute the work in the manner specified
 *     by the author or licensor (but not in any way that suggests that
 *     they endorse you or your use of the work).
 *   - Share Alike. If you alter, transform, or build upon this work,
 *     you may distribute the resulting work only under the same or
 *     similar license to this one.
 *
 * Any of the above conditions can be waived if you get permission
 * from the copyright holder.  Nothing in this license impairs or
 * restricts the author's moral rights.
 *
 * It is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 **********************************************************************/

#ifndef REGULARPRISM_H_INCLUDED
#define REGULARPRISM_H_INCLUDED

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
 * \brief Regular base prism primitive object
 *
 * This class provides a prism with a regular base.
 */
class OOMLComponents_EXP_DEC RegularPrism: public Component
{
public:
	/**
	 * \brief Constructor
	 *
	 * Creates a regular prism with the given regular n-side polygon.
	 *
	 * \param n Number of sides of the base regular polygon.
	 * \param s Length of every side of the base regular polygon.
	 * \param height Height over the z=0 plane of the apex.
	 *
	 */
    RegularPrism(unsigned int n, double s, double height) :
		 Component()
	{
		if (n < 3)
			n = 3;

        double angle = 2.0 * M_PI / n;
		double radius = s / 2 / sin(M_PI / 4);

		Polygon<Point2D> base;
        for (unsigned int i = 0; i < n; i++)
		{
			double a = angle * i;
			base.addPoint(Point2D(radius * cos(a), radius * sin(a)));
		}

        //std::cout << base.getPoints().size() << std::endl;

        set((PolygonalPrism(base, height)).get());
	}
};


#endif // REGULARPRISM_H_INCLUDED
