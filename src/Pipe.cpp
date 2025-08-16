#include "Pipe.hpp"

Pipe::Pipe(unsigned int heightlower_, unsigned int width_, unsigned int height_)
            : heightlower(heightlower_), width(static_cast<float>(width_)),
              height(static_cast<float>(height_)) {
    pipetexture.loadFromFile("assets/sprites/pipe-red.png");

    widthpipe = pipetexture.getSize().x;
    heightpipe = pipetexture.getSize().y;

    lowerpipe = std::make_unique<sf::Sprite>(pipetexture);
    upperpipe = std::make_unique<sf::Sprite>(pipetexture);

    upperpipe->setScale({1.5f, 2.f});
    lowerpipe->setScale({1.5f, 2.f});

    upperpipe->setRotation(sf::degrees(180));

    lowerpipe->setPosition({width, height - heightlower});
    upperpipe->setPosition({width + widthpipe * upperpipe->getScale().x, height - heightlower - distance});
}
void Pipe::draw(sf::RenderWindow &window) {
    window.draw(*lowerpipe);
    window.draw(*upperpipe);
}
void Pipe::update(float dt) {
    lowerpipe->move({velocity * dt, 0.f});
    upperpipe->move({velocity * dt, 0.f});
    path += -velocity * dt;
}
void Pipe::reset(unsigned int heightlower, unsigned int distance_) {
    scored = false;
    distance = distance_;
    path = 0.f;
    lowerpipe->setPosition({width, height - heightlower});
    upperpipe->setPosition({width + widthpipe * upperpipe->getScale().x, height - heightlower - distance});
}
void Pipe::Score() { scored = true; }
bool Pipe::getScored() const { return scored; }
float Pipe::getPath() const { return path; }
sf::FloatRect Pipe::getBoundsUpper() const {
    return upperpipe->getGlobalBounds();
}
sf::FloatRect Pipe::getBoundsLower() const {
    return lowerpipe->getGlobalBounds();
}