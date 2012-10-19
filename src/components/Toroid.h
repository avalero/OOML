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

#ifndef TOROID_H_INCLUDED
#define TOROID_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include <core/AbstractPart.h>

/**
 * \brief Toroid primitive object
 *
 * This class provides a toroid.
 */
class OOMLComponents_EXP_DEC Toroid : public AbstractPart
{
public:
	/**
	 * \brief Default constructor.
	 */
	Toroid() :
		AbstractPart(),
    _toroidRadius(1.0),
    _sectionRadius(0.5),
    _faces(100)
	{
    rebuild();
	}
	/**
	 * \brief Default parametrized constructor.
	 *
   * \param toroidRadius Radius of the toroid.
   * \param sectionRadius Radius of toroid's section.
	 * \param faces Number of faces of the rendered toroid.
	 */
	Toroid(double toroidRadius, double sectionRadius, unsigned int faces=100) :
		AbstractPart(),
    _toroidRadius(toroidRadius),
    _sectionRadius(sectionRadius),
    _faces(faces)
	{
		if (_sectionRadius > _toroidRadius)
			_sectionRadius = _toroidRadius;
		rebuild();
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Toroid() {}

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
  double _toroidRadius; /** Radius of the toroid. */
  double _sectionRadius; /** Radius of toroid's section. */
  unsigned int _faces; /** Number of faces of the rendered toroid. */
};

#endif // TOROID_H_INCLUDED
