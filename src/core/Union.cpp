/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Treviño
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

#include <core/Union.h>
#include <core/IndentWriter.h>

#include <iostream>

void Union::genScad(IndentWriter& writer) const
{
	writer << "union() {" << std::endl;
	{
		IndentBlock block(writer);
		CompositeObject::genScad(writer);
	}
	writer << "} // End union" << std::endl;
}

void Union::printAst(IndentWriter& writer) const
{
	writer << "// UNION()" << std::endl;
	{
		IndentBlock block(writer);
		CompositeObject::printAst(writer);
	}
}

Component operator+(Component const& lhs, Component const& rhs)
{
	 CompositeComponent result(Union::create());

     //Keep all the links of the children
     //avoid link 0, which is the default link at the origin
     if(lhs.hasLinks())
         for (int i=1; i<lhs.getLinks().size();i++)
            result.addLink(lhs.getLink(i));

     if (rhs.hasLinks())
         for (int i=1; i<rhs.getLinks().size();i++)
            result.addLink(rhs.getLink(i));


	 result << lhs.get() << rhs.get();
	 return result;
}
