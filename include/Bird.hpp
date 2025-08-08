#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Bird {
public:
    Bird(float x, float y) {
        //Get textures
        birddowntexture.loadFromFile("assets/sprites/yellowbird-downflap.png");
        birdmiddletexture.loadFromFile("assets/sprites/yellowbird-midflap.png");
        birduptexture.loadFromFile("assets/sprites/yellowbird-upflap.png");
        //Create sprite
        bird = std::make_unique<sf::Sprite>(birdmiddletexture);
        bird->setScale({1.5,1.5});
        bird->setPosition({x,y});
        auto bounds = bird->getLocalBounds();
        bird->setOrigin({bounds.getCenter().x, bounds.getCenter().y}); 
    }

    void flap() {
        velocity = jumpimpulse;
    }
    void update(float dt) {
        animationTimer += dt;
        if (animationTimer > animationDelay) {
            animationTimer = 0.f;
            currentScene = (currentScene+1) % 3;
            if (currentScene == 0) {
                bird->setTexture(birduptexture);
            }
            else if (currentScene == 1) {
                bird->setTexture(birdmiddletexture);
            }
            else {
                bird->setTexture(birddowntexture);
            }
        }

        velocity += gravity * dt;
        bird->move({0.f, velocity * dt});
    }
    void draw(sf::RenderWindow& window) {
        window.draw(*bird);
    }
private:
    //Textures 
    sf::Texture birddowntexture;
    sf::Texture birdmiddletexture;
    sf::Texture birduptexture;
    //Sprite
    std::unique_ptr<sf::Sprite> bird;
    // Bird
    float velocity = 0.f;
    float gravity = 500.f;
    float jumpimpulse = -300.f;

    float animationTimer = 0.f;
    float animationDelay = 0.1f;
    int currentScene; // up/middle/down -> 0/1/2

};