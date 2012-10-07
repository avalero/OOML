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

#include <components/PolygonalPrism.h>
#include <core/Point2D.h>
#include <core/Polygon.h>
#include <core/Polygon2D.h>
#include <core/Polyhedron.h>

Component PolygonalPrism::build()
{
    /* Create the base */

    Component2D polygon(Polygon2D::create());

   {
      Polygon2D & polygon2D = polygon.getRef<Polygon2D>();
      for (Polygon<Point2D>::PointVector::const_iterator it = _base.getPoints().begin();
          it != _base.getPoints().end(); it++)
      {
          polygon2D.addPoint(Point2D(it->getX(), it->getY()));
      }
   }

    return (polygon.linearExtrudedCopy(_height));

    /*


	Component component(Polyhedron::create());
	Polyhedron & polyhedron = dynamic_cast<Polyhedron &>(*component.get().get());

	// Add all the points
	for (Polygon<Point2D>::PointVector::const_iterator it = _base.getPoints().begin();
		it != _base.getPoints().end(); ++it)
	{
		polyhedron << Point3D(it->getX(), it->getY(), 0.0);
		polyhedron << Point3D(it->getX(), it->getY(), _height);
	}

	unsigned int baseLength = _base.getPoints().size();
	unsigned int modulus = baseLength * 2;

	// Top and bottom faces
	for (unsigned int i = 1; i < baseLength - 1; ++i)
	{
		unsigned int tbase = i * 2 + 1;
		unsigned int bbase = modulus - i * 2;

		polyhedron.addTriangle(1, tbase, tbase + 2);
		polyhedron.addTriangle(bbase, bbase - 2, 0);
	}

	// Lateral faces
	for (unsigned int i = 0; i < baseLength; ++i)
	{
		unsigned int base = i * 2;

		polyhedron.addTriangle(base, (base + 3) % modulus, base + 1);
		polyhedron.addTriangle(base, (base + 2) % modulus, (base + 3) % modulus);
    }
    return component;
*/
}
