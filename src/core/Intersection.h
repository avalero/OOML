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

#ifndef INTERSECTION_H_INCLUDED
#define INTERSECTION_H_INCLUDED

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
#include <core/CompositeComponent.h>
#include <core/CompositeObject.h>
#include <core/IndentWriter.h>

/**
 * \brief Intersection object.
 *
 * This class intersects multiple objects into a intersection object.
 */
class OOMLCore_EXP_DEC Intersection : public CompositeObject
{
public:
  /**
   * \brief Static factory method.
   *
   * Creates a intersection to use in other components.
   *
   * \return A intersection component.
   */
  static CompositeComponent create()
  {
    return CompositeComponent(SharedPtr<CompositeObject>(new Intersection()));
  }

  /**
   * \brief Adds an object to the composite.
   *
   * This method adds an object pointer to the composite object.
   *
   * \param object Object to be added.
   */
  virtual void addObject(SharedPtr<AbstractObject> const& object)
  {
    Intersection * objectIntersection = dynamic_cast<Intersection *>(object.get());
    if (objectIntersection)
    {
      _children.insert(_children.end()
          , objectIntersection->_children.begin()
          , objectIntersection->_children.end());
      return;
    }

    _children.push_back(object);
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
  Intersection() :
    CompositeObject()
  {}
  /**
   * \brief Default destructor.
   */
  virtual ~Intersection()
  {}

private:
  /**
   * \brief Default copy constructor.
   *
   * \note Disabled to avoid copies.
   *
   * \param other Other object to copy from.
   */
  Intersection(Intersection const& other);
  /**
   * \brief Default assignment operator.
   *
   * \note Disabled to avoid assignments.
   *
   * \param other Other object to assign from.
   */
  Intersection & operator=(Intersection const& other);
};

OOMLCore_EXP_DEC Component operator*(Component const& lhs, Component const& rhs);

#endif // INTERSECTION_H_INCLUDED
