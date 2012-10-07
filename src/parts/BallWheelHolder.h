/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael Treviño
 *
 * OOML is licenced under the Common Creative License,
 * Attribution-ShareAlike 3.0
 *
 * You are free:
 *   - to Share - to copy, distribute and transmit the work
 *   - to Remix - to adapt the work
 *
 * Under the following conditions:
 *   - Attribution. You must attribute the work in the manner specified
 *     by the author or licensor (but not in any way that suggests that
 *     they endorse you or your use of the work).
 *   - Share Alike. If you alter, transform, or build upon this work,
 *     you may distribute the resulting work only under the same or
 *     similar license to this one.
 *
 * Any of the above conditions can be waived if you get permission
 * from the copyright holder.  Nothing in this license impairs or
 * restricts the author's moral rights.
 *
 * It is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 **********************************************************************/

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
		 data.radius_inc=0.5;
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
