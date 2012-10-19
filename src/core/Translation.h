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

#ifndef OOML_TRANSLATION_H_INCLUDED
#define OOML_TRANSLATION_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <math.h>
#include <utility>

/**
 * \brief Translation Vector
 *
 * This class provides a translation vector
 */
class OOMLCore_EXP_DEC Translation
{
public:
    /**
     * \brief Default constructor.
     */
    Translation() :
        x(0),y(0),z(0)
    {
    }

    Translation(double x, double y, double z) : x(x),y(y),z(z)
    {}


    /**
      * \brief Translates the current vector
      * \param tx translation along x axis.
      * \param ty translation along y axis.
      * \param tz translation along z axis.
      */
    inline void translate(double tx, double ty, double tz){
        x+=tx;
        y+=ty;
        z+=tz;
    }

    inline Translation operator+(Translation const& rhs) const
    {
        return Translation(x + rhs.x
                       , y + rhs.y
                       , z + rhs.z);
    }



    double x,y,z;


};

#endif // TRANSLATION_H_INCLUDED
