file(GLOB_RECURSE CLIENT_SOURCES "src/*.cpp")

add_executable(RamorixEngineClient ${CLIENT_SOURCES})

if(PLATFORM_WINDOWS)
elseif(PLATFORM_LINUX)
endif()

if(MSVC)
    target_compile_options(RamorixEngineClient PRIVATE
        /W4 /permissive- /utf-8
    )
    target_link_options(RamorixEngineClient PRIVATE
        /SUBSYSTEM:WINDOWS
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(RamorixEngineClient PRIVATE
        -Wall -Wextra -finput-charset=utf-8
)
    target_link_options(RamorixEngineClient PRIVATE
        -mwindows
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(RamorixEngineClient PRIVATE
        -Weverything -finput-charset=utf-8
)
    target_link_options(RamorixEngineClient PRIVATE
        -mwindows
    )
endif()

target_link_libraries(RamorixEngineClient PRIVATE RamorixEngineCore)

target_include_directories(RamorixEngineClient PRIVATE "${CMAKE_SOURCE_DIR}/Core/include" "${CMAKE_SOURCE_DIR}/libs/spdlog/include")

set_target_properties(RamorixEngineClient PROPERTIES FOLDER "Client")
assign_source_groups(RamorixEngineClient)

target_compile_definitions(RamorixEngineClient PRIVATE
    $<$<CONFIG:Debug>:RMX_DEBUG=1>
    $<$<CONFIG:Release>:RMX_RELEASE=1>
    $<$<CONFIG:RelWithDebInfo>:RMX_RELEASE=1>
    $<$<CONFIG:MinSizeRel>:RMX_DIST=1>
)

add_custom_command(TARGET RamorixEngineClient POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_BINARY_DIR}/Core/$<CONFIGURATION>/RamorixEngineCore.dll"
        $<TARGET_FILE_DIR:RamorixEngineClient>)
