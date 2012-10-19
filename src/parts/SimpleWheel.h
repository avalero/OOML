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

#ifndef SIMPLEWHEEL_H_INCLUDED
#define SIMPLEWHEEL_H_INCLUDED

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
 * \brief Simple wheel primitive object
 *
 * This class provides a simple wheel.
 */
class OOMLParts_EXP_DEC SimpleWheel : public AbstractPart
{
public:
	/**
	 * \brief Default constructor.
	 */
	SimpleWheel() :
		AbstractPart(),
		_radius(1),
		_thickness(0.1),
		_axeRadius(0.1)
	{
		rebuild();
	}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param radius Wheel radius.
	 * \param axeRadius Wheel's axe radius.
	 * \param thickness Wheel thickness.
	 */
	SimpleWheel(double radius, double thickness, double axeRadius) :
		AbstractPart(),
		_radius(radius),
		_thickness(thickness),
		_axeRadius(axeRadius)
	{
		if (_axeRadius > _radius)
			_axeRadius = _radius - PART_MARGIN;
    rebuild();
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~SimpleWheel() {}

  inline double getRadius() const { return _radius; }
	inline double getThickness() const { return _thickness; }
	inline double getAxeRadius() const { return _axeRadius; }

protected:
	/**
	 * \brief Build the piece.
	 *
	 * This method build the piece from simpler objects.
	 *
	 * \return The piece built.
	 */
	virtual Component build();

private:
	double _radius; /** Wheel radius. */
	double _thickness; /** Wheel thickness. */
	double _axeRadius; /** Wheel's axe radius. */
};

#endif // SIMPLEWHEEL_H_INCLUDED
