cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("tusk2")

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory("C:\\Users\\Dorim\\projects\\module32\\tusk2\\nlohmann json")

add_executable (tusk2 "tusk2.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tusk2 PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(tusk2 PRIVATE nlohmann_json::nlohmann_json)
