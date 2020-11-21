#ifndef _PACKT_DROIDBLASTER_HPP_
#define _PACKT_DROIDBLASTER_HPP_

#include "ActivityHandler.hpp"
#include "GraphicsManager.hpp"
#include "PhysicsManager.hpp"
#include "SoundManager.hpp"
#include "InputHandler.hpp"
#include "MoveableBody.hpp"
#include "SpriteBatch.hpp"
#include "TimeManager.hpp"
#include "EventLoop.hpp"
#include "StarField.hpp"
#include "Resource.hpp"
#include "Asteroid.hpp"
#include "Types.hpp"
#include "Ship.hpp"

class DroidBlaster : public ActivityHandler {
public:
    DroidBlaster(android_app *pApplication);

    void run();

protected:
    status onActivate();
    void onDeactivate();
    status onStep();

    void onStart();
    void onResume();
    void onPause();
    void onStop();
    void onDestroy();

    void onSaveInstanceState(void **pData, size_t *pSize);

    void onConfigurationChanged();

    void onLowMemory();

    void onCreateWindow();

    void onDestroyWindow();

    void onGainFocus();

    void onLostFocus();

private:
    DroidBlaster(const DroidBlaster &);

    void operator=(const DroidBlaster &);

    TimeManager mTimeManager;
    GraphicsManager mGraphicsManager;
    PhysicsManager mPhysicsManager;
    SoundManager mSoundManager;
    InputManager mInputManager;
    EventLoop mEventLoop;

    Resource mAsteroidTexture;
    Resource mShipTexture;
    Resource mStarTexture;
    Resource mBGM;
    Resource mCollisionSound;

    Asteroid mAsteroids;
    Ship mShip;
    StarField mStarField;
    SpriteBatch mSpriteBatch;
    MoveableBody mMoveableBody;

};
#endif
