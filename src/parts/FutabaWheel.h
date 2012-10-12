#ifndef FUTABAWHEEL_H_INCLUDED
#define FUTABAWHEEL_H_INCLUDED

#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

#include <parts/SimpleWheel.h>

/**
 * \brief Futaba wheel primitive object
 *
 * This class provides a futaba wheel.
 */
class OOMLParts_EXP_DEC FutabaWheel : public SimpleWheel
{
public:
        /**
         * \brief Default constructor.
         */
        FutabaWheel() :
                _radius(12.75),
                _thickness(5),
                _crownType(0)
        {
                rebuild();
        }
        /**
         * \brief Default parametrized constructor.
         *
         * \param futabaRadius Futaba piece radius.
         * \param futabaThickness Futaba piece thickness.
         * \param crownType There are three types of crown.
         */
        FutabaWheel(double radius, double thickness, int crownType) :
                 _radius(radius),
                 _thickness(thickness),
                 _crownType(crownType)
        {
                if (_crownType < 0 || _crownType > 2)
                        _crownType = 0;
                if (_radius < 12.75 && _crownType == 0)
                        _radius = 12.75;
                if (_radius < 22 && _crownType == 1)
                        _radius = 22;
                if (_radius < 18.4 && _crownType == 2)
                        _radius = 18.4;
                if (_thickness < 5)
                        _thickness = 5;
    rebuild();
        }
        /**
         * \brief Default destructor.
         */
        virtual ~FutabaWheel() {}

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
        double _radius; /** Radius. */
        double _thickness; /** Thickness. */
        double _crownType; /** Type of crown. */
};

#endif // FUTABAWHEEL_H_INCLUDED
