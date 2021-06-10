// ***************************************************************
// Copyright (c) 2021 Jittor. All Rights Reserved. 
// Maintainers: 
//     Wenyang Zhou <576825820@qq.com>
//     Dun Liang <randonlang@gmail.com>. 
// 
// This file is subject to the terms and conditions defined in
// file 'LICENSE.txt', which is part of this source code package.
// ***************************************************************
#pragma once
#include "op.h"
#include "mlu_warper.h"
#include <cnnl.h>
#include <cnml.h>
#include <cnrt.h>

namespace jittor {

struct CnnlMluPoolOp : Op {
    Var* x, * y;
    int kernel_size, stride, padding, dilation, pool_mode_row;
    bool ceil_mode, count_include_pad;
    string xformat, yformat;
    /* CnnlMluPoolOp: xformat abcd represents nchw */
    CnnlMluPoolOp(Var* x, int kernel_size, int stride, int padding, int dilation, int pool_mode_row, bool ceil_mode, bool count_include_pad, string xformat="abcd", string yformat="");
    
    const char* name() const override { return "cnnl_mlu_pool"; }
    void infer_shape() override;
    DECLARE_jit_run;
};

struct CnnlMluPool_t {
    cnmlBaseOp_t pool_op_cache;
    cnmlPoolOpParam_t pool_param_cache;
    cnmlTensor_t input_tensor_cache;
    cnmlTensor_t output_tensor_cache;
};

} // jittor