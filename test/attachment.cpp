#include <components.h>
#include <parts.h>
#include <core.h>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::ofstream file("attachment.scad");
    IndentWriter writer;

    /* Create Cube */
    Component cube1 = Cube(10,10,10);

    /* Add links to the Cube */
    cube1.addLink(RefSys(5,-5,-5).relRotate(135,0,0));
//    cube1.addLink(RefSys(5,5,-5).relRotate(225,0,0));
//    cube1.addLink(RefSys(5,5,5).relRotate(-45,0,0));
//    cube1.addLink(RefSys(5,-5,5).relRotate(45,0,0));
//    cube1.addLink(RefSys(-5,5,5).relRotate(0,0,180).relRotate(45,0,0));
//    cube1.addLink(RefSys(-5,-5,5).relRotate(0,0,180).relRotate(-45,0,0));
//    cube1.addLink(RefSys(-5,-5,-5).relRotate(0,180,0).relRotate(45,0,0));
//    cube1.addLink(RefSys(-5,5,-5).relRotate(0,180,0).relRotate(-45,0,0));

    //Component cyl = Cylinder(3,50);

    //cube1.translate(5,0,0);

    cube1.addLink(RefSys(0,0,0));

    Component cube2 = Cube(3,50,2);
    cube2.addLink(RefSys(1.5,25,1.5));

    //cube1.translate(5,0,0);
    //cube1.rotate(0,0,45);

    Component ardu = ArduinoUNO();

    Component wheel = SharpIRSensor();

    wheel.addLink(RefSys(10,10,10));

    Component comp = ardu + cube1;

    //comp.addLink(RefSys(20,20,20));

    /* Generate OpenSCAD code and write to file */
    writer << LinksView(comp);
    writer << comp;
    file << writer ;
    file.close();
    std::cout << "Done" << std::endl;
}
