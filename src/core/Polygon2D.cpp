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
