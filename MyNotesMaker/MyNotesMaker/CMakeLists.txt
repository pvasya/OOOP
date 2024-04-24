cmake_minimum_required(VERSION 3.5)

project(MyNotesMaker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qt6 REQUIRED COMPONENTS Test)
find_package(Qt6 REQUIRED COMPONENTS PrintSupport)
find_package(Qt6 REQUIRED COMPONENTS StateMachine)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MyNotesMaker
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res.qrc
        style.h style.cpp
        tests/test_styles.h tests/test_styles.cpp
        frameless.h frameless.cpp
        tests/test_frameless.h tests/test_frameless.cpp
        QSidePanel/math.cpp
        QSidePanel/math.hpp
        QSidePanel/PanelBottomSide.cpp
        QSidePanel/PanelBottomSide.hpp
        QSidePanel/PanelLeftSide.cpp
        QSidePanel/PanelLeftSide.hpp
        QSidePanel/PanelRightSide.cpp
        QSidePanel/PanelRightSide.hpp
        QSidePanel/PanelTopSide.cpp
        QSidePanel/PanelTopSide.hpp
        QSidePanel/side_panel_helpers.cpp
        QSidePanel/side_panel_helpers.hpp
        QSidePanel/SidePanel.cpp
        QSidePanel/SidePanel.hpp
        QSidePanel/SidePanelState.cpp
        QSidePanel/SidePanelState.hpp
        searchwidget.h searchwidget.cpp searchwidget.ui
        settingswidget.h settingswidget.cpp settingswidget.ui
        ParticleLife/particlelifewidget.h ParticleLife/particlelifewidget.cpp ParticleLife/particlelifewidget.ui
        FormattingCommand/command.h
        FormattingCommand/bold.h FormattingCommand/bold.cpp
        FormattingCommand/italic.h FormattingCommand/italic.cpp
        FormattingCommand/underline.h FormattingCommand/underline.cpp
        FormattingCommand/color.h FormattingCommand/color.cpp
        FormattingCommand/backgroundcolor.h FormattingCommand/backgroundcolor.cpp
        FormattingCommand/invoker.h FormattingCommand/invoker.cpp
        ExportStrategy/export.h
        ExportStrategy/pdf.h ExportStrategy/pdf.cpp
        ExportStrategy/html.h ExportStrategy/html.cpp
        ExportStrategy/exportcontext.h ExportStrategy/exportcontext.cpp
        FormattingCommand/formatcommandsenum.h
        FormattingCommand/formatter.h FormattingCommand/formatter.cpp
        ParticleLife/particle.h ParticleLife/particle.cpp
        ParticleLife/particlefactorymethod.h ParticleLife/particlefactorymethod.cpp
        ParticleLife/particleworker.h ParticleLife/particleworker.cpp
        ParticleLife/customscene.h ParticleLife/customscene.cpp
        ParticleLife/movetomouseworker.h ParticleLife/movetomouseworker.cpp
        note.h note.cpp
        notemanager.h notemanager.cpp
        realnotemanager.h realnotemanager.cpp
        proxynotemanager.h proxynotemanager.cpp



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MyNotesMaker APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MyNotesMaker SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MyNotesMaker
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MyNotesMaker PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MyNotesMaker PRIVATE Qt6::Test)
target_link_libraries(MyNotesMaker PRIVATE Qt6::PrintSupport)
target_link_libraries(MyNotesMaker PRIVATE Qt6::StateMachine)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MyNotesMaker)
endif()
set_target_properties(MyNotesMaker PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MyNotesMaker
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MyNotesMaker)
endif()
