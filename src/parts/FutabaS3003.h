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

#ifndef FUTABAS3003_H_INCLUDED
#define FUTABAS3003_H_INCLUDED

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
 * \brief Futaba S3003 Bounding Box
 *
 * This class provides a Futaba S3003 Bounding Box.
 */
class OOMLParts_EXP_DEC FutabaS3003 : public AbstractPart
{
public:

    /**
     * Crown type enumeration.
     */
    enum CrownType
    {
            NONE = 0 /** Rounded crown type */
            , FOUR = 1 /** Four arms crown type */
            , SIX = 2 /** Six arms crown type */
    };

  /**
   * \brief Default constructor.
   */
  FutabaS3003(bool fill = true, bool cable_hole=true, int type = 0) :
                AbstractPart(), _fill_hole(fill), _cable_hole(cable_hole), _type(type)
  {
    rebuild();
  }
  /**
         * \brief returns a component only with the crown
         * \param height Height of the crown
         * \return crown
         *
         * \note Create another component for the crown only and then use it in this one.
         */
  static Component getCrown(int type=0, double height=3, bool fill_hole=false);

  /**
   * \brief Default destructor.
   */
  virtual ~FutabaS3003() {}

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
  bool _fill_hole;
  bool _cable_hole;
  int _type;
};

#endif // FUTABAS3003_H_INCLUDED
