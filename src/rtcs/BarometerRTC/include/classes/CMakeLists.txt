#set(hdrs Pressure.h
#    PARENT_SCOP
#    )
message(STATUS "020")
message(STATUS "${hdrs}")

install(FILES ${hdrs} DESTINATION ${INC_INSTALL_DIR}/${PROJECT_NAME_LOWER}
    COMPONENT library)

