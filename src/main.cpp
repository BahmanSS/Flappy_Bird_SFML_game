#include <SFML/Graphics.hpp>
#include "../include/StateManager.hpp"
#include "../include/MenuState.hpp"
int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({500u, 700u}), "Flappy Bird!");
    window.setFramerateLimit(144);


    StateManager manager;
    manager.setState(std::make_unique<MenuState>
        (manager, window.getSize().x, window.getSize().y));
    


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { window.close(); }

            manager.handleEvent((*event));
        }
        //TODO: state.update();
        
        window.clear();
        manager.draw(window);
        window.display();
    }
}
