#pragma once
#include <cstdlib> // rand()
#include "Pipe.hpp"
#include "BirdPipeCollider.hpp"


class PipeManager {
public:
    PipeManager(Bird& bird_, unsigned int width_, unsigned int height_)
    : width(width_), height(height_), bird(bird_) {
        pipe_1 = std::make_unique<Pipe>(static_cast<unsigned int>(std::rand()%101),
                                        width, height);
       
    }
    bool update(float dt) {
        BirdPipeCollider collider;
        bool pipeCol1 = collider.checkCollision(bird,*pipe_1);
        bool pipeCol2 = false;
        bool pipeCol3 = false;
        if (pipe_2) { pipeCol2 = collider.checkCollision(bird, *pipe_2); }
        if (pipe_3) { pipeCol3 = collider.checkCollision(bird, *pipe_3); }
        bool allCollision = false;
        if (pipeCol1 || pipeCol2 || pipeCol3) { allCollision = true; }

        if ( !allCollision ) {
            int randbust = height - distance - 10;
            if (!pipe_2 && pipe_1->getPath() > currentPath) {
            pipe_2 = std::make_unique<Pipe>(std::rand() % randbust, width, height);
            }
            if (!pipe_3 && pipe_2 && pipe_2->getPath() > currentPath) {
                pipe_3 = std::make_unique<Pipe>(std::rand() % randbust, width, height);
            }

            if (pipe_1->getPath() > currentPath * 3) {
                pipe_1->reset(std::rand() % randbust, distance);
            }
            if (pipe_2 && pipe_2->getPath() > currentPath * 3) {
                pipe_2->reset(std::rand() % randbust, distance);
            }
            if (pipe_3 && pipe_3->getPath() > currentPath * 3) {
                pipe_3->reset(std::rand() % randbust, distance);
            }

            if (pipe_1) { pipe_1->update(dt); }
            if (pipe_2) { pipe_2->update(dt); }
            if (pipe_3) { pipe_3->update(dt); }
            return true;
        }
        return false;
    }
    void draw(sf::RenderWindow& window) {
        if (pipe_1) pipe_1->draw(window);
        if (pipe_2) pipe_2->draw(window);
        if (pipe_3) pipe_3->draw(window);
    }
    bool checkBirdPassedPipes() {
        BirdPipeCollider collider;

        bool scoredThisFrame = false;

        if (!pipe_1->getScored() && collider.checkBirdPassedPipes(bird, *pipe_1)) {
            pipe_1->Score();
            scoredThisFrame = true;
        }
        if (pipe_2 && !pipe_2->getScored() && collider.checkBirdPassedPipes(bird, *pipe_2)) {
            pipe_2->Score();
            scoredThisFrame = true;
        }
        if (pipe_3 && !pipe_3->getScored() && collider.checkBirdPassedPipes(bird, *pipe_3)) {
            pipe_3->Score();
            scoredThisFrame = true;
        }

        return scoredThisFrame;
    }

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
    bool checkCollision() {
        BirdPipeCollider collider;
        if ( collider.checkCollision(bird,*pipe_1) 
            || collider.checkCollision(bird,*pipe_2)
            || collider.checkCollision(bird,*pipe_3) ) {
            return true;
        }
    }
};