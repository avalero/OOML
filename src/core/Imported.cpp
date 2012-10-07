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

#include <core/Imported.h>
#include <core/IndentWriter.h>

#include <fstream>
#include <iostream>
#include <string>

SharedPtr<AbstractObject> Imported::create(std::string const& filename)
{
  std::ifstream scadFile;
  scadFile.open(filename.c_str());
    
  std::string scadCode;
  if (scadFile.is_open())
  {
    while(!scadFile.eof())
			scadCode += scadFile.get();
    scadFile.close();
		scadCode.erase(scadCode.end() - 1); // Avoid EOF character
  }
  else
  {
    throw ImportError();
  }

  return SharedPtr<AbstractObject>(new Imported(filename, scadCode));
}

void Imported::genScad(IndentWriter& writer) const
{
	writer << "// Imported file '" << _filename << "'" << std::endl;
	for (std::string::const_iterator it = _scadCode.begin()
		; it != _scadCode.end(); ++it)
	{
		switch(*it)
		{
			case '\n':
				writer << std::endl;
				break;
			default:
				writer << *it;
				break;
		}
	}
	writer << "// End imported file '" << _filename << "'" << std::endl;
}

void Imported::printAst(IndentWriter& writer) const
{
	writer << "IMPORTED()" << std::endl;
}
