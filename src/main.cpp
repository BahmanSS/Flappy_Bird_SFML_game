#include <SFML/Graphics.hpp>
#include "../include/StateManager.hpp"
#include "../include/MenuState.hpp"
#include <cstdlib>
#include <ctime>
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    auto window = sf::RenderWindow(sf::VideoMode({500u, 700u}), "Flappy Bird!");
    window.setFramerateLimit(144);


    StateManager manager;
    manager.setState(std::make_unique<MenuState>
        (manager, window.getSize().x, window.getSize().y));
    
    sf::Clock clock;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            manager.handleEvent((*event));
            if (event->is<sf::Event::Closed>()) { window.close(); }
        }
        
        float dt = clock.restart().asSeconds();
        manager.update(dt);
        
        window.clear();
        manager.draw(window);
        window.display();
    }
}
