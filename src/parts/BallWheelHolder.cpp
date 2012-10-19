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

#include <parts/BallWheelHolder.h>
#include <components/Cylinder.h>
#include <components/Sphere.h>
#include <components/Cube.h>
#include <core/Difference.h>
#include <core/Intersection.h>

Component BallWheelHolder::build()
{
	 // Main Shape
	 Component main_shape=Cylinder(data.baseHeight/2,data.baseThickness+data.effectiveRadius*1.4,75,false);

	 //Cut Out
	 Component sphere = Sphere(data.effectiveRadius,80);
	 sphere.translate(0,0,data.effectiveRadius+data.holeSize);

	 Component cube=Cube(data.baseHeight+4,data.gapWidth, 2*data.effectiveRadius,false);
	 cube.translate(-data.baseHeight/2-2, -data.gapWidth/2, data.baseThickness);


	 Component cylinder = Cylinder(data.effectiveRadius*0.6,data.baseHeight+4 , 6 , false);
	 cylinder.rotate(0,90,0).translate(-data.baseHeight/2-2,0,data.baseThickness+data.effectiveRadius*1.2);

	 Component cylinder2 = Cylinder(data.effectiveRadius*0.85,data.effectiveRadius/2,75,false);

	 cylinder2.translate(0,0,data.baseThickness);

	 Component cutout = sphere + cube + cylinder + cylinder2;


	 // Support
	 double support_height = data.totalHeight - (data.baseThickness+data.effectiveRadius*1.4);
	 if (support_height < 0){
		  Component spherewheelsupport = main_shape - cutout;
		  return spherewheelsupport;
	 }

//else
	 Component support = Cylinder(data.baseHeight/2,support_height+1,75,false);
	 Component spherewheelsupport = support
				+ (main_shape - cutout).translate(0,0,support_height)
				- Cylinder(data.effectiveRadius*0.80,data.totalHeight,75,false).translate(0,0,6);

	 return spherewheelsupport;
}


Component BallWheelHolder::getBall(){
	 Component ball = Sphere(data.radius ,100);

	 double support_height = data.totalHeight - (data.baseThickness+data.effectiveRadius*1.4);
	 if(support_height<0)
		  ball.translate(0,0,data.effectiveRadius+data.holeSize);
	 else
		  ball.translate(0,0,data.effectiveRadius+data.holeSize).translate(0,0,support_height);

	 return ball;
}

