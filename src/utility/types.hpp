#pragma once

#include <cstdint>
#include <iosfwd>

namespace types {
    struct decimal5 {
        std::int64_t mantissa;
        std::int8_t exponent;
    };

    struct decimal5null
    {
        std::int64_t mantissa;
        std::int8_t exponent;
        enum class values : std::int64_t
        {
            min_value = -9223372036854775807,
            max_value = 9223372036854775806,
            null_value = 9223372036854775807
        };
    };

    struct group_size {
        std::uint16_t block_length;
        std::uint8_t num_in_group;
    };

    enum class int64null : std::int64_t {
        min_value = -9223372036854775807,
        max_value = 9223372036854775806,
        null_value = 9223372036854775807
    };

    enum class md_flags_set : std::uint64_t {
        day = 0x1,
        ioc = 0x2,
        non_system = 0x4,
        last_in_transaction = 0x1000,
        fill_or_kill = 0x80000,
        record_result_move = 0x100000,
        record_result_delete = 0x200000,
        record_result_group_delete = 0x400000,
        address_apply = 0x4000000,
        link_apply = 0x8000000,
        sign_delete_apply_cross_deal = 0x20000000,
        sign_cancel_or_disconnect = 0x100000000,
        sign_syntactic_apply = 0x200000000000,
        rfc_apply = 0x40000000000
    };

    enum class md_update_action : std::uint8_t {
        New = 0,
        Change = 1,
        Delete = 2
    };

    enum class md_entry_type : char {
        bid = '0',
        offer = '1',
        empty_book = 'J'
    };


    std::istream & operator>>(std::istream & stream, decimal5 & decimal5);
}