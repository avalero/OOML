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

#include <components/PolygonalPiramid.h>
#include <core/Point2D.h>
#include <core/Polygon.h>
#include <core/Polyhedron.h>

Component PolygonalPiramid::build()
{
	Component component(Polyhedron::create());
	Polyhedron & polyhedron = dynamic_cast<Polyhedron &>(*component.get().get());

	// Add all the points
	polyhedron << _apex;
	for (Polygon<Point2D>::PointVector::const_iterator it = _base.getPoints().begin();
			it != _base.getPoints().end(); ++it)
		polyhedron << Point3D(it->getX(), it->getY(), 0.0);

	unsigned int baseLength = _base.getPoints().size();

	// Bottom face
	for (unsigned int i = 0; i < baseLength - 2; ++i)
	{
		unsigned int base = baseLength - i;
		polyhedron.addTriangle(base, base - 1, 1);
	}

	// Lateral faces
	for (unsigned int i = 1; i < baseLength + 1; ++i)
		polyhedron.addTriangle(0, i, i % baseLength + 1);
	
	return component;
}
