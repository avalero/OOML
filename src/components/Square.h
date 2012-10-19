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

#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

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
 * \brief Square primitive object
 *
 * This class provides a square.
 */
class OOMLComponents_EXP_DEC Square : public AbstractObject
{
public:
	/**
	 * \brief Creates a Square 2D Component
	 *
	 * Creates a square to use in other components.
	 *
	 * \param sx Square dimension in the x axis.
	 * \param sy Square dimension in the y axis.
	 * \param center Centered square flag.
	 * \return Square Component2D
	 */
	static Component2D create(double sx, double sy, bool center=true)
	{
		return Component2D(SharedPtr<AbstractObject>(new Square(sx, sy, center)));
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
	Square() :
		AbstractObject(),
		_sx(1.0),
		_sy(1.0),
		_center(true)
	{}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param sx Square dimension in the x axis.
	 * \param sy Square dimension in the y axis.
	 * \param center Centered square flag.
	 */
	Square(double sx, double sy, bool center=true) :
		AbstractObject(),
		_sx(sx),
		_sy(sy),
		_center(center)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Square() {}

private:
	double _sx; /** Square dimension in the x axis. */
	double _sy; /** Square dimension in the y axis. */
	bool _center; /** Centered square flag. */
};

#endif // SQUARE_H_INCLUDED
