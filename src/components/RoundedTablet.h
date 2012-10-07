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
