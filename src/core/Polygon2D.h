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

#ifndef POLYGON2D_H_INCLUDED
#define POLYGON2D_H_INCLUDED

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
#include <core/Component2D.h>
#include <core/IndentWriter.h>
#include <core/Point2D.h>
#include <core/PointIndexMap.h>
#include <core/Polygon.h>
#include <core/SharedPtr.h>

#include <algorithm>
#include <vector>

/**
 * \brief Polygon 2D primitive object
 *
 * This class provides a polygon 2D.
 */
class OOMLCore_EXP_DEC Polygon2D : public AbstractObject
{
public:
	/**
	 * \brief Static factory method.
	 *
	 * Creates a polygon 2D to use in other components.
	 *
	 * \return A polygon 2D component.
	 */
	static Component2D create()
	{
		return Component2D(SharedPtr<AbstractObject>(new Polygon2D()));
	}

	/**
	 * \brief Adds a new point in the polygon 2D.
	 *
	 * Adds the point only if it's not yet present.
	 *
	 * \param point Point2D to insert in the polygon 2D.
	 */
	virtual void addPoint(Point2D const& point)
    {
        //add index only if point is added
        if(_point2DIndexMap.addPoint(point))
            _path.addIndex(_point2DIndexMap.size()-1);

	}

  /** Vector of indexes. */
  typedef std::vector<unsigned int> IndexVector;

	/**
	 * \brief Adds a new path to the polygon after the last.
	 *
	 * \param path Path indexes to be added to the polygon.
	 */
	virtual void setPath(IndexVector const& path)
	{
		_path = IndexedPath::create(path);
	}
	/*
	 * \brief Adds a new path to the polygon 2D after the last.
	 *
	 * \param path Polygon 2D to be added to the polygon.
	 */
	/* \note Disabled until new order
	virtual void setPath(Polygon<Point2D> const& path)
	{
		setPath(IndexedPath::create(path, _point2DIndexMap));
	}
	 */

	/**
	 * \brief Adds a point with insertor syntax.
	 *
	 * This methods adds a point through the insertor interface only if it's not
	 * yet present.
	 *
	 * \param point Point2D to insert in the polygon 2D.
	 */
	virtual Polygon2D & operator<<(Point2D const& point)
	{
    addPoint(point);
		return *this;
	}
	/*
	 * \brief Adds a path with insertor syntax.
	 *
	 * This methods adds a path through the insertor interface.
	 *
	 * \param path Polygon to be added to the polygon.
	 */
  /* \note Disabled until new order
	virtual Polygon2D & operator<<(Polygon<Point2D> const& path)
	{
		addPath(path);
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
	class OOMLCore_EXP_DEC IndexedPath : public AbstractObject
	{
		public:
			/**
			 * \brief Default factory method.
			 *
			 * \param path Polygon 2D to be converted.
			 * \param point2DIndexMap point2DIndexMap used for the conversion.
			 *
			 * \return an IndexedPath indexed by the indexMap of the path.
			 */
			static IndexedPath create(Polygon<Point2D> const& path, PointIndexMap<Point2D> & point2DIndexMap)
			{
				IndexVector v;
				for (Polygon<Point2D>::PointVector::const_iterator it = path.getPoints().begin(); it != path.getPoints().end(); ++it)
				{
					point2DIndexMap.addPoint(*it);
					v.push_back(point2DIndexMap.getIndex(*it));
				}
				return IndexedPath(v);
			}

			/**
			 * \brief Default referenced constructor.
			 *
			 * \param path Path indexes to be converted.
			 *
			 * \return an IndexedPath indexed by the indexMap of the path.
			 */
			static IndexedPath create(IndexVector const& path)
			{
				return IndexedPath(path);
			}

			/**
			 * \brief Default copy constructor.
			 *
			 * \param other Other object to copy from.
			 */
			IndexedPath(IndexedPath const& other) :
				AbstractObject(),
        _v(other._v)
			{}
			/**
			 * \brief Default assignment operator.
			 *
			 * \param other Other object to assign from.
			 */
			IndexedPath & operator=(IndexedPath const& other)
			{
        _v = other._v;
				return *this;
			}
			/**
			 * \brief Default destructor.
			 */
			virtual ~IndexedPath() {}

      /**
       * \brief Adds an index to the path.
       *
       * Adds a new index to the path.
       *
       * \param index New index to add.
       */
      void addIndex(unsigned int index)
      {
        _v.push_back(index);
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
			 * \brief Default vector constructor
			 *
			 * \param v Index vector of the path.
			 */
			IndexedPath(IndexVector const& v) :
				AbstractObject(),
        _v(v)
			{}

		private:
      IndexVector _v; /** Path indexes. */
	};

	/**
	 * \brief Default constructor.
	 */
	Polygon2D() :
		AbstractObject(),
		_point2DIndexMap(),
		_path(IndexedPath::create(IndexVector()))
	{}
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
	Polygon2D(Polygon2D const& other) :
		AbstractObject(),
		_point2DIndexMap(other.getPoint2DIndexMap()),
		_path(other.getPath())
	{}
	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other object to assign from.
	 */
	Polygon2D & operator=(Polygon2D const& other)
	{
		_point2DIndexMap = other.getPoint2DIndexMap();
		_path = other.getPath();

		return *this;
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Polygon2D() {}

	/**
	 * \brief Get the point index map.
	 *
	 * \return the point to index map.
	 */
	PointIndexMap<Point2D> const& getPoint2DIndexMap() const { return _point2DIndexMap; }

	/**
	 * \brief Get the polygon paths.
	 *
	 * \return the paths the polygon is made of.
	 */
	IndexedPath const& getPath() const { return _path; }

	PointIndexMap<Point2D> _point2DIndexMap; /** Points to indexes map. */
	IndexedPath _path; /** Paths of the polygon. */
};

#endif // POLYGON2D_H_INCLUDED
