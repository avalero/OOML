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

#include <core/CompositeObject.h>
#include <core/IndentWriter.h>

void CompositeObject::genScad(IndentWriter& writer) const
{
	for (Vector::const_iterator it = _children.begin(); it != _children.end(); ++it)
		(*it)->genScad(writer);
}

void CompositeObject::printAst(IndentWriter& writer) const
{
	for (Vector::const_iterator it = _children.begin(); it != _children.end(); ++it)
		(*it)->printAst(writer);
}

RefSys CompositeObject::getRefSys() const {
    if (hasRefSys()){
        return AbstractObject::getRefSys();
    }else{
        return _children[0]->getRefSys();
    }
}
