/**********************************************************************
 *
 * This code is part of the RepRapQuijote project
 * Authors: Alberto Valero-Gomez
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



#include "Nuts.h"
#include "../components.h"

NutShape::NutShape(Metric m, double thickness, double extra):AbstractPart()
{
    data.dim_margin=extra;

    switch (m){
    case M3:
        data.width_across_flats = 5.5;
        data.witdth_across_coners = 6.01;
        data.thickness = (thickness==0)?2.4:thickness;
        break;
    case M4:
        data.width_across_flats = 7;
        data.witdth_across_coners = 7.66;
        data.thickness = (thickness==0)?3.2:thickness;
        break;
    case M5:
        data.width_across_flats = 8;
        data.witdth_across_coners = 8.79;
        data.thickness = (thickness==0)?4.7:thickness;
        break;
    case M6:
        data.width_across_flats = 10;
        data.witdth_across_coners = 11.05;
        data.thickness = (thickness==0)?5.02:thickness;
        break;
    case M8:
        data.width_across_flats = 13;
        data.witdth_across_coners = 14.38;
        data.thickness = (thickness==0)?6.8:thickness;
        break;

    }
    //build the part
    rebuild();
}

Component NutShape::build(){
    Component hexnut = Cylinder((data.witdth_across_coners+data.dim_margin)/2 ,data.thickness,6,true);
    return hexnut;
}
