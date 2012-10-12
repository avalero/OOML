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
