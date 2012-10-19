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


#ifndef SHARPIRSENSOR_H_INCLUDED
#define SHARPIRSENSOR_H_INCLUDED

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
 * \brief Shrap IR Analogic Sensor Model
 *
 * This class provides a Sharp IR Analogical Sensor Model
 * Model Ref.: GP2D120XJ00F
 */
class OOMLParts_EXP_DEC SharpIRSensor : public AbstractPart
{
public:

	 struct Data{
         double sx; //!< x dimension
         double sy; //!< y dimension
         double sz;//!< z dimension

		  double base_sx; //!< base x dimension
		  double base_sy; //!< base y dimension
		  double base_sz; //!< base z dimension

		  double top_base_sx; //!< top base x dimension
		  double top_base_sy; //!< top base y dimension
		  double top_base_sz; //!< top base z dimension

		  double drills_x_dist; //!< x distance among drills
		  double drills_radius; //!< drills radius
		  double drills_support_radius; //!< drills support radius
		  double drills_support_thickness; //!< drills support thickness
		  double drills_support_x_dist; //!< drills support x distance

		  double light_emitter_x; //!< Light emitter x size
		  double light_emitter_y; //!< Light emitter y size
		  double light_emitter_z; //!< Light emitter z size
		  double light_emitter_dist_to_middle;

		  double light_detector_x; //!< Light detector x size
		  double light_detector_y; //!< Light detector y size
		  double light_detector_z; //!< Light detector z size
		  double light_detector_dist_to_middle;
	 };

  /**
	* \brief Default constructor.
	* \param fill_drills Fill Drill with Cylinder
	*/
  SharpIRSensor(bool fill_drills = true) :
		AbstractPart(), _fill_drills(fill_drills)
  {

		data.base_sx = 29.5;
		data.base_sy = 13;
		data.base_sz = 7.2;

		data.top_base_sx = 29.5;
		data.top_base_sy = 8.4;
		data.top_base_sz = 11.5; //from the bottom




		data.drills_x_dist = 37;
		data.drills_radius = 1.6 + PART_MARGIN;
		data.drills_support_radius = 3.75;
		data.drills_support_thickness = 1.5;
		data.drills_support_x_dist = 37;

		data.light_emitter_x = 7.5;
		data.light_emitter_y = 7.2;
		data.light_emitter_z = 13.5; //from the bottom
		data.light_emitter_dist_to_middle = -10.25; //from middle to middle;

		data.light_detector_x = 16.3;
		data.light_detector_y = 7.2;
		data.light_detector_z = 13.5; //from the bottom
		data.light_detector_dist_to_middle = data.light_emitter_dist_to_middle
				  + data.light_emitter_x / 2
				  + 4.5
				  + data.light_detector_x / 2; //from middle to middle;

        data.sz = data.light_emitter_z;
        data.sx = data.drills_support_x_dist + 2 * data.drills_support_radius;
        data.sy = data.base_sy;

	 rebuild();
  }
  /**
	* \brief Default destructor.
	*/
  virtual ~SharpIRSensor() {}

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
