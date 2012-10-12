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

#include "TransformDecorator.h"
#include "IndentWriter.h"

RefSys TransformDecorator::getRefSys() const{
    RefSys refsys;
    refsys.setTransformationMatrix(_tr);
    return refsys;

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
