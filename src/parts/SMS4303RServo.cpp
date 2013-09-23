#include "SMS4303RServo.h"
#include <components/Cube.h>
#include <core/Union.h>
#include <core/Difference.h>
#include <components/Cylinder.h>

SMS4303RServo::SMS4303RServo(bool fill, bool cable_space, double fill_length) :
    GenericServo(GenericServo::Data(),fill,cable_space,fill_length)
{
    _data.width = 20.5;
    _data.height = 39.5;
    _data.length = 41.2;
    _data.total_height_with_axis = 46.2;
    _data.total_lenght_with_holes = 55.70;
    _data.axis_radius = 5.9/2;
    _data.axis_position = 11.50;
    _data.holes_height = 30.24;
    _data.holes_radius = 2.2;
    _data.holes_support_thickness = 2.4;
    _data.d_op_holes = 49;
    _data.d_cl_holes = 10;
    _data.cable_clearance_length = 7.81;
    _data.cable_clearance_width = 7;

    rebuild();
}

Component SMS4303RServo::getBackCover()
{
    double cover_height = 5.70;
    double wall_thickness = 1.8;

    Component cover = GenericServo::getBackCover();
    Component body = Cube(_data.length,_data.width, cover_height)
            - Cube(_data.length-2*wall_thickness , _data.width-2*wall_thickness , cover_height).translate(0,0,wall_thickness)
            ;
    body.translate(0,0,cover_height/2);


    Component drills_around_tpl = Cylinder(2.4,cover_height,20,true).translate(0,0, cover_height/2);
    Component drills_tpl = Cylinder(1.4,3*cover_height,20,true);
    Component void_for_screws_tpl = Cylinder(3.2,1.5,20,true).translate(0,0, - _data.holes_support_thickness/2 + 1.5/2 - COMPONENT_MARGIN);

    Component drills = drills_tpl.translatedCopy(-_data.length/2 + 2.3 , -_data.width/2 + 2.3 , 0)
            + drills_tpl.translatedCopy(-_data.length/2 + 2.3 , _data.width/2 - 2.3, 0)
            + drills_tpl.translatedCopy(_data.length/2 -2.3 , -_data.width/2 + 2.3, 0)
            + drills_tpl.translatedCopy(_data.length/2 - 2.3 , _data.width/2 - 2.3 , 0)
            ;

    Component drills_around = drills_around_tpl.translatedCopy(-_data.length/2 + 2.3 , -_data.width/2 + 2.3 , 0)
            + drills_around_tpl.translatedCopy(-_data.length/2 + 2.3 , _data.width/2 - 2.3, 0)
            + drills_around_tpl.translatedCopy(_data.length/2 - 2.3 , -_data.width/2 + 2.3, 0)
            + drills_around_tpl.translatedCopy(_data.length/2 - 2.3 , _data.width/2 - 2.3 , 0)
            ;
    Component void_for_screws = void_for_screws_tpl.translatedCopy(-_data.length/2 + 2.3 , -_data.width/2 + 2.3 , 0)
            + void_for_screws_tpl.translatedCopy(-_data.length/2 + 2.3 , _data.width/2 - 2.3, 0)
            + void_for_screws_tpl.translatedCopy(_data.length/2 - 2.3 , -_data.width/2 + 2.3, 0)
            + void_for_screws_tpl.translatedCopy(_data.length/2 - 2.3 , _data.width/2 - 2.3 , 0)
            ;

    Component support_for_void_for_screws_tpl = Cylinder(3.2,1.9,20,true).translate(0,0, - _data.holes_support_thickness/2 + 1.9/2);


    Component support_for_void_for_screws = support_for_void_for_screws_tpl.translatedCopy(-_data.length/2 + 2.3 , -_data.width/2 + 2.3 , 0)
            + support_for_void_for_screws_tpl.translatedCopy(-_data.length/2 + 2.3 , _data.width/2 - 2.3, 0)
            + support_for_void_for_screws_tpl.translatedCopy(_data.length/2 - 2.3 , -_data.width/2 + 2.3, 0)
            + support_for_void_for_screws_tpl.translatedCopy(_data.length/2 - 2.3 , _data.width/2 - 2.3 , 0)
            ;

    Component wire_clearance = Cube(2*wall_thickness,_data.cable_clearance_width,cover_height).translate(_data.length/2 - wall_thickness/2 ,0,cover_height + _data.holes_support_thickness - 2);

    cover = cover
            + body
            + drills_around
            - drills
            + support_for_void_for_screws
            - void_for_screws
            - wire_clearance
            ;



    return cover;
}
