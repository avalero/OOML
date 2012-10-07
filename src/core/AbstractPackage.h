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

#ifndef ABSTRACTPACKAGE_H_INCLUDED
#define ABSTRACTPACKAGE_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <core/Component.h>
#include <core/IndentWriter.h>

#include <map>
#include <string>

/**
 * \brief Package interface.
 *
 * This class provides the package interface.
 */
class OOMLCore_EXP_DEC AbstractPackage
{
public:
	/**
	 * \brief Default constructor.
	 */
	AbstractPackage() :
		_children()
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~AbstractPackage() {}

	/**
	 * \brief Adds an named component to the package.
	 *
	 * This method adds an component to the package.
	 *
	 * \param name Name of the component to be added.
	 * \param component Component to be added.
	 */
	virtual void addComponent(std::string const& name, Component const& component)
	{
		_children.insert(Map::value_type(name, component));
	}
	/**
	 * \brief Removes an component from the package.
	 *
	 * This method removes an component from the package.
	 *
	 * \param name Name of the component to be removed.
	 */
	virtual void removeComponent(std::string const& name)
	{
		_children.erase(name);
	}

	/**
	 * \brief Generate SCAD files output for this package.
	 *
	 * This method allow the package to write the SCAD code
	 * for every component of the package. Files will be created at
	 * the current working directory.
	 */
	virtual void genScadFiles() const;

protected:
	/**
	 * \brief Build the package.
	 *
	 * This method build the package adding named components.
	 */
	virtual void build() = 0;

	/** Definition of the map of components. */
	typedef std::map<std::string, Component> Map;
  
  /** Component children. */
	Map _children;

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	AbstractPackage(AbstractPackage const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	AbstractPackage & operator=(AbstractPackage const& other);
};

#endif // ABSTRACTPACKAGE_H_INCLUDED
