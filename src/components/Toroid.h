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
