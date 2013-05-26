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


#ifndef USSENSOR_H_INCLUDED
#define USSENSOR_H_INCLUDED

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
 * \brief Generic Ultrasonic Sensor Model
 *
 * This class provides a Generic Ultrasonic Sensor Model

 */
class OOMLParts_EXP_DEC USSensor : public AbstractPart
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
    USSensor(double sx, double sy, double sz, double board_thinckness,
             double drills_x_dist, double drills_y_dist, double drills_radius,
             double sensor_radius, double sensor_dist_to_center,
             bool fill_drills = true) :
        AbstractPart(), _fill_drills(fill_drills)
    {
        data.sx=sx;
        data.sy=sy;
        data.sz=sz;
        data.board_thickness=board_thinckness;
        data.drills_x_dist=drills_x_dist;
        data.drills_y_dist=drills_y_dist;
        data.drills_radius=drills_radius;
        data.sensor_radius=sensor_radius;
        data.sensor_dist_to_center=sensor_dist_to_center;

        rebuild();
    }
    /**
    * \brief Default destructor.
    */
    virtual ~USSensor() {}

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
