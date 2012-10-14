#include <components.h>
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
    cube1.addLink(RefSys(5,5,-5).relRotate(225,0,0));
    cube1.addLink(RefSys(5,5,5).relRotate(-45,0,0));
    cube1.addLink(RefSys(5,-5,5).relRotate(45,0,0));
    cube1.addLink(RefSys(-5,5,5).relRotate(0,0,180).relRotate(45,0,0));
    cube1.addLink(RefSys(-5,-5,5).relRotate(0,0,180).relRotate(-45,0,0));
    cube1.addLink(RefSys(-5,-5,-5).relRotate(0,180,0).relRotate(45,0,0));
    cube1.addLink(RefSys(-5,5,-5).relRotate(0,180,0).relRotate(-45,0,0));
    //cube1.scale(0.9);
    cube1.translate(-20,0,0);
    cube1.translate(10,0,0);
    cube1 = cube1 + Cube(5,5,20);
    cube1.translate(40,0,0);
    cube1.color(1,0,0);
    cube1.translate(0,0,20);

    for (int i=0; i<cube1.numberOfLinks();i++){
        Component cub = Cube(5,5,1);
        cube1.attach(i,cub);
    }

    /* Generate OpenSCAD code and write to file */
    writer << LinksView(cube1);
    writer << cube1;
    file << writer ;
    file.close();
}
