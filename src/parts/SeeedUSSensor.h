/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Alberto Valero-Gomez
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
