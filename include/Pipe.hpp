#pragma once 
#include <SFML/Graphics.hpp>
#include <memory>

class Pipe {
public:
    Pipe(unsigned int heightlower_,unsigned int width_, unsigned int height_);
    void draw(sf::RenderWindow& window);
    void update(float dt);
    void reset(unsigned int heightlower, unsigned int distance_);
    void Score();
    bool getScored() const;
    float getPath() const;
    sf::FloatRect getBoundsUpper() const;
    sf::FloatRect getBoundsLower() const;
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
    float velocity = -120.f; 
    float path = 0.f;
    unsigned int heightlower;
    bool scored = false;
    //window info
    float width;
    float height;

};