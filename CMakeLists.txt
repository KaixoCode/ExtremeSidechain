
# ==============================================

cmake_minimum_required(VERSION 3.15)

# ==============================================

set(NAME "ExtremeSidechain")
set(CODE "Xsdc")
set(COMPANY "Kaixo")
set(COMPANY_CODE "Kaix")
set(WEBSITE "https://kaixo.me")
set(BUNDLE_IDENTIFIER "me.kaixo.extremesidechain")
set(VERSION "1.0.0")
set(IS_SYNTH false)

# ==============================================

add_subdirectory(JUCE)

set (CMAKE_CXX_STANDARD 23)

project(${NAME} VERSION ${VERSION} LANGUAGES C CXX)

set(PROJECT_SOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}")
set(CORE_SOURCE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE PROJECT_SOURCE
    "${PROJECT_SOURCE_DIRECTORY}/source/*.cpp"
    "${PROJECT_SOURCE_DIRECTORY}/include/*.hpp"
)

source_group(TREE ${PROJECT_SOURCE_DIRECTORY} FILES ${PROJECT_SOURCE})

# ==============================================

juce_add_plugin(${NAME}
    VERSION ${VERSION}
    COMPANY_NAME ${COMPANY}
    COMPANY_WEBSITE ${WEBSITE}
    BUNDLE_ID ${BUNDLE_IDENTIFIER}
    PLUGIN_MANUFACTURER_CODE ${COMPANY_CODE}
    PLUGIN_CODE ${PLUGIN_CODE}
    IS_SYNTH ${IS_SYNTH}
    NEEDS_MIDI_INPUT ${IS_SYNTH}
    FORMATS AU VST3 Standalone)

juce_generate_juce_header(${NAME})

target_sources(${NAME} 
    PRIVATE
        ${PROJECT_SOURCE}
        ${CORE_SOURCE})

target_include_directories(${NAME} 
    PRIVATE 
        "${PROJECT_SOURCE_DIRECTORY}/include/"
        ${LIBRARY_INCLUDE_DIRS})

target_compile_definitions(${NAME}
    PUBLIC
        JUCE_DISPLAY_SPLASH_SCREEN=0
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(${NAME}
    PRIVATE
        juce::juce_core
        juce::juce_audio_devices
        juce::juce_audio_utils
        juce::juce_gui_extra
        juce::juce_opengl
        juce::juce_product_unlocking
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
        
target_precompile_headers(${NAME} PUBLIC "${PROJECT_SOURCE_DIRECTORY}/include/Kaixo/ExtremeSidechain/pch.hpp")

# ==============================================
