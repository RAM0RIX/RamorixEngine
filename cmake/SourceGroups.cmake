# cmake/SourceGroups.cmake
function(assign_source_groups TARGET_NAME)
    get_target_property(SOURCES ${TARGET_NAME} SOURCES)
    foreach(SRC ${SOURCES})
        get_filename_component(SRC_PATH "${SRC}" PATH)
        file(RELATIVE_PATH REL_PATH "${CMAKE_SOURCE_DIR}" "${SRC_PATH}")
        string(REPLACE "/" "\\" GROUP "${REL_PATH}")
        source_group("${GROUP}" FILES "${SRC}")
    endforeach()
endfunction()

