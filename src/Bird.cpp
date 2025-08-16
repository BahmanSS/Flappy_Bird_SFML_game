#include "Bird.hpp"

Bird::Bird(float x, float y) {
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
        // Get SoundBuffer
        flapBuffer.loadFromFile("assets/audio/wing.wav");
        // Create Sound
        flapSound = std::make_unique<sf::Sound>(flapBuffer);
        
    }
void Bird::flap() {
    velocity = jumpimpulse;
    flapSound->play();
}
void Bird::update(float dt, unsigned int width, unsigned int height) {
    //Animation fly
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
    // change velocity and rotation bird
    velocity += gravity * dt;
    if (velocity < 0.f ) {
        bird->setRotation(sf::degrees(-25));
    }
    else {
        bird->setRotation(sf::degrees(25));
    }

    sf::FloatRect birdbounds = bird->getGlobalBounds();
    BirdCollider ColliderBird;
    if (ColliderBird.checkCollision(birdbounds,width,height) == 0 ||
        ColliderBird.checkCollision(birdbounds,width,height) == 1 && velocity < 0 ||
        ColliderBird.checkCollision(birdbounds,width,height) == 2 && velocity > 0 ) {
        bird->move({0.f, velocity * dt});
    }
}
void Bird::draw(sf::RenderWindow& window) {
    window.draw(*bird);
}
sf::FloatRect Bird::getGlobalBounds() const {
    return bird->getGlobalBounds();
}