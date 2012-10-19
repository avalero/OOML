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

#ifndef DIFFERENCE_H_INCLUDED
#define DIFFERENCE_H_INCLUDED

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
#include <core/CompositeComponent.h>
#include <core/CompositeObject.h>
#include <core/IndentWriter.h>
#include <core/Union.h>

/**
 * \brief Difference object.
 *
 * This class differs multiple objects into a difference object.
 */
class OOMLCore_EXP_DEC Difference : public CompositeObject
{
public:
  /**
   * \brief Static factory method.
   *
   * Creates a difference to use in other components.
   *
   * \return A difference component.
   */
  static CompositeComponent create()
  {
    return CompositeComponent(SharedPtr<CompositeObject>(new Difference()));
  }

  /**
   * \brief Adds an object to the composite.
   *
   * This method adds an object pointer to the composite object.
   *
   * \param object Object to be added.
   */
  virtual void addObject(SharedPtr<AbstractObject> const& object)
  {
		Union * objectUnion = dynamic_cast<Union *>(object.get());
		if (!_children.empty() && objectUnion)
		{
			_children.insert(_children.end()
				, objectUnion->_children.begin()
				, objectUnion->_children.end());
			return;
    }

    _children.push_back(object);
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
  Difference() :
    CompositeObject()
  {}
  /**
   * \brief Default destructor.
   */
  virtual ~Difference()
  {}

private:
  /**
   * \brief Default copy constructor.
   *
   * \note Disabled to avoid copies.
   *
   * \param other Other object to copy from.
   */
  Difference(Difference const& other);
  /**
   * \brief Default assignment operator.
   *
   * \note Disabled to avoid assignments.
   *
   * \param other Other object to assign from.
   */
  Difference & operator=(Difference const& other);
};

OOMLCore_EXP_DEC Component operator-(Component const& lhs, Component const& rhs);

#endif // DIFFERENCE_H_INCLUDED
