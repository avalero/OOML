# Install script for directory: /home/avalero/workspace/OOML/src/core

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Debug")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOOMLCore.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOOMLCore.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOOMLCore.so"
         RPATH "")
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/avalero/workspace/OOML/lib/libOOMLCore.so")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOOMLCore.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOOMLCore.so")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOOMLCore.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ooml/core" TYPE FILE FILES
    "/home/avalero/workspace/OOML/src/core/CubeObject.h"
    "/home/avalero/workspace/OOML/src/core/Difference.h"
    "/home/avalero/workspace/OOML/src/core/Component2D.h"
    "/home/avalero/workspace/OOML/src/core/SphereObject.h"
    "/home/avalero/workspace/OOML/src/core/TransformDecorator.h"
    "/home/avalero/workspace/OOML/src/core/Polyhedron.h"
    "/home/avalero/workspace/OOML/src/core/CylinderObject.h"
    "/home/avalero/workspace/OOML/src/core/AbstractObject.h"
    "/home/avalero/workspace/OOML/src/core/Point3D.h"
    "/home/avalero/workspace/OOML/src/core/SharedPtr.h"
    "/home/avalero/workspace/OOML/src/core/LinearExtrudeDecorator.h"
    "/home/avalero/workspace/OOML/src/core/ColorDecorator.h"
    "/home/avalero/workspace/OOML/src/core/DXFLinearExtrude.h"
    "/home/avalero/workspace/OOML/src/core/ScaleDecorator.h"
    "/home/avalero/workspace/OOML/src/core/AbstractPackage.h"
    "/home/avalero/workspace/OOML/src/core/Math.h"
    "/home/avalero/workspace/OOML/src/core/Matrix.h"
    "/home/avalero/workspace/OOML/src/core/TransformMatrix.h"
    "/home/avalero/workspace/OOML/src/core/Polygon2D.h"
    "/home/avalero/workspace/OOML/src/core/Triangle3D.h"
    "/home/avalero/workspace/OOML/src/core/Imported.h"
    "/home/avalero/workspace/OOML/src/core/globalfunctions.h"
    "/home/avalero/workspace/OOML/src/core/Polygon.h"
    "/home/avalero/workspace/OOML/src/core/ObjectDecorator.h"
    "/home/avalero/workspace/OOML/src/core/MirrorDecorator.h"
    "/home/avalero/workspace/OOML/src/core/Union.h"
    "/home/avalero/workspace/OOML/src/core/RotMatrix.h"
    "/home/avalero/workspace/OOML/src/core/DXFRotateExtrude.h"
    "/home/avalero/workspace/OOML/src/core/MinkowskiDecorator.h"
    "/home/avalero/workspace/OOML/src/core/CompositeObject.h"
    "/home/avalero/workspace/OOML/src/core/AbstractPart.h"
    "/home/avalero/workspace/OOML/src/core/CompositeComponent.h"
    "/home/avalero/workspace/OOML/src/core/Component.h"
    "/home/avalero/workspace/OOML/src/core/Point2D.h"
    "/home/avalero/workspace/OOML/src/core/Hull.h"
    "/home/avalero/workspace/OOML/src/core/RefSys.h"
    "/home/avalero/workspace/OOML/src/core/RotateExtrudeDecorator.h"
    "/home/avalero/workspace/OOML/src/core/Translation.h"
    "/home/avalero/workspace/OOML/src/core/Vector.h"
    "/home/avalero/workspace/OOML/src/core/PointIndexMap.h"
    "/home/avalero/workspace/OOML/src/core/IndentWriter.h"
    "/home/avalero/workspace/OOML/src/core/Intersection.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

