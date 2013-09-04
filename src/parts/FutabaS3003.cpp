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

#include <parts/FutabaS3003.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <components/RoundedTablet.h>
#include <core/Union.h>

Component FutabaS3003::getCrown(int type, double height, bool fill_hole)
{
    //Crown. Three types: rounded, four and six arms.
    Component difference, arm, crown;

    crown = Cylinder(10.75,height,30,true);

    if(!fill_hole)
        crown = crown - Cylinder(4.25, height + 2);

    return crown;
}




Component FutabaS3003::build()
{
    Component joint = Cylinder(4.25,4,30,true);
    Component hole_servo = Cylinder(1.8,1.8,15.0,20);
    Component hole_servo_fill = Cylinder(1.8,1.8,36.6,20,false);

    Component servo = RoundedTablet(20.5,41.5,36.6,1,true,true,true,true,100,false)
            + getCrown(_type,3,true).translate(10.5,10.5,42.1)
            + joint.translate(10.5,10.5,38.6)
            + RoundedTablet(20,9,3,1,true,true,true,true,50,false).translate(0.25,-8,26.6)
            + RoundedTablet(20,9,3,1,true,true,true,true,50,false).translate(0.25,40.5,26.6);




    //fill the holes of the screws?
    if(!_fill_hole)
        servo = servo
                - hole_servo.translatedCopy(5.25,-4.25,24)
                - hole_servo.translatedCopy(15.25,-4.25,24)
                - hole_servo.translatedCopy(5.25,45.75,24)
                - hole_servo.translatedCopy(15.25,45.75,24);
    else
        servo = servo //+ Cube(5,2,36.5,false).translate(7.75,41.5,0)
                + hole_servo_fill.translatedCopy(5.25,-4.25,0)
                + hole_servo_fill.translatedCopy(15.25,-4.25,0)
                + hole_servo_fill.translatedCopy(5.25,45.75,0)
                + hole_servo_fill.translatedCopy(15.25,45.75,0);

    //leave space for inserting the cable
    if (_cable_hole){
        servo = servo + Cube(5,2,3,false).translate(7.75,41.5,0);
    }

    servo.color(0.3,0.3,0.3);

    return servo;
}
