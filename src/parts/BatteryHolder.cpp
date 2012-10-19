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

#include <parts/BatteryHolder.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <core/Union.h>

Component BatteryHolder::build()
{
  double length, diameter, width;
  switch(_type)
  {
    case A23: length = 28.5; diameter = 10.3; break;
    case AAAA: length = 42.5; diameter = 8.3; break;
    case AAA: length = 44.5; diameter = 10.5; break;
    case AA: length = 50.5; diameter = 14.5; break;
    case C: length = 50; diameter = 26.2; break;
    case D: length = 61.5; diameter = 34.2; break;
  }
  ++length; // one millimeter of tolerance

  width = _number * diameter + (_number - 1) * 1.5;

  Component a(Cube(width + _thickness, _thickness + length, 3 + diameter).translate(0, 0, -1.5)
		- Cube(width, length, diameter).translate(0, 0, diameter / 2));

  Component b1(Cylinder(1.5, 3 * _thickness)
                + Cylinder(2.5, 2.5, 2, 6, true).translate(0,0,-0.75));
  Component b2(b1.rotatedCopy(90,0,0).translate((width/2) - (diameter/2), -1 - (length/2), 0));
  b1.rotate(-90,0,0).translate((width/2) - (diameter/2), (length/2) + 1, 0);

  Component battery(Cylinder(diameter / 2, length)
		.rotate(90,0,0).translate((width / 2) - (diameter/2), 0, 0));

  for(int i = 0; i < _number; ++i)
  {
    a = a
			- battery.translatedCopy(-i * (diameter + 1.5), 0, 0)
                        - b1.translatedCopy(-i * (diameter + 1.5), 0, 0)
			- b2.translatedCopy(-i * (diameter + 1.5), 0, 0);
  }

  return a.translate(0, 0, 3 + diameter / 2);
}
