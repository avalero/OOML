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

#ifndef DXFROTATEEXTRUDE_H_INCLUDED
#define DXFROTATEEXTRUDE_H_INCLUDED

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
 * This class provides a rotate extrude from a DXF filename.
 */
class OOMLCore_EXP_DEC DXFRotateExtrude : public AbstractObject
{
public:
	/**
	 * \brief Default DXF factory method.
	 *
	 * \param filename DXF filename to extrude.
   * \param convexity Maximum number of ray intersecting faces.
   * \param faces Number of faces to render.
	 *
	 * \return a rotate extrude of the DXF filename.
	 */
	static SharedPtr<AbstractObject> create(std::string const& filename, unsigned int convexity=10, unsigned int faces=100)
	{
		return SharedPtr<AbstractObject>(new DXFRotateExtrude(filename, convexity, faces));
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
	DXFRotateExtrude() :
		AbstractObject(),
    _DXFFilename(),
    _convexity(10),
    _faces(100)
	{}		
	/**
	 * \brief Default DXF referenced constructor.
	 *
	 * \param filename DXF filename to extrude.
   * \param convexity Maximum number of ray intersecting faces.
   * \param faces Number of faces to render.
	 */
	DXFRotateExtrude(std::string const& filename, unsigned int convexity=10, unsigned int faces=100) :
		AbstractObject(),
    _DXFFilename(filename),
    _convexity(convexity),
    _faces(faces)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~DXFRotateExtrude() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	DXFRotateExtrude(DXFRotateExtrude const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	DXFRotateExtrude & operator=(DXFRotateExtrude const& other);

  std::string _DXFFilename;
  unsigned int _convexity;
  unsigned int _faces;
};

#endif // DXFROTATEEXTRUDE_H_INCLUDED
