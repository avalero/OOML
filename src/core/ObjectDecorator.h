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

#ifndef OBJECTDECORATOR_H_INCLUDED
#define OBJECTDECORATOR_H_INCLUDED

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

/**
 * \brief Abstract object decorator interface.
 *
 * This class provides the object decorator interface of the library.
 */
class OOMLCore_EXP_DEC ObjectDecorator : public AbstractObject
{
public:
	/**
	 * \brief Default constructor.
	 */
	ObjectDecorator() :
		AbstractObject(),
		_decorated()
    {}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 */
	ObjectDecorator(SharedPtr<AbstractObject> const& decorated) :
		AbstractObject(),
		_decorated(decorated)
    {}
	/**
	 * \brief Default destructor.
	 */
	virtual ~ObjectDecorator() {}

	/**
	 * \brief Get the internally hold pointer. Const version.
	 *
	 * \return the internally hold object pointer.
	 */
	virtual SharedPtr<AbstractObject> const& get() const
	{
		return _decorated;
	}

	/**
	 * \brief Set the internally hold pointer.
	 *
	 * \param value New interanlly hold object pointer.
	 */
	virtual void set(SharedPtr<AbstractObject> const& value)
	{
		_decorated = value;
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
    virtual RefSys getLink(int id) const;
    virtual Links getLinks() const;

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	ObjectDecorator(ObjectDecorator const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	ObjectDecorator & operator=(ObjectDecorator const& other);

	SharedPtr<AbstractObject> _decorated; /** Object pointer to the decorated object. */
};

#endif // OBJECTDECORATOR_H_INCLUDED
