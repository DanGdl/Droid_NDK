#include "Ship.hpp"
#include "Log.hpp"

static const float INITIAL_X = 0.5f;
static const float INITIAL_Y = 0.25f;

Ship::Ship(android_app *pApplication, GraphicsManager &pGraphicsManager,
           SoundManager &pSoundManager) :
        mGraphicsManager(pGraphicsManager), mGraphics(NULL), mSoundManager(pSoundManager),
        mCollisionSound(NULL) {
}

void Ship::registerShip(Sprite *pGraphics, Sound *pCollisionSound) {
    mGraphics = pGraphics;
    mCollisionSound = pCollisionSound;
}

void Ship::registerShip(Sprite *pGraphics) {
    mGraphics = pGraphics;
}

void Ship::initialize() {
    mGraphics->location.x = INITIAL_X * mGraphicsManager.getRenderWidth();
    mGraphics->location.y = INITIAL_Y * mGraphicsManager.getRenderHeight();
    mSoundManager.playSound(mCollisionSound);

}
