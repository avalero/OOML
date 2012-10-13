/*
*    OOML : Object Oriented Mechanics Library
*    Copyright (C) 2012  Alberto Valero Gomez, Juan González Gómez, Rafael Treviño
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include <core/ObjectDecorator.h>
#include <core/IndentWriter.h>

void ObjectDecorator::genScad(IndentWriter& writer) const
{
    if (_decorated.get())
        _decorated->genScad(writer);
}

void ObjectDecorator::printAst(IndentWriter& writer) const
{
	if (_decorated.get())
		_decorated->printAst(writer);
}

RefSys ObjectDecorator::getRefSys() const{
    AbstractObject * object =  dynamic_cast<AbstractObject *>(_decorated.get());
    return object->getRefSys();
}

RefSys ObjectDecorator::getLink(int i) const{
    AbstractObject * object =  dynamic_cast<AbstractObject *>(_decorated.get());
    return object->getLink(i);
}

Links ObjectDecorator::getLinks() const{
    AbstractObject * object =  dynamic_cast<AbstractObject *>(_decorated.get());
    return object->getLinks();
}

