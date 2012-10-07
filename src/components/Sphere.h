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

#ifndef OOML_SPHERE_H_INCLUDED
#define OOML_SPHERE_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include "../core/Component.h"
#include "../core/IndentWriter.h"
#include "../core/SphereObject.h"

/**
 * \brief Sphere primitive object
 *
 * This class provides a sphere.
 */
class OOMLComponents_EXP_DEC Sphere : public Component
{
public:
	/**
     * \deprecated
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
        return SphereObject::create(radius,faces,center);
	}

	/**
	 * \brief Default constructor.
	 */
	Sphere() :
        Component(),
		_radius(1.0),
		_faces(50),
		_center(true)
    {
        Component sph = SphereObject::create(_radius,_faces,_center);
        set(sph.get());
    }
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param radius Cylinder radius.
	 * \param faces Number of faces of the rendered cylinder.
	 * \param center Centered cylinder flag.
	 */
	Sphere(double radius, unsigned int faces=100, bool center=true) :
        Component(),
		_radius(radius),
		_faces(faces),
		_center(center)
    {
        Component sph = SphereObject::create(_radius,_faces,_center);
        set(sph.get());
    }
	/**
	 * \brief Default destructor.
	 */
	virtual ~Sphere() {}

private:
	double _radius; /** Sphere radius. */
	unsigned int _faces; /** Number of faces of the rendered cylinder. */
	bool _center; /** Centered cylinder flag. */
};


#endif // SPHERE_H_INCLUDED
