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

#ifndef MINKOWSKIDECORATOR_H_INCLUDED
#define MINKOWSKIDECORATOR_H_INCLUDED

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
 * \brief Minkowski decorator.
 *
 * This class provides a minkowski decoration for an object.
 */
class OOMLCore_EXP_DEC MinkowskiDecorator : public ObjectDecorator
{
public:
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param reference Minkowski reference object.
   * \param faces Number of faces to render.
	 *
	 * \return a minkowski decoration of the object.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, SharedPtr<AbstractObject> const& reference, unsigned int faces=100)
	{
		return SharedPtr<AbstractObject>(new MinkowskiDecorator(decorated, reference, faces));
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
	MinkowskiDecorator() :
		ObjectDecorator(),
		_reference(),
		_faces(100)
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 * \param reference Minkowski reference object.
   * \param faces Number of faces to render.
	 */
	MinkowskiDecorator(SharedPtr<AbstractObject> const& decorated, SharedPtr<AbstractObject> const& reference, unsigned int faces=100) :
		ObjectDecorator(decorated),
		_reference(reference),
		_faces(faces)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~MinkowskiDecorator() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	MinkowskiDecorator(MinkowskiDecorator const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	MinkowskiDecorator & operator=(MinkowskiDecorator const& other);

	SharedPtr<AbstractObject> _reference;  /** Minkowski reference object. */
  unsigned int _faces; /** Number of faces to render. */
};

#endif // MINKOWSKIDECORATOR_H_INCLUDED
