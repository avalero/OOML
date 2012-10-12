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

#ifndef IMPORTED_H_INCLUDED
#define IMPORTED_H_INCLUDED

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

#include <string>
#include <exception>

/**
 * \brief Import error exception.
 *
 * This class provides the exception raised when import from a file is not
 * possible.
 */
class OOMLCore_EXP_DEC ImportError : public std::exception
{
public:
	explicit ImportError() {};
};

/**
 * \brief Imported object
 *
 * This class provides an imported object.
 */
class OOMLCore_EXP_DEC Imported: public AbstractObject
{
public:
  /**
   * \brief Default parametrized factory method.
   * \param filename Filename to import into component.
   */
	static SharedPtr<AbstractObject> create(std::string const& filename);

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
	Imported() :
		AbstractObject(),
		_filename(),
    _scadCode()
	{}
	/**
	 * \brief Default parametrized constructor.
	 *
   * \param scadCode SCAD code to import into component.
	 */
	Imported(std::string const& filename, std::string const& scadCode) :
		AbstractObject(),
		_filename(filename),
    _scadCode(scadCode)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Imported() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	Imported(Imported const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	Imported & operator=(Imported const& other);

	std::string _filename; /** Filename to import into component. */
  std::string _scadCode; /** SCAD code of component. */
};

#endif // IMPORTED_H_INCLUDED
