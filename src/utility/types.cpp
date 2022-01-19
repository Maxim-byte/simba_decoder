#include "types.hpp"

#include <iostream>

std::istream & types::operator>>(std::istream & stream, types::decimal5 & decimal5) {
    stream.read(reinterpret_cast<char *>(&decimal5.mantissa), sizeof(decimal5.mantissa));
    stream.read(reinterpret_cast<char *>(&decimal5.exponent), sizeof(decimal5.exponent));
    return stream;
}

