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


#ifndef ARDUINOUNO_H_INCLUDED
#define ARDUINOUNO_H_INCLUDED

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
 * \brief Arduino UNO Bounding Box
 *
 * This class provides a Arduino UNO Bounding Box.
 */
class OOMLParts_EXP_DEC ArduinoUNO : public AbstractPart
{
public:
  /**
   * \brief Default constructor.
	* \param fill_drills Draw Holes as cylinders
	* \param holes_height Height of the holes when they are drawn.
	* \param fourth_hole There's a holw without space for a screw. Draw it?
   */
  ArduinoUNO(bool fill_drills = true, double holes_height=5,
				 bool fourth_hole=true) :
		AbstractPart(), _fill_drills(fill_drills), _drills_height(holes_height),
		_fourth_drill(fourth_hole)
  {
    rebuild();
    addLink(RefSys(13.97,2.54,0));
    addLink(RefSys(66.04,7.62,0));
    addLink(RefSys(66.04,35.56,0));
    addLink(RefSys(15.24,50.8,0));
  }
  /**
   * \brief Default destructor.
   */
  virtual ~ArduinoUNO() {}

  /**
	 * \brief returns a component only with the board
	 * \param height Height of the board
	 * \return board bounding box
	 *
	 * \note Create another component for the board only and then use it in this one.
	 */
  Component getBoard(double height=2, double holes_height=5, bool fill_drills=true, bool fourth_hole=true);

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
  bool _fill_drills;
  double _drills_height;
  bool _fourth_drill;
};

#endif // ARDUINOUNO_H_INCLUDED
