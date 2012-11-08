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

#include "String.h"
#include "config.h"
#include <fstream>
#include "../core/CompositeComponent.h"
#include "../core/Union.h"


String::String(string cad, double font_size, double spacing, double height) :
    Component()
{

    data._string=cad;
    data._height=height;
    data._spacing = spacing;
    data._font_size=font_size;

    CompositeComponent comp = Union::create();

    for (int i=0; i<data._string.size();i++){
        Char ch(data._string.at(i),data._font_size,data._height);
        ch.translate(i*data._spacing,0,0);
        comp << ch;
    }

    data._created=true;

    set(comp.get());
}
