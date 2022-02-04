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

#ifndef POINT2D_H_INCLUDED
#define POINT2D_H_INCLUDED

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
#include <math.h>

#include <utility>

/**
 * \brief 2D point primitive object
 *
 * This class provides a 2D point.
 */
class OOMLCore_EXP_DEC Point2D : public AbstractObject
{
public:
	/**
	 * \brief Default constructor.
	 */
	Point2D() :
		AbstractObject(),
		_x(0.0),
		_y(0.0)
	{}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param x Point position in the x axis.
	 * \param y Point position in the y axis.
	 */
	Point2D(double x, double y) :
		AbstractObject(),
		_x(x),
		_y(y)
	{}
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
	Point2D(Point2D const& other) :
		AbstractObject(),
		_x(other._x),
		_y(other._y)
	{}
	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other object to assign from.
	 */
	Point2D & operator=(Point2D const& other)
	{
		_x = other._x;
		_y = other._y;

		return *this;
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Point2D() {}

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
	 * \brief Get a negated copy of the point.
	 *
	 * \return a negated copy.
	 */
	Point2D negatedCopy() const { return Point2D(-_x, -_y); }

	/**
	 * \brief Compare function.
	 *
	 * This method determine the order criterion.
	 *
	 * \param rhs Right hand side object to compare.
	 *
     * \return 0 on equal objects, !=0 on different points. 1 greater mod -1 lesser mod
	 */
    int compare(Point2D const& rhs) const
	{
        double alpha = 0.1; //minimum value to consider points different
        double tmpx,tmpy;

        tmpx = _x - rhs._x;
        tmpy = _y - rhs._y;


        if ( (fabs(tmpx) < alpha) && (fabs(tmpy) < alpha) ) return 0;

        //else

        double mod_rhs = rhs._x*rhs._x + rhs._y*rhs._y;
        double mod_this = _x*_x + _y*_y;

        double mod_diff = mod_rhs - mod_this;

        if (mod_diff > 0) return 1;
        else return -1;
	}

  /**
   * \brief Default equal operator.
   *
   * Compares if the points are equal.
   *
   * \param rhs Right hand side object.
   */
  inline bool operator==(Point2D const& rhs) const
  {
    return compare(rhs) == 0;
  }
  /**
   * \brief Default less operator.
   *
   * Compares if one point is less than another.
   *
   * \param rhs Right hand side object.
   */
  inline bool operator<(Point2D const& rhs) const
  {
    return compare(rhs) < 0;
  }
  /**
   * \brief Default plus operator.
   *
   * Sum up this point and another one.
   *
   * \param rhs Right hand side object.
   */
  inline Point2D operator+(Point2D const& rhs) const
  {
    return Point2D(getX() + rhs.getX()
        , getY() + rhs.getY());
  }
  /**
   * \brief Default minus operator.
   *
   * Substracts another point from this one.
   *
   * \param rhs Right hand side object.
   */
  inline Point2D operator-(Point2D const& rhs) const
  {
    return Point2D(getX() - rhs.getX()
        , getY() - rhs.getY());
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
      && (getY() == 0.0);
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
	double _x; /** Point position in the x axis. */
	double _y; /** Point position in the y axis. */
};

template<>
struct std::hash<Point2D>
{
    std::size_t operator()(const Point2D& p) const
    {
      std::hash<double> hf;
      return hf(p.getX()) ^ hf(p.getY());
    }
};

template<>
struct std::equal_to<Point2D>
{
    bool operator()(const Point2D& a, const Point2D& b) const
    {
      return (a.getX() == b.getX() &&
	      a.getY() == b.getY());
    }
};

#endif // POINT2D_H_INCLUDED
