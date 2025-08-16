#pragma once
#include<SFML/Graphics.hpp>
#include <array>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

class Counter {
public:
    Counter();
    void draw(sf::RenderWindow& window);
    void update(float dt);
    Counter& operator++();
    bool SaveScoreToFile();
    bool LoadScoreFromFile();
    void resetScore();
private:
    std::array <sf::Texture, 10> textures;
    std::array <std::unique_ptr<sf::Sprite>, 4> number;
    int cnt = 0u;
};