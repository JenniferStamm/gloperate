# Generate meta-header
configure_file(gloperate-version.h.in ${CMAKE_CURRENT_BINARY_DIR}/gloperate-version.h)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Libraries
set(IDE_FOLDER "")
add_subdirectory(gloperate)
add_subdirectory(gloperate-qt)
add_subdirectory(gloperate-glfw)
add_subdirectory(gloperate-osg)
add_subdirectory(gloperate-qtwidgets)

# Examples
set(IDE_FOLDER "Examples")
add_subdirectory(examples)

# Tests
set(IDE_FOLDER "Tests")
add_subdirectory(tests)
