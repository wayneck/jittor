// ***************************************************************
// Copyright (c) 2020 Jittor. All Rights Reserved. 
// Maintainers: 
//     Guowei Yang <471184555@qq.com>
//     Dun Liang <randonlang@gmail.com>. 
// 
// This file is subject to the terms and conditions defined in
// file 'LICENSE.txt', which is part of this source code package.
// ***************************************************************
#pragma once
#include "opt/pass/pass.h"

namespace jittor {

struct AtomicTunerPass : Pass {
    AtomicTunerPass() : Pass("atomic") {};
    void run() override;
};

} // jittor
