
add_library(rocketcad_data
    objects/object.h
    objects/tubing_object.cpp
    objects/tubing_object.h
    data.h
    document.cpp
    document.h
    rocket_object.cpp
    rocket_object.h
)
add_library(rocketcad::data ALIAS rocketcad_data)


