
cmake_minimum_required(VERSION 2.6)

project(common-api-dbus-tools)

find_package(CommonAPICodeGenFramework)

import_maven_repository(common-api-tools)

# We build and install the dbus code generator
add_maven_package(dbus-codegen ${CMAKE_CURRENT_SOURCE_DIR}/org.genivi.commonapi.dbus "")

# Then we build our "packager" which produces the dependencies folder, which we install in the command-line generator folder
add_maven_package(packager ${CMAKE_CURRENT_SOURCE_DIR}/packager dbus-codegen)

# Install our code generator by installing the dependencies of our "packager" maven package
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/packager/target/dependencies/ DESTINATION ${COMMON_API_CODEGEN_JAR_DESTINATION_PATH})

export_maven_repository(common-api-dbus-tools)
