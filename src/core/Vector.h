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

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

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

/**
 * \brief Generic vector primitive object.
 *
 * This class provides a generic vector.
 */
template <typename T>
class Vector : public AbstractObject
{
public:
	/**
	 * \brief Default constructor.
	 */
	Vector() :
		AbstractObject(),
		_pose(),
    _normal()
	{}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param pose Vector pose point.
	 * \param normal Vector normal point.
	 */
  Vector(T const& pose, T const& normal) :
    AbstractObject(),
    _pose(pose),
    _normal(normal)
  {}
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
	Vector(Vector const& other) :
		AbstractObject(),
    _pose(other.getPose()),
    _normal(other.getNormal())
	{}
	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other object to assign from.
	 */
	Vector & operator=(Vector const& other)
	{
		_pose = other.getPose();
		_normal = other.getNormal();
		return *this;
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Vector() {}

  /**
   * \brief Gets the pose point.
   *
   * \return vector pose point.
   */
  virtual T const& getPose() const
  {
    return _pose;
  }
  /**
   * \brief Sets the pose point.
   *
   * \param pose New vector pose point.
   */
  virtual void setPose(T const& pose)
  {
    _pose = pose;
  }
  /**
   * \brief Gets the normal point.
   *
   * \return vector normal point.
   */
  virtual T const& getNormal() const
  {
    return _normal;
  }
  /**
   * \brief Sets the normal point.
   *
   * \param normal New vector normal point.
   */
  virtual void setNormal(T const& normal)
  {
    _normal = normal;
  }

	/**
	 * \brief Vector add operator.
   *
   * This method adds both pose and normal in the resulting vector.
	 *
	 * \param vector Vector to be added to the Vector.
	 */
	virtual Vector & operator+(Vector<T> const& vector)
	{
    _pose += vector.getPose();
    _normal += vector.getNormal();
		return *this;
	}
	/**
	 * \brief Vector sub operator.
   *
   * This method subs both pose and normal in the resulting vector.
	 *
	 * \param vector Vector to be substracted to the Vector.
	 */
	virtual Vector & operator-(Vector<T> const& vector)
	{
    _pose -= vector.getPose();
    _normal -= vector.getNormal();
		return *this;
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

private:
	T _pose; /** Vector pose point. */
	T _normal; /** Vector normal point. */
};

template <typename T>
void Vector<T>::genScad(IndentWriter& writer) const
{
	writer << "[";
  _pose.genScad(writer);
  writer << ", ";
  _normal.genScad(writer);
	writer << "]";
}

template <typename T>
void Vector<T>::printAst(IndentWriter& writer) const
{
	writer << "[";
  _pose.printAst(writer);
  writer << ", ";
  _normal.printAst(writer);
	writer << "]";
}

#endif // VECTOR_H_INCLUDED
