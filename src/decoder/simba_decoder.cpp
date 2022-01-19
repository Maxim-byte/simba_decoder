#include "simba_decoder.hpp"

#include <boost/date_time/posix_time/posix_time.hpp> //recommendation for using fix parsing library
#include <boost/date_time/gregorian/gregorian.hpp> //recommendation for using fix parsing library

#include "../parts/market_data_packet_header.hpp"
#include "../parts/incremental_packet_header.hpp"
#include "../parts/sbe_header.hpp"

#include "../utility/details.hpp"

simba_decoder::simba_decoder() {
    hffix::dictionary_init_field(field_dictionary_); //init dictionary
}


std::string simba_decoder::decode_incremental_type(const std::string &source_binary_format) {
    input_stream_.str(source_binary_format);
    output_stream_.str("");

    input_stream_.seekg(details::constants::ip_header_size_bytes +
                        details::constants::udp_size_bytes, std::ios::cur);

    presentation_level::market_data_packet_header market_header{};
    input_stream_ >> market_header;
    check_input_stream();


    presentation_level::incremental_packet_header incremental_header{};
    input_stream_ >> incremental_header;
    check_input_stream();

    //parse some sbe messages(can be more than 1)
    
    while(!input_stream_.eof())
    {
        presentation_level::sbe_header sbe_header{};
        input_stream_ >> sbe_header;
        check_input_stream();


        //order_execution
        //order update
        //problems
        //how to check message id?
        input_stream_.read(buffer_.begin(), sizeof(incremental::order_execution));
        hffix::message_reader reader(&buffer_[0], sizeof(incremental::order_execution));
        std::cout << reader.message_type()->tag() << '\n';
        if (reader.is_valid()) {
            output_stream_ << "Order execution message" << '\n';
            try {
                hffix::message_reader::const_iterator i = reader.begin();
                if (reader.find_with_hint(hffix::tag::MDEntryID, i)) {
                    output_stream_ << "Md Entry id: " << i++->value() << '\n';
                }
                if (reader.find_with_hint(hffix::tag::MDEntryPx, i)) {
                    output_stream_ << "Md Entry Px: " << i++->value() << '\n';
                }
                if (reader.find_with_hint(hffix::tag::MDEntrySize, i)) {
                    output_stream_ << "Md Entry size: " << i++->value() << '\n';
                }
                if (reader.find_with_hint(hffix::tag::LastPx, i)) {
                    output_stream_ << "Last Px: " << i++->value() << '\n';
                }
                if (reader.find_with_hint(hffix::tag::LastQty, i)) {
                    output_stream_ << "Last Qty: " << i++->value() << '\n';
                }
                if (reader.find_with_hint(hffix::tag::TradeID, i)) {
                    output_stream_ << "Trade id: " << i++->value() << '\n';
                }
                /*if (reader.find_with_hint(hffix::tag::MDFlags, i)) { //not exist this tag in this library

                }*/
                if (reader.find_with_hint(hffix::tag::SecurityID, i)) {
                    output_stream_ << "Secutiry id: " << i++->value() << '\n';
                }
                if (reader.find_with_hint(hffix::tag::RptSeq, i)) {
                    output_stream_ << "Rpt Seq: " << i++->value() << '\n';
                }
                if (reader.find_with_hint(hffix::tag::MDUpdateAction, i)) {
                    output_stream_ << "Md update Action: " << i++->value() << '\n';
                }
                if (reader.find_with_hint(hffix::tag::MDEntryType, i)) {
                    output_stream_ << "Md entry type: " << i++->value() << '\n';
                }
            } catch (const std::exception& ex)
            {

            }
        }
    }

    return output_stream_.str();
}

void simba_decoder::check_input_stream() {
    if(input_stream_.fail()) {
        throw std::runtime_error("Invalid format!");
    }
}

std::string simba_decoder::decode_snapshot_type(const std::string &source_binary_format) {
    input_stream_.str(source_binary_format);
    output_stream_.str("");

    input_stream_.seekg(details::constants::ip_header_size_bytes +
                        details::constants::udp_size_bytes, std::ios::cur);

    presentation_level::market_data_packet_header market_header{};
    input_stream_ >> market_header;
    check_input_stream();

    while(!input_stream_.eof()) {
        presentation_level::sbe_header sbe_header{};
        input_stream_ >> sbe_header;
        check_input_stream();

        //read sbe message
    }

    return output_stream_.str();
}
