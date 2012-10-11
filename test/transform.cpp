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
    refsysview.relRotate(0,0,45);
    refsysview.relRotate(45,0,0);
    refsysview.relRotate(0,0,45);
    refsysview.relTranslate(0,0,10);
    refsysview.rotate(0,0,45);
    writer << refsysview;

    file << writer;

    file.close();

    return 0;
}
