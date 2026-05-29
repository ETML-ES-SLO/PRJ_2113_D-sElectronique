include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(2113_DeElectronique_V3_default_library_list )

# Handle files with suffix s, for group default-XC32_15
if(2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_assemble)
add_library(A_2113_DeElectronique_V3_default_default_XC32_15_assemble OBJECT ${2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_assemble})
    A_2113_DeElectronique_V3_default_default_XC32_15_assemble_rule(A_2113_DeElectronique_V3_default_default_XC32_15_assemble)
    list(APPEND 2113_DeElectronique_V3_default_library_list "$<TARGET_OBJECTS:A_2113_DeElectronique_V3_default_default_XC32_15_assemble>")
endif()

# Handle files with suffix S, for group default-XC32_15
if(2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_assembleWithPreprocess)
add_library(A_2113_DeElectronique_V3_default_default_XC32_15_assembleWithPreprocess OBJECT ${2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_assembleWithPreprocess})
    A_2113_DeElectronique_V3_default_default_XC32_15_assembleWithPreprocess_rule(A_2113_DeElectronique_V3_default_default_XC32_15_assembleWithPreprocess)
    list(APPEND 2113_DeElectronique_V3_default_library_list "$<TARGET_OBJECTS:A_2113_DeElectronique_V3_default_default_XC32_15_assembleWithPreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC32_15
if(2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_compile)
add_library(A_2113_DeElectronique_V3_default_default_XC32_15_compile OBJECT ${2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_compile})
    A_2113_DeElectronique_V3_default_default_XC32_15_compile_rule(A_2113_DeElectronique_V3_default_default_XC32_15_compile)
    list(APPEND 2113_DeElectronique_V3_default_library_list "$<TARGET_OBJECTS:A_2113_DeElectronique_V3_default_default_XC32_15_compile>")
endif()

# Handle files with suffix cpp, for group default-XC32_15
if(2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_compile_cpp)
add_library(A_2113_DeElectronique_V3_default_default_XC32_15_compile_cpp OBJECT ${2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_compile_cpp})
    A_2113_DeElectronique_V3_default_default_XC32_15_compile_cpp_rule(A_2113_DeElectronique_V3_default_default_XC32_15_compile_cpp)
    list(APPEND 2113_DeElectronique_V3_default_library_list "$<TARGET_OBJECTS:A_2113_DeElectronique_V3_default_default_XC32_15_compile_cpp>")
endif()

add_executable(${2113_DeElectronique_V3_default_image_name} ${2113_DeElectronique_V3_default_library_list})

target_link_libraries(${2113_DeElectronique_V3_default_image_name} PRIVATE ${2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_link})

# Add the link options from the rule file.
A_2113_DeElectronique_V3_default_link_rule(${2113_DeElectronique_V3_default_image_name})

# Add bin2hex target for converting built file to a .hex file.
add_custom_target(2113_DeElectronique_V3_default_Bin2Hex ALL
    ${MP_BIN2HEX} ${2113_DeElectronique_V3_default_image_name})
add_dependencies(2113_DeElectronique_V3_default_Bin2Hex ${2113_DeElectronique_V3_default_image_name})

# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${2113_DeElectronique_V3_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${2113_DeElectronique_V3_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${2113_DeElectronique_V3_default_image_name} ${2113_DeElectronique_V3_default_output_dir}/${2113_DeElectronique_V3_default_original_image_name}
                    BYPRODUCTS ${2113_DeElectronique_V3_default_output_dir}/${2113_DeElectronique_V3_default_original_image_name})
