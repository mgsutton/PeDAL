
set(PEDAL_HDRS
	"${CMAKE_SOURCE_DIR}/include/PeDAL/mainWindow.h"
	"${CMAKE_SOURCE_DIR}/include/PeDAL/editorTabWidget.h"
	"${CMAKE_SOURCE_DIR}/include/PeDAL/htmlTabWidget.h"
	"${CMAKE_SOURCE_DIR}/include/PeDAL/apdlEditor.h")

set(PEDAL_SRCS
	"main.cpp"
	"mainWindow.cpp"
	"editorTabWidget.cpp"
	"htmlTabWidget.cpp"
	"apdlEditor.cpp"
	)

set(PEDAL_QT_RESOURCES
	"PeDAL.qrc")

set(PEDAL_WINDOWS_RESOURCES
	"PeDAL.rc"
	"PeDAL.ico")

qt5_add_resources(PEDAL_RCC ${PEDAL_QT_RESOURCES})

add_executable(PeDAL WIN32 
	${PEDAL_SRCS} 
	${PEDAL_HDRS}
	${PEDAL_RCC}
	${PEDAL_WINDOWS_RESOURCES})

source_group("PeDAL Sources" ${PEDAL_SRCS})
source_group("PeDAL Headers" ${PEDAL_HDRS})
source_group("PeDAL Resources" ${PEDAL_QT_RESOURCES})

set_target_properties(PeDAL PROPERTIES
	                  RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/Debug
	                  RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/Release)

target_link_libraries(PeDAL
	Scintilla
	Lua 
	Qt5::Core 
	Qt5::Widgets
	Qt5::WebEngine 
	Qt5::WebEngineWidgets)

