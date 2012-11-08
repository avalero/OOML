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

#include "Char.h"
#include "config.h"
#include <fstream>

Char::Char(char character, double font_size, double height) :
    Component()
{
    bool capitalized;

    if ((character >= 65 && character <=90) || (character >=49 && character <=58)){
        capitalized = true;
    }else if (character >=97 && character <=122){
        capitalized = false;
    }else{
        cerr << "No dxf for that char: " << (int)character << endl;
        data._created=false;
        return;
    }

    data._capitalized=capitalized;
    data._character=character;
    data._height=height;
    data._font_size=font_size;

    if(capitalized == true){
        bool exists = false;
        bool exists_installed = false;
        string file_path="";
        //check whether the file exists in the installed dir
        {
            stringstream dxf;
            dxf << DXF_INSTALLED_PATH << "/" << character << ".dxf";
            string dxf_file = dxf.str();

            ifstream ifile(dxf_file.c_str());

            if (ifile){
                exists_installed = true;
                file_path = dxf_file;
            }
        }
        //check whether the file exists **but not installed**
        {
            stringstream dxf;
            dxf << DXF_PATH << "/" << character << ".dxf";
            string dxf_file = dxf.str();

            ifstream ifile(dxf_file.c_str());

            if(ifile){
                exists = true;
                file_path = dxf_file;
            }
        }

        if (exists_installed || exists){
            Component myChar(Component::linearExtrudeFromDXF(file_path,height ));  //A-Z y 0-9
	    myChar.scale(font_size/183.7, font_size/183.7,0);
            set(myChar.get());
        }
    }else{ //capitalized = false

        bool exists = false;
        bool exists_installed = false;
        string file_path="";
        //check whether the file exists in the installed dir
        {
            stringstream dxf;
            dxf << DXF_INSTALLED_PATH << "/" << character << "m.dxf";
            string dxf_file = dxf.str();

            ifstream ifile(dxf_file.c_str());

            if (ifile){
                exists_installed = true;
                file_path = dxf_file;
            }
        }

        //check whether the file exists **but not installed**
        {
            stringstream dxf;
            dxf << DXF_PATH << "/" << character << "m.dxf";
            string dxf_file = dxf.str();

            ifstream ifile(dxf_file.c_str());

            if (ifile){
                exists = true;
                file_path = dxf_file;
            }
        }

        if (exists_installed || exists){
            Component myChar(Component::linearExtrudeFromDXF(file_path,height ));  //a-Z y 0-9
            data._created=true;
	    myChar.scale(font_size/145, font_size/145,0);
            set(myChar.get());
        }else{
            cerr << "dxf file with " << data._character << " letter does not exist" << endl;
            data._created = false;
        }
    }
}
