# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.
cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.
project("blaster")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(${CMAKE_C_FLAGS}, "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wall -Werror")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")
set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../libs)

#add_library(png_lib STATIC IMPORTED)
#set_target_properties(png_lib PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/lib_png/obj/${ANDROID_ABI}/libpng.a)
add_library(native_app_glue STATIC ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)
add_library(png STATIC ${distribution_DIR}/lib_png/include/pnglibconf.h)

add_library(
        # Sets the name of the library.
        blaster

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        EventLoop.cpp
        EventLoop.hpp
        Log.cpp
        Log.hpp
        Main.cpp
        Types.hpp
        ActivityHandler.hpp
        DroidBlaster.cpp
        DroidBlaster.hpp
        GraphicsManager.cpp
        GraphicsManager.hpp
        Ship.cpp
        Ship.hpp
        Asteroid.cpp
        Asteroid.hpp
        PhysicsManager.cpp
        PhysicsManager.hpp
        TimeManager.cpp
        TimeManager.hpp
        Resource.cpp
        Resource.hpp
)

target_include_directories(blaster PRIVATE ${ANDROID_NDK}/sources/android/native_app_glue)
target_include_directories(blaster PRIVATE ${distribution_DIR}/lib_png/include)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
find_library(
        # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log
)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries(
        # Specifies the target library.
        blaster

        android
        native_app_glue
        png_lib
        EGL
        # GLESv1_CM
        GLESv2

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
)
