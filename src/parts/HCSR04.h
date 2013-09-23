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


#ifndef HCSR04_H_INCLUDED
#define HCSR04_H_INCLUDED

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
#include <components/Cube.h>
#include <parts/USSensor.h>

/**
 * \brief Seeed Ultrasonic Sensor Model
 *
 * This class provides a Seeed Ultrasonic Sensor Model
 * http://www.seeedstudio.com
 */
class OOMLParts_EXP_DEC HCSR04USSensor : public USSensor
{
public:

  /**
	* \brief Default constructor.
	* \param fill_drills Fill Drill with Cylinder
	*/
  HCSR04USSensor(bool fill_drills = false) :
  USSensor(45,20,15,2,40,15,0.75,8.4,13.5,fill_drills)
  {
	 rebuild();
  }
  /**
	* \brief Default destructor.
	*/
  virtual ~HCSR04USSensor() {}
};

#endif
