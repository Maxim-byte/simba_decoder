#include <iostream>
#include <array>

#include "decoder/simba_decoder.hpp"

int main() {
    std::string str("");
    simba_decoder decoder;
    auto str1 = decoder.decode_incremental_type(str);
    std::cout << str;
    return 0;
}
