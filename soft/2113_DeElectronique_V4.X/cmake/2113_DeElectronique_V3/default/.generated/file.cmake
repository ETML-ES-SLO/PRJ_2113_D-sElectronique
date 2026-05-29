# The following variables contains the files used by the different stages of the build process.
set(2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_assemble)
set_source_files_properties(${2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_assembleWithPreprocess)
set_source_files_properties(${2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_assembleWithPreprocess} PROPERTIES LANGUAGE ASM)
set(2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../Accelerometre.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../DeElectronique.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../Mc32Delays.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/clock.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/coretimer.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/exceptions.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/interrupt_manager.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/mcc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/pin_manager.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/spi1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/system.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../mcc_generated_files/tmr1.c")
set_source_files_properties(${2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_compile_cpp)
set_source_files_properties(${2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_compile_cpp} PROPERTIES LANGUAGE CXX)
set(2113_DeElectronique_V3_default_default_XC32_15_FILE_TYPE_link)

# The (internal) path to the resulting build image.
set(2113_DeElectronique_V3_default_internal_image_name "${CMAKE_CURRENT_SOURCE_DIR}/../../../_build/2113_DeElectronique_V3/default/default.elf")

# The name of the resulting image, including namespace for configuration.
set(2113_DeElectronique_V3_default_image_name "2113_DeElectronique_V3_default_default.elf")

# The name of the image, excluding the namespace for configuration.
set(2113_DeElectronique_V3_default_original_image_name "default.elf")

# The output directory of the final image.
set(2113_DeElectronique_V3_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/2113_DeElectronique_V3")
