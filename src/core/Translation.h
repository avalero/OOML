/**********************************************************************
 *
 * This code is part of the OOML project
 * Author: Alberto Valero-Gomez
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
