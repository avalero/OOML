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

#ifndef POLYGONALPRISM_H_INCLUDED
#define POLYGONALPRISM_H_INCLUDED

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
#include <core/Polygon.h>
#include <core/Component2D.h>

/**
 * \brief Polygonal base prism primitive object
 *
 * This class provides a prism with a polygonal base.
 */
class OOMLComponents_EXP_DEC PolygonalPrism : public AbstractPart
{
public:
	/**
	 * \brief Default constructor.
	 */
	PolygonalPrism() :
		AbstractPart(),
		_base(),
                _height(0),
                _centered(true)
	{
		rebuild();
	}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * The base must be convex and counter-clockwise ordered viewed from top.
	 *
	 * \param base Polygon used as base of the prism.
	 * \param height Prism height.
	 */
    PolygonalPrism(Polygon<Point2D> const& base, double height,bool centered=true) :
		AbstractPart(),
		_base(base),
        _height(height),
      _centered(centered)
	{
		rebuild();
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~PolygonalPrism() {}

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
    Polygon<Point2D> _base; /** Polygonal base of the prism */
	double _height; /** Prism height */
    bool _centered;
};

#endif // POLYGONALPRISM_H_INCLUDED
