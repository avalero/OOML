#include <core/Component2D.h>
#include <core/IndentWriter.h>
#include <core/Point2D.h>
#include <core/Polygon2D.h>

#include <iostream>

int main(int argc, char **argv)
{
  IndentWriter writer;
	Component2D polygon(Polygon2D::create());
  
  /* Create a square */
  {
    Polygon2D & polygon2D = polygon.getRef<Polygon2D>();
    polygon2D.addPoint(Point2D(-100.0, 100.0));
    polygon2D.addPoint(Point2D(100.0, 100.0));
    polygon2D.addPoint(Point2D(100.0, -100.0));
    polygon2D.addPoint(Point2D(-100.0, -100.0));
  }
  polygon.translate(5, 0, 0);

  Component extrudedComponent(polygon.linearExtrudedCopy(10));

  writer << polygon;
  writer << extrudedComponent;
  std::cout << writer;

	return 0;
}
