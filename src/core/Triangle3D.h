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
