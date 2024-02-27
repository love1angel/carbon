//
// Created by Helianthus Xie on 2024/2/27.
//

#pragma once

#include <boost/statechart/event.hpp>

#include "detail/event_token.hpp"

namespace carbon::fsm {

namespace sc = boost::statechart;

// initial state
struct initial_ready_event : sc::event<initial_ready_event>, detail::event_token {
};

// download state
struct download_event : sc::event<download_event>, detail::event_token {
    explicit download_event(const std::string& vin)
        : m_vin(vin)
    {
    }

    explicit download_event(std::string&& vin) noexcept
        : m_vin(std::move(vin))
    {
    }

    std::string m_vin;
};

inline bool
operator==(const download_event& lhs, const download_event& rhs)
{
    return lhs.m_vin == rhs.m_vin;
}

struct download_success_event : sc::event<download_success_event>, detail::event_token {
};

struct download_failed_event : sc::event<download_failed_event>, detail::event_token {
};

// export state
struct export_success : sc::event<export_success>, detail::event_token {
};

struct export_check_failed : sc::event<export_check_failed>, detail::event_token {
};

struct export_time_out : sc::event<export_time_out>, detail::event_token {
};

} // namespace carbon::fsm
