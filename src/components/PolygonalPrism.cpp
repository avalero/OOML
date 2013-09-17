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

    Component cad = polygon.linearExtrudedCopy(_height);

    if(_centered) cad.translate(0,0,-_height/2);

    return cad;

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
