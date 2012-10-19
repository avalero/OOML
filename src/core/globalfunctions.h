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

#ifndef OOML_GLOBAL_FUNCTIONS_H_INCLUDED
#define OOML_GLOBAL_FUNCTIONS_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

class Component;

/**
  * \brief Attaches two components
  * This method attaches attachment component to base componet, making the links fit together
  * \param base Base Component. Remains unmoved
  * \param link_base. The id number of the link to attach.
  * \param attachment. The component to attach. It will be rotated and translated.
  * \param link_attach. The link of the attachment we want to place at the link of the base. By default the center of the attachment
  * \return An Union of base and attachment
  */
OOMLCore_EXP_DEC Component& attach(Component&  base, int link_base, Component& attachment, int link_attach=0);



#endif // OOML_GLOBAL_FUNCTIONS_H_INCLUDED
