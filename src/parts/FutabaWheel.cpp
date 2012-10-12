#include <parts/FutabaWheel.h>
#include <components/Cylinder.h>
#include <core/Difference.h>
#include <parts/SimpleWheel.h>
#include <parts/FutabaS3003.h>

Component FutabaWheel::build()
{
    return SimpleWheel(_radius, _thickness, 4.25)
            - FutabaS3003::getCrown(_crownType, 3, true).translate(0, 0, _thickness - 1.5);
}
