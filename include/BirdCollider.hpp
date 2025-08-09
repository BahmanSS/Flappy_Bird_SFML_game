#pragma once
#include "Bird.hpp"
#include <SFML/Graphics/Rect.hpp>

//A class showing whether the bird encounters window frames and, if so, which ones
class BirdCollider {
public:
    // 0 - not collision / 1 - down collision / 2 - up collision
    int checkCollision(const sf::FloatRect& bird, unsigned int width, unsigned int height) {
        sf::FloatRect windowdown({0.f,static_cast<float>(height)},
                                 {static_cast<float>(width), 100.f});
        sf::FloatRect windowup({0.f,-100.f},
                                 {static_cast<float>(width), 100.f});
        auto intersectiondown = bird.findIntersection(windowdown);
        auto intersectionup = bird.findIntersection(windowup);
        if (intersectiondown.has_value()) {
            return 1;
        }
        else if (intersectionup.has_value()) {
            return 2;
        }
        return 0;
    }
};