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

#include <core/ColorDecorator.h>
#include <core/IndentWriter.h>

void ColorDecorator::genScad(IndentWriter& writer) const
{
	writer << "color([" << _r << ", " << _g << ", " << _b << ", " << _a << "]) {" << std::endl;
	{
		IndentBlock block(writer);
		ObjectDecorator::genScad(writer);
	}
	writer << "} // End color" << std::endl;
}

void ColorDecorator::printAst(IndentWriter& writer) const
{
	writer << "Color(" << _r << ", " << _g << ", " << _b << ", " << _a << ")" << std::endl;
	ObjectDecorator::printAst(writer);
}
