#pragma once
#include "Bird.hpp"
#include "PipeManager.hpp"

class BirdPipeCollider {
public:
    bool checkCollision(const Bird& bird, const Pipe& pipe );
    bool checkBirdPassedPipes(const Bird& bird, const Pipe& pipe);
};