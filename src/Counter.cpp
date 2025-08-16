#include "Counter.hpp"

Counter::Counter() {
    for (int i = 0; i < 10; ++i) {
        textures[i].loadFromFile("assets/sprites/" + std::to_string(i) + ".png");
    }
    for (int i = 0; i < 4; ++i) {
        number[i] = std::make_unique<sf::Sprite>(textures[0]);
        number[i]->setPosition({static_cast<float>(200 + i * number[i]->getTexture().getSize().x), 10.f});
    }
}

void Counter::draw(sf::RenderWindow &window) {
    for (int i = 0; i < 4; ++i) {
        window.draw(*number[i]);
    }
}
void Counter::update(float dt) {
    if (cnt < 10000) {
        std::string num = std::to_string(cnt);
        while (num.size() < 4) {
            num = "0" + num;
        }
        for (int i = 0; i < 4; ++i) {
            number[i]->setTexture(textures[num[i] - '0']);
        }
    }
}
Counter& Counter::operator++() {
    ++cnt;
    return *this;
}
bool Counter::SaveScoreToFile() {
    std::ifstream inFile("saves/score.txt");
    if (!inFile) {
        return false;
    }
    int Filecnt;
    inFile >> Filecnt;
    if (Filecnt < cnt) {
        std::ofstream outFile("saves/score.txt");
        if (!outFile) {
            return false;
        }
        outFile << cnt;
    }
    return true;
}
bool Counter::LoadScoreFromFile() {
    std::ifstream inFile("saves/score.txt");
    if (!inFile) {
        return false;
    }
    inFile >> cnt;
}
void Counter::resetScore() {
    cnt = 0u;
    SaveScoreToFile();
}