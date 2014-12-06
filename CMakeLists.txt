
project(common-api-dbus-tools)

set(JAR_DESTINATION_PATH share/CommonAPICodeGen)

# We build and install the "almost-vanilla" dbus code generator, then we build our "packager" which produces the
# dependencies folder, which we install in the command-line generator folder

add_custom_target(
	dbus-codegen ALL
	COMMAND mvn ${MAVEN_OPTIONS} -f ${CMAKE_CURRENT_SOURCE_DIR}/org.genivi.commonapi.dbus/pom.xml install
)

add_custom_target(
	packager ALL
	COMMAND mvn ${MAVEN_OPTIONS} -f ${CMAKE_CURRENT_SOURCE_DIR}/packager/pom.xml package
	DEPENDS dbus-codegen
)

# Install dependencies
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/packager/target/dependencies/ DESTINATION ${JAR_DESTINATION_PATH})
