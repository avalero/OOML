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

#ifndef POLYGONALPIRAMID_H_INCLUDED
#define POLYGONALPIRAMID_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include <core/AbstractPart.h>
#include <core/Point2D.h>
#include <core/Point3D.h>
#include <core/Polygon.h>

/**
 * \brief Polygonal base piramid primitive object
 *
 * This class provides a piramid with a polygonal base.
 */
class OOMLComponents_EXP_DEC PolygonalPiramid : public AbstractPart
{
public:
	/**
	 * \brief Default constructor.
	 */
	PolygonalPiramid() :
		AbstractPart(),
		_base(),
		_apex()
	{
		rebuild();
	}
	/**
	 * \brief Create parametrized Polygonal
	 *
	 * The base must be convex and counter-clockwise ordered viewed from top.
	 *
	 * \param base Polygon used as base of the piramid.
	 * \param apex Apex point of the piramid.
	 * \return PolygonalPiramid Component
	 */
	PolygonalPiramid(Polygon<Point2D> const& base, Point3D const& apex) :
		AbstractPart(),
		_base(base),
		_apex(apex)
	{
		rebuild();
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~PolygonalPiramid() {}

protected:
	/**
	 * \brief Build the piece.
	 *
	 * This method build the piece from simpler objects.
	 *
	 * \return The piece built.
	 */
	virtual Component build();

private:
	Polygon<Point2D> _base; /** Polygonal base of the piramid */
	Point3D _apex; /** Apex point of the piramid */
};

#endif // POLYGONALPIRAMID_H_INCLUDED
