#ifndef _PACKT_GRAPHICSSPRITE_HPP_
#define _PACKT_GRAPHICSSPRITE_HPP_

#include "GraphicsManager.hpp"
#include "Resource.hpp"
#include "Types.hpp"

#include <GLES2/gl2.h>

class SpriteBatch;

class Sprite {
public:
    struct Vertex {
        GLfloat x, y, u, v;
    };

    Sprite(GraphicsManager &pGraphicsManager, Resource &pTextureResource, int32_t pHeight,
           int32_t pWidth);

    void setAnimation(int32_t pStartFrame, int32_t pFrameCount, float pSpeed, bool pLoop);

    bool animationEnded() { return mAnimFrame > (mAnimFrameCount - 1); }

    Location location;

protected:
    friend class SpriteBatch;

    status load(GraphicsManager &pGraphicsManager);

    void draw(Vertex pVertex[4], float pTimeStep);

private:
    Sprite(const Sprite &);

    void operator=(const Sprite &);

    Resource &mTextureResource;
    GLuint mTexture;
    // Frame.
    int32_t mSheetHeight, mSheetWidth;
    int32_t mSpriteHeight, mSpriteWidth;
    int32_t mFrameXCount, mFrameYCount, mFrameCount;
    // Animation.
    int32_t mAnimStartFrame, mAnimFrameCount;
    float mAnimSpeed, mAnimFrame;
    bool mAnimLoop;
};
#endif
