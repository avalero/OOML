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

#ifndef OOML_TRANSFORMMATRIX_H_INCLUDED
#define OOML_TRANSFORMMATRIX_H_INCLUDED

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
 * \brief Homogeneous Transformation Matrix
 *
 * This class provides a homogeneous transformation matrix
 */
class OOMLCore_EXP_DEC TransformMatrix: public Matrix<double,4,4>
{
public:
    /**
     * \brief Default constructor.
     */
    TransformMatrix() :
        Matrix<double,4,4>()
    {
        for (int i=1;i<=4;i++){
            set(i,i,1);
        }
    }

    void printMatrix() const{
        for (int i=1 ; i<=4 ; i++){
            std::cout << "| ";
            for (int j=1; j<=4; j++){

                std::cout << get(i,j) << " ";
            }
            std::cout << "|" << std::endl;
        }
    }

    /**
     * @brief operator *
     * Multiplies two matrices
     * @param matrix the matrix to multiply with this
     * @return the resulting multiplication
     */
    TransformMatrix & operator*(TransformMatrix const& matrix);

    /**
      * \brief Applies an Euler rotation around the initial fixed z, x', z''
      * Applies three rotations around z, x' and z''
      * \param z Rotation (in degrees) around z axis.
      * \param xp Rotation (in degrees) around x' axis.
      * \param zpp Rotation (in degrees) around z'' aixs.
      */
    void rotateEulerZXZ(double z,double xp, double zpp);

    /**
      * \brief Applies an Euler rotation around the initial fixed z, y', z''
      * Applies three rotations around z, x' and z''
      * \param z (in degrees) Rotation around z axis.
      * \param yp (in degrees) Rotation around y' axis.
      * \param zpp (in degrees) Rotation around z'' aixs.
      */
    void rotateEulerZYZ(double z,double yp, double zpp);

    /**
      * \brief Applies a Roll-Pitch-Yaw rotation around the initial fixed  x, y, z
      * Applies three rotations around the fixed reference system x,y,z
      * \param x Rotation (in degrees) around x axis.
      * \param y Rotation (in degrees) around y axis.
      * \param z Rotation (in degrees) around z aixs.
      */
    void rotate(double x, double y, double z);

    /**
      * \brief Applies an Euler rotation around the local reference system z, x', z''
      * Applies three rotations around z, x' and z''
      * \param z Rotation (in degrees) around z axis.
      * \param xp Rotation (in degrees) around x' axis.
      * \param zpp Rotation (in degrees) around z'' aixs.
      */
    void relRotateEulerZXZ(double z,double xp, double zpp);

    /**
      * \brief Applies an Euler rotation around the local reference system  z, y', z''
      * Applies three rotations around z, x' and z''
      * \param z (in degrees) Rotation around z axis.
      * \param yp (in degrees) Rotation around y' axis.
      * \param zpp (in degrees) Rotation around z'' aixs.
      */
    void relRotateEulerZYZ(double z,double yp, double zpp);

    /**
      * \brief Applies a Roll-Pitch-Yaw rotation around the local reference system  x, y, z
      * Applies three rotations around the fixed reference system x,y,z
      * \param x Rotation (in degrees) around x axis.
      * \param y Rotation (in degrees) around y axis.
      * \param z Rotation (in degrees) around z aixs.
      */
    void relRotate(double x, double y, double z);


    /**
      * \brief Applies a rotation around initial fixed x axis
      * Applies a rotation around current x axis
      * \param x Rotation (in degrees) around x axis.
      */
    void rotateX(double x);

    /**
      * \brief Applies a rotation around initial fixed y axis
      * Applies a rotation around current y axis
      * \param y Rotation (in degrees) around y axis.
      */
    void rotateY(double y);

    /**
      * \brief Applies a rotation around initial fixed current z axis
      * Applies a rotation around current z axis
      * \param z Rotation (in degrees) around z axis.
      */
    void rotateZ(double z);

    /**
      * \brief Applies a rotation around current local x axis
      * Applies a rotation around current x axis
      * \param x Rotation (in degrees) around x axis.
      */
    void relRotateX(double x);

    /**
      * \brief Applies a rotation around current local y axis
      * Applies a rotation around current y axis
      * \param y Rotation (in degrees) around y axis.
      */
    void relRotateY(double y);

    /**
      * \brief Applies a rotation around current local z axis
      * Applies a rotation around current z axis
      * \param z Rotation (in degrees) around z axis.
      */
    void relRotateZ(double z);


    /**
      * \brief Gets the rotation angles about the fixed axes x,y,z.
      * Obtains the rotation angles about the fixed x,y,z
      * (Roll,Pich,Yaw).
      * \param x rotation (in degrees) around initial fixed x
      * \param y rotation (in degrees) around initial fixed y
      * \param z rotation (in degrees) around initial fixed z
      */
    void getGlobalXYZAngles(double &x, double &y, double &z) const;

    /**
      * \brief Gets the translation wrt. the fixed axes x,y,z.
      * Obtains the rotation angles about the fixed x,y,z
      * (Roll,Pich,Yaw).
      * \param x translation wrt. the initial fixed x
      * \param y translation wrt. the initial fixed y
      * \param z translation wrt. the initial fixed z
      */
    void getGlobalTranslation(double &x, double &y, double &z) const;

    /**
     * @brief performs a translation
     * @param x Translation with respect to the x axis
     * @param y Translation with respect to the y axis
     * @param z Translation with respect to the z axis
     */
    void translate(double x, double y, double z);

    /**
     * @brief performs a translation
     * @param x Translation with respect to the x axis
     * @param y Translation with respect to the y axis
     * @param z Translation with respect to the z axis
     */
    void relTranslate(double x, double y, double z);

    /**
     * @brief checke if matrix equals identity
     * @return ture when matrix is identitiy
     */
    bool inline isIdentity(){
        bool id = true;
        for (int i=1;i<=4;i++){
            for(int j=1; j<=4;j++){
                if (i==j)
                    id = id && (get(i,j)==1);
                else
                    id = id && (get(i,j)==0);

                if(!id){
                    return false;
                }
            }
        }

        return id;
    }



};

#endif
