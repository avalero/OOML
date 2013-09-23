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

#include <parts/GenericServo.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <components/RoundedTablet.h>
#include <core/Union.h>
#include <core/Hull.h>

Component GenericServo::getBackCover()
{
    // the drills for screwing the servo
    Component holes_tpl = Cylinder(_data.holes_radius,_data.holes_support_thickness+1,20,true);
    Component drills_tpl = Cylinder(0.75,_data.holes_support_thickness+1,10,true);


    Component holes = holes_tpl.translatedCopy(_data.d_op_holes/2 , _data.d_cl_holes/2, 0)
            + holes_tpl.translatedCopy(_data.d_op_holes/2 , - _data.d_cl_holes/2, 0)
            + holes_tpl.translatedCopy(- _data.d_op_holes/2 , _data.d_cl_holes/2, 0)
            + holes_tpl.translatedCopy(- _data.d_op_holes/2 , - _data.d_cl_holes/2, 0)
            ;

    Component drills = drills_tpl.translatedCopy(-_data.length/2 + 2 , -_data.width/2 + 2 , 0)
            + drills_tpl.translatedCopy(-_data.length/2 + 2 , _data.width/2 - 2, 0)
            + drills_tpl.translatedCopy(_data.length/2 -2 , -_data.width/2 + 2, 0)
            + drills_tpl.translatedCopy(_data.length/2 - 2 , _data.width/2 - 2 , 0)
            ;


    Component holes_support = Cube(_data.total_lenght_with_holes , _data.width , _data.holes_support_thickness);

    Component cover = holes_support
            - holes
            - drills
            ;

    return cover;


}

Component GenericServo::getCrown(int type, double thickness, bool fill_hole)
{
    Component crown;

    //axis
    double ext_radius = 8.32/2 + 0.3;
    double int_radius = _data.axis_radius + 0.1;
    double screw_radius = 2.9/2 + COMPONENT_MARGIN;
    double height = 5.55 - 1.9;

    Component axis = Cylinder(ext_radius, height + thickness, 50,false);

    if(!fill_hole)
            axis = axis - Cylinder(int_radius,height + COMPONENT_MARGIN,20,false).translate(0,0,-COMPONENT_MARGIN);

    Component screw_drill = Cylinder(screw_radius, thickness + height + COMPONENT_MARGIN, 20, false);

    switch (type){
    case 0:
    {
        double tail_distance = 50;
        Component tail = Cylinder(8.81/2,thickness,20,false);
        Component core = Cylinder(14.20/2 , thickness , 20, false);

        crown =
                ( core
                  &
                  tail.translatedCopy(tail_distance/2,0,0)
                  )
                +
                ( core
                  &
                  tail.translatedCopy( - tail_distance/2,0,0)
                  )
                ;
    }
        break;
    case 1:
    {
        double radius = 20.89 / 2;
        crown = Cylinder(radius,thickness,50,false);
    }
        break;
    case 2:
    {
        double radius = 45.5/2;
        crown = Cylinder(radius,thickness,100,false);
    }
        break;
    case 3:
    {
        double tail_distance = 31.95;

        Component tail = Cylinder(4.92/2,thickness,20,false);
        Component core = Cylinder(ext_radius , thickness , 20, false);

        crown =
                ( core
                   &
                   tail.translatedCopy(tail_distance/2,0,0)
                   )
                 +
                 ( core
                   &
                   tail.translatedCopy( - tail_distance/2,0,0)
                   )
                + Cylinder(12.20/2 , thickness , 20, false)
                ;
    }
        break;

    } // end switch

    crown.translate(0,0,height);

    crown = crown
            + axis
            ;


    if(!fill_hole){
        crown = crown - screw_drill;
    }


    crown.addLink(RefSys(0,0,0));
    crown.addLink(RefSys(0,0,0).rotate(0,180,0).translate(0,0,thickness + height));




    return crown;
}




Component GenericServo::build()
{
    Component servo;

    // Main body
    Component body = Cube(_data.length, _data.width, _data.height).translate(0,0,_data.height/2);

    // Axis of the servo
    Component axis = Cylinder(_data.axis_radius, _data.total_height_with_axis, 20, false).translate(_data.axis_position,0,0);

    // the drills for screwing the servo
    Component holes_tpl = Cylinder(_data.holes_radius,_fill_length,10,true).translate(0,0, _data.holes_height);

    Component holes = holes_tpl.translatedCopy(_data.d_op_holes/2 , _data.d_cl_holes/2, 0)
            + holes_tpl.translatedCopy(_data.d_op_holes/2 , - _data.d_cl_holes/2, 0)
            + holes_tpl.translatedCopy(- _data.d_op_holes/2 , _data.d_cl_holes/2, 0)
            + holes_tpl.translatedCopy(- _data.d_op_holes/2 , - _data.d_cl_holes/2, 0)
            ;


    Component holes_support = Cube(_data.total_lenght_with_holes , _data.width , _data.holes_support_thickness).translate(0,0,_data.holes_height);


    Component cable_clearance = Cube(_data.cable_clearance_width, _data.cable_clearance_length,_data.holes_height).translate( _data.length/2  + _data.cable_clearance_width/2 - COMPONENT_MARGIN , 0,  _data.holes_height / 2 );

    servo = body
            + axis
            + holes_support
            ;

    //check if we want the holes for the screws filled
    if (_fill_hole) servo = servo + holes;
    else servo = servo - holes;

    if (_cable_space) servo = servo + cable_clearance;

    // link for wheel
    servo.addLink(RefSys(_data.axis_position,0,_data.total_height_with_axis));
    // links for screws
    servo.addLink(RefSys(_data.d_op_holes/2 , _data.d_cl_holes/2, _data.holes_height));
    servo.addLink(RefSys(_data.d_op_holes/2 , -_data.d_cl_holes/2, _data.holes_height));
    servo.addLink(RefSys(-_data.d_op_holes/2 , _data.d_cl_holes/2, _data.holes_height));
    servo.addLink(RefSys(-_data.d_op_holes/2 , -_data.d_cl_holes/2, _data.holes_height));

    // Link at the base of the servo
    servo.addLink(RefSys(0,0,0));

    return servo;
}
