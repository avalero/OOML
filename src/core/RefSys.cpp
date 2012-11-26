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

RefSys RefSys::transform(TransformMatrix tr){
    _trans.transform(tr);
    return *this;
}

RefSys RefSys::relTransform(TransformMatrix tr){
    _trans.relTransform(tr);
    return *this;
}

