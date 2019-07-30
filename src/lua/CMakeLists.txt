
SET(LUA_SRCS
    lapi.c 
    lauxlib.c
    lbaselib.c
    lbitlib.c
    lcode.c
    lcorolib.c
    lctype.c
    ldblib.c
    ldebug.c
    ldo.c
    ldump.c
    lfunc.c
    lgc.c
    linit.c
    liolib.c
    llex.c
    lmathlib.c
    lmem.c
    loadlib.c
    lobject.c
    lopcodes.c
    loslib.c
    lparser.c
    lstate.c
    lstring.c
    lstrlib.c
    ltable.c
    ltablib.c
    ltm.c
    lundump.c
    lutf8lib.c
    lvm.c
    lzio.c
    )

SET(LUA_HDRS
	"${CMAKE_SOURCE_DIR}/include/lua/lapi.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lauxlib.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lcode.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lctype.h"
	"${CMAKE_SOURCE_DIR}/include/lua/ldebug.h"
	"${CMAKE_SOURCE_DIR}/include/lua/ldo.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lfunc.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lgc.h"
	"${CMAKE_SOURCE_DIR}/include/lua/llex.h"
	"${CMAKE_SOURCE_DIR}/include/lua/llimits.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lmem.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lobject.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lopcodes.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lparser.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lprefix.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lstate.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lstring.h"
	"${CMAKE_SOURCE_DIR}/include/lua/ltable.h"
	"${CMAKE_SOURCE_DIR}/include/lua/ltm.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lua.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lua.hpp"
	"${CMAKE_SOURCE_DIR}/include/lua/luaconf.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lualib.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lundump.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lvm.h"
	"${CMAKE_SOURCE_DIR}/include/lua/lzio.h")

set(SOL_HDRS 
	"${CMAKE_SOURCE_DIR}/include/sol2/forward.hpp"
	"${CMAKE_SOURCE_DIR}/include/sol2/sol.hpp")



foreach(L_HDR IN LISTS ${LUA_HDRS})
	set_property(SOURCE ${L_HDR} PROPERTY SKIP_AUTOMOC ON)
endforeach()

foreach(L_SRC IN LISTS ${LUA_SRCS})
	set_property(SOURCE ${L_SRC} PROPERTY SKIP_AUTOMOC ON)
endforeach()

add_compile_definitions(LUA_BUILD_AS_DLL)
add_library(Lua SHARED ${LUA_SRCS} ${LUA_HDRS} ${SOL_HDRS})

set_target_properties(Lua PROPERTIES
	                  RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/Debug
	                  RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/Release)

source_group("Lua Source" ${LUA_SRCS})
source_group("Lua Headers" ${LUA_HDRS})
source_group("Sol2 Headers" ${SOL_HDRS})