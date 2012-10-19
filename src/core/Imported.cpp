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
