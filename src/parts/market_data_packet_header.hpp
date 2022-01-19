#pragma once

#include <cstdint>
#include <iosfwd>


namespace presentation_level {
    struct market_data_packet_header
    {
        std::uint32_t msg_seq_num;
        std::uint16_t msg_size;
        std::uint16_t msg_flags;
        std::uint64_t sending_time;
    };

    std::istream & operator>>(std::istream & stream, market_data_packet_header & market_header);
    std::ostream & operator<<(std::ostream & stream, const market_data_packet_header & market_header);
}

