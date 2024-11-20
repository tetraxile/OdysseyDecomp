#pragma once

#include <basis/seadTypes.h>
#include <gfx/seadCamera.h>

#include <utility/aglParameter.h>
#include <utility/aglParameterObj.h>
#include <utility/aglParameterIO.h>

namespace agl {
class DrawContext;

namespace sdw {
class PrimitiveOcclusion;
}
}

namespace nn::g3d {
struct Aabb {
    char filler[0x20];
};

static_assert(sizeof(Aabb) == 0x20);

struct Plane {
    char filler[0x20];
};

static_assert(sizeof(Plane) == 0x20);

struct ViewVolume {
    Aabb unk1;
    Plane unk2[6];
    s32 unk3;
    s32 unk4;
};

static_assert(sizeof(ViewVolume) == 0xe8);
}

namespace al {
class AreaObjDirector;
class ExecuteDirector;
class EffectSystem;
class PlayerHolder;
class SceneCameraInfo;
class ShaderHolder;
class BloomDirector;
class CubeMapDirector;
class DirectionalLightKeeper;
class GraphicsAreaDirector;
class GraphicsPresetDirector;
class DemoGraphicsController;
class RadialBlurDirector;
class PrePassLightKeeper;
class ShaderEnvTextureKeeper;
class ShadowDirector;
class DepthOfFieldDrawer;
class GraphicsQualityController;
class ShaderMirrorDirector;
class GraphicsParamRequesterImpl;
class FlareFilterDirector;
class GodRayDirector;
class FogDirector;
class OccludedEffectDirector;
class LightStreakDirector;
class HdrCompose;
class SSIIKeeper;
class OceanWave;
class RandomTextureKeeper;
class WorldAODirector;
class PointSpriteCursorHolder;
class MaterialLightDirector;
class MaterialCategoryKeeper;
class SkyDirector;
class OcclusionCullingJudge;
class VignettingDrawer;
class CameraBlurController;
class ThunderRenderKeeper;
class StarrySky;
class NoiseTextureKeeper;
class CloudRenderKeeper;
class GpuMemAllocator;
class FootPrintTextureKeeper;
class ProgramTextureKeeper;
class RippleTextureKeeper;
class ViewRenderer;
class SubCameraRenderer;
class TemporalInterlace;
class PeripheryRendering;
class PostProcessingFilter;
class GBufferArray;
class Projection;
class FilterAA;
class AtmosScatter;
class AtmosScatterDrawer;
class GraphicsParamFilePath;
class UniformBlock;
class Resource;
class VastMeshGridDirector;
class FullScreenTriangle;
class ReducedBufferRenderer;
class ModelOcclusionCullingDirector;
class ModelLodAllCtrl;
class ModelShaderHolder;
class PrepassTriangleCulling;
class ApplicationMessageReceiver;

class GraphicsInitArg {
public:
    GraphicsInitArg();
    bool isUsingCubeMapAtmosScatter() const;
    s32 getAtmosScatterViewNum() const;

private:
    char filler[0x48];
};

static_assert(sizeof(GraphicsInitArg) == 0x48);

class GraphicsSystemInfo {
public:
    GraphicsSystemInfo();
    ~GraphicsSystemInfo();

    void init(const GraphicsInitArg&, AreaObjDirector*, ExecuteDirector*, EffectSystem*,
              PlayerHolder*, SceneCameraInfo*, ShaderHolder*);

    agl::DrawContext* getDrawContext() const;
    void endInit();
    void initAfterPlacement();
    void clearGraphicsRequest();
    void updateGraphics();
    void preDrawGraphics(SceneCameraInfo*);

    GpuMemAllocator* getGpuMemAllocator() const { return mGpuMemAllocator; }

private:
    unsigned char filler[0x20];
    GraphicsInitArg mGraphicsInitArg;
    BloomDirector* mBloomDirector;
    CubeMapDirector* mCubeMapDirector;
    DirectionalLightKeeper* mDirectionalLightKeeper;
    GraphicsAreaDirector* mGraphicsAreaDirector;
    GraphicsPresetDirector* mGraphicsPresetDirector;
    DemoGraphicsController* mDemoGraphicsController;
    RadialBlurDirector* mRadialBlurDirector;
    PrePassLightKeeper* mPrePassLightKeeper;
    ShaderEnvTextureKeeper* mShaderEnvTextureKeeper;
    ShadowDirector* mShadowDirector;
    DepthOfFieldDrawer* mDepthOfFieldDrawer;
    GraphicsQualityController* mGraphicsQualityController;
    ShaderMirrorDirector* mShaderMirrorDirector;
    GraphicsParamRequesterImpl* mRequesterSSAO;
    GraphicsParamRequesterImpl* mRequesterColorCorrection;
    FlareFilterDirector* mFlareFilterDirector;
    GodRayDirector* mGodRayDirector;
    FogDirector* mFogDirector;
    OccludedEffectDirector* mOccludedEffectDirector;
    LightStreakDirector* mLightStreakDirector;
    HdrCompose* mHdrCompose;
    SSIIKeeper* mSSIIKeeper;
    agl::sdw::PrimitiveOcclusion* mPrimitiveOcclusion;
    nn::g3d::ViewVolume mViewVolume;
    void* unk1;
    OceanWave* mOceanWave;
    RandomTextureKeeper* mRandomTextureKeeper;
    WorldAODirector* mWorldAODirector;
    PointSpriteCursorHolder* mPointSpriteCursorHolder;
    MaterialLightDirector* mMaterialLightDirector;
    MaterialCategoryKeeper* mMaterialCategoryKeeper;
    SkyDirector* mSkyDirector;
    ShaderHolder* mShaderHolder;
    OcclusionCullingJudge* mOcclusionCullingJudge;
    VignettingDrawer* mVignettingDrawer;
    CameraBlurController* mCameraBlurController;
    ThunderRenderKeeper* mThunderRenderKeeper;
    StarrySky* mStarrySky;
    NoiseTextureKeeper* mNoiseTextureKeeper;
    CloudRenderKeeper* mCloudRenderKeeper;
    GpuMemAllocator* mGpuMemAllocator;
    FootPrintTextureKeeper* mFootPrintTextureKeeper;
    ProgramTextureKeeper* mProgramTextureKeeper;
    RippleTextureKeeper* mRippleTextureKeeper;
    void* unk2;
    ViewRenderer* mViewRenderer;
    SubCameraRenderer* mSubCameraRenderer;
    TemporalInterlace* mTemporalInterlace;
    PeripheryRendering* mPeripheryRendering;
    PostProcessingFilter* mPostProcessingFilter;
    GBufferArray* mGBufferArray;
    sead::Camera* mDrawEnvCamera;
    Projection* mDrawEnvProjection;
    s32 mViewIndex;
    u32 unk3;
    FilterAA* mFilterAA;
    AtmosScatter* mAtmosScatter;
    AtmosScatterDrawer* mAtmosScatterDrawer;
    GraphicsParamFilePath* mFilePathaglgfx;
    agl::utl::IParameterIO mGraphicsSystemParam;
    agl::utl::IParameterObj mGraphicsSystemParamObj;
    agl::utl::Parameter<s32> mAreaFindMode;
    agl::utl::Parameter<s32> mAtmosScatterType;
    agl::utl::Parameter<bool> mIsUsingUpdateAtmosCubeMap;
    agl::utl::Parameter<bool> mIsUsingOceanWave;
    agl::utl::Parameter<s32> mOccGroupNum;
    agl::utl::IParameterIO mProjectParam;
    agl::utl::IParameterObj mProjectParamObj;
    agl::utl::Parameter<bool> mIsUsingTemporal;
    agl::utl::Parameter<bool> mIsUsingPeriphery;
    agl::utl::Parameter<bool> mIsUsingStarrySky;
    agl::utl::Parameter<f32> mCubeMapIntensityPower;
    agl::utl::Parameter<f32> mCubeMapIntensityRange;
    agl::utl::Parameter<f32> mLineLightAntiArtifact;
    agl::utl::Parameter<f32> mMinRoughnessGGX;
    agl::utl::Parameter<f32> mSphereLightDiffuseAdd;
    agl::utl::Parameter<f32> mSpecularScale;
    agl::utl::Parameter<f32> mLightUnitScale;
    agl::utl::Parameter<f32> mLightColorScale;
    UniformBlock* unk4;
    Resource* mStageResource;
    AreaObjDirector* mAreaObjDirector;
    ExecuteDirector* mExecuteDirector;
    EffectSystem* mEffectSystem;
    SceneCameraInfo* mSceneCameraInfo;
    void* unk5;
    sead::ListNode mPartsGraphics;
    s32 mPartsGraphicsCount;
    VastMeshGridDirector* mVastMeshGridDirector;
    FullScreenTriangle* mFullScreenTriangle;
    void* unk6;
    ReducedBufferRenderer* mReducedBufferRenderer;
    ModelOcclusionCullingDirector* mModelOcclusionCullingDirector;
    ModelLodAllCtrl* mModelLodAllCtrl;
    ModelShaderHolder* mModelShaderHolder;
    PrepassTriangleCulling* mPrepassTriangleCulling;
    void* unk7;
    ApplicationMessageReceiver* mApplicationMessageReceiver;
    void* unk8;
};

static_assert(sizeof(GraphicsSystemInfo) == 0x9c0);

}  // namespace al
