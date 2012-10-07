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

#ifndef ABSTRACTOBJECT_H_INCLUDED
#define ABSTRACTOBJECT_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include "IndentWriter.h"
#include "SharedPtr.h"
#include "RefSys.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


/**
 * \brief Abstract object interface.
 *
 * This class provides the object interface of the library.
 */
class OOMLCore_EXP_DEC AbstractObject
{
    typedef std::vector<RefSys> Links;

public:
	/**
	 * \brief Default constructor.
	 */
	AbstractObject() {}
	/**
	 * \brief Default destructor.
	 */
	virtual ~AbstractObject() {}

	/**
	 * \brief Generate SCAD output for this object.
	 *
	 * This method allow the object to write the SCAD code
	 * to the indent writer provided. The writer must be at the
	 * beggining of a line when leaving the method.
	 *
	 * \param writer An instance of indent writer to write to.
	 */
    virtual void genScad(IndentWriter& writer) const = 0;
	/**
	 * \brief Generate AST output for this object.
	 *
	 * This method allow the object to write the AST code
	 * to the indent writer provided. The writer must be at the
	 * beggining of a line when leaving the method.
	 *
	 * \param writer An instance of indent writer to write to.
	 */
	virtual void printAst(IndentWriter& writer) const = 0;

	/**
	 * \brief Set the debug mode ON.
	 *
	 * This method sets the debug mode to ON.
	 */
	static void debugMode() { _debugFlag = true; }

    /**
     * \return Returns de vector of links
     */
    inline Links getLinks() const {
        return _links;
    }

    /**
      * \return Return link number id
      */
    inline RefSys getLink(int id) const {
        return _links[id];
    }

    /**
      * \brief Adds a Link to the system.
      * \link Reference System of the Link.
      * \return Link Number.
      */
    inline int addLink(RefSys rs){
        _links.push_back(rs);
        return (_links.size()-1);
    }

    /**
      * \brief Adds a vector of Links to the system.
      * \links Vector of Reference Systems of the Links.
      */
    inline void addLinks(Links l){
        for (int i=0; i<l.size();i++)
            _links.push_back(l[i]);
    }

    /**
      * \brief Returns if the Object has links.
      * \return true when there are links
      */
    inline bool hasLinks() const {
        return (_links.size()>0);
    }

protected:
	/**
	 * \brief Print a debug message.
	 *
	 * This method print a message to the standard output only if
	 * debug mode is ON.
     */

    inline void debug(std::string const& str) const { if (_debugFlag) std::cout << "//-- " << str << std::endl;}

    Links _links;


private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	AbstractObject(AbstractObject const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	AbstractObject & operator=(AbstractObject const& other);

	static bool _debugFlag; /** Debug flag. */



};

/**
 * \brief Generate the SCAD code of the object with insertor syntax.
 *
 * This method inserts in the object's SCAD code into the writer.
 *
 * \param writer The writer to write to.
 * \param object The object to insert into the writer.
 *
 * \return The parameter writer to allow chained insertions.
 */
OOMLCore_EXP_DEC IndentWriter& operator<<(IndentWriter & writer, AbstractObject const& object);

#endif // ABSTRACTOBJECT_H_INCLUDED
