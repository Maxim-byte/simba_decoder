#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

namespace details {

    namespace market_data_header  {
        enum class msg_flags : std::uint16_t {
            fragment_message = 0x1,
            first_message_start_of_snapshot = 0x2,
            last_message_end_of_snapshot = 0x4,
            incremental_packet = 0x8,
            poss_dup_flag = 0x10
        };
        inline const std::unordered_map<msg_flags, std::string> flags {{msg_flags::fragment_message, "Message was divided into fragment!" },
                                                                       {msg_flags::first_message_start_of_snapshot, "First message in snapshot!"},
                                                                       {msg_flags::last_message_end_of_snapshot, "Last message in snapshot!"},
                                                                       {msg_flags::incremental_packet, "Incremental packet!"},
                                                                       {msg_flags::poss_dup_flag, "Poss dup flags sign!"}};
    }

    namespace constants {
        inline constexpr std::uint8_t udp_size_bytes = 8;
        inline constexpr std::uint8_t ip_header_size_bytes = 20;
        inline constexpr std::uint8_t market_data_header_size_bytes = 16;
        inline constexpr std::uint8_t incremental_packet_header_size_bytes = 12;
        inline constexpr std::uint8_t sbe_header_size_bytes = 8;
    }

    inline constexpr std::uint16_t swap_endian(std::uint16_t u)
    {
        return (u >> 8) | ((u & 0xFF) << 8);
    }
}