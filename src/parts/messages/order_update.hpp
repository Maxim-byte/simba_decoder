#pragma once

#include <cstdint>

#include "../../utility/types.hpp"

namespace incremental {
    struct order_update
    {
        std::int64_t md_entry_id;
        types::decimal5 md_entry_px;
        std::int64_t md_entry_size;
        std::uint64_t md_flags; //enum class md_flags_set
        std::int32_t security_id;
        std::uint32_t rppt_seq;
        std::uint8_t md_update_action;
        char md_entry_type;
    };

    //need to overload <</>>
}

