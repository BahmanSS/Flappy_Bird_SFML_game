#include "MenuState.hpp"

MenuState::MenuState(StateManager &Manager, int width_, unsigned int height_)
    : manager(Manager), width(width_), height(height_) {

    bgtexture.loadFromFile("assets/sprites/background-day.png");
    background = std::make_unique<sf::Sprite>(bgtexture);
    background->setScale({static_cast<float>(width) / static_cast<float>(background->getTexture().getSize().x),
                          static_cast<float>(height) / static_cast<float>(background->getTexture().getSize().y)});

    gameUItexture.loadFromFile("assets/sprites/message.png");
    gameUI = std::make_unique<sf::Sprite>(gameUItexture);
    gameUI->setPosition({50.f, 75.f});
    gameUI->setScale({static_cast<float>(width) / static_cast<float>(gameUI->getTexture().getSize().x) - 0.52f,
                      static_cast<float>(height) / static_cast<float>(gameUI->getTexture().getSize().y) - 0.52f});
    counter.LoadScoreFromFile();
}
void MenuState::handleEvent(const sf::Event &event) {
    if (const auto *KeyPresset = event.getIf<sf::Event::KeyPressed>()) {
        if (KeyPresset->scancode == sf::Keyboard::Scancode::Enter ||
            KeyPresset->scancode == sf::Keyboard::Scancode::Space) {
            ChangeStateToGame();
        }
    }
    else if (const auto *MouseKeyPresset = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (MouseKeyPresset->button == sf::Mouse::Button::Left) {
            ChangeStateToGame();
        }
    }
}
void MenuState::update(float dt) {
    counter.update(dt);
}
void MenuState::draw(sf::RenderWindow &window) {
    window.draw(*background);
    window.draw(*gameUI);
    counter.draw(window);
}
void MenuState::ChangeStateToGame() {
    manager.setState(std::make_unique<GameState>(manager, width, height));
}