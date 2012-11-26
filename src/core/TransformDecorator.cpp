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

#include "TransformDecorator.h"
#include "IndentWriter.h"

RefSys TransformDecorator::getRefSys() const{

    if (hasRefSys()){
        return AbstractObject::getRefSys();
    }
    else{
        RefSys refsys = ObjectDecorator::getRefSys();
        refsys.transform(_tr);
        return refsys;
    }

}

Links TransformDecorator::getLinks() const{
    Links lks1;
    Links lks2;

    lks1 = ObjectDecorator::getLinks();
    for (int i=0; i<lks1.size();i++)
        lks1[i].transform(_tr);

    if (hasLinks())
        lks2 = AbstractObject::getLinks();

    lks1.insert( lks1.end(), lks2.begin(), lks2.end() );
    return lks1;
}

RefSys TransformDecorator::getLink(int i) const{
    Links lks1;
    Links lks2;

    lks1 = ObjectDecorator::getLinks();
    for (int j=0; j<lks1.size();j++)
        lks1[j].transform(_tr);

    if (hasLinks())
        lks2 = AbstractObject::getLinks();

    lks1.insert( lks1.end(), lks2.begin(), lks2.end() );
    return lks1[i];
}

void TransformDecorator::genScad(IndentWriter& writer) const
{
    double ax, ay, az; _tr.getGlobalXYZAngles(ax,ay,az);
    double x,y,z;  _tr.getGlobalTranslation(x,y,z);
    writer << "translate(v=[" << x << ", " << y << ", " << z << "]) {" << std::endl;
        writer << "rotate([" << ax << "," << ay << "," << az << "]){" <<std::endl;
            {
                IndentBlock block(writer);
                ObjectDecorator::genScad(writer);
            }
        writer << "} // End rotate" << std::endl;
    writer << "} // End translate" << std::endl;
}

void TransformDecorator::printAst(IndentWriter& writer) const
{
    double ax, ay, az; _tr.getGlobalXYZAngles(ax,ay,az);
    double x,y,z; _tr.getGlobalTranslation(x,y,z);

    writer << "ROTATE(" << ax << "," << ay << "," << az << "){" <<std::endl;
    writer << "TRANSLATE(" << x << ", " << y << ", " << z << ")" << std::endl;
	ObjectDecorator::printAst(writer);
}
