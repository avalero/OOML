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
