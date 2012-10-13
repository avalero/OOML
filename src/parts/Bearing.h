/*
*    OOML : Object Oriented Mechanics Library
*    Copyright (C) 2012  Alberto Valero Gomez, Juan González Gómez, Rafael Treviño
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#ifndef BEARING_H_INCLUDED
#define BEARING_H_INCLUDED

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
 * \brief Bearing primitive object
 *
 * This class provides a bearing.
 */
class OOMLParts_EXP_DEC Bearing : public AbstractPart
{
public:

  /**
   * \brief Default constructor.
   */
  Bearing() :
    AbstractPart(),
    _radius(10),
    _width(8),
    _holes(0)
  {
                rebuild();
        }
  /**
   * \brief Default parametrized constructor.
   *
   * \param radius External radius.
   * \param width Height.
   * \param holes Holes' number.
   */
  Bearing(double radius, int width, int holes) :
    AbstractPart(),
    _radius(radius),
    _width(width),
    _holes(holes)
  {
    if (_radius < 5)
                        _radius =  8;
    if(_width < 4)
                        _width = 5;
    if(_holes < 0)
                        _holes = 0;
    rebuild();
  }
  /**
   * \brief Default destructor.
   */
  virtual ~Bearing() {}

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
  double _radius; /** External radius. */
  double _width; /** Height. */
  int _holes; /** Holes number. */
};

#endif // BEARING_H_INCLUDED
