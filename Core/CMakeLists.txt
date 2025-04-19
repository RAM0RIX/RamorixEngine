file(GLOB_RECURSE CORE_SOURCES "src/rmx/*.cpp" "src/rmx/Events/*.cpp")
file(GLOB_RECURSE CORE_HEADERS "include/.*h" "include/rmx/*.h" "include/rmx/Events/*.h")

add_library(RamorixEngineCore SHARED ${CORE_SOURCES} ${CORE_HEADERS})

target_link_libraries(RamorixEngineCore PRIVATE spdlog::spdlog)

target_include_directories(RamorixEngineCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_precompile_headers(RamorixEngineCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/rmxpch.h)

if(PLATFORM_WINDOWS)
    target_compile_definitions(RamorixEngineCore PRIVATE "RMX_BUILD_DLL"
)
elseif(PLATFORM_LINUX)
endif()

if(MSVC)
    target_compile_options(RamorixEngineCore PRIVATE
        /W4 /permissive- /utf-8
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(RamorixEngineCore PRIVATE
        -Wall -Wextra -finput-charset=utf-8
)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(RamorixEngineCore PRIVATE
        -Weverything -finput-charset=utf-8
)
endif()


set_target_properties(RamorixEngineCore PROPERTIES FOLDER "Core")
assign_source_groups(RamorixEngineCore)

target_compile_definitions(RamorixEngineCore PRIVATE
    $<$<CONFIG:Debug>:RMX_DEBUG=1>
    $<$<CONFIG:Release>:RMX_RELEASE=1>
    $<$<CONFIG:RelWithDebInfo>:RMX_RELEASE=1>
    $<$<CONFIG:MinSizeRel>:RMX_DIST=1>
)

install(TARGETS RamorixEngineCore
	RUNTIME DESTINATION C:/dev/DLLS)
