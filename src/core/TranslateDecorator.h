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

#ifndef TRANSLATEDECORATOR_H_INCLUDED
#define TRANSLATEDECORATOR_H_INCLUDED

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
class OOMLCore_EXP_DEC TranslateDecorator : public ObjectDecorator
{
public:
	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param tx Translate on the x axis.
	 * \param ty Translate on the y axis.
	 * \param tz Translate on the z axis.
	 *
	 * \return a translate decoration of the object.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, double tx, double ty, double tz)
	{
		if (Point3D(tx, ty, tz).empty())
			return decorated;

    TranslateDecorator * translate = dynamic_cast<TranslateDecorator *>(
        decorated.get());
    if (translate)
		{
      return SharedPtr<AbstractObject>(new TranslateDecorator(
            translate->get()
            , translate->_tx + tx
            , translate->_ty + ty
            , translate->_tz + tz));
		}

		return SharedPtr<AbstractObject>(new TranslateDecorator(decorated, tx, ty, tz));
	}

	/**
	 * \brief Default factory method.
	 *
	 * \param decorated Object to decorate.
	 * \param point Translation in point form.
	 */
	static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, Point3D const& translation)
	{
		if (translation.empty())
			return decorated;

    TranslateDecorator * translate = dynamic_cast<TranslateDecorator *>(
        decorated.get());
    if (translate)
		{
      return SharedPtr<AbstractObject>(new TranslateDecorator(
            translate->get()
            , translate->_tx + translation.getX()
            , translate->_ty + translation.getY()
            , translate->_tz + translation.getZ()));
		}

		return SharedPtr<AbstractObject>(new TranslateDecorator(decorated, translation));
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
	TranslateDecorator() :
		ObjectDecorator(),
		_tx(0.0),
		_ty(0.0),
		_tz(0.0)
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 * \param tx Translate on the x axis.
	 * \param ty Translate on the y axis.
	 * \param tz Translate on the z axis.
	 */
	TranslateDecorator(SharedPtr<AbstractObject> const& decorated, double tx, double ty, double tz) :
		ObjectDecorator(decorated),
		_tx(tx),
		_ty(ty),
		_tz(tz)
	{}
	/**
	 * \brief Default referenced constructor.
	 *
	 * \param decorated Object to decorate.
	 * \param point Translation in point form.
	 */
	TranslateDecorator(SharedPtr<AbstractObject> const& decorated, Point3D const& translation) :
		ObjectDecorator(decorated),
		_tx(translation.getX()),
		_ty(translation.getY()),
		_tz(translation.getZ())
	{}
	/**
	 * \brief Default destructor.
	 */
	virtual ~TranslateDecorator() {}

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	TranslateDecorator(TranslateDecorator const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	TranslateDecorator & operator=(TranslateDecorator const& other);

	double _tx;	 /** Translate on the x axis. */
	double _ty;	 /** Translate on the y axis. */
	double _tz;	 /** Translate on the z axis. */
};

#endif // TRANSLATEDECORATOR_H_INCLUDED
