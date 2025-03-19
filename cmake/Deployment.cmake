# Use winddeployqt to deploy all needed Qt libraries
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${TOOL_WINDEPLOYQT}
        $<TARGET_FILE:${PROJECT_NAME}>
        --qmldir "${QML_IMPORT_PATH}"
        COMMENT "Running windeployqt with QML deployment..."
)
