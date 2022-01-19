#pragma once

#include <cstdint>
#include <optional>

#include "../../utility/types.hpp"

namespace incremental {
    struct order_execution
    {
        std::int64_t md_entry_id;
        types::decimal5null md_entry_px;
        std::optional<std::int64_t> md_entry_size;
        types::decimal5 last_px;
        std::int64_t last_qty;
        std::int64_t trade_id;
        std::uint64_t md_flags; ////enum class md_flags_set
        std::int32_t security_id;
        std::uint32_t rpt_seq;
        std::uint8_t md_update_action; ////enum class md_update_action
        char md_entry_type; ////enum class md_entry_type
    };

    //need to overload <</>>
}
