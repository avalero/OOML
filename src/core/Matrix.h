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

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

//#include <core/AbstractObject.h>
//#include <core/IndentWriter.h>

#include <algorithm>
#include <vector>
#include <iostream>

/**
 * \brief Generic matrix primitive object
 *
 * This class provides a generic matrix.
 */
template <typename T, int ROWS, int COLUMNS>
class OOMLCore_EXP_DEC Matrix
{
public:
	/** Definition of a vector of elements. row by row. */
	typedef std::vector<T> ElementsVector;

	/**
	 * \brief Default constructor.
	 */
	Matrix() :
        _elements(),
        _rows(ROWS),_cols(COLUMNS)
	{
        _elements.resize(ROWS * COLUMNS);
		for (unsigned int i=0; i < ROWS * COLUMNS; ++i)
			_elements[i] = 0.0;
	}
	/**
	 * \brief Default parametrized constructor.
	 *
	 * \param elements Matrix elements. row by row.
	 */
  Matrix(ElementsVector const& elements) :
    _elements(elements),
    _rows(ROWS),_cols(COLUMNS)
  {
      if (elements.size()!=_rows*_cols){
          std::cerr << "Size of vector incorrect" << std::endl;
      }
  }
	/**
	 * \brief Default copy constructor.
	 *
	 * \param other Other object to copy from.
	 */
	Matrix(Matrix const& other) :
        _elements(other._elements),
        _rows(other._rows),_cols(other._cols)
	{}
	/**
	 * \brief Default assignment operator.
	 *
	 * \param other Other object to assign from.
	 */
	Matrix & operator=(Matrix const& other)
	{
        if (other._rows == _rows && other._cols == _cols){
            _elements = other._elements;
        }else{
            std::cerr << "Matrix are of different sizes" << std::endl;
        }

		return *this;
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~Matrix() {}

	/**
	 * \brief Matrix add operator.
   *
   * This method adds elements in the resulting matrix.
	 *
	 * \param matrix Matrix to be added to the Matrix.
	 */
	virtual Matrix & operator+(Matrix<T, ROWS, COLUMNS> const& matrix)
	{
        if (matrix._rows == _rows && matrix._cols == _cols){
            for (int i=0; i<_elements.size();i++)
                _elements[i] += matrix._elements[i];
        }else{
            std::cerr << "Matrix are of different sizes" << std::endl;
        }

		return *this;
	}
	/**
	 * \brief Matrix sub operator.
   *
   * This method subs elements in the resulting matrix.
	 *
	 * \param matrix Matrix to be substracted to the Matrix.
	 */
    virtual Matrix & operator-(Matrix<T, ROWS, COLUMNS> const& matrix)
    {
        if (matrix._rows == _rows && matrix._cols == _cols){
            for (int i=0; i<_elements.size();i++)
                _elements[i] -= matrix._elements[i];
        }else{
            std::cerr << "Matrix are of different sizes" << std::endl;
        }

        return *this;
    }

    T get(unsigned int row, unsigned int col) const {
        if (row <= _rows  && col <= _cols && row > 0 && col > 0)
            return _elements[(row-1)*_cols + (col-1)];
        else{
            std::cerr << "Wrong Matrix Index (" <<row<<","<<col<<")" << std::endl;
            return (T)NULL;
        }
    }

    void set(int row, int col, T value){
        if (row <= _rows  && col <= _cols && row > 0 && col > 0)
            _elements[(row-1)*_cols + (col-1)]=value;
        else
            std::cerr << "Wrong Matrix Index (" <<row<<","<<col<<")" << std::endl;
    }

protected:
	ElementsVector _elements; /** Matrix elements. row by row. */
    unsigned int _rows,_cols;
};

#endif // MATRIX_H_INCLUDED
