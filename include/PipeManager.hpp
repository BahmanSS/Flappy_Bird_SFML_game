#pragma once 
#include "Pipe.hpp"
#include <cstdlib> // rand()
#include <iostream>


class PipeManager {
public:
    PipeManager(unsigned int width_, unsigned int height_): width(width_), height(height_) {
        pipe_1 = std::make_unique<Pipe>(static_cast<unsigned int>(std::rand()%101),
                                        width, height);
       
    }
    void update(float dt) {
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
    }
    void draw(sf::RenderWindow& window) {
        if (pipe_1) pipe_1->draw(window);
        if (pipe_2) pipe_2->draw(window);
        if (pipe_3) pipe_3->draw(window);
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

    
};