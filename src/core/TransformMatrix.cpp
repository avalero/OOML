/**********************************************************************
 *
 * This code is part of the OOML project
 * Author: Alberto Valero-Gomez
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

#include "TransformMatrix.h"
#include "Math.h"

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

void TransformMatrix::rotateEulerZYZ(double z, double yp, double zpp){
    rotateZ(z);rotateY(yp);rotateZ(zpp);
}

void TransformMatrix::rotateEulerZXZ(double z, double xp, double zpp){
    rotateZ(z);rotateX(xp);rotateZ(zpp);
}

void TransformMatrix::rotateFixedXYZ(double x, double y, double z){
    rotateZ(z);rotateY(y);rotateX(x);
}

void TransformMatrix::getGlobalXYZAngles(double &x, double &y, double &z){

    x = atan2( - get(3,2) , - get(3,3) );
    y = atan2( - get(3,1) , - sqrt( get(3,2)*get(3,2)  + get(3,3)*get(3,3) ) );
    z = atan2( - get(2,1) , -get(1,1) );

    x = rad2deg(x);
    y = rad2deg(y);
    z = rad2deg(z);
}

void TransformMatrix::getGlobalTranslation(double &x, double &y, double &z){
    x = get(4,1);
    y = get(4,2);
    z = get(4,3);
}



void TransformMatrix::rotateX(double x){

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

    *this = *this * rotation;
}

void TransformMatrix::rotateZ(double z){

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
    translation.set(4,1,x);
    translation.set(4,2,y);
    translation.set(4,3,z);

    *this = *this * translation;
}
