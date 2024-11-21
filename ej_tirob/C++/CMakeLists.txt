cmake_minimum_required(VERSION 3.10)

project(TiroCliente CXX)

# Encuentra Protobuf y gRPC
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

# Archivo proto
set(PROTO_FILE "${CMAKE_SOURCE_DIR}/tiro.proto")

# Rutas generadas
set(PROTO_SRCS "${CMAKE_BINARY_DIR}/tiro.pb.cc")
set(PROTO_HDRS "${CMAKE_BINARY_DIR}/tiro.pb.h")
set(GRPC_SRCS "${CMAKE_BINARY_DIR}/tiro.grpc.pb.cc")
set(GRPC_HDRS "${CMAKE_BINARY_DIR}/tiro.grpc.pb.h")

# Generar archivos pb.cc y grpc.pb.cc
add_custom_command(
  OUTPUT "${PROTO_SRCS}" "${PROTO_HDRS}" "${GRPC_SRCS}" "${GRPC_HDRS}"
  COMMAND ${Protobuf_PROTOC_EXECUTABLE}
  ARGS --grpc_out "${CMAKE_BINARY_DIR}"
       --cpp_out "${CMAKE_BINARY_DIR}"
       -I "${CMAKE_SOURCE_DIR}"
       --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin
       "${PROTO_FILE}"
  DEPENDS "${PROTO_FILE}"
  COMMENT "Generando archivos de protobuf y gRPC"
)

# Añade las cabeceras generadas al proyecto
include_directories("${CMAKE_BINARY_DIR}")
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${gRPC_INCLUDE_DIRS})

# Define la librería proto
add_library(tiro_proto STATIC ${PROTO_SRCS} ${GRPC_SRCS})
target_include_directories(tiro_proto PUBLIC "${CMAKE_BINARY_DIR}")
target_link_libraries(tiro_proto PUBLIC ${Protobuf_LIBRARIES} gRPC::grpc++)

# Cliente
add_executable(client "${CMAKE_SOURCE_DIR}/client.cpp")
target_link_libraries(client PRIVATE tiro_proto ${Protobuf_LIBRARIES} gRPC::grpc++)

# Forzar la vinculación dinámica para evitar conflictos con bibliotecas estáticas
set_target_properties(client PROPERTIES LINK_SEARCH_END_STATIC OFF)
