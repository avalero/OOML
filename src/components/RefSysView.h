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

#ifndef OOML_REFSYSIEW_H_INCLUDED
#define OOML_REFSYSIEW_H_INCLUDED

#ifdef WIN32
#ifdef OOMLComponents_EXPORTS
#define OOMLComponents_EXP_DEC __declspec(dllexport)
#else
#define OOMLComponents_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLComponents_EXP_DEC
#endif


#include "../core/IndentWriter.h"
#include "../core/RefSys.h"
#include "../core/Component.h"
#include <math.h>

#include <utility>

/**
 * \brief 3D point primitive object
 *
 * This class provides a 3D point.
 */
class OOMLComponents_EXP_DEC RefSysView : public Component
{
public:
	/**
	 * \brief Default constructor.
	 */
    RefSysView() : _refSys()
    {
        set(genComponent().get());
    }
	/**
     * \brief constructor.
	 *
     * \param other Build from a RefSys.
	 */

    RefSysView(RefSys const & ref) :
        _refSys(ref)
    {
        set(genComponent().get());
    }

    RefSysView(RefSysView const & other):
        _refSys(other._refSys)
    {
        set(genComponent().get());
    }

    RefSysView(Component const & comp)
    {
        _refSys = comp.getRefSys();

        set(genComponent().get());
    }


	/**
	 * \brief Default destructor.
	 */
    virtual ~RefSysView() {}

private:
  RefSys _refSys;
  Component genComponent();
};

#endif // OOML_REFSYSIEW_H_INCLUDED
