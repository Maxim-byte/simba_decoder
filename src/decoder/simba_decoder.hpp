#pragma once

#include <string>
#include <sstream>
#include <unordered_map>
#include <array>

#include "../fix_parser/include/hffix.hpp"

#include "../parts/messages/order_execution.hpp"
#include "../parts/messages/order_update.hpp"
#include "../parts/messages/order_book_snapshot.hpp"

constexpr std::size_t max(std::size_t first, std::size_t second, std::size_t third) {
    std::size_t max = first;
    second > max ? max = second : max = first;
    max > third ? max = third : max = first;
    return max;
}

class simba_decoder
{
    public:
    simba_decoder();

    ~simba_decoder() = default;

    std::string decode_incremental_type(const std::string & source_binary_format);

    std::string decode_snapshot_type(const std::string & source_binary_format); //for order book execution

    private:

    void check_input_stream();

    std::array<char , max(sizeof(incremental::order_execution), sizeof(incremental::order_update),
                          sizeof(snapshot::order_book_snapshot))> buffer_{}; //sizes

    std::unordered_map<int, std::string> field_dictionary_; //for fix parsing library
    std::stringstream input_stream_;
    std::stringstream output_stream_;

};

