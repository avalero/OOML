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

            //if there are links apply inverse of transformation before transforming
            Links lks = transform->AbstractObject::getLinks();
            for (int i=0;i<lks.size();i++){
                RefSys lk = lks[i];
                if (rel)
                    lk.relTransform(tr2.getInv());
                else
                    lk.transform(tr2.getInv());

                transform->get()->addLink(lk);
            }


            if(rel){
                tr = tr2 * tr;
            }else{
                tr = tr * tr2;
            }
            double x,y,z;tr.getGlobalXYZAngles(x,y,z);
            double ax,ay,az; tr.getGlobalXYZAngles(ax,ay,az);

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
    virtual Links getLinks() const;
    virtual RefSys getLink(int id) const;

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
