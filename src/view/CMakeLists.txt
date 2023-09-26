
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(rocketcad_view
    recents_window/recents_window.cpp
    recents_window/recents_window.h
    recents_window/recents_window.ui
    main.cpp
    rocketcad.qrc
    rocketcad_app.cpp
    rocketcad_app.h
)
target_link_libraries(rocketcad_view PRIVATE Qt5::Widgets)
set_target_properties(rocketcad_view PROPERTIES
    AUTOMOC TRUE
    AUTORCC TRUE
    AUTOUIC TRUE
)

