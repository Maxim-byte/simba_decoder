#include "sbe_header.hpp"

#include <iostream>

std::istream & presentation_level::operator>>(std::istream & stream, presentation_level::sbe_header & sbe_header) {
    stream.read(reinterpret_cast<char *>(&sbe_header.block_length), sizeof(sbe_header.block_length));
    stream.read(reinterpret_cast<char *>(&sbe_header.template_id), sizeof(sbe_header.template_id));
    stream.read(reinterpret_cast<char *>(&sbe_header.schema_id), sizeof(sbe_header.schema_id));
    stream.read(reinterpret_cast<char *>(&sbe_header.version), sizeof(sbe_header.version));
    return stream;
}

std::ostream & presentation_level::operator<<(std::ostream & stream, const presentation_level::sbe_header & sbe_header) {
    stream << "Block length: " << sbe_header.block_length << '\n';
    stream << "Template id: " << sbe_header.template_id << '\n';
    stream << "Schema id: " << sbe_header.schema_id << '\n';
    stream << "Version: " << sbe_header.version << '\n';
    return stream;
}
