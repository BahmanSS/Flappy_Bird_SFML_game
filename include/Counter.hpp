#pragma once
#include<SFML/Graphics.hpp>
#include <array>
#include <string>
#include <memory>

class Counter {
public:
    Counter(){
        for (int i = 0; i < 10; ++i) {
            textures[i].loadFromFile( "assets/sprites/" + std::to_string(i) + ".png" );
        }
        for (int i = 0 ; i < 4; ++ i) {
            number[i] = std::make_unique<sf::Sprite>(textures[0]);
            number[i]->setPosition({static_cast<float>(10 + i * number[i]->getTexture().getSize().x), 10.f});
        } 
    }
    
    void draw(sf::RenderWindow& window) {
        for (int i = 0; i < 4; ++i) {
            window.draw(*number[i]);
        }
    }
    void update(float dt) {
        if (cnt < 10000) {
            std::string num = std::to_string(cnt);
            while (num.size() < 4) {
                num = "0" + num;
            }
            for(int i = 0; i < 4; ++i) {
                number[i]->setTexture(textures[ num[i] - '0' ]);
            }
        }
    }
    Counter& operator++() {
        ++cnt;
        return *this;
    }

private:
    std::array <sf::Texture, 10> textures;
    std::array <std::unique_ptr<sf::Sprite>, 4> number;
    int cnt = 0u;
    
};