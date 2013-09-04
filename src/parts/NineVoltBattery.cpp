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

#include <parts/NineVoltBattery.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <components/RoundedTablet.h>
#include <core/Union.h>

Component NineVoltBattery::build()
{
     _data.sx = 26.32; // 26.32;
     _data.sy = 17.26; // 17.26;
     _data.sz = 45.30; // 45.30;

     _data.connector_r = 5;
     _data.connector_lenght = 3.20;
     _data.connect_width = 22;

     Component battery = RoundedTablet(_data.sx , _data.sy , _data.sz , 2);
     Component connector = RoundedTablet(_data.connect_width , 2*_data.connector_r , _data.connector_lenght , 2*_data.connector_r);
     connector.translate( 0 , 0 , _data.sz/2 + _data.connector_lenght/2);
	 battery = battery + connector;

	 return battery;
}
