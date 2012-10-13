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

#include <parts/NineVoltBattery.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <components/RoundedTablet.h>
#include <core/Union.h>

Component NineVoltBattery::build()
{
	 double sx = 26.32; // 26.32;
	 double sy = 17.26; // 17.26;
	 double sz = 45.30; // 45.30;

	 double connector_r = 5;
	 double connector_lenght = 3.20;
	 double connect_width = 22;

	 Component battery = RoundedTablet(sx , sy , sz , 2);
	 Component connector = RoundedTablet(connect_width , 2*connector_r , connector_lenght , 2*connector_r);
	 connector.translate( 0 , 0 , sz/2 + connector_lenght/2);
	 battery = battery + connector;
	 battery.color(0.7,0.7,0.7);

	 return battery;
}
