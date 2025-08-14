#pragma once
#include "Bird.hpp"
#include "PipeManager.hpp"

class BirdPipeCollider {
public:
    bool checkCollision(const Bird& bird, const Pipe& pipe ) {
        sf::FloatRect birdBounds = bird.getGlobalBounds();
        birdBounds.position = {birdBounds.position.x+10.f,birdBounds.position.y+5.f};
        birdBounds.size = {birdBounds.size.x-17.f,birdBounds.size.y-13.f};
        sf::FloatRect lowerbounds = pipe.getBoundsLower();
        sf::FloatRect upperbounds = pipe.getBoundsUpper();
        if (birdBounds.findIntersection(lowerbounds).has_value() 
            || birdBounds.findIntersection(upperbounds).has_value()) {
                return true;
        }
        return false;
    }
    bool checkBirdPassedPipes(const Bird& bird, const Pipe& pipe) {
        return bird.getGlobalBounds().position.x > pipe.getBoundsLower().position.x;
    }
};