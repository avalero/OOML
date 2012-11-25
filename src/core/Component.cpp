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

#include "Component.h"
#include "globalfunctions.h"
#include "RefSys.h"
#include "Translation.h"
#include "RotMatrix.h"
#include "Union.h"

Component & Component::moveToLink(const Component & base, int link_id){

    RefSys link = base.getLink(link_id);
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

Component Component::rotatedCopy(double ax, double ay, double az) const
{
    TransformMatrix tr;
    tr.rotate(ax,ay,az);
    return Component(TransformDecorator::create(get(), tr));

}

Component Component::relRotatedCopy(double ax, double ay, double az) const
{
    TransformMatrix tr;
    tr.relRotate(ax,ay,az);
    return Component(TransformDecorator::create(get(), tr, true));

}


Component & Component::rotate(double ax, double ay, double az)
{
    TransformMatrix tr;
    tr.rotate(ax,ay,az);
    set(TransformDecorator::create(get(), tr));
    return *this;
}

Component & Component::relRotate(double ax, double ay, double az)
{
    TransformMatrix tr;
    tr.relRotate(ax,ay,az);
    set(TransformDecorator::create(get(), tr,true));
    return *this;

}

Component & Component::rotate(RotationalMatrix rot)
{
    double ax, ay, az;
    rot.getGlobalXYZAngles(ax,ay,az);
    TransformMatrix tr;
    tr.rotate(ax,ay,az);
    set(TransformDecorator::create(get(), tr));
    return *this;
}

Component Component::rotatedCopy(RotationalMatrix rot) const
{
    double ax, ay, az;
    rot.getGlobalXYZAngles(ax,ay,az);
    TransformMatrix tr;
    tr.rotate(ax,ay,az);
    return Component(TransformDecorator::create(get(), tr));
}

Component & Component::rotateEulerZXZ(double az, double axp, double azpp)
{
    TransformMatrix tr;
    tr.rotateEulerZXZ(az,axp,azpp);
    set(TransformDecorator::create(get(), tr));
    return *this;
}

Component & Component::relRotateEulerZXZ(double az, double axp, double azpp)
{
    TransformMatrix tr;
    tr.relRotateEulerZXZ(az,axp,azpp);
    set(TransformDecorator::create(get(), tr, true));
    return *this;
}


Component Component::rotatedEulerZXZCopy(double az, double axp, double azpp) const
{
    TransformMatrix tr;
    tr.rotateEulerZXZ(az,axp,azpp);
    return Component(TransformDecorator::create(get(), tr));

}

Component Component::relRotatedEulerZXZCopy(double az, double axp, double azpp) const
{
    TransformMatrix tr;
    tr.relRotateEulerZXZ(az,axp,azpp);
    return Component(TransformDecorator::create(get(), tr, true));

}


Component & Component::rotateEulerZYZ(double az, double ayp, double azpp)
{

    TransformMatrix tr;
    tr.rotateEulerZYZ(az,ayp,azpp);
    set(TransformDecorator::create(get(), tr));
    return *this;
}

Component & Component::relRotateEulerZYZ(double az, double ayp, double azpp)
{

    TransformMatrix tr;
    tr.relRotateEulerZYZ(az,ayp,azpp);
    set(TransformDecorator::create(get(), tr,true));
    return *this;
}


Component Component::rotatedEulerZYZCopy(double az, double ayp, double azpp) const
{
    TransformMatrix tr;
    tr.rotateEulerZYZ(az,ayp,azpp);
    return Component(TransformDecorator::create(get(), tr));
}

Component Component::relRotatedEulerZYZCopy(double az, double ayp, double azpp) const
{
    TransformMatrix tr;
    tr.relRotateEulerZYZ(az,ayp,azpp);
    return Component(TransformDecorator::create(get(), tr, true));
}


Component Component::scaledCopy(double s) const
{
    return Component(ScaleDecorator::create(get(), s));
}

Component & Component::scale(double s)
{
    SharedPtr<AbstractObject> aux = get();
    set(ScaleDecorator::create(aux, s));

    return *this;
}

Component Component::scaledCopy(double sx, double sy, double sz) const
{
    SharedPtr<AbstractObject> aux = get();
    return Component(ScaleDecorator::create(aux, sx, sy, sz));
}

Component & Component::scale(double sx, double sy, double sz)
{
    SharedPtr<AbstractObject> aux = get();
    set(ScaleDecorator::create(aux, sx,sy,sz));
    return *this;
}

Component Component::translatedCopy(double tx, double ty, double tz) const
{
    TransformMatrix tr;
    tr.translate(tx,ty,tz);
    return Component(TransformDecorator::create(get(), tr));
}

Component Component::relTranslatedCopy(double tx, double ty, double tz) const
{
    TransformMatrix tr;
    tr.relTranslate(tx,ty,tz);
    return Component(TransformDecorator::create(get(), tr, true));
}

Component & Component::transform(TransformMatrix tr){
    set(TransformDecorator::create(get(), tr));
    return *this;
}

Component & Component::relTransform(TransformMatrix tr){
    set(TransformDecorator::create(get(), tr, true));
    return *this;
}

Component & Component::translate(double tx, double ty, double tz)
{
    TransformMatrix tr;
    tr.translate(tx,ty,tz);
    set(TransformDecorator::create(get(), tr));
    return *this;
}

Component & Component::relTranslate(double tx, double ty, double tz)
{
    TransformMatrix tr;
    tr.relTranslate(tx,ty,tz);
    set(TransformDecorator::create(get(), tr, true));
    return *this;
}

