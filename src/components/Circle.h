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

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include <core/AbstractObject.h>
#include <core/Component2D.h>
#include <core/IndentWriter.h>

/**
 * \brief Circle primitive object
 *
 * This class provides a circle.
 */
class OOMLComponents_EXP_DEC Circle : public AbstractObject
{
public:
	/**
	 * \brief Creates a Circle Object
	 *
	 * \param radius Circle radius.
	 * \param faces Number of faces to render.
	 * \return Circle Componet
	 */
	static Component2D create(double radius, unsigned int faces=100)
	{
		return SharedPtr<AbstractObject>(new Circle(radius, faces));
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
	 Circle() :
		AbstractObject(),
		_radius(1.0),
    _faces(100)
	{}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param radius Circle radius.
   * \param faces Number of faces to render.
	 */
	Circle(double radius, unsigned int faces) :
		 AbstractObject(),
		 _radius(radius),
		 _faces(faces)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Circle() {}

private:
	double _radius; /** Circle radius. */
	unsigned int _faces; /** Circle faces number. */
};


#endif // CIRCLE_H_INCLUDED
