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
	 * \param radius Sphere radius.
	 * \param faces Number of faces of the rendered sphere.
	 *
	 */
	static Component create(double radius, unsigned int faces=100)
	{
        return SphereObject::create(radius,faces);
	}

	/**
	 * \brief Default constructor.
	 */
	Sphere() :
        Component(),
		_radius(1.0),
		_faces(50)
    {
        Component sph = SphereObject::create(_radius,_faces);
        set(sph.get());
    }
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param radius Sphere radius.
	 * \param faces Number of faces of the rendered sphere.
	 */
	Sphere(double radius, unsigned int faces=100) :
        Component(),
		_radius(radius),
		_faces(faces)
    {
        Component sph = SphereObject::create(_radius,_faces);
        set(sph.get());
    }
	/**
	 * \brief Default destructor.
	 */
	virtual ~Sphere() {}

private:
	double _radius; /** Sphere radius. */
	unsigned int _faces; /** Number of faces of the rendered sphere. */
};


#endif // SPHERE_H_INCLUDED
