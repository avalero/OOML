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

#ifndef INDENTWRITER_H_INCLUDED
#define INDENTWRITER_H_INCLUDED

#ifdef WIN32
#ifdef OOMLCore_EXPORTS
#define OOMLCore_EXP_DEC __declspec(dllexport)
#else
#define OOMLCore_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLCore_EXP_DEC
#endif

#include <iostream>
#include <sstream>
#include <string>

/**
 * \brief Indented output writer.
 *
 * This class provides an interface to write indented outputs.
 */
class OOMLCore_EXP_DEC IndentWriter : public std::ostream
{
public:
	/**
	 * \brief Default constructor.
	 * 
	 * \param indent Indent spaces used for each indentation level.
	 */
	IndentWriter(unsigned int indent=2) :
    std::ostream(&_strbuf),
    _strbuf(indent)
	{
		setf(std::ios::boolalpha);
		setf(std::ios::fixed, std::ios::floatfield);
		precision(3);
	}
	/**
	 * \brief Default destructor.
	 */
	virtual ~IndentWriter() {}

	/**
	 * \brief Indent the output.
	 *
	 * This method indent the output one more level.
	 */
	virtual void indent()	{	_strbuf.indent(); }
	/**
	 * \brief Unindent the output.
	 *
	 * This method unindent the output one more level if possible.
	 */
	virtual void unindent() { _strbuf.unindent(); }

  /**
   * \brief Dumps the output.
   *
   * This method dumps the output constructed so far to the given
   * output stream.
   *
   * \param os The output stream to write to.
   */
  virtual void dump(std::ostream& os) const { _strbuf.dump(os); }

private:
  class OOMLCore_EXP_DEC IndentStringBuf : public std::stringbuf
  {
    public:
      IndentStringBuf(unsigned int indent=2) :
        std::stringbuf(),
        _ostr(),
        _indent(indent),
        _indentLevel(0)
			{}

      /**
       * \brief Indent the output.
       *
       * This method indent the output one more level.
       */
      virtual void indent()	{	_indentLevel++; }
      /**
       * \brief Unindent the output.
       *
       * This method unindent the output one more level if possible.
       */
      virtual void unindent()
      {
        if (_indentLevel)
          _indentLevel--;
      }

			/* Dumps the output.
			 * This method dumps the output constructed so far to the given
			 * output stream.
			 *
			 * \param os The output stream to write to.
			 */
			virtual void dump(std::ostream& os) const { os << _ostr.str(); }

    protected:
      virtual int sync()
      {
        _ostr << std::string(_indent * _indentLevel, ' ') << str();
        str("");
        _ostr.flush();
        return 0;
      }

    private:
      std::ostringstream _ostr; /** Internally host stream instance. */
      unsigned int _indent; /** Indent spaces used for each indentation level. */
      unsigned int _indentLevel; /** Number of levels of indentation. */
  };

	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	IndentWriter(IndentWriter const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	IndentWriter & operator=(IndentWriter const& other);

	IndentStringBuf _strbuf; /** Internally hold stringbuf. */
};

/**
 * \brief Indent block class.
 *
 * This class opens an indent block at creation and exits from it at destruction.
 */
class OOMLCore_EXP_DEC IndentBlock
{
public:
	/**
	 * \brief Default constructor.
	 *
	 * \param writer Writer reference to indent/unindent to.
	 */
	IndentBlock(IndentWriter & writer) :
		_writer(writer)
	{ _writer.indent(); }

	/**
	 * \brief Default destructor.
	 */
	virtual ~IndentBlock() { _writer.unindent(); }

private:
	/**
	 * \brief Default copy constructor.
	 *
	 * \note Disabled to avoid copies.
	 *
	 * \param other Other object to copy from.
	 */
	IndentBlock(IndentBlock const& other);
	/**
	 * \brief Default assignment operator.
	 *
	 * \note Disabled to avoid assignments.
	 *
	 * \param other Other object to assign from.
	 */
	IndentBlock & operator=(IndentBlock const& other);

	IndentWriter & _writer; /** Writer reference. */
};

/**
 * \brief Generate the SCAD code of the writer with insertor syntax.
 *
 * This method inserts in the writer's SCAD code into the stream.
 *
 * \param os The stream to write to.
 * \param writer The writer to write from.
 *
 * \return The parameter stream to allow chained insertions.
 */
OOMLCore_EXP_DEC std::ostream& operator<<(std::ostream & os, IndentWriter const& writer);

#endif // INDENTWRITER_H_INCLUDED
