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

#ifndef COMPOSITEOBJECT_H_INCLUDED
#define COMPOSITEOBJECT_H_INCLUDED

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
#include <core/SharedPtr.h>

#include <algorithm>
#include <vector>

class CompositeComponent;
class Component;

/**
 * \brief Composite object interface.
 *
 * This class provides a composite object interface.
 */
class OOMLCore_EXP_DEC CompositeObject : public AbstractObject
{
public:
	/**
	 * \brief Default constructor.
	 */
	CompositeObject() :
		AbstractObject(),
		_children()
	{}
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	CompositeObject(CompositeObject const& other)	:
		AbstractObject(),
		_children(other._children)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~CompositeObject() {}

	/**
	 * \brief Adds an object to the composite.
	 *
	 * This method adds an object pointer to the composite object.
	 *
	 * \param object Object to be added.
	 */
	virtual void addObject(SharedPtr<AbstractObject> const& object)
	{
		_children.push_back(object);
	}
	/**
	 * \brief Removes an object from the composite.
	 *
	 * This method removes an object pointer from the composite object.
	 *
	 * \param object Object to be removed.
	 */
	virtual void removeObject(SharedPtr<AbstractObject> const& object)
	{
		_children.erase(std::remove(_children.begin(), _children.end(), object), _children.end());
	}

	/**
	 * \brief Adds an object with insertor syntax.
	 *
	 * This methods adds an object through the insertor interface.
	 *
	 * \param object Object to be inserted.
	 */
	virtual CompositeObject & operator<<(SharedPtr<AbstractObject> const& object)
	{
		addObject(object);
		return *this;
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

    virtual RefSys getRefSys() const;
    virtual Links getLinks() const;
    virtual RefSys getLink(int id) const;

protected:
	/** Definition of the vector of objects. */
	typedef std::vector<SharedPtr<AbstractObject> > Vector;

  /** Object children. */
	Vector _children;

private:
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	CompositeObject & operator=(CompositeObject const& other);
};

#endif // COMPOSITEOBJECT_H_INCLUDED
