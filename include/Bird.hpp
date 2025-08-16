#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <vector>
#include "BirdCollider.hpp"

class Bird {
public:
    Bird(float x, float y);
    void flap();
    void update(float dt, unsigned int width, unsigned int height);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds() const;
private:
    //Textures 
    sf::Texture birddowntexture;
    sf::Texture birdmiddletexture;
    sf::Texture birduptexture;
    //Sprite
    std::unique_ptr<sf::Sprite> bird;
    //SoundBuffer
    sf::SoundBuffer flapBuffer;
    //Sound
    std::unique_ptr<sf::Sound> flapSound;
    // Bird
    float velocity = 0.f;
    float gravity = 450.f;
    float jumpimpulse = -250.f;

    float animationTimer = 0.f;
    float animationDelay = 0.1f;
    int currentScene; // up/middle/down -> 0/1/2

};