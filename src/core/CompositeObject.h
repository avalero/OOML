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
