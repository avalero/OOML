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

#ifndef POLYHEDRON_H_INCLUDED
#define POLYHEDRON_H_INCLUDED

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
#include <core/PointIndexMap.h>
#include <core/SharedPtr.h>
#include <core/Triangle3D.h>

#include <algorithm>
#include <map>
#include <vector>

/**
 * \brief Polyhedron primitive object
 *
 * This class provides a polyhedron.
 */
class OOMLCore_EXP_DEC Polyhedron : public AbstractObject
{
public:
	/**
	 * \brief Static factory method.
	 *
	 * Creates a polyhedron to use in other components.
	 *
	 * \return A polyhedron component.
	 */
	static Component create()
	{
		return Component(SharedPtr<AbstractObject>(new Polyhedron()));
	}

	/**
	 * \brief Adds a new point in the polyhedron.
	 *
	 * Adds the point only if it's not yet present.
	 *
	 * \param point Point3D to insert in the polyhedron.
	 */
	virtual void addPoint(Point3D const& point)
	{
		_point3DIndexMap.addPoint(point);
	}
	/**
	 * \brief Adds a new triangle to the polygon after the last.
	 *
   * \param p Triangle first point index.
   * \param q Triangle second point index.
   * \param r Triangle third point index.
	 */
	virtual void addTriangle(unsigned int p, unsigned int q, unsigned int r)
	{
		_triangles.push_back(IndexedTriangle3D::create(p, q, r));
	}
	/*
	 * \brief Adds a new triangle to the polygon after the last.
	 *
	 * \param triangle Triangle to be added to the polygon.
	 */
	/* \note Disabled until new order
	virtual void addTriangle(Triangle3D const& triangle)
	{
		addTriangle(IndexedTriangle3D::create(triangle, _point3DIndexMap));
	}
	 */
	/*
	 * \brief Removes a triangle from the polyhedron.
	 *
	 * This method removes a triangle from the polyhedron.
	 *
	 * \param triangle Triangle to be removed.
	 */
	/* \note Disabled until new order.
	virtual void removeTriangle(Triangle3D const& triangle)
	{
		_triangles.erase(std::remove(_triangles.begin(), _triangles.end(), triangle), _triangles.end());
	}
	 */

	/**
	 * \brief Adds a point with insertor syntax.
	 *
	 * This methods adds a point through the insertor interface only if it's not
	 * yet present.
	 *
	 * \param point Point3D to insert in the polyhedron.
	 */
	virtual Polyhedron & operator<<(Point3D const& point)
	{
		_point3DIndexMap << point;
		return *this;
	}
	/*
	 * \brief Adds a triangle with insertor syntax.
	 *
	 * This methods adds a triangle through the insertor interface.
	 *
	 * \param triangle Triangle to be added to the polygon.
	 */
	/* \note Disabled until new order
	virtual Polyhedron & operator<<(Triangle3D const& triangle)
	{
		addTriangle(triangle);
		return *this;
	}
	 */

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
	class OOMLCore_EXP_DEC IndexedTriangle3D : public AbstractObject
	{
		public:
			/**
			 * \brief Default factory method.
			 *
			 * \param triangle Triangle3D to be converted.
			 * \param point3DIndexMap Point3DIndexMap used for the conversion.
			 *
			 * \return an IndexedTriangle3D indexed by the indexMap of the triangle.
			 */
			static IndexedTriangle3D create(Triangle3D const& triangle, PointIndexMap<Point3D> & point3DIndexMap)
			{
				IndexVector v;
				for (Triangle3D::PointVector::const_iterator it = triangle.getPoints().begin(); it != triangle.getPoints().end(); ++it)
				{
					point3DIndexMap.addPoint(*it);
					v.push_back(point3DIndexMap.getIndex(*it));
				}
				return IndexedTriangle3D(v);
			}

			/**
			 * \brief Default referenced constructor.
			 *
			 * \param p First point of the triangle.
			 * \param q Second point of the triangle.
			 * \param r Third point of the triangle.
			 *
			 * \return an IndexedTriangle3D indexed by the indexMap of the triangle.
			 */
			static IndexedTriangle3D create(unsigned int p, unsigned int q, unsigned int r)
			{
				return IndexedTriangle3D(p, q, r);
			}

			/**
			 * \brief Default copy constructor.
			 *
			 * \param other Other object to copy from.
			 */
			IndexedTriangle3D(IndexedTriangle3D const& other) :
				AbstractObject(),
				_p(other._p),
				_q(other._q),
				_r(other._r)
			{}
			/**
			 * \brief Default assignment operator.
			 *
			 * \param other Other object to assign from.
			 */
			IndexedTriangle3D & operator=(IndexedTriangle3D const& other)
			{
				_p = other._p;
				_q = other._q;
				_r = other._r;

				return *this;
			}
			/**
			 * \brief Default destructor.
			 */
			virtual ~IndexedTriangle3D() {}

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
			 * \brief Default referenced constructor.
			 *
			 * \param p First point of the triangle.
			 * \param q Second point of the triangle.
			 * \param r Third point of the triangle.
			 */
			IndexedTriangle3D(unsigned int p, unsigned int q, unsigned int r) :
				AbstractObject(),
				_p(p),
				_q(q),
				_r(r)
			{}

			typedef std::vector<unsigned int> IndexVector; /** Vector of indexes. */

			/**
			 * \brief Default vector constructor
			 *
			 * \param v Index vector of the triangle.
			 */
			IndexedTriangle3D(IndexVector const& v) :
				AbstractObject(),
				_p(v[0]),
				_q(v[1]),
				_r(v[2])
			{}

		private:
			unsigned int _p; /** Triangle x index */
			unsigned int _q; /** Triangle y index */
			unsigned int _r; /** Triangle z index */
	};

	/**
	 * \brief Default constructor.
	 */
	Polyhedron() :
		AbstractObject(),
		_point3DIndexMap(),
		_triangles()
	{}
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
	Polyhedron(Polyhedron const& other) :
		AbstractObject(),
		_point3DIndexMap(other.getPoint3DIndexMap()),
		_triangles(other.getTriangles())
	{}
	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other object to assign from.
	 */
	Polyhedron & operator=(Polyhedron const& other)
	{
		_point3DIndexMap = other.getPoint3DIndexMap();
		_triangles = other.getTriangles();

		return *this;
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Polyhedron() {}

	/**
	 * \brief Get the point index map.
	 *
	 * \return the point to index map.
	 */
	PointIndexMap<Point3D> const& getPoint3DIndexMap() const { return _point3DIndexMap; }

	typedef std::vector<IndexedTriangle3D> Triangle3DVector; /** A vector of 3D triangles. */

	/**
	 * \brief Get the polygon triangles.
	 *
	 * \return the triangles the polygon is made of.
	 */
	Triangle3DVector const& getTriangles() const { return _triangles; }

	PointIndexMap<Point3D> _point3DIndexMap; /** Points to indexes map. */
	Triangle3DVector _triangles; /** Triangles of the polygon. */
};

#endif // POLYHEDRON_H_INCLUDED
