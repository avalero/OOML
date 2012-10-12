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

#endif // POINT2D_H_INCLUDED
