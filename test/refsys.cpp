#include <core/RefSys.h>
#include <core/IndentWriter.h>
#include <components/RefSysView.h>
#include <components/Cube.h>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::ofstream file("refsys.scad");
    IndentWriter writer;

    RefSys refsys;

    //refsys.relTranslate(10,0,0);
    //refsys.relRotate(0,0,45);
    //refsys.relTranslate(10,0,0);
    //refsys.relRotate(45,0,0);
    //refsys.relTranslate(0,0,10);
    refsys.translate(10,0,0);
    refsys.rotate(0,0,-45);
    refsys.rotate(45,0,0);
    RefSysView refsysview(refsys);

    RefSysView refsysview2;
    refsysview2.translate(11,0,0);
    refsysview2.rotate(0,0,-45);
    refsysview2.rotate(45,0,0);

    writer << refsysview;
    writer << refsysview2;

    file << writer;

    file.close();

    return 0;
}
