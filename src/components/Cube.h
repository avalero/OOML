/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Treviño, Nieves Cubo, Mario Almagro
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
