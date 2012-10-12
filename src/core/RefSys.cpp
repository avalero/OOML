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

#include "RefSys.h"
#include "Union.h"
#include "IndentWriter.h"

#include <iostream>

RefSys RefSys::translate(double x, double y, double z){
    _trans.translate(x,y,z);
    return *this;
}

RefSys RefSys::relRotate(double x, double y, double z){
    _trans.relRotate(x,y,z);
    return *this;
}

RefSys RefSys::relTranslate(double x, double y, double z){
    _trans.relTranslate(x,y,z);
    return *this;
}

RefSys RefSys::rotate(double x, double y, double z){
    _trans.rotate(x,y,z);
    return *this;
}

RefSys RefSys::rotateEulerZYZ(double z, double yp, double zpp){
    _trans.rotateEulerZYZ(z,yp,zpp);
    return *this;
}

RefSys RefSys::rotateEulerZXZ(double z, double xp, double zpp){
    _trans.rotateEulerZXZ(z,xp,zpp);
    return *this;
}


RefSys RefSys::relRotateEulerZYZ(double z, double yp, double zpp){
    _trans.relRotateEulerZYZ(z,yp,zpp);
    return *this;
}

RefSys RefSys::relRotateEulerZXZ(double z, double xp, double zpp){
    _trans.relRotateEulerZXZ(z,xp,zpp);
    return *this;
}
