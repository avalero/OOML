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
		_height(0)
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
	PolygonalPrism(Polygon<Point2D> const& base, double height) :
		AbstractPart(),
		_base(base),
		_height(height)
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
};

#endif // POLYGONALPRISM_H_INCLUDED
