#pragma once 
#include <SFML/Graphics.hpp>
#include <memory>

class Pipe {
public:
    // heightlower
    Pipe(unsigned int heightlower,unsigned int width_, unsigned int height_)
                : width(static_cast<float>(width_)), height(static_cast<float>(height_)) {
        pipetexture.loadFromFile("assets/sprites/pipe-red.png");
        
        widthpipe = pipetexture.getSize().x;
        heightpipe = pipetexture.getSize().y;

        lowerpipe = std::make_unique<sf::Sprite>(pipetexture);
        upperpipe = std::make_unique<sf::Sprite>(pipetexture);

        upperpipe->setScale({1.5f,2.f});
        lowerpipe->setScale({1.5f,2.f});

        upperpipe->setRotation(sf::degrees(180));

        lowerpipe->setPosition({width, height - heightlower});
        upperpipe->setPosition({width + widthpipe * upperpipe->getScale().x, height - heightlower - distance});
    } 
    void draw(sf::RenderWindow& window) {
        window.draw(*lowerpipe);
        window.draw(*upperpipe);
    }
    void update(float dt) {
        lowerpipe->move({velocity*dt, 0.f});
        upperpipe->move({velocity*dt, 0.f});
        path += -velocity*dt;
    }
    void reset(unsigned int heightlower, unsigned int distance_) {
        distance = distance_;
        path = 0.f;
        lowerpipe->setPosition({width, height - heightlower});
        upperpipe->setPosition({width + widthpipe * upperpipe->getScale().x, height - heightlower - distance});
    }
    float getPath() { return path; }
private:
    //Textures
    sf::Texture pipetexture;
    //Sprites
    std::unique_ptr <sf::Sprite> lowerpipe;
    std::unique_ptr <sf::Sprite> upperpipe;
    // info for Pipe
    float widthpipe;
    float heightpipe;
    unsigned int distance = 170u;
    float velocity = -100.f;
    float path = 0.f;
    //window info
    float width;
    float height;

};