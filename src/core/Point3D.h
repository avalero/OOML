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

#ifndef POINT3D_H_INCLUDED
#define POINT3D_H_INCLUDED

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
#include <math.h>

#include <utility>

/**
 * \brief 3D point primitive object
 *
 * This class provides a 3D point.
 */
class OOMLCore_EXP_DEC Point3D : public AbstractObject
{
public:
    /**
     * \brief Default constructor.
     */
    Point3D() :
        AbstractObject(),
        _x(0.0),
        _y(0.0),
        _z(0.0)
    {}
    /**
     * \brief Default parametrized constructor.
     *
     * \param x Point position in the x axis.
     * \param y Point position in the y axis.
     * \param z Point position in the z axis.
     */
    Point3D(double x, double y, double z) :
        AbstractObject(),
        _x(x),
        _y(y),
        _z(z)
    {}
    /**
     * \brief Default copy constructor.
     *
     * \param other Other object to copy from.
     */
    Point3D(Point3D const& other) :
        AbstractObject(),
        _x(other._x),
        _y(other._y),
        _z(other._z)
    {}
    /**
     * \brief Default assignment operator.
     *
     * \param other Other object to assign from.
     */
    Point3D & operator=(Point3D const& other)
    {
        _x = other._x;
        _y = other._y;
        _z = other._z;

        return *this;
    }
    /**
     * \brief Default destructor.
     */
    virtual ~Point3D() {}

    /**
     * \brief Get the x component.
     *
     * \return the x component.
     */
    inline double getX() const { return _x; }

    /**
     * \brief Get the y component.
     *
     * \return the y component.
     */
    inline double getY() const { return _y; }

    /**
     * \brief Get the z component.
     *
     * \return the z component.
     */
    inline double getZ() const { return _z; }

    /**
     * \brief Get a negated copy of the point.
     *
     * \return a negated copy.
     */
    Point3D negatedCopy() const { return Point3D(-_x, -_y, -_z); }

    /**
     * \brief Compare function.
     *
     * This method determine the order criterion.
     *
     * \param rhs Right hand side object to compare.
     *
     * \return true on equal objects
     */
    bool compare(Point3D const& rhs) const
    {
        double tmpx,tmpy,tmpz;
        double alpha = 0.1;  //minimum value to consider points different

        tmpx = _x - rhs._x;
        tmpy = _y - rhs._x;
        tmpz = _z - rhs._x;

        if ((fabs(tmpx) < alpha) && (fabs(tmpy) < alpha) && (fabs(tmpz) < alpha))
            return true;
        else
            return false;
    }

    /**
   * \brief Default equal operator.
   *
   * Compares if the points are equal.
   *
   * \param rhs Right hand side object.
   */
    inline bool operator==(Point3D const& rhs) const
    {
        return compare(rhs);
    }

    inline bool operator < (Point3D const& rhs) const{
        if (compare(rhs)) return false;

        double mod1, mod2;

        mod1 = sqrt(_x*_x + _y*_y + _y*_y);
        mod2 = sqrt(rhs.getX()*rhs.getX() + rhs.getY()*rhs.getY() + rhs.getZ()*rhs.getZ());

        return (mod1 < mod2);

    }

    /**
   * \brief Default plus operator.
   *
   * Sum up this point and another one.
   *
   * \param rhs Right hand side object.
   */
    inline Point3D operator+(Point3D const& rhs) const
    {
        return Point3D(getX() + rhs.getX()
                       , getY() + rhs.getY()
                       , getZ() + rhs.getZ());
    }
    /**
   * \brief Default minus operator.
   *
   * Substracts another point from this one.
   *
   * \param rhs Right hand side object.
   */
    inline Point3D operator-(Point3D const& rhs) const
    {
        return Point3D(getX() - rhs.getX()
                       , getY() - rhs.getY()
                       , getZ() - rhs.getZ());
    }

    /**
   * \brief Check if the point is empty.
   *
   * Check if all the components of the point are 0.
   *
   * \return if the point is empty.
   */
    inline bool empty() const
    {
        return (getX() == 0.0)
                && (getY() == 0.0)
                && (getZ() == 0.0);
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
    double _x; /** Point position in the x axis. */
    double _y; /** Point position in the y axis. */
    double _z; /** Point position in the z axis. */
};

template<>
struct std::hash<Point3D>
{
    std::size_t operator()(const Point3D& p) const
    {
      std::hash<double> hf;
      return hf(p.getX()) ^ hf(p.getY()) ^ hf(p.getZ());
    }
};

template<>
struct std::equal_to<Point3D>
{
    bool operator()(const Point3D& a, const Point3D& b) const
    {
      return (a.getX() == b.getX() &&
              a.getY() == b.getY() &&
              a.getZ() == b.getZ());
    }
};

#endif // POINT3D_H_INCLUDED
