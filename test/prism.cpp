#include <components/PolygonalPrism.h>
#include <core/IndentWriter.h>
#include <core/Point2D.h>
#include <core/Polygon.h>

#include <iostream>

int main(int argc, char **argv)
{
  IndentWriter writer;
	Polygon<Point2D> base;

    base.addPoint(Point2D(1.0, 2.0));
    base.addPoint(Point2D(1.0, -2.0));
	base.addPoint(Point2D(-1.0, -1.0));
    base.addPoint(Point2D(-2.0, 1.0));

  Component prism(PolygonalPrism(base, 5.0));

  writer << prism;
	std::cout << writer;

	return 0;
}
