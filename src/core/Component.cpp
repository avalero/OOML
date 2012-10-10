/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Alberto Valero-Gomez
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

#include "Component.h"
#include "globalfunctions.h"
#include "RefSys.h"
#include "Translation.h"
#include "RotMatrix.h"
#include "Union.h"

Component & Component::moveToLink(Component const& base, int link_id){
    //move the object to the link ref sys
    RefSys link = base.getLink(link_id);
    Translation translation;

    TransformMatrix trans = link.getTransformMatrix();

    double xa, ya, za; trans.getGlobalXYZAngles(xa,ya,za);
    double x,y,z; trans.getGlobalTranslation(x,y,z);

    //rotate and translate
    this->rotate(xa,ya,za);
    this->translate(x, y, z);

    return * this;
}

Component & Component::attach(int link_base, Component & attachment, int link_attach){
    RefSys link = this->getLink(link_base);

    TransformMatrix trans = link.getTransformMatrix();

    double xa, ya, za; trans.getGlobalXYZAngles(xa,ya,za);
    double x,y,z; trans.getGlobalTranslation(x,y,z);

    //rotate and translate
    attachment.rotate(xa,ya,za);
    attachment.translate(x, y, z);

    *this = *this + attachment;

    return *this;
}
