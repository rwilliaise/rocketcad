
include(FetchContent)

fetchcontent_declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0.9.9.8
    FIND_PACKAGE_ARGS NAMES glm
)

fetchcontent_declare(
    GLEW
    GIT_REPOSITORY https://github.com/nigels-com/glew.git
    GIT_TAG glew-2.2.0
    FIND_PACKAGE_ARGS NAMES GLEW
)

fetchcontent_makeavailable(glm GLEW)

