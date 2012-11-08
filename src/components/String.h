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

#ifndef OOML_STRING_H
#define OOML_STRING_H

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
#include "Char.h"

/**
 * \brief Extruded Char primitive object
 *
 * This class provides an 3D Char.
 */


class OOMLComponents_EXP_DEC String : public Component
{
    struct Data{
        string _string;
        double _height;
        bool _created;
        double _font_size;
        double _spacing;
};


public:
    String(string cad, double font_size, double spacing, double height);
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
