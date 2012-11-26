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

#include "TransformMatrix.h"
#include "Math.h"

TransformMatrix TransformMatrix::getInv() const {
    TransformMatrix inv;

    //Traspose the 3x3 submatrix
    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++){
            inv.set(i,j,get(j,i));
        }
    }

    //Las row all 0 but last
    for (int i=1;i<=3;i++)
        inv.set(4,i,0);
    inv.set(4,4,1);

    double e14 = get(1,4)*get(1,1) + get(2,4)*get(2,1) + get(3,4)*get(3,1) ;
    double e24 = get(1,4)*get(1,2) + get(2,4)*get(2,2) + get(3,4)*get(3,2) ;
    double e34 = get(1,4)*get(1,3) + get(2,4)*get(2,3) + get(3,4)*get(3,3) ;

    inv.set(1,4,-e14);
    inv.set(2,4,-e24);
    inv.set(3,4,-e34);

    return inv;

}

TransformMatrix& TransformMatrix::operator *(TransformMatrix const & matrix){
    TransformMatrix* result = new TransformMatrix();

    for (int i=1;i<=4;i++){
        for (int j=1;j<=4;j++){
            double value = 0;
            for (int k=1;k<=4;k++){
                value+=get(i,k)*matrix.get(k,j);
            }
            result->set(i,j,value);
        }
    }

    return *result;
}

void TransformMatrix::transform(TransformMatrix tr){
    *this = tr * (*this);
}

void TransformMatrix::relTransform(TransformMatrix tr){
    *this = (*this) * tr;
}

void TransformMatrix::rotateEulerZYZ(double z, double yp, double zpp){
    rotateZ(z);rotateY(yp);rotateZ(zpp);
}

void TransformMatrix::relRotateEulerZYZ(double z, double yp, double zpp){
    relRotateZ(z);relRotateY(yp);relRotateZ(zpp);
}

void TransformMatrix::rotateEulerZXZ(double z, double xp, double zpp){
    rotateZ(z);rotateX(xp);rotateZ(zpp);
}

void TransformMatrix::relRotateEulerZXZ(double z, double xp, double zpp){
    relRotateZ(z);relRotateX(xp);relRotateZ(zpp);
}


void TransformMatrix::rotate(double x, double y, double z){
    rotateX(x);rotateY(y);rotateZ(z);

}

void TransformMatrix::relRotate(double x, double y, double z){
    relRotateZ(z);relRotateY(y);relRotateX(x);
}


void TransformMatrix::getGlobalXYZAngles(double &x, double &y, double &z) const {

    x = atan2( - get(3,2) , - get(3,3) );
    y = atan2( - get(3,1) , - sqrt( get(3,2)*get(3,2)  + get(3,3)*get(3,3) ) );
    z = atan2( - get(2,1) , -get(1,1) );

    x = rad2deg(x);
    y = rad2deg(y);
    z = rad2deg(z);
}

void TransformMatrix::getGlobalTranslation(double &x, double &y, double &z) const {
    x = get(1,4);
    y = get(2,4);
    z = get(3,4);
}



void TransformMatrix::rotateX(double x){

    x = deg2rad(x);

    TransformMatrix rotation;
    //rotation.set(1,1,1);
    rotation.set(2,2,cos(x));
    rotation.set(2,3,-sin(x));
    rotation.set(3,2,sin(x));
    rotation.set(3,3,cos(x));

    *this = rotation * (*this);
}

void TransformMatrix::relRotateX(double x){

    x = deg2rad(x);

    TransformMatrix rotation;
    //rotation.set(1,1,1);
    rotation.set(2,2,cos(x));
    rotation.set(2,3,-sin(x));
    rotation.set(3,2,sin(x));
    rotation.set(3,3,cos(x));

    *this = *this * rotation;
}


void TransformMatrix::rotateY(double y){

    y = deg2rad(y);

    TransformMatrix rotation;
    rotation.set(1,1,cos(y));
    rotation.set(1,3,sin(y));
    rotation.set(3,1,-sin(y));
    rotation.set(3,3,cos(y));

    *this = rotation * (*this);
}


void TransformMatrix::relRotateY(double y){

    y = deg2rad(y);

    TransformMatrix rotation;
    rotation.set(1,1,cos(y));
    rotation.set(1,3,sin(y));
    rotation.set(3,1,-sin(y));
    rotation.set(3,3,cos(y));

    *this = *this * rotation;
}

void TransformMatrix::rotateZ(double z){

    z = deg2rad(z);

    TransformMatrix rotation;
    rotation.set(1,1,cos(z));
    rotation.set(1,2,-sin(z));
    rotation.set(2,1,sin(z));
    rotation.set(2,2,cos(z));

    *this =  rotation * (*this);

}

void TransformMatrix::relRotateZ(double z){

    z = deg2rad(z);

    TransformMatrix rotation;
    rotation.set(1,1,cos(z));
    rotation.set(1,2,-sin(z));
    rotation.set(2,1,sin(z));
    rotation.set(2,2,cos(z));

    *this = *this * rotation;

}

void TransformMatrix::translate(double x, double y, double z){
    TransformMatrix translation;
    translation.set(1,4,x);
    translation.set(2,4,y);
    translation.set(3,4,z);

    *this =  translation * (*this);
}

void TransformMatrix::relTranslate(double x, double y, double z){
    TransformMatrix translation;
    translation.set(1,4,x);
    translation.set(2,4,y);
    translation.set(3,4,z);

    *this = *this * translation;
}

