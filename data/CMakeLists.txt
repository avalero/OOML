cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

file(GLOB DXFS "./dxf/*.dxf")
install(FILES ${DXFS} DESTINATION include/ooml/data/dxf)
