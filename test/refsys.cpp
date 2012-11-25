#include <core/RefSys.h>
#include <core/IndentWriter.h>
#include <components/RefSysView.h>
#include <components.h>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::ofstream file("refsys.scad");
    IndentWriter writer;


    Component comp = Cube(10,20,30);
    Component cyl = Cylinder(2,50);
    comp.translate(20,0,0);

    comp = comp + cyl;

    comp.translate(0,20,0);

    //comp.resetRefSys();

    writer << "%";
    writer << comp;
    writer << RefSysView(comp);

    file << writer;

    file.close();

    std::cout << "Done" << std::endl;

    return 0;
}
