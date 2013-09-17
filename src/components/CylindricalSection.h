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

#ifndef CYLINDRICAL_SECTION_H_INCLUDED
#define CYLINDRICAL_SECTION_H_INCLUDED

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
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <core/Intersection.h>
#include <core/Math.h>
#include <core/Point2D.h>
#include <core/Polygon.h>

#include <math.h>

/**
 * \brief Regular base prism primitive object
 *
 * This class provides a prism with a regular base.
 */
class OOMLComponents_EXP_DEC CylindricalSection: public Component
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
    CylindricalSection(double r1, double r2, double alpha, double height, int num_faces=100, bool centered=true) :
		 Component()
    {

        Component object = Cylinder(r2,height,num_faces,centered)
                - Cylinder(r1 , height+2*COMPONENT_MARGIN , num_faces ,centered ).translate(0,0,-COMPONENT_MARGIN/2)
                ;


        Polygon<Point2D> section_base;
        section_base.addPoint(Point2D(0,0));
        section_base.addPoint(Point2D( r2 , r2*sin(deg2rad(alpha/2))));
        section_base.addPoint(Point2D( r2 , -r2*sin(deg2rad(alpha/2))));

        Component section = PolygonalPrism(section_base,height,centered);

        object = object * section;

        set(object.get());
	}
};


#endif
