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

#ifndef REFSYS_H_INCLUDED
#define REFSYS_H_INCLUDED

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
#include "TransformMatrix.h"
#include "RotMatrix.h"

#include <utility>

/**
 * \brief 3D point primitive object
 *
 * This class provides a reference system x,y,z.
 */
class OOMLCore_EXP_DEC RefSys
{
public:
	/**
	 * \brief Default constructor.
	 */
    RefSys()
	{}
	/**
	 * \brief Default parametrized constructor.
	 *
     * \param x origin of the reference system
     * \param y origin of the reference system
     * \param z origin of the reference system
     * \param a_x first rotation around translated fixed x axis.
     * \param a_y second rotation around translated fixed y axis.
     * \param a_z third rotation around translated fized z axis.
	 */
    RefSys(double x, double y, double z, double a_x=0, double a_y=0, double a_z=0)
    {
        _trans.translate(x,y,z);
        _trans.relRotate(a_x,a_y,a_z);
    }
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
    RefSys(RefSys const& other) :
        _trans(other._trans)
	{}
	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other object to assign from.
	 */
    RefSys & operator=(RefSys const& other)
	{
        _trans = other._trans;

		return *this;
	}


	/**
	 * \brief Default destructor.
	 */
    virtual ~RefSys() {}

    /**
      * \brief Translates the origin of the reference system
      * This methods translated the origin of the reference system
      * The axes are kept parallel to the non translated ref sys.
      * \param x Translation along the initial fixed x axis.
      * \param y Translation along y initial fixed y axis.
      * \param z Translation along z initial fixed z axis.
      */
    void translate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system
      * The origin is kept unmoved
      * \param x Rotation around initial fixed x axis.
      * \param y Rotation around initial fixed y axis.
      * \param z Rotation around initial fixed z axis.
      */
    void rotate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZXZ angles.
      * The origin is kept unmoved
      * \param z Rotation around the initial z axis.
      * \param xp Rotation around new x' axis.
      * \param zpp Rotation around z'' axis.
      */


    void rotateEulerZXZ(double z, double xp, double zpp);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZYZ angles.
      * The origin is kept unmoved
      * \param z Rotation around the initial fixed z axis.
      * \param yp Rotation around new y' axis.
      * \param zpp Rotation around y'' axis.
      */
    void rotateEulerZYZ(double z, double yp, double zpp);

    /**
      * \brief Translates the origin of the reference system
      * This methods translated the origin of the reference system
      * The axes are kept parallel to the non translated ref sys.
      * \param x Translation along the initial fixed x axis.
      * \param y Translation along y initial fixed y axis.
      * \param z Translation along z initial fixed z axis.
      */
    void relTranslate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system
      * The origin is kept unmoved
      * \param x Rotation around the object fixed x axis.
      * \param y Rotation around the object fixed y axis.
      * \param z Rotation around the object fixed z axis.
      */
    void relRotate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZXZ angles.
      * The origin is kept unmoved
      * \param z Rotation around the object z axis.
      * \param xp Rotation around the object new x' axis.
      * \param zpp Rotation around the object z'' axis.
      */
    void relRotateEulerZXZ(double z, double xp, double zpp);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZYZ angles.
      * The origin is kept unmoved
      * \param z Rotation around the object z axis.
      * \param yp Rotation around the object  new y' axis.
      * \param zpp Rotation around the object  y'' axis.
      */
    void relRotateEulerZYZ(double z, double yp, double zpp);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with a rotational matrix.
      * The origin is kept unmoved
      * \param rot Rotational Matrix
      */
    //void applyRotation(RotationalMatrix const & rot);

    inline TransformMatrix getTransformMatrix() const {return _trans;}

private:
    TransformMatrix _trans;

};

#endif // REFSYS_H_INCLUDED
