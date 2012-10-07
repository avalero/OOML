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
