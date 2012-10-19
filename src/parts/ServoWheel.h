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

#ifndef SERVOWHEEL_H_INCLUDED
#define SERVOWHEEL_H_INCLUDED

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

#include <parts/SimpleWheel.h>

/**
 * \brief Servo wheel primitive object
 *
 * This class provides a servo wheel.
 */
class OOMLParts_EXP_DEC ServoWheel : public SimpleWheel
{
public:
	/**
	 * \brief Default constructor.
	 */
	ServoWheel() :
		SimpleWheel(1, 0.1, 0.1),
		_servoRadius(0.4),
		_servoThickness(0.05)
	{
		rebuild();
	}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param radius Wheel radius.
	 * \param axeRadius Wheel's axe radius.
	 * \param thickness Wheel thickness.
	 * \param servoRadius Servo piece radius.
	 * \param servoThickness Servo piece thickness.
	 */
	ServoWheel(double radius, double axeRadius, double thickness, double servoRadius, double servoThickness) :
		 SimpleWheel(radius,thickness,axeRadius),
		 _servoRadius(servoRadius),
		 _servoThickness(servoThickness)
	{
		if (_servoRadius > radius)
			_servoRadius = radius - PART_MARGIN;
		if (_servoThickness > thickness)
			_servoThickness = thickness - PART_MARGIN;
    rebuild();
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~ServoWheel() {}

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
	double _servoRadius; /** Servo's piece radius. */
	double _servoThickness; /** Servo's piece thickness. */
};

#endif // SERVOWHEEL_H_INCLUDED
