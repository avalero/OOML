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
        refsys.transfrom(_tr);
        return refsys;
    }

}

Links TransformDecorator::getLinks() const{
    double x,y,z; _tr.getGlobalTranslation(x,y,z);
    double xa, ya, za; _tr.getGlobalXYZAngles(xa,ya,za);
    Links tr_links(_links.size());

    for (int i=0 ; i<_links.size(); i++){
        RefSys link =_links[i];
        link.rotate(xa,ya,za);
        link.translate(x,y,z);
        tr_links[i]=link;
    }

    return tr_links;
}

RefSys TransformDecorator::getLink(int i) const{
    double x,y,z; _tr.getGlobalTranslation(x,y,z);
    double xa, ya, za; _tr.getGlobalXYZAngles(xa,ya,za);

    RefSys link =_links[i];
    link.rotate(xa,ya,za);
    link.translate(x,y,z);

    return link;
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
