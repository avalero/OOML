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

#ifndef TRANSFORMDECORATOR_H_INCLUDED
#define TRANSFORMDECORATOR_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include "AbstractObject.h"
#include "IndentWriter.h"
#include "ObjectDecorator.h"
#include "Point3D.h"
#include "SharedPtr.h"
#include "TransformMatrix.h"

/**
 * \brief Translate decorator.
 *
 * This class provides a translate decoration for an object.
 */
class OOMLCore_EXP_DEC TransformDecorator : public ObjectDecorator
{
public:
    /**
     * \brief Default factory method.
     *
     * \param decorated Object to decorate.
     * \param tr Homogeneous Transformation Matrix
     *
     * \return a homogeneous transformation decoration of the object.
     */
    static SharedPtr<AbstractObject> create(SharedPtr<AbstractObject> const& decorated, TransformMatrix tr, bool rel=false)
    {
        if (tr.isIdentity())
            return decorated;

        TransformDecorator * transform = dynamic_cast<TransformDecorator *>(decorated.get());
        if (transform)
        {

            TransformMatrix tr2  = transform->_tr;
            if(rel){
                tr = tr2 * tr;
            }else{
                tr = tr * tr2;
            }

            return SharedPtr<AbstractObject>(new TransformDecorator(transform->get(),tr));
        }
        return SharedPtr<AbstractObject>(new TransformDecorator(decorated, tr));
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

    virtual RefSys getRefSys() const;

protected:
    /**
     * \brief Default constructor.
     */
    TransformDecorator() :
        ObjectDecorator(),
        _tr()
    {}

    /**
     * \brief Default referenced constructor.
     *
     * \param decorated Object to decorate.
     * \param point Translation in point form.
     */
    TransformDecorator(SharedPtr<AbstractObject> const& decorated, TransformMatrix const & trans) :
        ObjectDecorator(decorated),
        _tr(trans)
    {}
    /**
     * \brief Default destructor.
     */
    virtual ~TransformDecorator() {}

private:
    /**
     * \brief Default copy constructor.
     *
     * \note Disabled to avoid copies.
     *
     * \param other Other object to copy from.
     */
    TransformDecorator(TransformDecorator const& other);
    /**
     * \brief Default assignment operator.
     *
     * \note Disabled to avoid assignments.
     *
     * \param other Other object to assign from.
     */
    TransformDecorator & operator=(TransformDecorator const& other);


    TransformMatrix _tr; //!< Homogenous Transformation Matrix (includes rotations and translations)
};

#endif // TRANSFORMDECORATOR_H_INCLUDED
