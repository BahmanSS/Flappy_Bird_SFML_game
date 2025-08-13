#pragma once
#include "Bird.hpp"
#include "PipeManager.hpp"

class BirdPipeCollider {
public:
    bool checkCollision(const Bird& bird, const Pipe& pipe ) {
        sf::FloatRect birdBounds = bird.getGlobalBounds();
        birdBounds.position = {birdBounds.position.x+5.f,birdBounds.position.y+5.f};
        birdBounds.size = {birdBounds.size.x-10.f,birdBounds.size.y-10.f};
        sf::FloatRect lowerbounds = pipe.getBoundsLower();
        sf::FloatRect upperbounds = pipe.getBoundsUpper();
        if (birdBounds.findIntersection(lowerbounds).has_value() 
            || birdBounds.findIntersection(upperbounds).has_value()) {
                return true;
        }
        return false;
    }
};