//
// Created by Peng Xie on 2024/2/27.
//

#pragma once


#include <fsm/StateMachine.hpp>
#include "detail/event_token.hpp"

namespace carbon::fsm {

class StateMachineBridge;

class FSM {
public:
    [[nodiscard]] static std::unique_ptr<FSM> create(StateMachineBridge& bridge);

public:
    FSM(StateMachineBridge& bridge)
        : m_fsm(bridge)
    {
    }

    ~FSM() = default;

    FSM(const FSM&) = delete;
    FSM& operator=(const FSM&) = delete;

    void start();

    template <typename Event, typename... Args>
    void post_event_to_fsm(Args&&... args)
    {
        static_assert(std::is_base_of_v<detail::event_token, Event>, "not derived from event!!!");

        this->m_fsm.process_event(Event { std::forward<Args>(args)... });
    }

private:
    StateMachine m_fsm;
};

} // namespace carbon::fsm
