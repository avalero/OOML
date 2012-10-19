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

#ifndef FUTABAWHEEL_H_INCLUDED
#define FUTABAWHEEL_H_INCLUDED

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

#include <parts/SimpleWheel.h>

/**
 * \brief Futaba wheel primitive object
 *
 * This class provides a futaba wheel.
 */
class OOMLParts_EXP_DEC FutabaWheel : public SimpleWheel
{
public:
        /**
         * \brief Default constructor.
         */
        FutabaWheel() :
                _radius(12.75),
                _thickness(5),
                _crownType(0)
        {
                rebuild();
        }
        /**
         * \brief Default parametrized constructor.
         *
         * \param futabaRadius Futaba piece radius.
         * \param futabaThickness Futaba piece thickness.
         * \param crownType There are three types of crown.
         */
        FutabaWheel(double radius, double thickness, int crownType) :
                 _radius(radius),
                 _thickness(thickness),
                 _crownType(crownType)
        {
                if (_crownType < 0 || _crownType > 2)
                        _crownType = 0;
                if (_radius < 12.75 && _crownType == 0)
                        _radius = 12.75;
                if (_radius < 22 && _crownType == 1)
                        _radius = 22;
                if (_radius < 18.4 && _crownType == 2)
                        _radius = 18.4;
                if (_thickness < 5)
                        _thickness = 5;
    rebuild();
        }
        /**
         * \brief Default destructor.
         */
        virtual ~FutabaWheel() {}

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
        double _radius; /** Radius. */
        double _thickness; /** Thickness. */
        double _crownType; /** Type of crown. */
};

#endif // FUTABAWHEEL_H_INCLUDED
