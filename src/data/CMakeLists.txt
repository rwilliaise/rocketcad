
add_library(rocketcad_data
    objects/object.h
    objects/tubing_object.h
    data.h
    document.cpp
    document.h
    rocket_object.cpp
    rocket_object.h
)
target_link_libraries(rocketcad_data PRIVATE simdjson_static)
add_library(rocketcad::data ALIAS rocketcad_data)


