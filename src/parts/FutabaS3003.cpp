#include <parts/FutabaS3003.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <components/RoundedTablet.h>
#include <core/Union.h>

Component FutabaS3003::getCrown(int type, double height, bool fill_hole)
{
    //Crown. Three types: rounded, four and six arms.
    Component difference, arm, crown;

            //Four arms type.
            if(type == FOUR)
            {
                difference = Cube(10,20.5,height).translate(10,6,0).rotateAround(0,0,13.392,5,2,0);

                arm = Cube(10,12.5,height).translate(0,6.25,0)
                      - difference
                      - difference.mirroredCopy(1,0,0)
                      + Cylinder(2.5,height,20,true).translate(0,12.5,0);

                crown = Cube(10.2,10.2,height);
                for(int i=0; i<4; i++)
                    crown = crown + arm.translatedCopy(0,5,0).rotatedCopy(0,0,90*i);
            }

            //Six arms type.
            else if(type == SIX)
            {
                difference = Cube(7.5,9.3,height).translate(7.5,4.75,0).rotateAround(0,0,9.717,3.75,0.1,0);

                arm = Cube(7.5,7.4,height).translate(0,3.65,0)
                      - difference
                      - difference.mirroredCopy(1,0,0)
                      + Cylinder(2.5,height,20,true).translate(0,7.4,0);

                crown = Cylinder(7.5,height);
                for(int i=0; i<6; i++)
                    crown = crown + arm.translatedCopy(0,6.5,0).rotatedCopy(0,0,60*i);
            }

            //Rounded type.
            else
                crown = Cylinder(10.75,height,30,true);




            if(!fill_hole)
                crown = crown - Cylinder(4.25, height + 2);

            return crown;
}




Component FutabaS3003::build()
{
        Component joint = Cylinder(4.25,4,30,true);
        Component hole_servo = Cylinder(1.8,1.8,15.0,20);
        Component hole_servo_fill = Cylinder(1.8,1.8,36.6,20,false);

        Component servo = RoundedTablet(20.5,41.5,36.6,1,true,true,true,true,100,false)
                          + getCrown(_type,3,true).translate(10.5,10.5,42.1)
                          + joint.translate(10.5,10.5,38.6)
                          + RoundedTablet(20,9,3,1,true,true,true,true,50,false).translate(0.25,-8,26.6)
                          + RoundedTablet(20,9,3,1,true,true,true,true,50,false).translate(0.25,40.5,26.6);




        //fill the holes of the screws?
        if(!_fill_hole)
                        servo = servo
                                - hole_servo.translatedCopy(5.25,-4.25,24)
                                - hole_servo.translatedCopy(15.25,-4.25,24)
                                - hole_servo.translatedCopy(5.25,45.75,24)
                                - hole_servo.translatedCopy(15.25,45.75,24);
        else
                        servo = servo //+ Cube(5,2,36.5,false).translate(7.75,41.5,0)
                                + hole_servo_fill.translatedCopy(5.25,-4.25,0)
                                + hole_servo_fill.translatedCopy(15.25,-4.25,0)
                                + hole_servo_fill.translatedCopy(5.25,45.75,0)
                                + hole_servo_fill.translatedCopy(15.25,45.75,0);

		  //leave space for inserting the cable
		  if (_cable_hole){
				servo = servo + Cube(5,2,3,false).translate(7.75,41.5,0);
		  }

        servo.color(0.3,0.3,0.3);

	return servo;
}
