/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Trevio
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
     * \param radius Cylinder radius.
     * \param faces Number of faces of the rendered cylinder.
     * \param center Centered cylinder flag.
     *
     */
    static Component create(double radius, unsigned int faces=100, bool center=true)
    {
        return Component(SharedPtr<AbstractObject>(new SphereObject(radius, faces, center)));
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
        _faces(50),
        _center(true)
    {}
    /**
     * \brief Default parametrized constructor.
     *
     * \param radius Cylinder radius.
     * \param faces Number of faces of the rendered cylinder.
     * \param center Centered cylinder flag.
     */
    SphereObject(double radius, unsigned int faces=100, bool center=true) :
        AbstractObject(),
        _radius(radius),
        _faces(faces),
        _center(center)
    {}
    /**
     * \brief Default destructor.
     */
    virtual ~SphereObject() {}

private:
    double _radius; /** Sphere radius. */
    unsigned int _faces; /** Number of faces of the rendered cylinder. */
    bool _center; /** Centered cylinder flag. */
};


#endif // SPHERE_H_INCLUDED
