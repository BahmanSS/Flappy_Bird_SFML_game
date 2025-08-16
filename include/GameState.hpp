#pragma once
#include "StateManager.hpp"
#include "Bird.hpp"
#include "PipeManager.hpp"
#include "Counter.hpp"
#include <iostream>

class GameState: public State {
public:
    GameState(StateManager& Manager, unsigned int width_, unsigned int height_);
    void handleEvent(const sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
private:
    StateManager& manager;
    // game window information
    unsigned int width;
    unsigned int height;
    // Textures
    sf::Texture bgdaytexture;
    sf::Texture bgnighttexture;
    sf::Texture basetexture;
    sf::Texture gameovertexture;
    // Sprites
    std::unique_ptr<sf::Sprite> bgday;
    std::unique_ptr<sf::Sprite> bgnight;
    std::unique_ptr<sf::Sprite> base;
    std::unique_ptr<sf::Sprite> gameOver;
    //SoundBuffers
    sf::SoundBuffer pointbuffer;
    sf::SoundBuffer diebuffer;
    bool dieSoundPlay = false;
    //Sounds
    std::unique_ptr<sf::Sound> pointSound;
    std::unique_ptr<sf::Sound> dieSound;
    // Objects
    Bird bird;
    std::unique_ptr<PipeManager> pipemanager;
    Counter counter;

    void ChangeStateToMenu();
};