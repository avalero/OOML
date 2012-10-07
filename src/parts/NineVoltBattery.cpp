#include <parts/NineVoltBattery.h>
#include <components/Cube.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <components/RoundedTablet.h>
#include <core/Union.h>

Component NineVoltBattery::build()
{
	 double sx = 26.32; // 26.32;
	 double sy = 17.26; // 17.26;
	 double sz = 45.30; // 45.30;

	 double connector_r = 5;
	 double connector_lenght = 3.20;
	 double connect_width = 22;

	 Component battery = RoundedTablet(sx , sy , sz , 2);
	 Component connector = RoundedTablet(connect_width , 2*connector_r , connector_lenght , 2*connector_r);
	 connector.translate( 0 , 0 , sz/2 + connector_lenght/2);
	 battery = battery + connector;
	 battery.color(0.7,0.7,0.7);

	 return battery;
}
