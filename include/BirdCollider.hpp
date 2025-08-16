#pragma once
#include "Bird.hpp"
#include <SFML/Graphics/Rect.hpp>

//A class showing whether the bird encounters window frames and, if so, which ones
class BirdCollider {
public:
    // 0 - not collision / 1 - down collision / 2 - up collision
    int checkCollision(const sf::FloatRect& bird, unsigned int width, unsigned int height);
};