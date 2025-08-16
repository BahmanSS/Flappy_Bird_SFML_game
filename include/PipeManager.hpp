#pragma once
#include <cstdlib> // rand()
#include "Pipe.hpp"
#include "BirdPipeCollider.hpp"


class PipeManager {
public:
    PipeManager(Bird& bird_, unsigned int width_, unsigned int height_);
    bool update(float dt);
    void draw(sf::RenderWindow& window);
    bool checkBirdPassedPipes();
private:
    std::unique_ptr <Pipe> pipe_1;
    std::unique_ptr <Pipe> pipe_2;
    std::unique_ptr <Pipe> pipe_3;
    float currentPath = 300.f;
    unsigned int distance = 170u;
    //window info
    unsigned int width;
    unsigned int height;
    // Bird info
    Bird& bird;
    // BirdPipeCollider
    bool checkCollision();
};