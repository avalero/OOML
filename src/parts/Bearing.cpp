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

#include <parts/Bearing.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <components/Sphere.h>
#include <core/Difference.h>
#include <core/Union.h>

Component Bearing::build()
{

//Creates two types of bearings depending on whether the radius is larger than the width or vice versa.

    //External cylinder.
        Component ext_cylinder = Cylinder(_radius,_width,40,true);
    //Internal cylinder.
        Component int_cylinder = Cylinder(0.615*_radius,_width,40,true);

    //Hole that divides the bearing from external cylinder and internal cylinder.
        Component hole_ext_int = Cylinder((float)0.635*_radius,_width+2,40,true);
    //Gap where balls are to roll. It's formed by the difference between two cylinder (these depend on the relationship between radius and width).
        Component gap;

        //Cylinders 1 and 2, belong to first kind of bearing.
            Component cyl1 = Cylinder(0.75*_radius, 0.25*_radius,40,true);
            Component cyl2 = Cylinder(0.5*_radius, 0.25*_radius,40,true);
        //Cylinders 3 and 4, belong to second kind of bearing.
            Component cyl3 = Cylinder(0.625*_radius+0.16*_width, 0.32*_width,40,true);
            Component cyl4 = Cylinder(0.625*_radius-0.08*_width, 0.32*_width,40,true);

    //Ball.
        Component sphere;

        //Two ball types depending on the bearing type.
            Component sphere1 = Sphere(0.15*_width,24,true);
            Component sphere2 = Sphere(0.125*_radius,24,true);

    //Parameter to determine the number of spheres.
        double distance;

    //Choice of type of bearing.
        if(_radius < _width){
            gap = cyl1 - cyl2;
            sphere = sphere2;
            distance = 0.25*_radius;}
        else{
            gap = cyl3 - cyl4;
            sphere = sphere1;
            distance = 0.32*_width;}


    //Number of spheres that bearing has.
        int number_spheres = 3.1416 * 2 * 0.625 *_radius / (distance * 1.6);

    //Angle between each ball.
        float angle = 360 / (number_spheres + 3);

    //Balls. Set of balls for the bearing.
        Component spheres = sphere.translate(0.615*_radius,0,0);

        for(int j=1; j<360; j=j+angle)
            spheres = spheres + sphere.rotatedCopy(0,0,j);

    //Choice of holes number.
        Component hole = Cylinder(1.8,_radius*1.25,40,true);
        Component holes;

        if(_holes==1)
            holes = hole;
        if(_holes==2)
            holes = hole.translatedCopy(0.3*_radius,0,0) + hole.translatedCopy(-0.3*_radius,0,0);
        if(_holes==3)
            holes = hole.translatedCopy(0.3*_radius,0,0) + hole.translatedCopy(0.3*_radius,0,0).rotatedCopy(0,0,120) + hole.translatedCopy(0.3*_radius,0,0).rotatedCopy(0,0,240);
        if(_holes==4)
            holes = hole.translatedCopy(0.3*_radius,0,0) + hole.translatedCopy(0.3*_radius,0,0).rotatedCopy(0,0,90) + hole.translatedCopy(0.3*_radius,0,0).rotatedCopy(0,0,180) + hole.translatedCopy(0.3*_radius,0,0).rotatedCopy(0,0,270);
        else
            holes = hole.translatedCopy(_radius*10,0,0);

    //Final part.
        Component part = ext_cylinder - hole_ext_int + int_cylinder - holes - gap + spheres;

    return part;
}
