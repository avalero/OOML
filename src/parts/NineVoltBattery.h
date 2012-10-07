#ifndef NINEVOLTBATTERY_H_INCLUDED
#define NINEVOLTBATTERY_H_INCLUDED

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
#include <components/Cube.h>

/**
 * \brief Futaba S3003 Bounding Box
 *
 * This class provides a Futaba S3003 Bounding Box.
 */
class OOMLParts_EXP_DEC NineVoltBattery : public AbstractPart
{
public:
  /**
   * \brief Default constructor.
   */
  NineVoltBattery() :
	 AbstractPart()
  {
    rebuild();
  }
  /**
   * \brief Default destructor.
   */
  virtual ~NineVoltBattery() {}

protected:
  /**
   * \brief Build the piece.
   *
   * This method build the piece from simpler objects.
   *
   * \return The piece built.
   */
  virtual Component build();
};

#endif // NINEVOLT_H_INCLUDED
