#pragma once

#include "Library/Area/AreaShape.h"

namespace al {

class AreaShapeOval : public AreaShape {
public:
    AreaShapeOval();

    bool isInVolume(const sead::Vector3f&) const override;
    bool isInVolumeOffset(const sead::Vector3f&, f32) const override;
    bool calcNearestEdgePoint(sead::Vector3f*, const sead::Vector3f&) const override;
    bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&,
                             const sead::Vector3f&) const override;

    bool calcLocalBoundingBox(sead::BoundBox3f*) const override { return false; }
};

}  // namespace al
