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

#include <core/Polygon2D.h>
#include <core/IndentWriter.h>

void Polygon2D::IndexedPath::genScad(IndentWriter& writer) const
{
  writer << "[";
	for (IndexVector::const_iterator it = _v.begin(); ; )
	{
    writer << *it;
		if (++it == _v.end())
			break;
		writer << ", ";
	}
  writer << "]";
}

void Polygon2D::IndexedPath::printAst(IndentWriter& writer) const
{
  writer << "[";
	for (IndexVector::const_iterator it = _v.begin(); ; )
	{
    writer << *it;
		if (++it == _v.end())
			break;
		writer << ", ";
	}
  writer << "]";
}

void Polygon2D::genScad(IndentWriter& writer) const
{
	writer << "polygon(points=";
	_point2DIndexMap.genScad(writer);
	writer << ", path=";
  _path.genScad(writer);
	writer << ");" << std::endl;
}

void Polygon2D::printAst(IndentWriter& writer) const
{
	writer << "POLYGON(";
	_point2DIndexMap.printAst(writer);
	writer << ", ";
  _path.printAst(writer);
	writer << ")" << std::endl;
}
