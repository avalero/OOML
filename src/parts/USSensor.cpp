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

#include <parts/USSensor.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <components/RoundedTablet.h>
#include <core/Union.h>



Component USSensor::build()
{
	 Component us = Cube(data.sx,data.sy,data.board_thickness,true).translate(0,0,data.board_thickness/2) //board
                + Cylinder(data.sensor_radius + 1.5*PART_MARGIN,data.sz,100,false).translate(data.sensor_dist_to_center,0,0) //us1
                + Cylinder(data.sensor_radius + 1.5*PART_MARGIN,data.sz,100,false).translate(-data.sensor_dist_to_center,0,0); //us2


     Component drills = Cylinder(data.drills_radius+PART_MARGIN,12,20,false)
				.translate(data.drills_x_dist/2,data.drills_y_dist/2,-5)
                + Cylinder(data.drills_radius+PART_MARGIN,12,20,false)
									 .translate(-data.drills_x_dist/2,data.drills_y_dist/2,-5)
                + Cylinder(data.drills_radius+PART_MARGIN,12,20,false)
									 .translate(data.drills_x_dist/2,-data.drills_y_dist/2,-5)
                + Cylinder(data.drills_radius+PART_MARGIN,12,20,false)
									 .translate(-data.drills_x_dist/2,-data.drills_y_dist/2,-5);

	 if (_fill_drills){
		  us = us + drills;
	 }else{
		  us = us - drills;
	 }
	 return us;
}
