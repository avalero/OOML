#include <components.h>
#include <parts.h>
#include <core.h>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::ofstream file("attachment.scad");
    IndentWriter writer;


    Component ardu = ArduinoUNO();

    /* Create Cube */
    Component cube1 = Cube(10,10,10);

    /* Add links to the Cube */
    cube1.addLink(RefSys(5,-5,-5).relRotate(135,0,0));
    cube1.addLink(RefSys(5,5,-5).relRotate(225,0,0));
    cube1.addLink(RefSys(5,5,5).relRotate(-45,0,0));
    cube1.addLink(RefSys(5,-5,5).relRotate(45,0,0));
    cube1.addLink(RefSys(-5,5,5).relRotate(0,0,180).relRotate(45,0,0));
    cube1.addLink(RefSys(-5,-5,5).relRotate(0,0,180).relRotate(-45,0,0));
    cube1.addLink(RefSys(-5,-5,-5).relRotate(0,180,0).relRotate(45,0,0));
    cube1.addLink(RefSys(-5,5,-5).relRotate(0,180,0).relRotate(-45,0,0));

    //Component cyl = Cylinder(3,50);

    //Component comp = cube1  - cyl;

    cube1.translate(10,0,0);
    cube1.rotate(45,0,0);

    Component cyl = Cylinder(2,50);

    cube1 = cube1 + cyl;

    cube1.translate(20,40,10);

    /* Generate OpenSCAD code and write to file */
    writer << LinksView(ardu);
    writer << ardu;
    file << writer ;
    file.close();
    std::cout << "Done" << std::endl;
}
