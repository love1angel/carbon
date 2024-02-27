//
// Created by Peng Xie on 2024/2/27.
//

#include <iostream>

#include <fsm/ExportState.hpp>

#include <fsm/DownloadState.hpp>

namespace carbon::fsm {

ExportState::ExportState()
{
    std::clog << "[StateMachine] -> ExportState";
}

ExportState::~ExportState() noexcept
{
    std::clog << "[StateMachine] ExportState leave";
}

} // namespace carbon::fsm
