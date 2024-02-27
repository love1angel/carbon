//
// Created by Helianthus Xie on 2024/2/27.
//

#include <fsm/FSM.hpp>

#include <fsm/DownloadState.hpp>
#include <fsm/ExportState.hpp>

namespace carbon::fsm {

std::unique_ptr<FSM> FSM::create(StateMachineBridge& bridge)
{
    return std::make_unique<FSM>(bridge);
}

void FSM::start()
{
    this->m_fsm.initiate();
}

} // namespace carbon::fsm
