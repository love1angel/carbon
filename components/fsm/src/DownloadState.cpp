//
// Created by Peng Xie on 2024/2/27.
//

#include <iostream>

#include <fsm/DownloadState.hpp>

#include <fsm/ExportState.hpp>
#include <fsm/StateMachineBridge.hpp>

namespace carbon::fsm {

DownloadState::DownloadState()
{
    std::clog << "[StateMachine] -> DownloadState";
}

DownloadState::~DownloadState() noexcept
{
    std::clog << "[StateMachine] DownloadState leave";
}

sc::result DownloadState::react(const download_event& event)
{
    std::clog <<  "[event] download_event";

    return this->discard_event();
}

sc::result DownloadState::react([[maybe_unused]] const download_success_event& event)
{
    std::clog << "[event] download_success_event";

    this->context<StateMachine>().m_task = {};
    return this->transit<ExportState>();
}

sc::result DownloadState::react([[maybe_unused]] const download_failed_event& event)
{
    std::clog << "[event] download_failed_event";

    this->context<StateMachine>().m_task = {};
    return this->discard_event();
}

} // namespace carbon::fsm
