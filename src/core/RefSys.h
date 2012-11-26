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
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
    RefSys(RefSys const& other) :
        _trans(other._trans)
	{}

    RefSys(double x, double y, double z):
        _trans()
    {
        _trans.translate(x,y,z);
    }

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

    inline void setTransformationMatrix(TransformMatrix tr){
        _trans = tr;
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
    RefSys translate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system
      * The origin is kept unmoved
      * \param x Rotation around initial fixed x axis.
      * \param y Rotation around initial fixed y axis.
      * \param z Rotation around initial fixed z axis.
      */
    RefSys rotate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZXZ angles.
      * The origin is kept unmoved
      * \param z Rotation around the initial z axis.
      * \param xp Rotation around new x' axis.
      * \param zpp Rotation around z'' axis.
      */


    RefSys rotateEulerZXZ(double z, double xp, double zpp);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZYZ angles.
      * The origin is kept unmoved
      * \param z Rotation around the initial fixed z axis.
      * \param yp Rotation around new y' axis.
      * \param zpp Rotation around y'' axis.
      */
    RefSys rotateEulerZYZ(double z, double yp, double zpp);

    /**
      * \brief Translates the origin of the reference system
      * This methods translated the origin of the reference system
      * The axes are kept parallel to the non translated ref sys.
      * \param x Translation along the initial fixed x axis.
      * \param y Translation along y initial fixed y axis.
      * \param z Translation along z initial fixed z axis.
      */
    RefSys relTranslate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system
      * The origin is kept unmoved
      * \param x Rotation around the object fixed x axis.
      * \param y Rotation around the object fixed y axis.
      * \param z Rotation around the object fixed z axis.
      */
    RefSys relRotate(double x, double y, double z);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZXZ angles.
      * The origin is kept unmoved
      * \param z Rotation around the object z axis.
      * \param xp Rotation around the object new x' axis.
      * \param zpp Rotation around the object z'' axis.
      */
    RefSys relRotateEulerZXZ(double z, double xp, double zpp);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with the Euler ZYZ angles.
      * The origin is kept unmoved
      * \param z Rotation around the object z axis.
      * \param yp Rotation around the object  new y' axis.
      * \param zpp Rotation around the object  y'' axis.
      */
    RefSys relRotateEulerZYZ(double z, double yp, double zpp);

    /**
      * \brief Rotates the reference system
      * This methods rotates the reference system with a rotational matrix.
      * The origin is kept unmoved
      * \param rot Rotational Matrix
      */
    //void applyRotation(RotationalMatrix const & rot);

    RefSys transform(TransformMatrix tr);
    RefSys relTransform(TransformMatrix tr);

    inline TransformMatrix getTransformMatrix() const {return _trans;}

private:
    TransformMatrix _trans;

};

#endif // REFSYS_H_INCLUDED
