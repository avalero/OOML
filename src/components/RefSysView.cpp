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

#include "RefSysView.h"
#include "Cylinder.h"
#include "../core/Union.h"
#include "../core/IndentWriter.h"

#include <iostream>

Component RefSysView::genComponent()
{
    Component x_axis = Cylinder(0.5,7,10,false)
            + Cylinder(1,0,3,10,false).translate(0,0,7);
    x_axis.rotate(0,90,0);

    Component y_axis = Cylinder(0.5,7,10,false)
            + Cylinder(1,0,3,10,false).translate(0,0,7);;
    y_axis.rotate(-90,0,0);

    Component z_axis = Cylinder(0.5,7,10,false)
            + Cylinder(1,0,3,10,false).translate(0,0,7);

    Component refsysview = x_axis.color(1,0,0)
            + y_axis.color(0,1,0)
            + z_axis.color(0,0,1)
            ;
    TransformMatrix trans = _refSys.getTransformMatrix();
    double ax,ay,az; trans.getGlobalXYZAngles(ax,ay,az);
    double x,y,z; trans.getGlobalTranslation(x,y,z);



    refsysview.rotate(ax,ay,az).translate(x,y,z);

    return refsysview;
}
