//
// Created by Peng Xie on 2024/2/27.
//

#pragma once

#include <fsm/StateMachine.hpp>

namespace carbon::fsm {

class DownloadState : public sc::simple_state<DownloadState, StateMachine> {
public:
    using reactions = mpl::list<
        sc::custom_reaction<download_event>,
        sc::custom_reaction<download_success_event>,
        sc::custom_reaction<download_failed_event>>;

public:
    DownloadState();
    ~DownloadState() noexcept override;

    sc::result react(const download_event& event);
    sc::result react(const download_success_event& event);
    sc::result react(const download_failed_event& event);
};

} // namespace carbon::fsm
