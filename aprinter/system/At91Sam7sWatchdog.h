/*
 * Copyright (c) 2013 Ambroz Bizjak
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef AMBROLIB_AT91SAM7S_WATCHDOG_H
#define AMBROLIB_AT91SAM7S_WATCHDOG_H

#include <math.h>

#include <aprinter/meta/Position.h>
#include <aprinter/base/DebugObject.h>

#include <aprinter/BeginNamespace.h>

struct At91Sam7sWatchdogParams {};

template <typename Position, typename Context, typename Params>
class At91Sam7sWatchdog : private DebugObject<Context, void>
{
    static At91Sam7sWatchdog * self (Context c)
    {
        return PositionTraverse<typename Context::TheRootPosition, Position>(c.root());
    }
    
public:
    static constexpr double WatchdogTime = INFINITY;
    
    static void init (Context c)
    {
        At91Sam7sWatchdog *o = self(c);
        o->debugInit(c);
    }
    
    static void deinit (Context c)
    {
        At91Sam7sWatchdog *o = self(c);
        o->debugDeinit(c);
    }
    
    template <typename ThisContext>
    static void reset (ThisContext c)
    {
        At91Sam7sWatchdog *o = self(c);
        o->debugAccess(c);
    }
};

#include <aprinter/EndNamespace.h>

#endif