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

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

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
 * \brief Circle primitive object
 *
 * This class provides a circle.
 */
class OOMLComponents_EXP_DEC Circle : public AbstractObject
{
public:
	/**
	 * \brief Creates a Circle Object
	 *
	 * \param radius Circle radius.
	 * \param faces Number of faces to render.
	 * \return Circle Componet
	 */
	static Component2D create(double radius, unsigned int faces=100)
	{
		return SharedPtr<AbstractObject>(new Circle(radius, faces));
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

	inline double getRadius() { return _radius; }

protected:
	/**
	 * \brief Default constructor.
	 */
	 Circle() :
		AbstractObject(),
		_radius(1.0),
    _faces(100)
	{}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param radius Circle radius.
   * \param faces Number of faces to render.
	 */
	Circle(double radius, unsigned int faces) :
		 AbstractObject(),
		 _radius(radius),
		 _faces(faces)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Circle() {}

private:
	double _radius; /** Circle radius. */
	unsigned int _faces; /** Circle faces number. */
};


#endif // CIRCLE_H_INCLUDED
