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

#ifndef DXFLINEAREXTRUDE_H_INCLUDED
#define DXFLINEAREXTRUDE_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <core/AbstractObject.h>
#include <core/IndentWriter.h>
#include <core/SharedPtr.h>

/**
 * \brief Linear extrude from DXF filename.
 *
 * This class provides a linear extrude from a DXF filename.
 */
class OOMLCore_EXP_DEC DXFLinearExtrude : public AbstractObject
{
public:
	/**
	 * \brief Default DXF factory method.
	 *
	 * \param filename DXF filename to extrude.
   * \param height Height of the extrusion (in the z axis).
   * \param twist Degrees of twist for every step.
   * \param faces Number of faces to render.
   * \param convexity Maximum number of ray intersecting faces.
   * \param center Centered or not.
	 *
	 * \return a linear extrude of the DXF filename.
	 */
	static SharedPtr<AbstractObject> create(std::string const& filename, double height, unsigned int twist=0, unsigned int faces=100, unsigned int convexity=10, bool center=true)
	{
		return SharedPtr<AbstractObject>(new DXFLinearExtrude(filename, height, twist, faces, convexity, center));
	}

	/**
	 * \brief Generate SCAD output for this object.
	 *
	 * This method allow the object to write the SCAD code
	 * to the indent writer provided. The writer must be at the
	 * beggining of a line when leaving the method.
	 *
	 * \param writer An instance of indent writer to write to.
	 */
	virtual void genScad(IndentWriter& writer) const;
	/**
	 * \brief Generate AST output for this object.
	 *
	 * This method allow the object to write the AST code
	 * to the indent writer provided. The writer must be at the
	 * beggining of a line when leaving the method.
	 *
	 * \param writer An instance of indent writer to write to.
	 */
	virtual void printAst(IndentWriter& writer) const;

protected:
	/**
	 * \brief Default constructor.
	 */
	DXFLinearExtrude() :
		AbstractObject(),
    _DXFFilename(),
    _height(1.0),
    _twist(0),
    _faces(100),
    _convexity(10),
    _center(true)
	{}		
	/**
	 * \brief Default DXF referenced constructor.
	 *
	 * \param filename DXF filename to extrude.
   * \param height Height of the extrusion (in the z axis).
   * \param twist Degrees of twist for every step.
   * \param faces Number of faces to render.
   * \param convexity Maximum number of ray intersecting faces.
   * \param center Centered or not.
	 */
	DXFLinearExtrude(std::string const& filename, double height, unsigned int twist=0, unsigned int faces=100, unsigned int convexity=10, bool center=true) :
		AbstractObject(),
    _DXFFilename(filename),
    _height(height),
    _twist(twist),
    _faces(faces),
    _convexity(convexity),
    _center(center)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~DXFLinearExtrude() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	DXFLinearExtrude(DXFLinearExtrude const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	DXFLinearExtrude & operator=(DXFLinearExtrude const& other);

  std::string _DXFFilename;
  double _height;
  unsigned int _twist;
  unsigned int _faces;
  unsigned int _convexity;
  bool _center;
};

#endif // DXFLINEAREXTRUDE_H_INCLUDED
