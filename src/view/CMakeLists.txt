
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(rocketcad_view
    workbench_window/render/render.h
    workbench_window/render/render_exception.h
    workbench_window/render/renderer.cpp
    workbench_window/render/renderer.h
    workbench_window/explorer_item_model.cpp
    workbench_window/explorer_item_model.h
    workbench_window/property_table_model.cpp
    workbench_window/property_table_model.h
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
target_link_libraries(rocketcad_view PRIVATE Qt5::Widgets glm GLEW OpenGL::GL rocketcad::data)
set_target_properties(rocketcad_view PROPERTIES
    AUTOMOC TRUE
    AUTORCC TRUE
    AUTOUIC TRUE
)

