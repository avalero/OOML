/*
*    OOML : Object Oriented Mechanics Library
*    Copyright (C) 2012  Alberto Valero Gomez, Juan González Gómez, Rafael Treviño
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License (LGPL) as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License (LGPL) for more details.
*
*    You should have received a copy of the GNU Lesser General Public License (LGPL)
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/
#include "StepperMotors.h"

#include "../core.h"
#include "../components.h"

StepperMotor::StepperMotor(StepperMotorType type):AbstractPart(){
    switch(type){
    case Nema17:
        data.x_dim_body=42.3;
        data.y_dim_body=42.3;
        data.z_dim_body=47;
        data.drills_distance=31;
        data.shaft_d=5;
        data.shaft_length=24;
        data.shaft_base_d=22;
        data.shaft_base_thickness=2;

        rebuild();
    }
}

Component StepperMotor::build(){
    Component motor = Cube(data.x_dim_body,data.y_dim_body,data.z_dim_body)
            + Cylinder(data.shaft_d/2,data.shaft_length,20,false).translate(0,0,data.z_dim_body/2)
            + Cylinder(data.shaft_base_d/2,data.shaft_base_thickness,20,false).translate(0,0,data.z_dim_body/2)
            ;

    for(int i=-1;i<=1;i+=2){
        for (int j=-1;j<=1;j+=2){
            motor = motor
                    - Cylinder(1.5,5,20,false).translate(i*data.drills_distance/2,j*data.drills_distance/2,data.z_dim_body/2-4.9)
                    ;
        }
    }

    motor.translate(0,0,-data.z_dim_body/2);
    return motor;
}
