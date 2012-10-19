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

#include "CylinderObject.h"
#include "IndentWriter.h"

#include <iostream>

void CylinderObject::genScad(IndentWriter& writer) const
{
    writer << "cylinder(h=" << _height <<", r1=" << _radius1 <<", r2=" << _radius2 << ", $fn=" << _faces
        << ", center=" << _center << ");" << std::endl;
}

void CylinderObject::printAst(IndentWriter& writer) const
{
    writer << "// CYLINDER(" << _height << ", " << _radius1 << ", " << _radius2 << ", " << _faces << ", " << _center << ")" << std::endl;
}
