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

#include "RotMatrix.h"
#include "Math.h"

RotationalMatrix RotationalMatrix::getInv() const{
    RotationalMatrix inv;

    //Inverse of RotMatrix is its traspose
    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++){
            inv.set(i,j,get(j,i));
        }
    }

    return inv;
}

RotationalMatrix& RotationalMatrix::operator *(RotationalMatrix const & matrix){
    RotationalMatrix* result = new RotationalMatrix();

    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++){
            double value = 0;
            for (int k=1;k<=3;k++){
                value+=get(i,k)*matrix.get(k,j);
            }
            result->set(i,j,value);
        }
    }

    return *result;
}

void RotationalMatrix::rotateEulerZYZ(double z, double yp, double zpp){
    rotateZ(z);rotateY(yp);rotateZ(zpp);
}

void RotationalMatrix::rotateEulerZXZ(double z, double xp, double zpp){
    rotateZ(z);rotateX(xp);rotateZ(zpp);
}

void RotationalMatrix::rotateFixedXYZ(double x, double y, double z){
    rotateZ(z);rotateY(y);rotateX(x);
}

void RotationalMatrix::getGlobalXYZAngles(double &x, double &y, double &z){

    x = atan2( - get(3,2) , - get(3,3) );
    y = atan2( - get(3,1) , - sqrt( get(3,2)*get(3,2)  + get(3,3)*get(3,3) ) );
    z = atan2( - get(2,1) , -get(1,1) );

    x = rad2deg(x);
    y = rad2deg(y);
    z = rad2deg(z);
}



void RotationalMatrix::rotateX(double x){

    x = deg2rad(x);

    RotationalMatrix rotation;
    //rotation.set(1,1,1);
    rotation.set(2,2,cos(x));
    rotation.set(2,3,-sin(x));
    rotation.set(3,2,sin(x));
    rotation.set(3,3,cos(x));

    *this = *this * rotation;
}

void RotationalMatrix::rotateY(double y){

    y = deg2rad(y);

    RotationalMatrix rotation;
    rotation.set(1,1,cos(y));
    rotation.set(1,3,sin(y));
    rotation.set(3,1,-sin(y));
    rotation.set(3,3,cos(y));

    *this = *this * rotation;
}

void RotationalMatrix::rotateZ(double z){

    z = deg2rad(z);

    RotationalMatrix rotation;
    rotation.set(1,1,cos(z));
    rotation.set(1,2,-sin(z));
    rotation.set(2,1,sin(z));
    rotation.set(2,2,cos(z));

    *this = *this * rotation;

}
