#pragma once
#include "StateManager.hpp"
#include "Bird.hpp"
#include "PipeManager.hpp"
#include "Counter.hpp"
#include <iostream>

class GameState: public State {
public:
    GameState(StateManager& Manager, unsigned int width_, unsigned int height_)
              : manager(Manager), width(width_), height(height_), bird(width/2,height/2) {
                // Load textures
                bgdaytexture.loadFromFile("assets/sprites/background-day.png");
                bgnighttexture.loadFromFile("assets/sprites/background-night.png");
                basetexture.loadFromFile("assets/sprites/base.png");
                gameovertexture.loadFromFile("assets/sprites/gameover.png");
                // Create Sprites
                bgday = std::make_unique<sf::Sprite>(bgdaytexture);
                bgday->setScale({
                    static_cast<float>(width)/static_cast<float>(bgday->getTexture().getSize().x),
                    static_cast<float>(height)/static_cast<float>(bgday->getTexture().getSize().y)
                });

                bgnight = std::make_unique<sf::Sprite>(bgnighttexture);
                bgnight->setScale({
                    static_cast<float>(width)/static_cast<float>(bgnight->getTexture().getSize().x),
                    static_cast<float>(height)/static_cast<float>(bgnight->getTexture().getSize().y)
                });

                base = std::make_unique<sf::Sprite>(basetexture);
                base->setPosition({0.f,static_cast<float>(height - basetexture.getSize().y)});
                base->setScale({static_cast<float>(width)/static_cast<float>(basetexture.getSize().x),1.f});

                gameOver = std::make_unique<sf::Sprite>(gameovertexture);
                gameOver->setOrigin({static_cast<float>(gameovertexture.getSize().x/2),
                                    static_cast<float>(gameovertexture.getSize().y/2)});
                gameOver->setPosition({static_cast<float>(width/2),static_cast<float>(height/2)});
                gameOver->setScale({1.5f,1.5f});
                //Load SoundBuffers
                pointbuffer.loadFromFile("assets/audio/point.wav");
                diebuffer.loadFromFile("assets/audio/die.wav");
                //Create Sound
                pointSound = std::make_unique<sf::Sound>(pointbuffer);
                dieSound = std::make_unique<sf::Sound>(diebuffer);

                // Others
                pipemanager = std::make_unique<PipeManager>(bird, width, height - base->getTexture().getSize().y * base->getScale().y);
              }
    void handleEvent(const sf::Event& event) override {
        if (const auto* KeyPresset = event.getIf<sf::Event::KeyPressed>() ) {
            if (KeyPresset->scancode == sf::Keyboard::Scancode::Enter ||
                KeyPresset->scancode == sf::Keyboard::Scancode::Space) {
                if (!dieSoundPlay) {
                    bird.flap();
                }
                else {
                    ChangeStateToMenu();
                }
            }
        }
        else if (const auto* MouseKeyPresset = event.getIf<sf::Event::MouseButtonPressed>()) {
            if (MouseKeyPresset->button == sf::Mouse::Button::Left) {
                if (!dieSoundPlay) {
                    bird.flap();
                }
                else {
                    ChangeStateToMenu();
                }
            }
        }
    }
    void update(float dt) override {
        if (pipemanager->update(dt)) {
            bird.update(dt,width,height - base->getTexture().getSize().y * base->getScale().y);
            if (pipemanager->checkBirdPassedPipes()) {
                ++counter;
                pointSound->play();
            }
            counter.update(dt);
            
        }
        else {
            if(dieSound->getStatus() != sf::SoundSource::Status::Playing && !dieSoundPlay) {
                dieSound->play();
                dieSoundPlay = true;
            }
            counter.SaveScoreToFile();

        }
    }
    void draw(sf::RenderWindow& window) override {
        window.draw(*bgnight);
        pipemanager->draw(window);
        window.draw(*base);
        bird.draw(window);
        counter.draw(window);
        if (dieSoundPlay == true) {
            window.draw(*gameOver);
        }
    }
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