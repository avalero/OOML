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

#ifndef POINTINDEXMAP_H_INCLUDED
#define POINTINDEXMAP_H_INCLUDED

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

#include <unordered_map>
#include <vector>

/**
 * \brief Point to index map.
 *
 * This class provides a mapping between points and their index value.
 */
template <typename T>
class PointIndexMap : public AbstractObject
{
public:
  /**
   * \brief Default constructor.
   */
  PointIndexMap() :
    AbstractObject(),
    _vector(),
    _map()
  {}
  /**
   * \brief Default copy constructor.
   *
   * \param other Other object to copy from.
   */
  PointIndexMap(PointIndexMap const& other) :
    AbstractObject(),
    _vector(other._vector),
    _map(other._map)
  {}
  /**
   * \brief Default assignment operator.
   *
   * \param other Other object to assign from.
   */
  PointIndexMap & operator=(PointIndexMap const& other)
  {
    _vector = other._vector;
    _map = other._map;

    return *this;
  }
  /**
   * \brief Default destructor.
   */
  virtual ~PointIndexMap() {}

  /**
   * \brief Adds a new point in the map.
   *
   * Adds the point only if it's not yet present. Asigning it a
   * unique increasing index number.
   *
   * \param point Point to insert in the map.
   */
  bool addPoint(T const& point)
  {
    typename Map::iterator it = _map.find(point);
    /** Add point if it doesn't already exist. */
    if (it == _map.end())
    {
      _map.insert(typename Map::value_type(point, _vector.size()));
      _vector.push_back(typename Vector::value_type(point));
      return true;
    }
    return false;
  }

  /**
   * \brief Adds a point with insertor syntax.
   *
   * This methods adds a point through the insertor interface.
   *
   * \param point Point to be added to the map.
   */
  virtual PointIndexMap & operator<<(T const& point)
  {
    addPoint(point);
    return *this;
  }

  /**
   * \brief Return the assigned index to the given point.
   *
   * This method returns the internally assigned index to the point given.
   *
   * \param point Point to get the index.
   *
   * \return the index assigned to the point.
   */
  unsigned int getIndex(T const& point)
  {
    return _map[point];
  }

  /**
   * \brief Get the map size.
   *
   * Get the size of the map.
   *
   * \return the size of the map.
   */
  inline unsigned int size() { return _vector.size(); }

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
  typedef std::vector<T> Vector; /** A vector of points. */
  typedef std::unordered_map<T, unsigned int, std::hash<T>, std::equal_to<T>> Map;
      /** A map from points to its point index. */

  Vector _vector; /** Vector of points inside the index. */
  Map _map; /** Map of conversion from points to indexes. */
};

template <typename T>
void PointIndexMap<T>::genScad(IndentWriter& writer) const
{
	const char *comma = "";

	writer << "[";
	for (typename Vector::const_iterator it = _vector.begin();
	     it != _vector.end(); ++it )
	{
		writer << comma;
		it->genScad(writer);
		comma = ", ";
	}
	writer << "]";
}

template <typename T>
void PointIndexMap<T>::printAst(IndentWriter& writer) const
{
	const char *comma = "";

	writer << "[";
	for (typename Vector::const_iterator it = _vector.begin();
	     it != _vector.end(); ++it )
	{
		writer << comma;
		it->printAst(writer);
		comma = ", ";
	}
	writer << "]";
}

#endif // POINTINDEXMAP_H_INCLUDED
