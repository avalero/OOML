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

#include <parts/SharpIRSensor.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <components/RoundedTablet.h>
#include <core/Union.h>



Component SharpIRSensor::build()
{

	 Component base = Cube(data.base_sx, data.base_sy, data.base_sz)
				.translate(0,0,data.base_sz/2);


	 Component top_base = Cube(data.top_base_sx, data.top_base_sy, data.top_base_sz)
				.translate(0,0,data.top_base_sz/2);

	 Component light_emitter = Cube(data.light_emitter_x,data.light_emitter_y,data.light_emitter_z)
				.translate(data.light_emitter_dist_to_middle,0,data.light_emitter_z/2);


	 Component light_detector = Cube(data.light_detector_x,data.light_detector_y,data.light_detector_z)
				.translate(data.light_detector_dist_to_middle, 0 , data.light_detector_z/2);


	 Component drill_support = Cylinder(data.drills_support_radius,
																data.drills_support_thickness,
																50,false)+
				Cube(data.drills_support_radius,
								 2*data.drills_support_radius,
								 data.drills_support_thickness)
				.translate(-data.drills_support_radius/2,0,data.drills_support_thickness/2);

	 Component drills_support = drill_support.translatedCopy(data.drills_support_x_dist/2,0,0)
				+ drill_support.rotatedCopy(0,0,180).translate(-data.drills_support_x_dist/2,0,0);

	 Component drill = Cylinder(data.drills_radius,10,20,true);

	 Component drills = drill.translatedCopy(data.drills_x_dist/2,0,0) +
				drill.translatedCopy(-data.drills_x_dist/2,0,0);

	 if (_fill_drills){
		  drills_support = drills_support + drills;
	 }else{
		  drills_support = drills_support - drills;
	 }

	 Component ir = base
				+ top_base
				+ light_emitter
				+ light_detector
				+ drills_support;

	 return ir;
}
