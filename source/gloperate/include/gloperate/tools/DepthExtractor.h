#pragma once

#include <gloperate/gloperate_api.h>

#include <gloperate/tools/GBufferExtractor.h>

namespace gloperate
{

class GLOPERATE_API DepthExtractor : protected GBufferExtractor
{
public:
    DepthExtractor(
        AbstractViewportCapability * viewportCapability,
        AbstractTypedRenderTargetCapability * typedRenderTargetCapability);

    virtual ~DepthExtractor();

    float get(const glm::ivec2 & windowCoordinates) const;
    static bool isValidDepth(const float depth);
};

} // namespace gloperate
