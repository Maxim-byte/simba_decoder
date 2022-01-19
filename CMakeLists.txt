cmake_minimum_required(VERSION 3.20.2)
project(simba_decoder)

set(CMAKE_CXX_STANDARD 20)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(simba_decoder src/main.cpp
        src/utility/details.hpp
        src/utility/types.hpp
        src/utility/types.cpp

        src/parts/incremental_packet_header.cpp
        src/parts/incremental_packet_header.hpp
        src/parts/sbe_header.hpp
        src/parts/sbe_header.cpp
        src/parts/market_data_packet_header.cpp
        src/parts/market_data_packet_header.hpp

        src/parts/messages/order_update.cpp
        src/parts/messages/order_update.hpp
        src/parts/messages/order_execution.hpp
        src/parts/messages/order_execution.cpp
        src/parts/messages/order_book_snapshot.hpp
        src/parts/messages/order_book_snapshot.cpp

        src/decoder/simba_decoder.cpp
        src/decoder/simba_decoder.hpp

        src/fix_parser/include/hffix.hpp
        src/fix_parser/include/hffix_fields.hpp)

target_link_libraries(simba_decoder ${CONAN_LIBS})

