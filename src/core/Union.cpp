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

#include <core/Union.h>
#include <core/IndentWriter.h>

#include <iostream>

Links Union::getLinks() const {
    //std::cout << "I am here" << std::endl;
    Links lks1;

    if (hasLinks()){ //If the Union Component has links return all its links and all the children links
        lks1 = AbstractObject::getLinks();
    }

    for (int j=0;j<_children.size();j++){
        Links lks2 = _children[j]->getLinks();
        lks1.insert( lks1.end(), lks2.begin(), lks2.end() );
    }

    return lks1;
}

RefSys Union::getLink(int i) const {
    Links lks1, lks2;

    if (hasLinks()){ //If the Union Component has links return all its links and all the children links
        lks1 = AbstractObject::getLinks();
    }

    for (int j=0;j<_children.size();j++){
        lks2 = _children[j]->getLinks();
        lks1.insert( lks1.end(), lks2.begin(), lks2.end() );
    }

    return lks1[i];
}


void Union::genScad(IndentWriter& writer) const
{
	writer << "union() {" << std::endl;
	{
		IndentBlock block(writer);
		CompositeObject::genScad(writer);
	}
	writer << "} // End union" << std::endl;
}

void Union::printAst(IndentWriter& writer) const
{
	writer << "// UNION()" << std::endl;
	{
		IndentBlock block(writer);
		CompositeObject::printAst(writer);
	}
}

Component operator+(Component const& lhs, Component const& rhs)
{
	 CompositeComponent result(Union::create());
	 result << lhs.get() << rhs.get();
	 return result;
}
