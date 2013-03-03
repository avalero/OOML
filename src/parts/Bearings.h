/**********************************************************************
 *
 * This code is part of the RepRap Plastic Valley project
 * Authors: Alberto Valero-Gomez
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

#ifndef PLASTICVALLEY_BEARINGS_H
#define PLASTICVALLEY_BEARINGS_H

#include "../core.h"

#include <core/AbstractPart.h>

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

enum LinearBearings{LM8uu, LM10uu};

class OOMLParts_EXP_DEC LMXuu : public AbstractPart
{
public:
    /**
      * Part Data
      */
    struct Data{
        double inner_diameter; //<! the rod diameter (mm)
        double ext_diameter; //<! the rod diameter (mm)
        double length; //<! the rod lenght (mm)
    };

    /**
      * Constructor
      */
    LMXuu(LinearBearings type);

    /**
     * \brief returns part data
     * \return part data
     */
    inline const Data getData() const{return data;}

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
    Data data;
};

class OOMLParts_EXP_DEC B608zz : public AbstractPart
{
public:
    /**
      * Part Data
      */
    struct Data{
        double inner_diameter; //<! the rod diameter (mm)
        double ext_diameter; //<! the rod diameter (mm)
        double length; //<! the rod lenght (mm)
    };

    /**
      * Constructor
      */
    B608zz();

    /**
     * \breif returns part data
     * \return part data
     */
    inline const Data getData() const{return data;}

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
    Data data;
};

class OOMLParts_EXP_DEC B624zz : public AbstractPart
{
public:
    /**
      * Part Data
      */
    struct Data{
        double inner_diameter; //<! the rod diameter (mm)
        double ext_diameter; //<! the rod diameter (mm)
        double length; //<! the rod lenght (mm)
    };

    /**
      * Constructor
      */
    B624zz();

    /**
     * \breif returns part data
     * \return part data
     */
    inline const Data getData() const{return data;}

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
    Data data;
};

#endif
