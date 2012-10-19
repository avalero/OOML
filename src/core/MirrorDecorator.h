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

#ifndef MIRRORDECORATOR_H_INCLUDED
#define MIRRORDECORATOR_H_INCLUDED

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
#include <core/ObjectDecorator.h>
#include <core/SharedPtr.h>

/**
 * \brief Mirror decorator.
 *
 * This class provides a mirror decoration for an object.
 */
class OOMLCore_EXP_DEC MirrorDecorator : public ObjectDecorator
{
public:
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param vx Mirror normal vector plane (x component).
	 * \param vy Mirror normal vector plane (y component).
	 * \param vz Mirror normal vector plane (z component).
	 *
	 * \return a mirror decoration of the object.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, double vx, double vy, double vz)
	{
		return SharedPtr<AbstractObject>(new MirrorDecorator(decorated, vx, vy, vz));
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
	MirrorDecorator() :
		ObjectDecorator(),
		_vx(0.0),
		_vy(0.0),
		_vz(0.0)
	{}		
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 * \param vx Mirror normal vector plane (x component).
	 * \param vy Mirror normal vector plane (y component).
	 * \param vz Mirror normal vector plane (z component).
	 */
	MirrorDecorator(SharedPtr<AbstractObject> const& decorated, double vx, double vy, double vz) :
		ObjectDecorator(decorated),
		_vx(vx),
		_vy(vy),
		_vz(vz)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~MirrorDecorator() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	MirrorDecorator(MirrorDecorator const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	MirrorDecorator & operator=(MirrorDecorator const& other);

	double _vx;	 /** Mirror normal vector plane (x component). */
	double _vy;	 /** Mirror normal vector plane (y component). */
	double _vz;	 /** Mirror normal vector plane (z component). */
};


#endif // MIRRORDECORATOR_H_INCLUDED
