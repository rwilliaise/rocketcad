
add_library(rocketcad_data
    objects/nose_cone_object.cpp
    objects/nose_cone_object.h
    objects/object.h
    objects/tubing_object.cpp
    objects/tubing_object.h
    data.h
    document.cpp
    document.h
    rocket_object.cpp
    rocket_object.h
)
target_link_libraries(rocketcad_data PRIVATE simdjson_static)
add_library(rocketcad::data ALIAS rocketcad_data)


