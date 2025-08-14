#pragma once
#include "StateManager.hpp"
#include "GameState.hpp"
#include <iostream>
#include <memory>

class MenuState : public State {
public:
    MenuState(StateManager& Manager,
              int width_, unsigned int height_)
              : manager(Manager), width(width_), height(height_) {
        
        bgtexture.loadFromFile("assets/sprites/background-day.png");
        background = std::make_unique<sf::Sprite>(bgtexture);
        background->setScale({
            static_cast<float>(width)/static_cast<float>(background->getTexture().getSize().x),
            static_cast<float>(height)/static_cast<float>(background->getTexture().getSize().y)
        });

        gameUItexture.loadFromFile("assets/sprites/message.png");
        gameUI = std::make_unique<sf::Sprite>(gameUItexture);
        gameUI->setScale({
            static_cast<float>(width)/static_cast<float>(gameUI->getTexture().getSize().x),
            static_cast<float>(height)/static_cast<float>(gameUI->getTexture().getSize().y)
        });
    }
    void handleEvent(const sf::Event& event) override {
        if (const auto* KeyPresset = event.getIf<sf::Event::KeyPressed>() ) {
            if (KeyPresset->scancode == sf::Keyboard::Scancode::Enter ||
                KeyPresset->scancode == sf::Keyboard::Scancode::Space) {
                ChangeStateToGame();
            }
        }
        else if (const auto* MouseKeyPresset = event.getIf<sf::Event::MouseButtonPressed>()) {
            if (MouseKeyPresset->button == sf::Mouse::Button::Left) {
                ChangeStateToGame();
            }
        }
    }
    void update(float dt) override {

    }
    void draw(sf::RenderWindow& window) override {
        window.draw(*background);
        window.draw(*gameUI);
    }
private:
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

    //TODO: go to game function
    void ChangeStateToGame() {
        manager.setState(std::make_unique<GameState>(manager, width, height));
    }
};