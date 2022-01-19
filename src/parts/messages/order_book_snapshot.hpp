#pragma once

#include <cstdint>
#include <optional>

#include "../../utility/types.hpp"

namespace snapshot {
    struct order_book_snapshot
    {
        std::int32_t security_id;
        std::uint32_t last_msg_seq_num_processed;
        std::uint32_t rpt_seq;
        std::uint32_t exchange_trading_session_id;
        types::group_size no_md_entries;
        std::optional<std::int64_t> md_entry_id;
        std::uint64_t transact_time;
        types::decimal5null md_entry_px;
        std::optional<std::int64_t> md_entry_size;
        std::optional<std::int64_t> trade_id;
        std::uint64_t md_flags; //// enum class md_flags_set
        char md_entry_type; //// enum class md_entry_type
    };

    //need to overload <</>>

}

