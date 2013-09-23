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

#ifndef OOML_GENERIC_SERVO_H_INCLUDED
#define OOML_GENERIC_SERVO_H_INCLUDED

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
 * \brief Generic Servo Model
 *
 * This class provides a Generic Servo Model
 */
class OOMLParts_EXP_DEC GenericServo : public AbstractPart
{

    // VARIABLE MEMBERS //
public:

    /**
     * @brief The Data struct
     */
    struct Data{
        double length; /// Length in mm
        double width; /// width in mm
        double height; /// height in mm
        double d_op_holes; /// disstance between opposite holes in mm
        double d_cl_holes; /// distance between closer holes in mm
        double holes_height; /// height of the holes position
        double holes_radius; /// radius of the holes
        double holes_support_thickness; /// thickness of the holes support
        double total_lenght_with_holes; ///total length of the servo
        double axis_position; /// position of the axis in relation with the center
        double axis_radius; /// radius of the axis
        double total_height_with_axis; ///total length of the servo with axis
        double cable_clearance_width; ///clearance space for cable (width direction)
        double cable_clearance_length; ///clearance space for cable (length direction)
    };

protected:

    Data _data; /// servo data
    bool _fill_hole; ///fill holes with screws
    bool _cable_space; ///make space for the cable;
    double _fill_length;

public:

/* MEMBER FUNCTIONS */

    /**
     * @brief GenericServo
     * @param data Data of the servo
     * @param fill
     * @param cable_space
     * @param crown
     */
    GenericServo(Data data, bool fill = true, bool cable_space=true, double fill_length = 10) :
        AbstractPart(), _data(data), _fill_hole(fill), _cable_space(cable_space), _fill_length(fill_length)
    {
        rebuild();
    }

    /**
     * \brief returns a component only with the crown
     * \param height Height of the crown
     * \return crown
     *
     * \note Create another component for the crown only and then use it in this one.
     */
    Component getCrown(int type=0, double thickness=2.6, bool fill_hole=false);

    /**
     * \brief Default destructor.
     */
    virtual ~GenericServo() {}

    inline virtual Data getData(){return _data;}

    /**
     * @brief getBackCover
     * @return Back cover for servo. To substitute de original
     */
    Component getBackCover();

protected:
   /**
   * \brief Build the piece.
   *
   * This method build the piece from simpler objects.
   *
   * \return The Generic Servo without Crown.
   */
    virtual Component build();

};

#endif // OOML_GENERIC_SERVO_H_INCLUDED
