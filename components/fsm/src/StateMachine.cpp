//
// Created by Peng Xie on 2024/2/27.
//

#include <iostream>

#include <fsm/StateMachine.hpp>
#include <fsm/StateMachineBridge.hpp>

#include <fsm/DownloadState.hpp>
#include <fsm/ExportState.hpp>

namespace carbon::fsm {

StateMachine::StateMachine(StateMachineBridge& bridge)
    : m_bridge(bridge)
{
    std::clog << "[StateMachine] start";
}

InitialState::InitialState()
{
    std::clog << "[StateMachine] -> InitialState";
}

sc::result InitialState::react(const download_event& event)
{
    this->context<StateMachine>().m_task = {};
    return this->discard_event();
}

} // namespace carbon::fsm
