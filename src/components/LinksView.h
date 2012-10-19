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

#ifndef OOML_LINKSWIEW_H_INCLUDED
#define OOML_LINKSWIEW_H_INCLUDED

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
class OOMLComponents_EXP_DEC LinksView : public Component
{
public:
	/**
	 * \brief Default constructor.
	 */
    LinksView()
    {
        _links.clear();
        _links.resize(0);
        set(genComponent().get());
    }
	/**
     * \brief constructor.
	 *
     * \param other Build from a RefSys.
	 */

    LinksView(Links const & links) :
        _links(links)
    {
        set(genComponent().get());
    }

    LinksView(LinksView const & other):
        _links(other._links)
    {
        set(genComponent().get());
    }

    LinksView(Component const & comp)
    {
        _links=comp.getLinks();
        set(genComponent().get());
    }


	/**
	 * \brief Default destructor.
	 */
    virtual ~LinksView() {}

private:
  Links _links;
  Component genComponent();
};

#endif // OOML_LINKSWIEW_H_INCLUDED
