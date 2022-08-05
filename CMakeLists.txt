cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(kdtrace VERSION 0.0.1 LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)
include(FetchContent)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add GoogleTest at configure time for linking unit tests
if(BUILD_TESTING)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
  )
endif()

# Add spdlog at configure time for logging
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.9.1
)

# Add jsoncpp at configure time for configuration input
FetchContent_Declare(
  jsoncpp
  GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
  GIT_TAG        1.9.4		
)

# Compilation options
option(BUILD_PYTHON "Enable building of Python bindings" ON)
option(BUILD_DOCS "Enable building of documentation" ON)

if(BUILD_TESTING)
# Make GTest::gtest etc. available here
  FetchContent_MakeAvailable(googletest)
endif()
FetchContent_MakeAvailable(spdlog)
FetchContent_MakeAvailable(jsoncpp)

# Compile the library
add_subdirectory(src)


# Compile the application
add_subdirectory(app)

# Compile the tests
include(CTest)
if(BUILD_TESTING)
  include(GoogleTest)
  add_subdirectory(tests)
endif()

if(BUILD_DOCS)
  # Add the documentation
  add_subdirectory(doc)
endif()
if(BUILD_PYTHON)
  # Add Python bindings
  add_subdirectory(ext/pybind11)
  
  # Compile the Pybind11 module
  pybind11_add_module(_kdtrace python/kdtrace/_kdtrace.cpp)
  target_link_libraries(_kdtrace PUBLIC kdtrace)

  # Install the Python module shared library
  install(TARGETS _kdtrace DESTINATION .)
endif()

# Add an alias target for use if this project is included as a subproject in another project
add_library(kdtrace::kdtrace ALIAS kdtrace)

# Install targets and configuration
install(
  TARGETS kdtrace
  EXPORT kdtrace-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
  EXPORT kdtrace-config
  NAMESPACE kdtrace::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/kdtrace
)

install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
