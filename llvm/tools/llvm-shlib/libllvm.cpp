//===-libllvm.cpp - LLVM Shared Library -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// LLVMSharp's generated InitializeAll* methods only include stable upstream
// targets. Xtensa is experimental in LLVM 21, so register it when the native
// library is loaded without requiring a managed-code special case.
//
//===----------------------------------------------------------------------===//

extern "C" void LLVMInitializeXtensaTargetInfo();
extern "C" void LLVMInitializeXtensaTarget();
extern "C" void LLVMInitializeXtensaTargetMC();
extern "C" void LLVMInitializeXtensaAsmParser();
extern "C" void LLVMInitializeXtensaAsmPrinter();

namespace {
struct InitializeXtensa {
  InitializeXtensa() {
    LLVMInitializeXtensaTargetInfo();
    LLVMInitializeXtensaTarget();
    LLVMInitializeXtensaTargetMC();
    LLVMInitializeXtensaAsmParser();
    LLVMInitializeXtensaAsmPrinter();
  }
};

InitializeXtensa initializeXtensa;
} // namespace
