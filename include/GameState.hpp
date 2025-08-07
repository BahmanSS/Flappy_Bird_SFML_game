#pragma once
#include "StateManager.hpp"

class GameState: public State {
public:
    GameState(StateManager& Manager, unsigned int width_, unsigned int height_)
              : manager(Manager), width(width_), height(height_)  {}
    void handleEvent(const sf::Event& event) override {}
    void update(float dt) override {}
    void draw(sf::RenderWindow& window) override {}
private:
    StateManager& manager;
    // game window information
    unsigned int width;
    unsigned int height;
};