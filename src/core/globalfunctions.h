/**********************************************************************
 *
 * This code is part of the OOML project
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
