#pragma once 
#include "State.hpp"
#include "memory"

class StateManager {
public:
    void setState(std::unique_ptr<State> newState) {
        state = std::move(newState);
    }
    void handleEvent(const sf::Event& event) {
         if (state) { state->handleEvent(event); }
    }
    void update(float dt) {
         if (state) { state->update(dt); }
    }
    void draw(sf::RenderWindow& window) {
         if (state) { state->draw(window); }
    }
private:
    std::unique_ptr<State> state;
};