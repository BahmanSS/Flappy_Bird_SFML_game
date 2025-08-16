#pragma once
#include "StateManager.hpp"
#include "GameState.hpp"
#include <iostream>
#include <memory>
#include "Counter.hpp"

class MenuState : public State {
public:
    MenuState(StateManager& Manager, int width_, unsigned int height_);
    void handleEvent(const sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
private:
    Counter counter;
    StateManager& manager;
    // game window information
    unsigned int width;
    unsigned int height;
    // Textures
    sf::Texture bgtexture;
    sf::Texture gameUItexture;
    // Sprites
    std::unique_ptr <sf::Sprite> background;
    std::unique_ptr <sf::Sprite> gameUI;
    void ChangeStateToGame();
};