
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(rocketcad_view
    workbench_window/viewport_widget.cpp
    workbench_window/viewport_widget.h
    workbench_window/workbench_window.cpp
    workbench_window/workbench_window.h
    workbench_window/workbench_window.ui
    recents_window/recents_window.cpp
    recents_window/recents_window.h
    recents_window/recents_window.ui
    app.cpp
    app.h
    main.cpp
    rocketcad.qrc
)
target_link_libraries(rocketcad_view PRIVATE Qt5::Widgets glm rocketcad::data)
set_target_properties(rocketcad_view PROPERTIES
    AUTOMOC TRUE
    AUTORCC TRUE
    AUTOUIC TRUE
)

