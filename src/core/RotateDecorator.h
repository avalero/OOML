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

#ifndef ROTATEDECORATOR_H_INCLUDED
#define ROTATEDECORATOR_H_INCLUDED

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
#include <core/Point3D.h>
#include <core/SharedPtr.h>

/**
 * \brief Translate decorator.
 *
 * This class provides a translate decoration for an object.
 */
class OOMLCore_EXP_DEC RotateDecorator : public ObjectDecorator
{
public:
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param vx Rotation vector x axis component.
	 * \param vy Rotation vector y axis component.
	 * \param vz Rotation vector z axis component.
	 * \param a Rotation angle around the rotation vector.
	 *
	 * \return a rotate decoration of the object.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, double vx, double vy, double vz, double a)
	{
		if (a == 0.0)
			return decorated;

		return SharedPtr<AbstractObject>(new RotateDecorator(decorated, vx, vy, vz, a));
	}
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param ax Rotation angle x axis.
	 * \param ay Rotation angle y axis.
	 * \param az Rotation angle z axis.
	 *
	 * \return a rotate decoration of the object.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, double ax, double ay, double az)
	{
		if (Point3D(ax, ay, az).empty())
			return decorated;

		return SharedPtr<AbstractObject>(new RotateDecorator(decorated, ax, ay, az));
	}
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param point Rotation angles in point form.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, Point3D const& rotation)
	{
		if (rotation.empty())
			return decorated;

		return SharedPtr<AbstractObject>(new RotateDecorator(decorated, rotation));
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
	RotateDecorator() :
		ObjectDecorator(),
		_vx(0.0),
		_vy(0.0),
		_vz(0.0),
		_ax(0.0),
		_ay(0.0),
		_az(0.0)
	{}		
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 * \param vx Rotation vector x axis component.
	 * \param vy Rotation vector y axis component.
	 * \param vz Rotation vector z axis component.
	 * \param a Rotation angle around the rotation vector.
	 */
	RotateDecorator(SharedPtr<AbstractObject> const& decorated, double vx, double vy, double vz, double a) :
		ObjectDecorator(decorated),
		_vx(vx),
		_vy(vy),
		_vz(vz),
		_ax(a),
		_ay(a),
		_az(a)
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 * \param ax Rotation angle x axis.
	 * \param ay Rotation angle y axis.
	 * \param az Rotation angle z axis.
	 */
	RotateDecorator(SharedPtr<AbstractObject> const& decorated, double ax, double ay, double az) :
		ObjectDecorator(decorated),
		_vx(0.0),
		_vy(0.0),
		_vz(0.0),
		_ax(ax),
		_ay(ay),
		_az(az)
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 * \param point Rotation angles in point form.
	 */
	RotateDecorator(SharedPtr<AbstractObject> const& decorated, Point3D const& rotation) :
		ObjectDecorator(decorated),
		_vx(0.0),
		_vy(0.0),
		_vz(0.0),
		_ax(rotation.getX()),
		_ay(rotation.getY()),
		_az(rotation.getZ())
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~RotateDecorator() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	RotateDecorator(RotateDecorator const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	RotateDecorator & operator=(RotateDecorator const& other);

	double _vx;	 /** Rotation vector x axis component. */
	double _vy;	 /** Rotation vector y axis component. */
	double _vz;	 /** Rotation vector z axis component. */
	double _ax;	 /** Rotation angle x axis. */
	double _ay;	 /** Rotation angle y axis. */
	double _az;	 /** Rotation angle z axis. */
};

#endif // ROTATEDECORATOR_H_INCLUDED
