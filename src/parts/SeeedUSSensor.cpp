#include <parts/SeeedUSSensor.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <components/RoundedTablet.h>
#include <core/Union.h>



Component SeeedUSSensor::build()
{
	 data.sx = 43;
	 data.sy = 20;
	 data.sz = 15;

	 data.board_thickness = 2;
	 data.drills_x_dist = 40;
	 data.drills_y_dist = 17;
	 data.drills_radius = 1;
	 data.sensor_radius = 16.1/2;
	 data.sensor_dist_to_center = 20 - data.sensor_radius;

	 Component us = Cube(data.sx,data.sy,data.board_thickness,true).translate(0,0,data.board_thickness/2) //board
                + Cylinder(data.sensor_radius + 1.5*PART_MARGIN,data.sz,100,false).translate(data.sensor_dist_to_center,0,0) //us1
                + Cylinder(data.sensor_radius + 1.5*PART_MARGIN,data.sz,100,false).translate(-data.sensor_dist_to_center,0,0); //us2


     Component drills = Cylinder(data.drills_radius+PART_MARGIN,12,20,false)
				.translate(data.drills_x_dist/2,data.drills_y_dist/2,-5)
                + Cylinder(data.drills_radius+PART_MARGIN,12,20,false)
									 .translate(-data.drills_x_dist/2,data.drills_y_dist/2,-5)
                + Cylinder(data.drills_radius+PART_MARGIN,12,20,false)
									 .translate(data.drills_x_dist/2,-data.drills_y_dist/2,-5)
                + Cylinder(data.drills_radius+PART_MARGIN,12,20,false)
									 .translate(-data.drills_x_dist/2,-data.drills_y_dist/2,-5);

	 if (_fill_drills){
		  us = us + drills;
	 }else{
		  us = us - drills;
	 }
	 return us;
}
