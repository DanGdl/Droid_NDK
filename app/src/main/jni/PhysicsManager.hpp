#ifndef PACKT_PHYSICSMANAGER_HPP
#define PACKT_PHYSICSMANAGER_HPP

#include "GraphicsManager.hpp"
#include "TimeManager.hpp"
#include "Types.hpp"

#include <Box2D/Box2D.h>
#include <vector>

#define PHYSICS_SCALE 32.0f

struct PhysicsCollision {
    bool collide;

    PhysicsCollision() :
            collide(false) {}
};

struct PhysicsBody {
    PhysicsBody(Location *pLocation, int32_t pWidth, int32_t pHeight) :
            location(pLocation),
            width(pWidth), height(pHeight),
            velocityX(0.0f), velocityY(0.0f) {
    }

    Location *location;
    int32_t width;
    int32_t height;
    float velocityX;
    float velocityY;
};

class PhysicsManager : private b2ContactListener {
public:
    PhysicsManager(TimeManager &pTimeManager, GraphicsManager &pGraphicsManager);

    ~PhysicsManager();

    b2Body *
    loadBody(Location &pLocation, uint16 pCategory, uint16 pMask, int32_t pSizeX, int32_t pSizeY,
             float pRestitution);

    b2MouseJoint *loadTarget(b2Body *pBodyObj);

    void start();

    void update();

private:
    PhysicsManager(const PhysicsManager &);

    void operator=(const PhysicsManager &);

    void BeginContact(b2Contact *pContact);

    TimeManager &mTimeManager;
    GraphicsManager &mGraphicsManager;

    b2World mWorld;
    std::vector<b2Body *> mBodies;
    std::vector<Location *> mLocations;
    b2Body *mBoundsBodyObj;

};
#endif
