/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkComposeShader_DEFINED
#define SkComposeShader_DEFINED

#include "include/core/SkBlendMode.h"
#include "src/shaders/SkShaderBase.h"

class SkShader_Blend final : public SkShaderBase {
public:
    SkShader_Blend(SkBlendMode mode, sk_sp<SkShader> dst, sk_sp<SkShader> src)
        : fDst(std::move(dst))
        , fSrc(std::move(src))
        , fMode(mode)
    {}

#if SK_SUPPORT_GPU
    std::unique_ptr<GrFragmentProcessor> asFragmentProcessor(const GrFPArgs&) const override;
#endif

protected:
    SkShader_Blend(SkReadBuffer&);
    void flatten(SkWriteBuffer&) const override;
    bool onAppendStages(const SkStageRec&) const override;
    skvm::Color onProgram(skvm::Builder*, skvm::F32 x, skvm::F32 y, skvm::Color paint,
                          const SkMatrixProvider&, const SkMatrix* localM,
                          SkFilterQuality, const SkColorInfo& dst,
                          skvm::Uniforms*, SkArenaAlloc*) const override;

private:
    SK_FLATTENABLE_HOOKS(SkShader_Blend)

    sk_sp<SkShader>     fDst;
    sk_sp<SkShader>     fSrc;
    const SkBlendMode   fMode;

    typedef SkShaderBase INHERITED;
};

class SkShader_Lerp final : public SkShaderBase {
public:
    SkShader_Lerp(float weight, sk_sp<SkShader> dst, sk_sp<SkShader> src)
        : fDst(std::move(dst))
        , fSrc(std::move(src))
        , fWeight(weight)
    {
        SkASSERT(weight >= 0 && weight <= 1);
    }

#if SK_SUPPORT_GPU
    std::unique_ptr<GrFragmentProcessor> asFragmentProcessor(const GrFPArgs&) const override;
#endif

protected:
    SkShader_Lerp(SkReadBuffer&);
    void flatten(SkWriteBuffer&) const override;
    bool onAppendStages(const SkStageRec&) const override;
    skvm::Color onProgram(skvm::Builder*, skvm::F32 x, skvm::F32 y, skvm::Color paint,
                          const SkMatrixProvider&, const SkMatrix* localM,
                          SkFilterQuality, const SkColorInfo& dst,
                          skvm::Uniforms*, SkArenaAlloc*) const override;

private:
    SK_FLATTENABLE_HOOKS(SkShader_Lerp)

    sk_sp<SkShader> fDst;
    sk_sp<SkShader> fSrc;
    const float     fWeight;

    typedef SkShaderBase INHERITED;
};

#endif
