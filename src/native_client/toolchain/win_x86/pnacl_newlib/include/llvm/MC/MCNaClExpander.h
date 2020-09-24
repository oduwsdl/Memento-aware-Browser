//===- MCNaClExpander.h -----------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the MCNaClExpander class. This is an abstract
// class that encapsulates the expansion logic for MCInsts, and holds
// state such as available scratch registers.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_MC_MCNACLEXPANDER_H
#define LLVM_MC_MCNACLEXPANDER_H

#include "llvm/ADT/SmallVector.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"

namespace llvm {
class MCInst;
class MCSubtargetInfo;
class MCStreamer;

class MCNaClExpander {
private:
  SmallVector<unsigned, 2> ScratchRegs;
  const MCContext &Ctx;

protected:
  std::unique_ptr<MCInstrInfo> InstInfo;
  std::unique_ptr<MCRegisterInfo> RegInfo;
  void invalidateScratchRegs(const MCInst &Inst);
  unsigned getScratchReg(int index);
  unsigned numScratchRegs() const;
  virtual bool isValidScratchRegister(unsigned Reg) const = 0;

public:
  MCNaClExpander(const MCContext &Ctx, std::unique_ptr<MCRegisterInfo> &&RI,
                 std::unique_ptr<MCInstrInfo> &&II)
      : Ctx(Ctx), InstInfo(std::move(II)), RegInfo(std::move(RI)) {}

  void Error(const MCInst &Inst, const char msg[]);

  bool addScratchReg(unsigned Reg);
  void clearScratchRegs();

  bool isPseudo(const MCInst &Inst) const;

  bool mayAffectControlFlow(const MCInst &Inst) const;
  bool isCall(const MCInst &Inst) const;
  bool isBranch(const MCInst &Inst) const;
  bool isIndirectBranch(const MCInst &Inst) const;
  bool isReturn(const MCInst &Inst) const;
  bool isVariadic(const MCInst &Inst) const;

  bool mayLoad(const MCInst &Inst) const;
  bool mayStore(const MCInst &Inst) const;

  bool mayModifyRegister(const MCInst &Inst, unsigned Reg) const;
  bool explicitlyModifiesRegister(const MCInst &Inst, unsigned Reg) const;

  void replaceDefinitions(MCInst &Inst, unsigned RegOld, unsigned RegNew) const;

  virtual ~MCNaClExpander() = default;
  virtual bool expandInst(const MCInst &Inst, MCStreamer &Out,
                          const MCSubtargetInfo &STI) = 0;
};

}
#endif
