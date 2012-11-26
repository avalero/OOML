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

#ifndef OOML_ROTMATRIX_H_INCLUDED
#define OOML_ROTMATRIX_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <math.h>
#include "Matrix.h"
#include <utility>

/**
 * \brief Rotational Matrix
 *
 * This class provides a rotational matrix
 */
class OOMLCore_EXP_DEC RotationalMatrix: public Matrix<double,3,3>
{
public:
    /**
     * \brief Default constructor.
     */
    RotationalMatrix() :
        Matrix<double,3,3>()
    {
        for (int i=1;i<=3;i++){
            set(i,i,1);
        }
    }

    void printMatrix() const{
        for (int i=1 ; i<=3 ; i++){
            std::cout << "| ";
            for (int j=1; j<=3; j++){

                std::cout << get(i,j) << " ";
            }
            std::cout << "|" << std::endl;
        }
    }

    RotationalMatrix & operator*(RotationalMatrix const& matrix);

    /**
      * \brief Applies an Euler rotation around z, x', z''
      * Applies three rotations around z, x' and z''
      * \param z Rotation (in degrees) around z axis.
      * \param xp Rotation (in degrees) around x' axis.
      * \param zpp Rotation (in degrees) around z'' aixs.
      */
    void rotateEulerZXZ(double z,double xp, double zpp);

    /**
      * \brief Applies an Euler rotation around z, y', z''
      * Applies three rotations around z, x' and z''
      * \param z (in degrees) Rotation around z axis.
      * \param yp (in degrees) Rotation around y' axis.
      * \param zpp (in degrees) Rotation around z'' aixs.
      */
    void rotateEulerZYZ(double z,double yp, double zpp);

    /**
      * \brief Applies a Roll-Pitch-Yaw rotation around x, y, z
      * Applies three rotations around the fixed reference system x,y,z
      * \param x Rotation (in degrees) around x axis.
      * \param y Rotation (in degrees) around y axis.
      * \param z Rotation (in degrees) around z aixs.
      */
    void rotateFixedXYZ(double x, double y, double z);

    /**
      * \brief Applies a rotation around current x axis
      * Applies a rotation around current x axis
      * \param x Rotation (in degrees) around x axis.
      */
    void rotateX(double x);

    /**
      * \brief Applies a rotation around current y axis
      * Applies a rotation around current y axis
      * \param y Rotation (in degrees) around y axis.
      */
    void rotateY(double y);

    /**
      * \brief Applies a rotation around current z axis
      * Applies a rotation around current z axis
      * \param z Rotation (in degrees) around z axis.
      */
    void rotateZ(double z);

    /**
      * \brief Gets the rotation angles about the fixed axes x,y,z.
      * Obtains the rotation angles about the fixed x,y,z
      * (Roll,Pich,Yaw).
      * \param x rotation (in degrees) around initial fixed x axis
      * \param y rotation (in degrees) around initial fixed y axis
      * \param z rotation (in degrees) around initial fixed z axis
      */
    void getGlobalXYZAngles(double &x, double &y, double &z);

    RotationalMatrix getInv() const;

};

#endif // REFSYS_H_INCLUDED
