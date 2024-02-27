//
// Created by Peng Xie on 2024/2/27.
//

#pragma once

#include <fsm/event.hpp>
#include <fsm/DownloadTask.hpp>

namespace carbon::fsm {

class StateMachineBridge {
public:
    StateMachineBridge() = default;

    StateMachineBridge(StateMachineBridge&) = delete;
    StateMachineBridge& operator=(StateMachineBridge&) = delete;

    virtual ~StateMachineBridge() = default;

    virtual void downloadTask(DownloadTask& event) = 0;
};

} // namespace carbon::fsm
