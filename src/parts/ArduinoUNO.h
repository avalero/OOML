#ifndef ARDUINOUNO_H_INCLUDED
#define ARDUINOUNO_H_INCLUDED

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

#include <core/AbstractPart.h>

/**
 * \brief Arduino UNO Bounding Box
 *
 * This class provides a Arduino UNO Bounding Box.
 */
class OOMLParts_EXP_DEC ArduinoUNO : public AbstractPart
{
public:
  /**
   * \brief Default constructor.
	* \param fill_drills Draw Holes as cylinders
	* \param holes_height Height of the holes when they are drawn.
	* \param fourth_hole There's a holw without space for a screw. Draw it?
   */
  ArduinoUNO(bool fill_drills = true, double holes_height=5,
				 bool fourth_hole=true) :
		AbstractPart(), _fill_drills(fill_drills), _drills_height(holes_height),
		_fourth_drill(fourth_hole)
  {
    rebuild();
  }
  /**
   * \brief Default destructor.
   */
  virtual ~ArduinoUNO() {}

  /**
	 * \brief returns a component only with the board
	 * \param height Height of the board
	 * \return board bounding box
	 *
	 * \note Create another component for the board only and then use it in this one.
	 */
  static Component getBoard(double height=2, double holes_height=5, bool fill_drills=true, bool fourth_hole=true);

protected:
  /**
   * \brief Build the piece.
   *
   * This method build the piece from simpler objects.
   *
   * \return The piece built.
   */
  virtual Component build();

private:
  bool _fill_drills;
  double _drills_height;
  bool _fourth_drill;
};

#endif // ARDUINOUNO_H_INCLUDED
