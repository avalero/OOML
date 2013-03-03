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



#include "Bearings.h"
#include "../components.h"

LMXuu::LMXuu(LinearBearings type):AbstractPart()
{
    switch(type){
    case LM8uu:
        data.inner_diameter=8; //mm
        data.ext_diameter=15; //mm
        data.length = 24; //mm
        break;
    case LM10uu:
        data.inner_diameter=10; //mm
        data.ext_diameter=19; //mm
        data.length = 29; //mm
        break;
    }
    //build the part
    rebuild();
}

Component LMXuu::build(){
    Component bearing = Cylinder::create(data.ext_diameter/2,data.length,100,true)
            - Cylinder::create(data.inner_diameter/2,data.length+1,20,true)
            ;
    return bearing;
}

B608zz::B608zz():AbstractPart()
{
    data.inner_diameter=8; //mm
    data.ext_diameter=22; //mm
    data.length = 7; //mm

    //build the part
    rebuild();
}

Component B608zz::build(){
    Component bearing = Cylinder::create(data.ext_diameter/2,data.length,20,true)
            - Cylinder::create(data.inner_diameter/2,data.length+1,20,true)
            ;
    return bearing;
}

B624zz::B624zz():AbstractPart()
{
    data.inner_diameter=4; //mm
    data.ext_diameter=13; //mm
    data.length = 5; //mm

    //build the part
    rebuild();
}

Component B624zz::build(){
    Component bearing = Cylinder::create(data.ext_diameter/2,data.length,20,true)
            - Cylinder::create(data.inner_diameter/2,data.length+1,20,true)
            ;
    return bearing;
}
