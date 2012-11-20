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
#ifndef OOML_STEPPERMOTOR_H
#define OOML_STEPPERMOTOR_H_H

#include "../core.h"

#include <core/AbstractPart.h>

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

enum StepperMotorType{Nema17};

class OOMLParts_EXP_DEC StepperMotor : public AbstractPart
{
public:
    /**
      * Part Data
      */
    struct Data{
        double x_dim_body;
        double y_dim_body;
        double z_dim_body;
        double drills_distance;
        double shaft_d;
        double shaft_length;
        double shaft_base_d;
        double shaft_base_thickness;
    };

    /**
      * Constructor
      */
    StepperMotor(StepperMotorType type);

    /**
     * \brief returns part data
     * \return part data
     */
    inline const Data getData() const{return data;}

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
    Data data;
};


#endif
