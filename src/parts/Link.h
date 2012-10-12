/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Treviño
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

#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

#include <core/AbstractPart.h>

/**
 * \brief link primitive object
 *
 * This class provides a link.
 */
class OOMLParts_EXP_DEC Link : public AbstractPart
{
public:
	/**
	 * \brief Default constructor.
	 */
	Link() :
		AbstractPart(),
		_radius(1),
		_axeRadius(0.1),
		_thickness(0.1)
	{}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param radius Wheel radius.
	 * \param axeRadius Wheel's axe radius.
	 * \param thickness Wheel thickness.
	 */
	Link(double radius, double axeRadius, double thickness) :
		AbstractPart(),
		_radius(radius),
		_axeRadius(axeRadius),
		_thickness(thickness)
	{
		if (_axeRadius > _radius)
			_axeRadius = _radius - PART_MARGIN;
    rebuild();
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Link() {}

protected:
	/**
	 * \brief Build the piece.
	 *
	 * This method build the piece from simpler objects.
	 *
	 * \return The piece built.
	 *
	 * \note Complete the link, now it's incomplete.
	 */
	virtual Component build();

private:
	double _radius; /** Wheel radius. */
	double _axeRadius; /** Wheel's axe radius. */
	double _thickness; /** Wheel thickness. */
};

#endif // LINK_H_INCLUDED
