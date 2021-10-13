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

#ifndef OOML_SPHEREOBJECT_H_INCLUDED
#define OOML_SPHEREOBJECT_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <core/AbstractObject.h>
#include <core/Component.h>
#include <core/IndentWriter.h>

/**
 * \brief Sphere primitive object
 *
 * This class provides a sphere.
 */
class OOMLCore_EXP_DEC SphereObject : public AbstractObject
{
public:
    /**
     * \brief Creates a Sphere Component
     *
     * Creates a sphere to use in other components.
     *
     * \param radius Sphere radius.
     * \param faces Number of faces of the rendered sphere.
     *
     */
    static Component create(double radius, unsigned int faces=100)
    {
        return Component(SharedPtr<AbstractObject>(new SphereObject(radius, faces)));
    }

    /**
     * \brief Generate SCAD output for this object.
     *
     * This method allow the object to write the SCAD code
     * to the indent writer provided. The writer must be at the
     * beggining of a line when leaving the method.
     *
     * \param writer An instance of indent writer to write to.
     */
    virtual void genScad(IndentWriter& writer) const;
    /**
     * \brief Generate AST output for this object.
     *
     * This method allow the object to write the AST code
     * to the indent writer provided. The writer must be at the
     * beggining of a line when leaving the method.
     *
     * \param writer An instance of indent writer to write to.
     */
    virtual void printAst(IndentWriter& writer) const;

    inline double getRadius() { return _radius; }

protected:
    /**
     * \brief Default constructor.
     */
    SphereObject() :
        AbstractObject(),
        _radius(1.0),
        _faces(50)
    {}
    /**
     * \brief Default parametrized constructor.
     *
     * \param radius Sphere radius.
     * \param faces Number of faces of the rendered sphere.
     */
    SphereObject(double radius, unsigned int faces=100) :
        AbstractObject(),
        _radius(radius),
        _faces(faces)
    {}
    /**
     * \brief Default destructor.
     */
    virtual ~SphereObject() {}

private:
    double _radius; /** Sphere radius. */
    unsigned int _faces; /** Number of faces of the rendered sphere. */
};


#endif // SPHERE_H_INCLUDED
