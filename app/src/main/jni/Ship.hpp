#ifndef _PACKT_SHIP_HPP_
#define _PACKT_SHIP_HPP_

#include "GraphicsManager.hpp"
#include "SoundManager.hpp"
#include "Sprite.hpp"

class Ship {
public:
    Ship(android_app *pApplication, GraphicsManager &pGraphicsManager, SoundManager &pSoundManager);

    void registerShip(Sprite *pGraphics, Sound *pCollisionSound);

    void registerShip(Sprite *pGraphics);

    void initialize();

private:
    Ship(const Ship &);

    void operator=(const Ship &);

    GraphicsManager &mGraphicsManager;
    SoundManager &mSoundManager;

    Sprite *mGraphics;
    Sound *mCollisionSound;

};

#endif
