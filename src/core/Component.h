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

#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include "ColorDecorator.h"
#include "DXFLinearExtrude.h"
#include "DXFRotateExtrude.h"
#include "Imported.h"
#include "MirrorDecorator.h"
#include "ObjectDecorator.h"
#include "TransformDecorator.h"
#include "ScaleDecorator.h"
#include "RotMatrix.h"
#include "RefSys.h"

#include <map>
#include <string.h>

#define COMPONENT_MARGIN 0.05

/**
 * \brief Component class.
 *
 * This class provides a component object.
 */
class OOMLCore_EXP_DEC Component : public ObjectDecorator
{
public:
    /**
   * \brief Default constructor.
   */
    Component() :
        ObjectDecorator()
    {  resetRefSys(); }
    /**
   * \brief Default referenced constructor.
   *
   * \param decorated Object to decorate.
   */
    Component(SharedPtr<AbstractObject> const& decorated) :
        ObjectDecorator(decorated)
    {  resetRefSys();  }
    /**
   * \brief Default copy constructor.
   *
   * \param other Other object to copy from.
   */
    Component(Component const& other) :
        ObjectDecorator(other.get())
    {
        _links = other._links;
    }
    /**
   * \brief Default assignment operator.
   *
   * \param other Other object to assign from.
   */
    Component & operator=(Component const& other)
    {
        set(other.get());
        _links = other._links;
        return *this;
    }
    /**
   * \brief Default destructor.
   */
    virtual ~Component() {}

    /**
   * \brief Loads an SCAD object from file.
   *
   * \param filename Filename to load.
   *
   * \return a component loaded with the SCAD code from the filename.
   */
    static Component loadFromFilename(std::string const& filename)
    {
        return Component(Imported::create(filename));
    }

    /**
   * \brief Linear extrude an DXF filename.
   *
   * \param filename Filename to load.
   * \param height Height of the extrusion (in the z axis).
   * \param twist Degrees of twist for every step.
   * \param faces Number of faces to render.
   * \param convexity Maximum number of ray intersecting faces.
   * \param center Centered or not.
   *
   * \return a component of the linear extrude of an DXF filename.
   */
    static Component linearExtrudeFromDXF(std::string const& filename, double height, unsigned int twist=0, unsigned int faces=100, unsigned int convexity=10, bool center=true)
    {
        return Component(DXFLinearExtrude::create(filename, height, twist, faces, convexity, center));
    }
    /**
   * \brief Rotate extrude an DXF filename.
   *
   * \param filename Filename to load.
   * \param convexity Maximum number of ray intersecting faces.
   * \param faces Number of faces to render.
   *
   * \return a component of the rotate extrude of an DXF filename.
   */
    static Component rotateExtrudeFromDXF(std::string const& filename, unsigned int convexity=10, unsigned int faces=100)
    {
        return Component(DXFRotateExtrude::create(filename, convexity, faces));
    }

    /**
   * \brief Color the component.
   *
   * This method create a copied component, but colored.
   *
   * \param r Red component of the color.
   * \param g Green component of the color.
   * \param b Blue component of the color.
   * \param a Alpha component of the color.
   *
   * \return a color decoration of the object.
   */
    Component coloredCopy(double r, double g, double b, double a=1.0) const
    {
        SharedPtr<AbstractObject> aux = get();
        return Component(ColorDecorator::create(aux, r, g, b, a));
    }
    /**
   * \brief Color the component.
   *
   * This method colors the component "in place".
   *
   * \param r Red component of the color.
   * \param g Green component of the color.
   * \param b Blue component of the color.
   * \param a Alpha component of the color.
   *
   * \return the component color decorated.
   */
    Component & color(double r, double g, double b, double a=1.0)
    {
        SharedPtr<AbstractObject> aux = get();
        set(ColorDecorator::create(aux, r, g, b, a));
        return *this;
    }

    /**
   * \brief Mirror the component.
   *
   * This method create a copied component, but mirrored.
   *
   * \param vx Mirror normal vector plane (x component).
   * \param vy Mirror normal vector plane (y component).
   * \param vz Mirror normal vector plane (z component).
   *
   * \return a mirror decoration of the object.
   */
    Component mirroredCopy(double vx, double vy, double vz) const
    {
        return Component(MirrorDecorator::create(get(), vx, vy, vz));
    }
    /**
   * \brief Mirror the component.
   *
   * This method mirrors the component "in place".
   *
   * \param vx Mirror normal vector plane (x component).
   * \param vy Mirror normal vector plane (y component).
   * \param vz Mirror normal vector plane (z component).
   *
   * \return the component mirror decorated.
   */
    Component & mirror(double vx, double vy, double vz)
    {
        set(MirrorDecorator::create(get(), vx, vy, vz));
        return *this;
    }

    /**
    * \brief Move To Link Function
    * This method rotates and translates the component in order to place it at a link position.
    * \param base The Component from which we take the links.
    * \param link_id. The id number of the link
    */
    Component & moveToLink(Component const& base, int link_id);

    /**
      * \brief Attaches two components
      * This method attaches attachment component to the componet, making the links fit together
      * \param link_base. The id number of the link to attach.
      * \param attachment. The component to attach. It will be rotated and translated.
      * \param link_attach. The link of the attachment we want to place at the link of the base. By default the center of the attachment
      * \return An Union of base and attachment
      */
    Component & attach(int link_base, Component & attachment, int link_attach=0);

    /**
   * \brief Rotate the component.
   *
   * This method create a copied component, but rotated.
   *
   * \param ax Rotation angle x axis.
   * \param ay Rotation angle y axis.
   * \param az Rotation angle z axis.
   *
   * \return a rotate decoration of the object.
   */
    Component rotatedCopy(double ax, double ay, double az) const;

    /**
    * \brief Rotate the component around its local reference system.
    *
    * This method create a copied component, but rotated around its reference system.
    *
    * \param ax Rotation angle around local x axis.
    * \param ay Rotation angle around local y axis.
    * \param az Rotation angle around local z axis.
    *
    * \return a rotate decoration of the object.
    */
    Component relRotatedCopy(double ax, double ay, double az) const;
    /**
   * \brief Rotate the component.
   *
   * This method rotates the component "in place".
   *
   * \param ax Rotation angle x axis.
   * \param ay Rotation angle y axis.
   * \param az Rotation angle z axis.
   *
   * \return the component rotate decorated.
   */
    Component & rotate(double ax, double ay, double az);

    /**
    * \brief Rotate the component around its local reference system.
    *
    * This method rotates the component around its reference system.
    *
    * \param ax Rotation angle around local x axis.
    * \param ay Rotation angle around local y axis.
    * \param az Rotation angle around local z axis.
    *
    * \return a rotate decoration of the object.
    */
    Component & relRotate(double ax, double ay, double az);

    /**
   * \brief Rotate the component.
   *
   * This method rotates the component "in place".
   *
   * \param rot Rotation Matrix
   * \return the component rotate decorated.
   */
    Component & rotate(RotationalMatrix rot);

    Component rotatedCopy(RotationalMatrix rot) const ;

    /**
   * \brief Rotate the component with Euler Angles ZX'Z''.
   *
   * This method rotates the component "in place".
   *
   * \param az Rotation angle z axis.
   * \param axp Rotation angle x' axis.
   * \param azpp Rotation angle z'' axis.
   *
   * \return the component rotate decorated.
   */
    Component & rotateEulerZXZ(double az, double axp, double azpp);

    /**
   * \brief Rotate the component with Euler Angles ZX'Z'' around its local reference system
   *
   * This method rotates the component around its local reference system following the Euler Angles
   *
   * \param az Rotation angle z axis.
   * \param axp Rotation angle x' axis.
   * \param azpp Rotation angle z'' axis.
   *
   * \return the component rotate decorated.
   */
    Component & relRotateEulerZXZ(double az, double axp, double azpp);


    /**
   * \brief Rotate a copy of the component with Euler Angles ZX'Z''
   *
   * This method rotates the component "in place".
   *
   * \param az Rotation angle z axis.
   * \param axp Rotation angle x' axis.
   * \param azpp Rotation angle z'' axis.
   *
   * \return a copy of the component rotate decorated.
   */
    Component rotatedEulerZXZCopy(double az, double axp, double azpp) const;

    /**
   * \brief Rotate a copy of the component with Euler Angles ZX'Z'' around its local reference system
   *
   * Rotate a copy of the component with Euler Angles ZX'Z'' around its local reference system
   *
   * \param az Rotation angle z axis.
   * \param axp Rotation angle x' axis.
   * \param azpp Rotation angle z'' axis.
   *
   * \return a copy of the component rotate decorated.
   */
    Component relRotatedEulerZXZCopy(double az, double axp, double azpp) const;


    /**
   * \brief Rotate the component with Euler Angles ZY'Z''.
   *
   * This method rotates the component "in place".
   *
   * \param az Rotation angle z axis.
   * \param ayp Rotation angle y' axis.
   * \param azpp Rotation angle z'' axis.
   *
   * \return the component rotate decorated.
   */
    Component & rotateEulerZYZ(double az, double ayp, double azpp);

    /**
   * \brief Rotate the component with Euler Angles ZY'Z'' around its local reference system.
   *
   * Rotate the component with Euler Angles ZY'Z'' around its local reference system.
   *
   * \param az Rotation angle z axis.
   * \param ayp Rotation angle y' axis.
   * \param azpp Rotation angle z'' axis.
   *
   * \return the component rotate decorated.
   */
    Component & relRotateEulerZYZ(double az, double ayp, double azpp);


    /**
   * \brief Rotate a copy of the component with Euler Angles ZX'Z''
   *
   * This method rotates the component "in place".
   *
   * \param az Rotation angle z axis.
   * \param ayp Rotation angle x' axis.
   * \param azpp Rotation angle z'' axis.
   *
   * \return a copy of the component rotate decorated.
   */
    Component rotatedEulerZYZCopy(double az, double ayp, double azpp) const;

    /**
   * \brief Rotate a copy of the component with Euler Angles ZX'Z'' around its local reference system
   *
   * Rotate a copy of the component with Euler Angles ZX'Z'' around its local reference system
   *
   * \param az Rotation angle z axis.
   * \param ayp Rotation angle x' axis.
   * \param azpp Rotation angle z'' axis.
   *
   * \return a copy of the component rotate decorated.
   */
    Component relRotatedEulerZYZCopy(double az, double ayp, double azpp) const;


    /**
   * \brief Scale the component.
   *
   * This method create a copied component, but scaled.
   *
   * \param s Scale factor on the three axis.
   *
   * \return a scale decoration of the object.
   */
    Component scaledCopy(double s) const;

    /**
   * \brief Scale the component.
   *
   * This method scales the component "in place".
   *
   * \param s Scale factor on the three axis.
   *
   * \return the component scale decorated.
   */

    Component & scale(double s);

    /**
   * \brief Scale the component.
   *
   * This method create a copied component, but scaled.
   *
   * \param sx Scale factor on the x axis.
   * \param sy Scale factor on the y axis.
   * \param sz Scale factor on the z axis.
   *
   * \return a scale decoration of the object.
   */
    Component scaledCopy(double sx, double sy, double sz) const;
    /**
   * \brief Scale the component.
   *
   * This method scales the component "in place".
   *
   * \param sx Scale factor on the x axis.
   * \param sy Scale factor on the y axis.
   * \param sz Scale factor on the z axis.
   *
   * \return the component scale decorated.
   */
    Component & scale(double sx, double sy, double sz);

    /**
   * \brief Translate the component.
   *
   * This method create a copied component, but translated.
   *
   * \param tx Translate on the x axis.
   * \param ty Translate on the y axis.
   * \param tz Translate on the z axis.
   *
   * \return a transform decoration of the object.
   */
    Component translatedCopy(double tx, double ty, double tz) const;

    /**
   * \brief Translate the component wrt. to its local reference system
   *
   * This method create a copied component, but translated.
   *
   * \param tx Translate on the x axis.
   * \param ty Translate on the y axis.
   * \param tz Translate on the z axis.
   *
   * \return a transfrom decoration of the object.
   */
    Component relTranslatedCopy(double tx, double ty, double tz) const;

    /**
   * \brief Translate the component.
   *
   * This method translates the component "in place".
   *
   * \param tx Translate on the x axis.
   * \param ty Translate on the y axis.
   * \param tz Translate on the z axis.
   *
   * \return the component translate decorated.
   */
    Component & translate(double tx, double ty, double tz);

    Component & transform(TransformMatrix tr);
    Component & relTransform(TransformMatrix tr);

    /**
   * \brief Translate the component wrt. to its local reference system
   *
   * Translate the component wrt. to its local reference system
   *
   * \param tx Translate on the x axis.
   * \param ty Translate on the y axis.
   * \param tz Translate on the z axis.
   *
   * \return the component translate decorated.
   */
    Component & relTranslate(double tx, double ty, double tz);

    inline virtual RefSys getRefSys() const{

        if (hasRefSys()){
            return AbstractObject::getRefSys();
        }
        else{
            return this->get()->getRefSys();
        }
    }

    inline virtual Links getLinks() const{
        return get()->getLinks();
    }

    inline virtual RefSys getLink(int i) const{
        return this->get()->getLink(i);
    }

    /**
      * \brief Adds a Link to the system.
      * \link Reference System of the Link.
      * \return Link Number.
      */
    inline int addLink(RefSys rs){
        get()->links()->push_back(rs);
        return (get()->links()->size()-1);
    }

    inline void setLinks(Links l){
        get()->links()->clear();
        *(get()->links()) = l;
    }

    inline void clearLinks(){
        get()->links()->clear();
        get()->links()->resize(0);
    }

    /**
      * \brief Adds a vector of Links to the system.
      * \links Vector of Reference Systems of the Links.
      */
    inline void addLinks(Links l){
        for (int i=0; i<l.size();i++)
            get()->links()->push_back(l[i]);
    }

    /**
      * \brief Returns if the Object has links.
      * \return true when there are links
      */
    //inline bool hasLinks() const {
    //    return (get()->links()->size()>0);
    //}


    /**
     * \brief Try to cast the decorated pointer to a concrete type.
     *
     * This method will try to cast the decorated object to
     * a reference to the given type, raising an exception if fails.
     *
     * \return The converted reference of the given type.
     */
    template <typename T>
    inline T const& getRef() const
    {
        T const& ref = dynamic_cast<T const&>(*get());
        return ref;
    }

    /**
     * \brief Try to cast the decorated pointer to a concrete type.
     *
     * This method will try to cast the decorated object to
     * a reference to the given type, raising an exception if fails.
     *
     * \return The converted reference of the given type.
     */
    template <typename T>
    inline T & getRef()
    {
        T & ref = dynamic_cast<T &>(*get());
        return ref;
    }

};



#endif // COMPONENT_H_INCLUDED
