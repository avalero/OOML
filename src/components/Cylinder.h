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

#ifndef OOML_CYLINDER_H_INCLUDED
#define OOML_CYLINDER_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include "../core/CylinderObject.h"
#include "../core/Component.h"
#include "../core/IndentWriter.h"

/**
 * \brief Cylinder primitive object
 *
 * This class provides a cylinder.
 */
class OOMLComponents_EXP_DEC Cylinder : public Component
{
public:

    /**
     * \brief Default cylinder constructor.
     *
     * \param radius Cylinder radius.
     * \param height Cylinder height.
     * \param faces Number of faces of the rendered cylinder.
     * \param center Centered cylinder flag.
     */
    Cylinder(double radius, double height, unsigned int faces=100, bool center=true) :
        Component(),
        _radius1(radius),
        _radius2(radius),
        _height(height),
        _faces(faces),
        _center(center)
    {
        Component cyl = CylinderObject::create(_radius1,_radius2,_height,_faces,_center);
        set(cyl.get());
    }
    /**
     * \brief Default conical frustum constructor.
     *
     * \param radius1 Cylinder top radius.
     * \param radius2 Cylinder bottom radius.
     * \param height Cylinder height.
     * \param faces Number of faces of the rendered cylinder.
     * \param center Centered cylinder flag.
     */
    Cylinder(double radius1, double radius2, double height, unsigned int faces=100, bool center=true) :
        Component(),
        _radius1(radius1),
        _radius2(radius2),
        _height(height),
        _faces(faces),
        _center(center)
    {
        Component cyl = CylinderObject::create(_radius1,_radius2,_height,_faces,_center);
        set(cyl.get());
    }
    /**
     * \brief Default destructor.
     */
    virtual ~Cylinder() {}

protected:
    /**
     * \brief Default constructor.
     */
    Cylinder() :
        Component(),
        _radius1(1.0),
        _radius2(1.0),
        _height(1.0),
        _faces(50),
        _center(true)
    { }

public:

    /**
     * \deprecated
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
        return CylinderObject::create(radius, height, faces, center);
	}
	/**
     * \deprecated
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
        return CylinderObject::create(radius1, radius2, height, faces, center);
	}

	inline double getTopRadius() { return _radius1; }
	inline double getBottomRadius() { return _radius2; }
	inline double getHeight() { return _height; }



private:
	double _radius1; /** Cylinder top radius. */
	double _radius2; /** Cylinder bottom radius. */
	double _height; /** Cylinder height. */
	unsigned int _faces; /** Number of faces of the rendered cylinder. */
	bool _center; /** Centered cylinder flag. */
};

#endif // CYLINDER_H_INCLUDED
