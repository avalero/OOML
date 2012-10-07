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

#ifndef OOML_CYLINDEROBJECT_H_INCLUDED
#define OOML_CYLINDEROBJECT_H_INCLUDED


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
 * \brief Cylinder primitive object
 *
 * This class provides a cylinder.
 */
class OOMLCore_EXP_DEC CylinderObject : public AbstractObject
{
public:
    /**
     * \brief Creates a Cylinder Component
     *
     * Creates a cylinder to use in other components.
     *
     * \param radius Cylinder radius.
     * \param height Cylinder height.
     * \param faces Number of faces of the rendered cylinder.
     * \param center Centered cylinder flag.
     * \retrun Cylinder Component
     *
     */
    static Component create(double radius, double height, unsigned int faces=100, bool center=true)
    {
        return Component(SharedPtr<AbstractObject>(new CylinderObject(radius, height, faces, center)));
    }
    /**
     * \brief Constructor.
     *
     * Creates a cylinder to use in other components.
     *
     * \param radius1 Cylinder top radius.
     * \param radius2 Cylinder bottom radius.
     * \param height Cylinder height.
     * \param faces Number of faces of the rendered cylinder.
     * \param center Centered cylinder flag.
     *
     */
    static Component create(double radius1, double radius2, double height, unsigned int faces=100, bool center=true)
    {
        return Component(SharedPtr<AbstractObject>(new CylinderObject(radius1, radius2, height, faces, center)));
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

    inline double getTopRadius() { return _radius1; }
    inline double getBottomRadius() { return _radius2; }
    inline double getHeight() { return _height; }

protected:
    /**
     * \brief Default constructor.
     */
    CylinderObject() :
        AbstractObject(),
        _radius1(1.0),
        _radius2(1.0),
        _height(1.0),
        _faces(50),
        _center(true)
    {}
    /**
     * \brief Default cylinder constructor.
     *
     * \param radius Cylinder radius.
     * \param height Cylinder height.
     * \param faces Number of faces of the rendered cylinder.
     * \param center Centered cylinder flag.
     */
    CylinderObject(double radius, double height, unsigned int faces=100, bool center=true) :
        AbstractObject(),
        _radius1(radius),
        _radius2(radius),
        _height(height),
        _faces(faces),
        _center(center)
    {}
    /**
     * \brief Default conical frustum constructor.
     *
     * \param radius1 Cylinder top radius.
     * \param radius2 Cylinder bottom radius.
     * \param height Cylinder height.
     * \param faces Number of faces of the rendered cylinder.
     * \param center Centered cylinder flag.
     */
    CylinderObject(double radius1, double radius2, double height, unsigned int faces=100, bool center=true) :
        AbstractObject(),
        _radius1(radius1),
        _radius2(radius2),
        _height(height),
        _faces(faces),
        _center(center)
    {}
    /**
     * \brief Default destructor.
     */
    virtual ~CylinderObject() {}

private:
    double _radius1; /** Cylinder top radius. */
    double _radius2; /** Cylinder bottom radius. */
    double _height; /** Cylinder height. */
    unsigned int _faces; /** Number of faces of the rendered cylinder. */
    bool _center; /** Centered cylinder flag. */
};

#endif // CYLINDER_H_INCLUDED
