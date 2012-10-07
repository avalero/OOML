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

#ifndef SCALEDECORATOR_H_INCLUDED
#define SCALEDECORATOR_H_INCLUDED

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
 * \brief Scale decorator.
 *
 * This class provides a scale decoration for an object.
 */
class OOMLCore_EXP_DEC ScaleDecorator : public ObjectDecorator
{
public:
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param s Scale factor on the three axis.
	 *
	 * \return a scale decoration of the object.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, double s)
	{
		if (s == 1.0)
			return decorated;

    ScaleDecorator * scale = dynamic_cast<ScaleDecorator *>(
        decorated.get());
    if (scale)
		{
			scale->_sx *= s;
			scale->_sy *= s;
			scale->_sz *= s;
			return decorated;
		}

		return SharedPtr<AbstractObject>(new ScaleDecorator(decorated, s));
	}
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param sx Scale factor on the x axis.
	 * \param sy Scale factor on the y axis.
	 * \param sz Scale factor on the z axis.
	 *
	 * \return a scale decoration of the object.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, double sx, double sy, double sz)
	{
		if (sx == 1.0 && sy == 1.0 && sz == 1.0)
			return decorated;

    ScaleDecorator * scale = dynamic_cast<ScaleDecorator *>(
        decorated.get());
    if (scale)
		{
			scale->_sx *= sx;
			scale->_sy *= sy;
			scale->_sz *= sz;
			return decorated;
		}

		return SharedPtr<AbstractObject>(new ScaleDecorator(decorated, sx, sy, sz));
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
	ScaleDecorator() :
		ObjectDecorator(),
		_sx(1.0),
		_sy(1.0),
		_sz(1.0)
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param s Scale factor on the three axis.
	 * \param decorated Object to decorate.
	 */
	ScaleDecorator(SharedPtr<AbstractObject> const& decorated, double s) :
		ObjectDecorator(decorated),
		_sx(s),
		_sy(s),
		_sz(s)
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param sx Scale factor on the x axis.
	 * \param sy Scale factor on the y axis.
	 * \param sz Scale factor on the z axis.
	 * \param decorated Object to decorate.
	 */
	ScaleDecorator(SharedPtr<AbstractObject> const& decorated, double sx, double sy, double sz) :
		ObjectDecorator(decorated),
		_sx(sx),
		_sy(sy),
		_sz(sz)
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~ScaleDecorator() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	ScaleDecorator(ScaleDecorator const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	ScaleDecorator & operator=(ScaleDecorator const& other);

	double _sx;	 /** Scale on the x axis. */
	double _sy;	 /** Scale on the y axis. */
	double _sz;	 /** Scale on the z axis. */
};

#endif // SCALEDECORATOR_H_INCLUDED
