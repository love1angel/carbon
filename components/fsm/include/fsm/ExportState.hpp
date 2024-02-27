//
// Created by Peng Xie on 2024/2/27.
//

#pragma once

#include <fsm/StateMachine.hpp>

namespace carbon::fsm {

class ExportState : public sc::simple_state<ExportState, StateMachine> {
public:
    using reactions = mpl::list<
        sc::transition<export_success, DownloadState>,
        sc::transition<export_check_failed, DownloadState>,
        sc::transition<export_time_out, DownloadState>,
        sc::deferral<download_event>>;

public:
    ExportState();
    ~ExportState() noexcept override;

};

} // namespace carbon::fsm
