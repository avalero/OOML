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
