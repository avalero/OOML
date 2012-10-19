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

#ifndef ROUNDEDTABLET_H_INCLUDED
#define ROUNDEDTABLET_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Union.h>
#include <core/Difference.h>

/**
 * \brief Rounded tablet primitive object
 *
 * This class provides a rounded tablet.
 */
class OOMLComponents_EXP_DEC RoundedTablet : public Component
{
public:
	/**
	 * \brief Constructor
	 *
	 * Creates a rounded tablet.
	 *
	 * \param sx Tablet dimension in the x axis.
	 * \param sy Tablet dimension in the y axis.
	 * \param sz Tablet dimension in the z axis.
	 * \param radius Tablet corner radius.
	 * \param faces Number of faces of the rendered rounded tablet.
	 * \param center Centered tablet flag.
	 *
	 * \note Change the horrible set of bools by a bitfield and an enum.
	 */
	RoundedTablet(double sx, double sy, double sz, double radius, bool one=true, bool two=true, bool three=true, bool four=true, unsigned int faces=100, bool center=true) :
		Component()
	{
		if (sx < 1)
			sx=1;
		if (sy < 1)
			sy=1;
		if (sz < 1)
			sz=1;
		if (2*radius > sx)
			radius = sx/2;
		if (2*radius > sy)
			radius = sy/2;

		Component round_box;

     Component cyl(Cylinder(radius,sz));
     Component corner(Cube(2*radius,2*radius,sz));

    if (one)
            round_box = Cube(sx-2*radius + COMPONENT_MARGIN ,
											 sy-2*radius + COMPONENT_MARGIN,
											 sz)
					  + cyl.translatedCopy(sx/2-radius,sy/2-radius,0);
    else
            round_box = Cube(sx-2*radius + COMPONENT_MARGIN,
											 sy-2*radius + COMPONENT_MARGIN ,
											 sz) + corner.translatedCopy(sx/2-radius,sy/2-radius,0);

    if (two)
			round_box = round_box + cyl.translatedCopy(-sx/2+radius,sy/2-radius,0);
		else
			round_box = round_box + corner.translatedCopy(-sx/2+radius,sy/2-radius,0);

    if (three)
			round_box = round_box + cyl.translatedCopy(-sx/2+radius,-sy/2+radius,0);
    else
			round_box = round_box + corner.translatedCopy(-sx/2+radius,-sy/2+radius,0);

    if (four)
			round_box = round_box + cyl.translatedCopy(sx/2-radius,-sy/2+radius,0);
		else
			round_box = round_box + corner.translatedCopy(sx/2-radius,-sy/2+radius,0);

     round_box = round_box + Cube(sx-2*radius , radius , sz).translate(0,sy/2 -radius/2,0)
            + Cube(sx-2*radius , radius , sz).translate(0,-sy/2 +radius/2,0)
            + Cube(radius , sy - 2*radius , sz).translate(sx/2-radius/2,0,0)
            + Cube(radius , sy - 2*radius , sz).translate(-sx/2+radius/2,0,0);

    if (!center)
			round_box.translate(sx/2,sy/2,sz/2);

    set(round_box.get());
	}
};

#endif // ROUNDEDTABLET_H_INCLUDED
