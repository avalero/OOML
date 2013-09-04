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

#ifndef NINEVOLTBATTERY_H_INCLUDED
#define NINEVOLTBATTERY_H_INCLUDED

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
#include <components/Cube.h>

/**
 * \brief Nine volt Battery Model
 *
 * This class provides a Nine Volt Battery Model.
 */
class OOMLParts_EXP_DEC NineVoltBattery : public AbstractPart
{
public:

  struct Data{
      double sx;
      double sy;
      double sz;

      double connector_r;
      double connector_lenght;
      double connect_width;

  };

  /**
   * \brief Default constructor.
   */
  NineVoltBattery() :
	 AbstractPart()
  {
    rebuild();
  }
  /**
   * \brief Default destructor.
   */
  virtual ~NineVoltBattery() {}


  inline virtual Data getData(){ return _data; }

protected:
  /**
   * \brief Build the piece.
   *
   * This method build the piece from simpler objects.
   *
   * \return The piece built.
   */
  virtual Component build();

  Data _data;
};

#endif // NINEVOLT_H_INCLUDED
