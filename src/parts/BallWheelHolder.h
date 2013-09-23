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

#ifndef BALLWHEEL_H_INCLUDED
#define BALLWHEEL_H_INCLUDED

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

#include <core/AbstractPart.h>
#include <components/Sphere.h>

/**
 * \brief Ball Wheel Holder primitive object
 *
 * This class provides a simple wheel.
 */
class OOMLParts_EXP_DEC BallWheelHolder : public AbstractPart
{
public:
	 struct Data{
		  double radius; // = 17/2;
		  double wallThickness; // = 2.5;
		  double gapWidth; // = 5;
		  double height; //<! Height from ball to base
		  double holeSize; // = 3
		  double baseHeight;
		  double baseWidth;
		  double baseThickness; // = 3;
		  double effectiveRadius;
		  double totalHeight;
		  double radius_inc; // = 0.5
	 };

public:
	/**
	 * \brief Default constructor.
	 */
	BallWheelHolder() :
		 AbstractPart()
	{
		 data.radius=8;
         data.radius_inc=0.8;
		 data.wallThickness=2.5;
		 data.gapWidth=5.;
		 data.holeSize=3.;
		 data.baseThickness=3.;
		 data.totalHeight=0;
		 data.effectiveRadius = data.radius + data.radius_inc;
		 data.baseHeight = 2.*data.radius+data.wallThickness*2.;
		 data.baseWidth = data.wallThickness*4.+2.*data.radius;
		 data.height= 2.5*data.radius;

		 rebuild();
	}
	BallWheelHolder(double totalHeight) :
		 AbstractPart()
	{
		 data.radius=8;
		 data.radius_inc=0.5;
		 data.wallThickness=2.5;
		 data.gapWidth=5.;
		 data.holeSize=3.;
		 data.baseThickness=3.;
		 data.totalHeight=totalHeight;
		 data.effectiveRadius = data.radius + data.radius_inc;
		 data.baseHeight = 2.*data.radius+data.wallThickness*2.;
		 data.baseWidth = data.wallThickness*4.+2.*data.radius;
		 data.height= 2.5*data.radius;

		 rebuild();
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~BallWheelHolder() {}

	Component getBall();

	static Component create(double totalHeight=0){
		 return BallWheelHolder(totalHeight);
	}

	inline const Data getData() const {
		 return data;
	}

protected:
	/**
	 * \brief Build the piece.
	 *
	 * This method build the piece from simpler objects.
	 *
	 * \return The piece built.
	 */
	virtual Component build();



	Data data;

private:
};

#endif // SIMPLEWHEELdata.Hdata.INCLUDED
