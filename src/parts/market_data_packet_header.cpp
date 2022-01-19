#include "market_data_packet_header.hpp"

#include <iostream>

#include "../utility/details.hpp"

std::istream & presentation_level::operator>>(std::istream & stream, presentation_level::market_data_packet_header & market_header) {
    stream.read(reinterpret_cast<char *>(&market_header.msg_seq_num), sizeof(market_header.msg_seq_num));
    stream.read(reinterpret_cast<char *>(&market_header.msg_size), sizeof(market_header.msg_size));
    stream.read(reinterpret_cast<char *>(&market_header.msg_flags), sizeof(market_header.msg_seq_num));
    stream.read(reinterpret_cast<char *>(&market_header.sending_time), sizeof(market_header.sending_time));
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const presentation_level::market_data_packet_header & market_header) {
    stream << "Msg seq num: " << market_header.msg_seq_num << '\n';
    stream << "Msg size: " << market_header.msg_size << '\n';
    auto it = details::market_data_header::flags.find(static_cast<details::market_data_header::msg_flags>(market_header.msg_flags));
    if(it == details::market_data_header::flags.end()) {
        stream << "" << '\n';
    } else {
        stream << it->second << '\n';
    }
    stream << "Time since epoch: " << market_header.sending_time << '\n';
    return stream;
}
