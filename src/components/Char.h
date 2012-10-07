/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael TreviÒo
 *          Nieves Cubo
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

#ifndef OOML_CHAR_H
#define OOML_CHAR_H

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif

#include <iostream>
#include <sstream>

using namespace std;

#include "../core/DXFLinearExtrude.h"
#include "../core/AbstractPart.h"

/**
 * \brief Extruded Char primitive object
 *
 * This class provides an 3D Char.
 */


class OOMLComponents_EXP_DEC Char : public Component
{
    struct Data{
        char _character;
        double _height;
        bool _created;
	bool _capitalized;
	double _font_size;
    };

public:
    Char(char character, double font_size, double height);
    Data getData(){
        return data;
    }
    bool exists(){
        return data._created;
    }

private:
    Data data;
};

#endif // CHAR_H
