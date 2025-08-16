#include "GameState.hpp"
#include "MenuState.hpp"

GameState::GameState(StateManager &Manager, unsigned int width_, unsigned int height_)
    : manager(Manager), width(width_), height(height_), bird(width / 2, height / 2) {
    // Load textures
    bgdaytexture.loadFromFile("assets/sprites/background-day.png");
    bgnighttexture.loadFromFile("assets/sprites/background-night.png");
    basetexture.loadFromFile("assets/sprites/base.png");
    gameovertexture.loadFromFile("assets/sprites/gameover.png");
    // Create Sprites
    bgday = std::make_unique<sf::Sprite>(bgdaytexture);
    bgday->setScale({static_cast<float>(width) / static_cast<float>(bgday->getTexture().getSize().x),
                     static_cast<float>(height) / static_cast<float>(bgday->getTexture().getSize().y)});

    bgnight = std::make_unique<sf::Sprite>(bgnighttexture);
    bgnight->setScale({static_cast<float>(width) / static_cast<float>(bgnight->getTexture().getSize().x),
                       static_cast<float>(height) / static_cast<float>(bgnight->getTexture().getSize().y)});

    base = std::make_unique<sf::Sprite>(basetexture);
    base->setPosition({0.f, static_cast<float>(height - basetexture.getSize().y)});
    base->setScale({static_cast<float>(width) / static_cast<float>(basetexture.getSize().x), 1.f});

    gameOver = std::make_unique<sf::Sprite>(gameovertexture);
    gameOver->setOrigin({static_cast<float>(gameovertexture.getSize().x / 2),
                         static_cast<float>(gameovertexture.getSize().y / 2)});
    gameOver->setPosition({static_cast<float>(width / 2), static_cast<float>(height / 2)});
    gameOver->setScale({1.5f, 1.5f});
    // Load SoundBuffers
    pointbuffer.loadFromFile("assets/audio/point.wav");
    diebuffer.loadFromFile("assets/audio/die.wav");
    // Create Sound
    pointSound = std::make_unique<sf::Sound>(pointbuffer);
    dieSound = std::make_unique<sf::Sound>(diebuffer);

    // Others
    pipemanager = std::make_unique<PipeManager>(bird, width, height - base->getTexture().getSize().y * base->getScale().y);
}
void GameState::handleEvent(const sf::Event &event) {
    if (const auto *KeyPresset = event.getIf<sf::Event::KeyPressed>()) {
        if (KeyPresset->scancode == sf::Keyboard::Scancode::Enter ||
            KeyPresset->scancode == sf::Keyboard::Scancode::Space) {
            if (!dieSoundPlay) {
                bird.flap();
            }
            else {
                ChangeStateToMenu();
            }
        }
    }
    else if (const auto *MouseKeyPresset = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (MouseKeyPresset->button == sf::Mouse::Button::Left) {
            if (!dieSoundPlay) {
                bird.flap();
            }
            else {
                ChangeStateToMenu();
            }
        }
    }
}
void GameState::update(float dt) {
    if (pipemanager->update(dt)) {
        bird.update(dt, width, height - base->getTexture().getSize().y * base->getScale().y);
        if (pipemanager->checkBirdPassedPipes()) {
            ++counter;
            pointSound->play();
        }
        counter.update(dt);
    }
    else {
        if (dieSound->getStatus() != sf::SoundSource::Status::Playing && !dieSoundPlay) {
            dieSound->play();
            dieSoundPlay = true;
        }
        counter.SaveScoreToFile();
    }
}
void GameState::draw(sf::RenderWindow &window) {
    window.draw(*bgnight);
    pipemanager->draw(window);
    window.draw(*base);
    bird.draw(window);
    counter.draw(window);
    if (dieSoundPlay == true) {
        window.draw(*gameOver);
    }
}

void GameState::ChangeStateToMenu()
{
    manager.setState(std::make_unique<MenuState>(manager, width, height));
}