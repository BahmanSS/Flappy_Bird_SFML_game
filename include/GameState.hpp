#pragma once
#include "StateManager.hpp"
#include "Bird.hpp"
#include "PipeManager.hpp"

class GameState: public State {
public:
    GameState(StateManager& Manager, unsigned int width_, unsigned int height_)
              : manager(Manager), width(width_), height(height_), bird(width/2,height/2), 
                pipemanager(width_, height_) {
                bgdaytexture.loadFromFile("assets/sprites/background-day.png");
                bgday = std::make_unique<sf::Sprite>(bgdaytexture);
                bgday->setScale({
                    static_cast<float>(width)/static_cast<float>(bgday->getTexture().getSize().x),
                    static_cast<float>(height)/static_cast<float>(bgday->getTexture().getSize().y)
                });
                bgnighttexture.loadFromFile("assets/sprites/background-night.png");
                bgnight = std::make_unique<sf::Sprite>(bgnighttexture);
                bgnight->setScale({
                    static_cast<float>(width)/static_cast<float>(bgnight->getTexture().getSize().x),
                    static_cast<float>(height)/static_cast<float>(bgnight->getTexture().getSize().y)
                });
                

              }
    void handleEvent(const sf::Event& event) override {
        if (const auto* KeyPresset = event.getIf<sf::Event::KeyPressed>() ) {
            if (KeyPresset->scancode == sf::Keyboard::Scancode::Enter ||
                KeyPresset->scancode == sf::Keyboard::Scancode::Space) {
                bird.flap();
            }
        }
        else if (const auto* MouseKeyPresset = event.getIf<sf::Event::MouseButtonPressed>()) {
            if (MouseKeyPresset->button == sf::Mouse::Button::Left) {
                bird.flap();
            }
        }
    }
    void update(float dt) override {
        bird.update(dt,width,height);
        pipemanager.update(dt);
    }
    void draw(sf::RenderWindow& window) override {
        window.draw(*bgnight);
        bird.draw(window);
        pipemanager.draw(window);
    }
private:
    StateManager& manager;
    // game window information
    unsigned int width;
    unsigned int height;
    // Textures
    sf::Texture bgdaytexture;
    sf::Texture bgnighttexture;
    // Sprites
    std::unique_ptr<sf::Sprite> bgday;
    std::unique_ptr<sf::Sprite> bgnight;

    Bird bird;
    PipeManager pipemanager;
};