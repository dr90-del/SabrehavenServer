/**
 * Tibia GIMUD Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2019 Sabrehaven and Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "otpch.h"
#include "outputmessage.h"
#include "protocol.h"
#include "scheduler.h"

extern Scheduler g_scheduler;

void OutputMessagePool::scheduleSendAll()
{
    auto functor = std::bind(&OutputMessagePool::sendAll, this);
    g_scheduler.addEvent(createSchedulerTask(OUTPUTMESSAGE_AUTOSEND_DELAY.count(), functor));
}

void OutputMessagePool::sendAll()
{
    for (auto& protocol : bufferedProtocols) {
        auto& msg = protocol->getCurrentBuffer();
        if (msg) {
            protocol->send(std::move(msg));
        }
    }

    if (!bufferedProtocols.empty()) {
        scheduleSendAll();
    }
}

void OutputMessagePool::addProtocolToAutosend(Protocol_ptr protocol)
{
    if (bufferedProtocols.empty()) {
        scheduleSendAll();
    }
    bufferedProtocols.emplace_back(protocol);
}

void OutputMessagePool::removeProtocolFromAutosend(const Protocol_ptr& protocol)
{
    auto it = std::find(bufferedProtocols.begin(), bufferedProtocols.end(), protocol);
    if (it != bufferedProtocols.end()) {
        std::swap(*it, bufferedProtocols.back());
        bufferedProtocols.pop_back();
    }
}

OutputMessage_ptr OutputMessagePool::getOutputMessage()
{
    // switched to make_shared to avoid allocator mismatches
    return std::make_shared<OutputMessage>();
}
