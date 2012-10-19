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

#ifndef COMPONENT2D_H_INCLUDED
#define COMPONENT2D_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <core/Component.h>
#include <core/LinearExtrudeDecorator.h>
#include <core/RotateExtrudeDecorator.h>

/**
 * \brief 2D component class.
 *
 * This class provides a 2D component object.
 */
class OOMLCore_EXP_DEC Component2D : public Component
{
public:
	/**
	 * \brief Default constructor.
	 */
	Component2D() :
		Component()
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 */
	Component2D(SharedPtr<AbstractObject> const& decorated) :
		Component(decorated)
	{}
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
	Component2D(Component const& other) :
    Component(other)
  {}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Component2D() {}

	/**
	 * \brief Linear extrude the component.
	 *
	 * This method create a copied component, but linear extruded.
	 *
   * \param height Height of the extrusion (in the z axis).
   * \param twist Degrees of twist for every step.
   * \param faces Number of faces to render.
   * \param convexity Maximum number of ray intersecting faces.
   * \param center Centered or not.
	 *
	 * \return a linear extrusion decoration of the object.
	 */
    Component linearExtrudedCopy(double height, unsigned int twist=0, unsigned int faces=100, unsigned int convexity=10, bool center=false)
	{
		return Component(LinearExtrudeDecorator::create(get(), height, twist, faces, convexity, center));
	}

	/**
	 * \brief Rotate extrude the component.
	 *
	 * This method create a copied component, but rotate extruded.
	 *
   * \param convexity Maximum number of ray intersecting faces.
   * \param faces Number of faces to render.
	 *
	 * \return a rotate extrusion decoration of the object.
	 */
	Component rotateExtrudedCopy(unsigned int convexity=10, unsigned int faces=100)
	{
		return Component(RotateExtrudeDecorator::create(get(), convexity, faces));
	}
};

#endif // COMPONENT2D_H_INCLUDED
