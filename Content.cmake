
include(FetchContent)

set(SIMDJSON_BUILD_STATIC_LIB TRUE)

fetchcontent_declare(
    simdjson
    GIT_REPOSITORY https://github.com/simdjson/simdjson.git
    GIT_TAG v3.3.0
)

fetchcontent_declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0.9.9.8
    FIND_PACKAGE_ARGS NAMES glm
)

fetchcontent_makeavailable(simdjson glm)

