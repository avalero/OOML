#include <core/RefSys.h>
#include <core/IndentWriter.h>
#include <components/RefSysView.h>
#include <components/Cube.h>
#include <iostream>
#include <fstream>
#include <core/TransformDecorator.h>
#include <parts.h>

int main(int argc, char **argv)
{
    std::ofstream file("transform.scad");
    IndentWriter writer;

    RefSysView refsysview;
    //refsysview.rotate(0,0,45);
    refsysview.translate(10,0,0);
    //refsysview.rotate(0,0,45);
    refsysview.translate(10,20,30);

    //writer << refsysview;

    TransformMatrix tr;
    //tr.rotate(45,0,0);
    tr.translate(10,0,0);
    //tr.rotate(0,0,45);
    tr.translate(10,20,30);
    Component cube = Cube(5,5,10);
    Component trd = TransformDecorator::create(cube.get(),tr);

    //writer << trd;

    Component ard = SeeedUSSensor();
    ard.rotate(90,0,0);
    ard.translate(0,0,10);
    writer << ard;

    file << writer;

    file.close();

    return 0;
}
