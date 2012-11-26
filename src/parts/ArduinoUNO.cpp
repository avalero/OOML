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

#include <parts/ArduinoUNO.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <components/PolygonalPrism.h>
#include <core/Polygon2D.h>
#include <core/Difference.h>
#include <core/Union.h>

Component ArduinoUNO::getBoard(double height, double holes_height, bool fill_holes, bool fourth_hole){

	 Component board;

	 Polygon<Point2D> base1, base2;

         base1.addPoint(Point2D(0, 0));
         base1.addPoint(Point2D(0, 37.846));
         base1.addPoint(Point2D(68.58, 37.846));
         base1.addPoint(Point2D(68.58, 5.08));
         base1.addPoint(Point2D(66.04, 2.54));
         base1.addPoint(Point2D(66.04, 0));

         base2.addPoint(Point2D(0, 37.346));
         base2.addPoint(Point2D(0, 53.34));
         base2.addPoint(Point2D(64.516, 53.34));
         base2.addPoint(Point2D(66.04, 51.816));
         base2.addPoint(Point2D(66.04, 40.386));
         base2.addPoint(Point2D(68.58, 37.846));

	 Component prism1 = PolygonalPrism(base1, height);
	 Component prism2 = PolygonalPrism(base2, height);
	 Component hole_arduino = Cylinder(1.58,1.58,holes_height,20,true);
	 Component holes = hole_arduino.translatedCopy(13.97,2.54,0)
				+  hole_arduino.translatedCopy(66.04,7.62,0)
				+  hole_arduino.translatedCopy(66.04,35.56,0);
	 if(fourth_hole){
		  holes = holes +  hole_arduino.translatedCopy(15.24,50.8,0);
	 }



	 if(fill_holes)
		 board = prism1 + prism2 + holes;
	 else
		 board = prism1 + prism2 - holes;

	 return board.color(0,0,1);
}

Component ArduinoUNO::build()
{
	 Component board = getBoard(2,_drills_height,_fill_drills,_fourth_drill);

			Component micro = Cube(35.5,10,7,false).translate(28.5,11.5,2);
			Component pins = Cube(42.5,2.5,8,false).translate(22.5,49.5,2)
										  + Cube(33.5,2.5,8,false).translate(31.7,1.5,2)
										  + Cube(5,7.5,8,false).translate(62.5,24.5,2);
			Component usb = Cube(15.875,11.43,11,false).translate(-6.35,32.385,2);
			Component power = Cylinder(4,14,int(50),false).rotate(0,-90,0).translate(-1.905 + 14,3.175 + 4 + 0.5,8.5)
										  + Cube(14,9,6.5,false).translate(-1.905,3.175,2)
										  + Cube(3.5,9,10.5,false).translate(-1.905,3.175,2);
			Component capacitors = Cube(6.5,6.5,5,false).translate(17.5,1.6,2)
										  + Cube(6.5,6.5,5,false).translate(25,1.6,2);
			Component button = Cube(6,6,3,false).translate(52.5,24.5,2);

            Component arduino = board + pins.color(0.2,0.2,0.2) + micro.color(0.2,0.2,0.2) + usb.color(0.7,0.7,0.7) + power.color(0.7,0.7,0.7) + capacitors.color(0.5,0.5,0.5) + button.color(0.5,0.5,0.5);

	 return arduino;
}
