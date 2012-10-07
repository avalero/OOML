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
      * \param x rotation (in degrees) around x
      * \param y rotation (in degrees) around y
      * \param z rotation (in degrees) around z
      */
    void getXYZAngles(double &x, double &y, double &z);

};

#endif // REFSYS_H_INCLUDED
