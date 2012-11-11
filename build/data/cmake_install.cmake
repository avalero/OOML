# Install script for directory: /home/avalero/workspace/OOML/data

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ooml/data/dxf" TYPE FILE FILES
    "/home/avalero/workspace/OOML/data/./dxf/A.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/sm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/xm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/Y.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/T.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/8.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/4.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/lm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/H.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/jm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/V.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/9.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/bm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/P.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/G.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/0.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/J.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/X.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/nm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/3.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/Z.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/C.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/I.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/om.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/&m.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/D.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/M.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/O.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/gm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/im.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/U.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/2.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/mm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/L.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/B.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/am.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/ym.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/Q.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/cm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/N.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/um.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/E.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/vm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/wm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/dm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/qm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/S.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/zm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/pm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/F.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/tm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/R.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/W.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/fm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/6.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/rm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/1.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/7.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/km.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/K.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/&.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/5.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/hm.dxf"
    "/home/avalero/workspace/OOML/data/./dxf/em.dxf"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

