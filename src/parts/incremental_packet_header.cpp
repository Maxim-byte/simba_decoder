#include "incremental_packet_header.hpp"

#include <iostream>

std::istream & presentation_level::operator>>(std::istream & stream, presentation_level::incremental_packet_header & incremental_header) {
    stream.read(reinterpret_cast<char *>(&incremental_header.transact_time), sizeof(incremental_header.transact_time));
    stream.read(reinterpret_cast<char *>(&incremental_header.exchange_trading_session),  sizeof(incremental_header.exchange_trading_session));
    return stream;
}

std::ostream & presentation_level::operator<<(std::ostream & stream, const presentation_level::incremental_packet_header & incremental_header) {
    stream << "Transact time: " << incremental_header.transact_time << '\n';
    stream << "Trading session id: " << incremental_header.exchange_trading_session << '\n';
    return stream;
}
