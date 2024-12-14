project(vtc)

set(HEADER_FILES
        LogManager/LogManager.h
)

set(SOURCE_FILES
        LogManager/LogManager.cpp
)

add_library(vtc STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_compile_definitions(vtc PRIVATE DEBUG_MODE)