#include <core/RefSys.h>
#include <core/IndentWriter.h>
#include <components/RefSysView.h>
#include <components/Cube.h>
#include <core.h>
#include <iostream>
#include <fstream>
#include <core/TransformDecorator.h>
#include <parts.h>

int main(int argc, char **argv)
{
    std::ofstream file("transform.scad");
    IndentWriter writer;

    Component cube1 = Cube(10,10,10);
    Component cube2 = Cube(10,10,10);
    //cube.translate(10,0,0);
    cube1.rotate(0,0,45).translate(10,0,0);
    cube2.rotate(45,0,0);
    //cube.relTranslate(10,0,0);

    Component cube = cube1 * cube2;
    writer << "% ";
    writer << cube;
    writer << RefSysView(cube);

    file << writer;

    file.close();

    return 0;
}
