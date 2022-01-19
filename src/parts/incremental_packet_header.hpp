#pragma once

#include <cstdint>
#include <iosfwd>

namespace presentation_level {
    struct incremental_packet_header
    {
        std::uint64_t transact_time;
        std::uint32_t exchange_trading_session;
    };

    std::istream & operator>>(std::istream & stream, incremental_packet_header & incremental_header);
    std::ostream & operator<<(std::ostream & stream, const incremental_packet_header & incremental_header);
}

