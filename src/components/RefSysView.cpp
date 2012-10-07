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

    Component z_axis = Cylinder(0.5,10,10,false)
            + Cylinder(1,0,3,10,false).translate(0,0,10);

    Component refsysview = x_axis.color(1,0,0)
            + y_axis.color(0,1,0)
            + z_axis.color(0,0,1)
            ;
    RotationalMatrix rot = _refSys.getRotMatrix();
    double ax,ay,az;

    rot.getXYZAngles(ax,ay,az);

    refsysview.rotate(ax,ay,az)
            .translate(_refSys.getOrigin().x,_refSys.getOrigin().y,_refSys.getOrigin().z);

    return refsysview;
}
