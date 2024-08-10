find_package(Doxygen REQUIRED)
if(NOT DOXYGEN_FOUND)
    message(FATAL_ERROR "glit - Cannot build documentation without Doxygen")
endif()

set(GLIT_DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in" "${GLIT_DOXYGEN_OUT}" @ONLY)

add_custom_target(doc ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${GLIT_DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "glit - Generating API documentation with Doxygen"
    VERBATIM
)
