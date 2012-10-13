/*
*    OOML : Object Oriented Mechanics Library
*    Copyright (C) 2012  Alberto Valero Gomez, Juan González Gómez, Rafael Treviño
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/


#ifndef SEEEDUSSENSOR_H_INCLUDED
#define SEEEDUSSENSOR_H_INCLUDED

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

/**
 * \brief Seeed Ultrasonic Sensor Model
 *
 * This class provides a Seeed Ultrasonic Sensor Model
 * http://www.seeedstudio.com
 */
class OOMLParts_EXP_DEC SeeedUSSensor : public AbstractPart
{
public:

	 struct Data{
		  double sx; //!< x dimension
		  double sy; //!< y dimension
		  double sz;//!< z dimension

		  double board_thickness; //!< thickness of the board
		  double drills_x_dist; //!< x distance among drills
		  double drills_y_dist; //!< y distance among drills
		  double drills_radius; //!< drills radius
		  double sensor_radius; //!< sensor radius
		  double sensor_dist_to_center; //!< distance between the center of the sensor and center of the board
	 };

  /**
	* \brief Default constructor.
	* \param fill_drills Fill Drill with Cylinder
	*/
  SeeedUSSensor(bool fill_drills = true) :
		AbstractPart(), _fill_drills(fill_drills)
  {
	 rebuild();
  }
  /**
	* \brief Default destructor.
	*/
  virtual ~SeeedUSSensor() {}

  /**
	 * \breif returns part data
	 * \return part data
	 */
  inline const Data getData() const{ return data;}
protected:
  /**
	* \brief Build the piece.
	*
	* This method build the piece from simpler objects.
	*
	* \return The piece built.
	*/
  virtual Component build();

  bool _fill_drills;
  Data data;

};

#endif
