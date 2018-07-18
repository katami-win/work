set(hdrs BarometerRTC.h
    PARENT_SCOP
    )
#set(hdrs ${PROJECT_SOURCE_DIR}/../../classes/)
#set(hdrs ${hdrs} ${PROJECT_SOURCE_DIR}/../../classes/Pressure.h)
#set(hdrs ${hdrs} Pressure.h PARENT_SCOP)

install(FILES ${hdrs} DESTINATION ${INC_INSTALL_DIR}/${PROJECT_NAME_LOWER}
    COMPONENT library)

