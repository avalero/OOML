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

#ifndef SMS4303R_SERVO_H_INCLUDED
#define SMS4303R_SERVO_H_INCLUDED

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

#include "GenericServo.h"

/**
 * \brief Generic Servo Model
 *
 * This class provides a Generic Servo Model
 */
class OOMLParts_EXP_DEC SMS4303RServo : public GenericServo
{
public:

    /* MEMBER FUNCTIONS */

    /**
     * @brief SM-S4303RServoServo
     * @param fill
     * @param cable_space
     * @param crown
     */
    SMS4303RServo(bool fill = true, bool cable_space=true, double fill_length=10);

    /**
     * \brief Default destructor.
     */
    virtual ~SMS4303RServo() {}

    /**
     * @brief getBackCover
     * @return BackCover of this precise servo model
     */
    virtual Component getBackCover();
};

#endif // OOML_GENERIC_SERVO_H_INCLUDED
