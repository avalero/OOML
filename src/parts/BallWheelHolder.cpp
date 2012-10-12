/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Trevio
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

