#pragma once

namespace agl {
class DrawContext;
}

namespace al {

class FullScreenQuadModel {
public:
	FullScreenQuadModel();
	~FullScreenQuadModel();
	void drawQuad(agl::DrawContext* drawCtx) const;

private:
	// agl::VertexAttribute mVertexAttr;
	// agl::VertexBuffer* mVertexBuffer;
	// agl::GPUMemBlockBase mGPUBlock;
};

// static_assert(sizeof(FullScreenQuadModel) == 0x220);

}
