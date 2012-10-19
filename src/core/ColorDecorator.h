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

#ifndef COLORDECORATOR_H_INCLUDED
#define COLORDECORATOR_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <core/ObjectDecorator.h>
#include <core/IndentWriter.h>
#include <core/SharedPtr.h>

/**
 * \brief Color decorator.
 *
 * This class provides a color decoration for an object.
 */
class OOMLCore_EXP_DEC ColorDecorator : public ObjectDecorator
{
public:
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param r Red component of the color.
	 * \param g Green component of the color.
	 * \param b Blue component of the color.
	 * \param a Alpha component of the color.
	 *
	 * \return a color decoration of the object.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, double r, double g, double b, double a=1.0)
	{
		return SharedPtr<AbstractObject>(new ColorDecorator(decorated, r, g, b, a));
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
	ColorDecorator() :
		ObjectDecorator(),
		_r(0.0),
		_g(0.0),
		_b(0.0),
		_a(1.0)
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param r Red component of the color.
	 * \param g Green component of the color.
	 * \param b Blue component of the color.
	 * \param a Alpha component of the color.
	 * \param decorated Object to decorate.
	 */
	ColorDecorator(SharedPtr<AbstractObject> const& decorated, double r, double g, double b, double a=1.0) :
		ObjectDecorator(decorated),
		_r(r),
		_g(g),
		_b(b),
		_a(a)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~ColorDecorator() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	ColorDecorator(ColorDecorator const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	ColorDecorator & operator=(ColorDecorator const& other);

	double _r; /** Red component of the color. */
	double _g; /** Green component of the color. */
	double _b; /** Blue component of the color. */
	double _a; /** Alpha component of the color. */
};

#endif // COLORDECORATOR_H_INCLUDED
