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

#ifndef DUMMYPART_H_INCLUDED
#define DUMMYPART_H_INCLUDED

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
 * \brief DummyPart
 *
 * This class provides a DummyPart that can be used as template for other parts.
 */
class OOMLParts_EXP_DEC DummyPart : public AbstractPart
{
public:

    /**
     * @brief The Data struct
     */
    struct Data{
        double sx; //!< x dimension (mm)
        double sy; //!< y dimension (mm)
        double sz; //!< z dimension (mm)
    };

    /**
     * \brief Default parametrized constructor.
     *
     * \param sx x size(mm).
     * \param sy y size(mm).
     * \param sz z size(mm).
     */
    DummyPart(double sx, double sy, double sz):
        AbstractPart()
    {
        if (sx<=0) sx=1;
        if (sy<=0) sy=1;
        if (sz<=0) sz=1;

        data.sx=sx;
        data.sy=sy;
        data.sz=sz;

        rebuild();
    }
    /**
     * \brief Default destructor.
     */
    virtual ~DummyPart() {}

    inline Data getData(){ return data;}
protected:
    /**
     * \brief Build the piece.
     *
     * This method build the piece from simpler objects.
     *
     * \return The piece built.
     *
     * \note Complete the link, now it's incomplete.
     */
    virtual Component build();

private:
    Data data;
};

#endif // LINK_H_INCLUDED
