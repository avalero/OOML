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

#include <core/Polyhedron.h>
#include <core/IndentWriter.h>

void Polyhedron::IndexedTriangle3D::genScad(IndentWriter& writer) const
{
	writer << "[" << _p << ", " << _q << ", " << _r << "]";
}

void Polyhedron::IndexedTriangle3D::printAst(IndentWriter& writer) const
{
	writer << "[" << _p << ", " << _q << ", " << _r << "]";
}

void Polyhedron::genScad(IndentWriter& writer) const
{
	const char *comma = "";
	writer << "polyhedron(points=";
	_point3DIndexMap.genScad(writer);
	writer << ", faces=[";
	for (Triangle3DVector::const_iterator it = _triangles.begin();
	     it != _triangles.end(); ++it )
	{
		writer << comma;
		it->genScad(writer);
		comma = ", ";
	}
        writer << "]);" << std::endl;
}

void Polyhedron::printAst(IndentWriter& writer) const
{
	const char *comma = "";
	writer << "POLYHEDRON(";
	_point3DIndexMap.printAst(writer);
	writer << ", [";
	for (Triangle3DVector::const_iterator it = _triangles.begin();
	     it != _triangles.end(); ++it )
	{
		writer << comma;
		it->printAst(writer);
		comma = ", ";
	}
	writer << "])" << std::endl;
}
