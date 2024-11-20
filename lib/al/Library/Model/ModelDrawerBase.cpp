#include "Library/Model/ModelDrawerBase.h"

#include "Library/Draw/GraphicsSystemInfo.h"
#include "Library/Model/ModelDrawBufferCounter.h"
#include "Project/Model/ModelDrawDisplayList.h"

namespace al {

ModelDrawerBase::ModelDrawerBase(const char* name) : mName(name) {}

ModelDrawerBase::~ModelDrawerBase() {}

void ModelDrawerBase::createTable() {
	mModels = new ModelCtrl*[mModelNum];
	for (s32 i = 0; i < mModelNum; i++)
		mModels[i] = nullptr;
}

void ModelDrawerBase::setDrawInfo(agl::DrawContext* drawCtx, const GraphicsSystemInfo* gfxInfo, const ModelDrawBufferCounter* bufferCounter, const ModelKeeper* modelKeeper) {
	mGraphicsSystemInfo = gfxInfo;
	mBufferCounter = bufferCounter;
	mDrawCtx = drawCtx;
	mModelKeeper = modelKeeper;
}

void ModelDrawerBase::registerModel(ModelCtrl* model) {
	mModelNum++;
}

void ModelDrawerBase::addModel(ModelCtrl* model) {
	
}

bool ModelDrawerBase::addModelToTable(ModelCtrl* model) {}

void ModelDrawerBase::removeModel(ModelCtrl* model) {}

void ModelDrawerBase::updateModel(ModelCtrl* model) {}

s32 ModelDrawerBase::getDrawBufferIndex() const {}

void ModelDrawerBase::createModelDrawDisplayList(s32 size) {
	mDrawDisplayList = new ModelDrawDisplayList(mName, mGraphicsSystemInfo->getGpuMemAllocator(), size, mBufferCounter->mDisplayListCount);
}

bool ModelDrawerBase::isDraw() const {
	return mModelMaxNum > 0;
}

}
