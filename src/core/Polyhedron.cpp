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
	writer << "polyhedron(points=";
	_point3DIndexMap.genScad(writer);
	writer << ", triangles=[";
	for (Triangle3DVector::const_iterator it = _triangles.begin(); ; )
	{
		it->genScad(writer);
		if (++it == _triangles.end())
			break;
		writer << ", ";
	}
        writer << "]);" << std::endl;
}

void Polyhedron::printAst(IndentWriter& writer) const
{
	writer << "POLYHEDRON(";
	_point3DIndexMap.printAst(writer);
	writer << ", [";
	for (Triangle3DVector::const_iterator it = _triangles.begin(); ; )
	{
		it->printAst(writer);
		if (++it == _triangles.end())
			break;
		writer << ", ";
	}
	writer << "])" << std::endl;
}
