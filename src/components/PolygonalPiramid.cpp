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
