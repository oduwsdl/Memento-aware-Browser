/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrTextureGradientColorizer.fp; do not modify.
 **************************************************************************************************/
#ifndef GrTextureGradientColorizer_DEFINED
#define GrTextureGradientColorizer_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"

#include "src/gpu/GrCoordTransform.h"
#include "src/gpu/GrFragmentProcessor.h"

class GrTextureGradientColorizer : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(
            std::unique_ptr<GrFragmentProcessor> textureFP) {
        return std::unique_ptr<GrFragmentProcessor>(
                new GrTextureGradientColorizer(std::move(textureFP)));
    }
    GrTextureGradientColorizer(const GrTextureGradientColorizer& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "TextureGradientColorizer"; }
    int textureFP_index = -1;

private:
    GrTextureGradientColorizer(std::unique_ptr<GrFragmentProcessor> textureFP)
            : INHERITED(kGrTextureGradientColorizer_ClassID, kNone_OptimizationFlags) {
        SkASSERT(textureFP);
        textureFP->setSampledWithExplicitCoords();
        textureFP_index = this->registerChildProcessor(std::move(textureFP));
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    typedef GrFragmentProcessor INHERITED;
};
#endif
