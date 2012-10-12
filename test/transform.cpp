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

    Component cube = Cube(10,10,10);

    cube.translate(10,10,10);
    //cube = cube + cube;
   // cube.scale(10);
    AbstractObject * abso = dynamic_cast<AbstractObject*>(cube.get().get());
    abso->getRefSys();
    std::cout << " main --- main" << std::endl;
    cube.getRefSys();

//    cube.translate(10,0,0);
//    cube.relRotate(45,0,0);
//    cube.translate(0,0,10);

//    cube = cube + cube;
//    writer << "% ";
//    writer << cube;
    std::cout << " RefSysView --- RefSysView" << std::endl;
    writer << RefSysView(cube);

    file << writer;

    file.close();

    return 0;
}
