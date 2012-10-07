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
