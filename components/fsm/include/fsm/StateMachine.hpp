//
// Created by Peng Xie on 2024/2/27.
//

#pragma once

#include <optional>

#include <boost/mpl/list.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/statechart/deferral.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/transition.hpp>

#include <fsm/event.hpp>
#include <fsm/DownloadTask.hpp>

namespace carbon::fsm {

namespace sc = boost::statechart;
namespace mpl = boost::mpl;

class StateMachineBridge;

class InitialState;
class DownloadState;
class ExportState;

class StateMachine : public sc::state_machine<StateMachine, InitialState> {
public:
    explicit StateMachine(StateMachineBridge& bridge);

    std::optional<DownloadTask> m_task = std::nullopt;
    StateMachineBridge& m_bridge;
};

class InitialState : public sc::simple_state<InitialState, StateMachine> {
public:
    using reactions = mpl::list<
        sc::transition<initial_ready_event, DownloadState>,
        sc::custom_reaction<download_event>>;

public:
    InitialState();

    sc::result react(const download_event& event);
};

} // namespace carbon::fsm
