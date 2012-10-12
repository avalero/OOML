/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Treviño
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

#ifndef TRIANGLE3D_H_INCLUDED
#define TRIANGLE3D_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <core/Point3D.h>
#include <core/Polygon.h>

/**
 * \brief 3D triangle primitive object
 *
 * This class provides a 3D triangle.
 */
class OOMLCore_EXP_DEC Triangle3D : public Polygon<Point3D>
{
public:
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param p First point of the triangle.
	 * \param q Second point of the triangle.
	 * \param r Third point of the triangle.
	 */
	Triangle3D(Point3D const& p, Point3D const& q, Point3D const& r) :
		Polygon<Point3D>()
	{
		addPoint(p);
		addPoint(q);
		addPoint(r);
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Triangle3D() {}
};

#endif // TRIANGLE3D_H_INCLUDED
