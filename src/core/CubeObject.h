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

#ifndef OOML_CUBEOBJECT_H_INCLUDED
#define OOML_CUBEOBJECT_H_INCLUDED

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
 * \brief Cube primitive object
 *
 * This class provides a cube.
 */
class OOMLCore_EXP_DEC CubeObject : public AbstractObject
{
public:
        /**
     * \brief Creates a parametrized Cube.
     *
     * \param sx Cube dimension in the x axis.
     * \param sy Cube dimension in the y axis.
     * \param sz Cube dimension in the z axis.
     * \param center Centered cube flag.
     * \return Cube Component
     */
    static Component create(double sx, double sy, double sz, bool center=true)
    {
        return Component(SharedPtr<AbstractObject>(new CubeObject(sx, sy, sz, center)));
    }
    /**
     * \brief Creates a parametrized Cube.
     *
     * \param s Cube dimension in all the axes.
     * \param center Centered cube flag.
     * \return Cube Component
     */
    static Component create(double s, bool center=true)
    {
        return Component(SharedPtr<AbstractObject>(new CubeObject(s, s, s, center)));
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

    inline double getX(){ return _sx; }
    inline double getY(){ return _sy; }
    inline double getZ(){ return _sz; }

protected:
    /**
     * \brief Default constructor.
     */
    CubeObject() :
        AbstractObject(),
        _sx(1.0),
        _sy(1.0),
        _sz(1.0),
        _center(true)
    {}
    /**
     * \brief Default parametrized constructor.
     *
     * \param sx Cube dimension in the x axis.
     * \param sy Cube dimension in the y axis.
     * \param sz Cube dimension in the z axis.
     * \param center Centered cube flag.
     */
    CubeObject(double sx, double sy, double sz, bool center=true) :
        AbstractObject(),
        _sx(sx),
        _sy(sy),
        _sz(sz),
        _center(center)
    {}
    /**
     * \brief Default destructor.
     */
    virtual ~CubeObject() {}

private:
    double _sx; /** Cube dimension in the x axis. */
    double _sy; /** Cube dimension in the y axis. */
    double _sz; /** Cube dimension in the z axis. */
    bool _center; /** Centered cube flag. */
};

#endif // CUBEOBJECT_H_INCLUDED
