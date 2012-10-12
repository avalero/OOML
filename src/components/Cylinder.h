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
