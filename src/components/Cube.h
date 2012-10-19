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

#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include "../core/CubeObject.h"
#include "../core/Component.h"
#include "../core/IndentWriter.h"

/**
 * \brief Cube primitive object
 *
 * This class provides a cube.
 */
class OOMLComponents_EXP_DEC Cube : public Component
{
public:
    /**
     * \brief Default constructor.
     */
    Cube() :
        Component(),
        _sx(1.0),
        _sy(1.0),
        _sz(1.0),
        _center(true)
    {
        Component cube = CubeObject::create(_sx,_sy,_sz,_center);
        set(cube.get());
    }
    /**
     * \brief Default parametrized constructor.
     *
     * \param sx Cube dimension in the x axis.
     * \param sy Cube dimension in the y axis.
     * \param sz Cube dimension in the z axis.
     * \param center Centered cube flag.
     */
    Cube(double sx, double sy, double sz, bool center=true) :
        Component(),
        _sx(sx),
        _sy(sy),
        _sz(sz),
        _center(center)
    {
        Component cube = CubeObject::create(_sx,_sy,_sz,_center);
        set(cube.get());
    }

    /**
     * \brief Creates a parametrized Cube.
     *
     * \param s Cube dimension in all the axes.
     * \param center Centered cube flag.
     * \return Cube Component
     */
    Cube(double s, bool center=true) :
        Component(),
        _sx(s),
        _sy(s),
        _sz(s),
        _center(center)
    {
        Component cube = CubeObject::create(_sx,_sy,_sz,_center);
        set(cube.get());
    }

    /**
     * \brief Default destructor.
     */
    virtual ~Cube() {}


    /**
     * \deprecated
	 * \brief Creates a parametrized Cube.
	 *
	 * \param sx Cube dimension in the x axis.
	 * \param sy Cube dimension in the y axis.
	 * \param sz Cube dimension in the z axis.
	 * \param center Centered cube flag.
	 * \return Cube Component
	 */
	static Component create(double sx, double sy, double sz, bool center=true)
	{
        return Cube(sx, sy, sz, center);
	}
	/**
     * \deprecated
     * \deprecated
	 * \brief Creates a parametrized Cube.
	 *
	 * \param s Cube dimension in all the axes.
	 * \param center Centered cube flag.
	 * \return Cube Component
	 */
	static Component create(double s, bool center=true)
	{
        return Cube(s, s, s, center);
	}

	inline double getX(){ return _sx; }
	inline double getY(){ return _sy; }
	inline double getZ(){ return _sz; }

private:
	double _sx; /** Cube dimension in the x axis. */
	double _sy; /** Cube dimension in the y axis. */
	double _sz; /** Cube dimension in the z axis. */
	bool _center; /** Centered cube flag. */
};

#endif // CUBE_H_INCLUDED
