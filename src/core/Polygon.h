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

#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

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
#include <core/Component.h>
#include <core/IndentWriter.h>
#include <core/Point3D.h>

#include <algorithm>
#include <vector>

/**
 * \brief Generic polygon primitive object
 *
 * This class provides a generic polygon.
 */
template <typename T>
class Polygon : public AbstractObject
{
public:
	/**
	 * \brief Default constructor.
	 */
	Polygon() :
		AbstractObject(),
		_points()
	{}
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
	Polygon(Polygon const& other) :
		AbstractObject(),
		_points(other.getPoints())
	{}
	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other object to assign from.
	 */
	Polygon & operator=(Polygon const& other)
	{
		_points = other.getPoints();
		return *this;
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Polygon() {}

	/**
	 * \brief Adds a new point to the polygon after the last.
	 *
	 * \param point Point to be added to the polygon.
	 */
	virtual void addPoint(T const& point)
	{
		_points.push_back(point);
	}
	/**
	 * \brief Removes a point from the polygon.
	 *
	 * This method removes a point from the polygon.
	 *
	 * \param point Point to be removed.
	 */
	virtual void removePoint(T const& point)
	{
		_points.erase(std::remove(_points.begin(), _points.end(), point), _points.end());
	}

	/**
	 * \brief Adds a point with insertor syntax.
	 *
	 * This methods adds a point through the insertor interface.
	 *
	 * \param point Point to be added to the polygon.
	 */
	virtual Polygon & operator<<(T const& point)
	{
		addPoint(point);
		return *this;
	}

  /** A vector of points. */
	typedef std::vector<T> PointVector;

	/**
	 * \brief Get the polygon points.
	 *
	 * \returns the points the polygon is made of.
	 */
	PointVector const& getPoints() const { return _points; }

	/**
	 * \brief Close the polygon.
	 *
	 * This method will add the first point added at the end of the point
	 * list, closing the polygon.
	 */
	virtual void close()
	{
		addPoint(_points[0]);
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
	PointVector _points; /** Points of the polygon. */
};

template <typename T>
void Polygon<T>::genScad(IndentWriter& writer) const
{
	writer << "[";
	for (typename PointVector::const_iterator it = _points.begin();
		it != _points.end(); ++it)
		it->genScad(writer);
	writer << "]";
}

template <typename T>
void Polygon<T>::printAst(IndentWriter& writer) const
{
	writer << "[";
	for (typename PointVector::const_iterator it = _points.begin();
		it != _points.end(); ++it)
		it->printAst(writer);
	writer << "]";
}

#endif // POLYGON_H_INCLUDED
