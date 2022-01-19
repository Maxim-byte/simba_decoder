#pragma once

#include <cstdint>
#include <iosfwd>

namespace presentation_level {
    struct sbe_header
    {
        std::uint16_t block_length;
        std::uint16_t template_id;
        std::uint16_t schema_id;
        std::uint64_t version;
    };

    std::istream & operator>>(std::istream & stream, sbe_header & sbe_header);
    std::ostream & operator<<(std::ostream & stream, const sbe_header & sbe_header);
}

