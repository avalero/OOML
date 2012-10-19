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

#ifndef BATTERYHOLDER_H_INCLUDED
#define BATTERYHOLDER_H_INCLUDED

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
 * \brief Battery holder primitive object
 *
 * This class provides a battery holder.
 */
class OOMLParts_EXP_DEC BatteryHolder : public AbstractPart
{
public:
	/**
	 * Battery type enumeration.
	 */
	enum BatteryType
	{
		A23 = 0 /** A23 battery type */
		, AAAA=1 /** AAAA battery type */
		, AAA=2 /** AAA battery type */
		, AA=3 /** AA battery type */
		, C=4 /** C battery type */
		, D=5 /** D battery type */
	};

  /**
   * \brief Default constructor.
   */
  BatteryHolder() :
    AbstractPart(),
    _thickness(3.5),
    _number(4),
    _type(AA)
  {
		rebuild();
	}
  /**
   * \brief Default parametrized constructor.
   *
   * \param thickness Walls thickness.
   * \param number Batteries' number.
   * \param type Battery's type.
   */
  BatteryHolder(double thickness, int number, int type) :
    AbstractPart(),
    _thickness(thickness),
    _number(number),
    _type(type)
  {
    if (_thickness < 3.5)
                        _thickness =  3.5;
    if(_number<1)
			_number = 1;
    if(_type < 0 || _type > 5)
			_type = AA;
    rebuild();
  }
  /**
   * \brief Default destructor.
   */
  virtual ~BatteryHolder() {}

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
  double _thickness; /** Walls thickness. */
  int _number; /** Batteries' number. */
  int _type; /** Battery's type. */
};

#endif // BATTERYHOLDER_H_INCLUDED
