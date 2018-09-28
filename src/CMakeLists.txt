FILE(GLOB SRC_FILE *.c *.cpp)
FILE(GLOB RC_FILE *.rc)
FILE(GLOB HEADER_FILE *.h)

add_executable(reverse_tool ${SRC_FILE} ${RC_FILE} ${HEADER_FILE})
set_target_properties(reverse_tool PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /SAFESEH:NO")