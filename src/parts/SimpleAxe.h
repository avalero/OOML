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
