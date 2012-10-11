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
