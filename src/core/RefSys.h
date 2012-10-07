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
#include "RotMatrix.h"
#include "Translation.h"

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
    RefSys() : _origin(0,0,0)
	{}
	/**
	 * \brief Default parametrized constructor.
	 *
     * \param x origin of the reference system
     * \param y origin of the reference system
     * \param z origin of the reference system
     * \param a_x first rotation around fixed x axis.
     * \param a_y second rotation around fixed y axis.
     * \param a_z third rotation around fized z axis.
	 */
    RefSys(double x, double y, double z, double a_x=0, double a_y=0, double a_z=0) :
        _origin(x,y,z)
    {
      _rot.rotateFixedXYZ(a_x,a_y,a_z);
    }
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
    RefSys(RefSys const& other) :
        _origin(other._origin),
        _rot(other._rot)
	{}
	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other object to assign from.
	 */
    RefSys & operator=(RefSys const& other)
	{
        _origin = other._origin;
        _rot = other._rot;

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
      * \param x Translation along x axis.
      * \param y Translation along y axis.
      * \param z Translation along z axis.
      */
    void translate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system
      * The origin is kept unmoved
      * \param x Rotation around fixed x axis.
      * \param y Rotation around fixed y axis.
      * \param z Rotation around fixed z axis.
      */
    void rotate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZXZ angles.
      * The origin is kept unmoved
      * \param z Rotation around z axis.
      * \param xp Rotation around new x' axis.
      * \param zpp Rotation around z'' axis.
      */
    void rotateEulerZXZ(double z, double xp, double zpp);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZYZ angles.
      * The origin is kept unmoved
      * \param z Rotation around z axis.
      * \param yp Rotation around new y' axis.
      * \param zpp Rotation around y'' axis.
      */
    void rotateEulerZYZ(double z, double yp, double zpp);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with a rotational matrix.
      * The origin is kept unmoved
      * \param rot Rotational Matrix
      */
    void applyRotation(RotationalMatrix const & rot);

    inline RotationalMatrix getRotMatrix() const {return _rot;}

    inline Translation getOrigin() const {return _origin;}

private:
    Translation _origin; /** Origin of the reference system */
    RotationalMatrix _rot; /** Rotational Matrix defining the orientation **/

};

#endif // REFSYS_H_INCLUDED
