/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Alberto Valero-Gomez, Nieves Cubo
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

#include "Char.h"
#include "config.h"
#include <fstream>

Char::Char(char character, double font_size, double height) :
    Component()
{
    bool capitalized;

    if (character >= 65 && character <=90){
        capitalized = true;
    }else if ((character >=97 && character <=122) || (character >=0 && character <=9)){
        capitalized = false;
    }else{
        cerr << "No dxf for that char" << endl;
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
