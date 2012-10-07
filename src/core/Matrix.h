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
            std::cerr << "Matrix are of differente sizes" << std::endl;
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
