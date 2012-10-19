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

#ifndef LINEAREXTRUDEDECORATOR_H_INCLUDED
#define LINEAREXTRUDEDECORATOR_H_INCLUDED

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
#include <core/IndentWriter.h>
#include <core/ObjectDecorator.h>
#include <core/SharedPtr.h>

/**
 * \brief Translate decorator.
 *
 * This class provides a linear extrude decoration for an object.
 */
class OOMLCore_EXP_DEC LinearExtrudeDecorator : public ObjectDecorator
{
public:
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
   * \param height Height of the extrusion (in the z axis).
   * \param twist Degrees of twist for every step.
   * \param faces Number of faces to render.
   * \param convexity Maximum number of ray intersecting faces.
   * \param center Centered or not.
	 *
	 * \return a translate decoration of the object.
	 */
    static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, double height, unsigned int twist=0, unsigned int faces=100, unsigned int convexity=10, bool center=false)
	{
		return SharedPtr<AbstractObject>(new LinearExtrudeDecorator(decorated, height, twist, faces, convexity, center));
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

protected:
	/**
	 * \brief Default constructor.
	 */
	LinearExtrudeDecorator() :
		ObjectDecorator(),
    _height(1.0),
    _twist(0),
    _faces(100),
    _convexity(10),
    _center(false)
	{}		
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
   * \param height Height of the extrusion (in the z axis).
   * \param twist Degrees of twist for every step.
   * \param faces Number of faces to render.
   * \param convexity Maximum number of ray intersecting faces.
   * \param center Centered or not.
	 */
    LinearExtrudeDecorator(SharedPtr<AbstractObject> const& decorated, double height, unsigned int twist=0, unsigned int faces=100, unsigned int convexity=10, bool center=false) :
		ObjectDecorator(decorated),
    _height(height),
    _twist(twist),
    _faces(faces),
    _convexity(convexity),
    _center(center)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~LinearExtrudeDecorator() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	LinearExtrudeDecorator(LinearExtrudeDecorator const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	LinearExtrudeDecorator & operator=(LinearExtrudeDecorator const& other);

  double _height;
  unsigned int _twist;
  unsigned int _faces;
  unsigned int _convexity;
  bool _center;
};

#endif // LINEAREXTRUDEDECORATOR_H_INCLUDED
