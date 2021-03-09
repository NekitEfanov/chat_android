cmake_minimum_required(VERSION 3.5)

project(chat_android LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Core Gui Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Gui Network REQUIRED)

set( INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include )
set( SRC_DIR ${CMAKE_SOURCE_DIR}/src )
set( FORMS_DIR ${CMAKE_SOURCE_DIR}/src )

include_directories( ${INCLUDE_DIR} )

file( GLOB HEADERS "${INCLUDE_DIR}/*.h" "${INCLUDE_DIR}/*.hpp" )
file( GLOB SOURCES "${SRC_DIR}/*.c" "${SRC_DIR}/*.cpp" )
file( GLOB FORMS "${FORMS_DIR}/*.ui" )

set( PROJECT_SOURCES res.qrc ${SOURCES} ${HEADERS} ${FORMS} )

source_group("ui" FILES ${FORMS})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(chat_android
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(chat_android SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(chat_android
            ${PROJECT_SOURCES}
        )
    endif()
endif()


target_link_libraries(chat_android PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)
