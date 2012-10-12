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

#ifndef SIMPLEAXE_H_INCLUDED
#define SIMPLEAXE_H_INCLUDED

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

#include <core/AbstractPart.h>

/**
 * \brief Simple axe primitive object
 *
 * This class provides a simple axe.
 */
class OOMLParts_EXP_DEC SimpleAxe : public AbstractPart
{
public:
	/**
	 * \brief Default constructor.
	 */
	SimpleAxe() :
		AbstractPart(),
		_length(1),
		_radius(0.1)
	{
		rebuild();
	}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param length Axe length.
	 * \param radius Axe radius.
	 */
	SimpleAxe(double length, double radius) :
		AbstractPart(),
		_length(length),
		_radius(radius)
	{
    rebuild();
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~SimpleAxe() {}

protected:
	/**
	 * \brief Build the piece.
	 *
	 * This method build the piece from simpler objects.
	 *
	 * \return The piece built.
	 */
	virtual Component build();

private:
	double _length; /** Axe length. */
	double _radius; /** Axe radius. */
};

#endif // SIMPLEAXE_H_INCLUDED
