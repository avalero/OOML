﻿/**********************************************************************
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
