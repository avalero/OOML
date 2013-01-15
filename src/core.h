/**********************************************************************
 *
 * This code is part of the OOML project
 * Authors: Juan Gonzalez-Gomez, Alberto Valero-Gomez, Rafael TreviÒo,
 *          Nieves Cubo, Mario Almagro
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

#ifndef OOML_CORE_H
#define OOML_CORE_H

#include "core/AbstractObject.h"
#include "core/AbstractPackage.h"
#include "core/AbstractPart.h"
#include "core/ColorDecorator.h"
#include "core/Component.h"
#include "core/Component2D.h"
#include "core/CompositeComponent.h"
#include "core/CompositeObject.h"
#include "core/DXFLinearExtrude.h"
#include "core/DXFRotateExtrude.h"
#include "core/Difference.h"
#include "core/Imported.h"
#include "core/IndentWriter.h"
#include "core/Intersection.h"
#include "core/LinearExtrudeDecorator.h"
#include "core/Math.h"
#include "core/Matrix.h"
#include "core/MinkowskiDecorator.h"
#include "core/MirrorDecorator.h"
#include "core/ObjectDecorator.h"
#include "core/Point2D.h"
#include "core/Point3D.h"
#include "core/PointIndexMap.h"
#include "core/Polygon.h"
#include "core/Polygon2D.h"
#include "core/Polyhedron.h"
#include "core/RotateExtrudeDecorator.h"
#include "core/ScaleDecorator.h"
#include "core/SharedPtr.h"
#include "core/Triangle3D.h"
#include "core/Union.h"
#include "core/Vector.h"
#include "core/RefSys.h"
#include "config.h"
#include "core/CubeObject.h"
#include "core/CylinderObject.h"
#include "core/SphereObject.h"
#include "core/RotMatrix.h"
#include "core/globalfunctions.h"
#include "core/TransformDecorator.h"
#include "core/Hull.h"

#endif // OOML_CORE_H
