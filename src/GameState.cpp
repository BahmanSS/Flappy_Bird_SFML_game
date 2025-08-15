#include "../include/GameState.hpp"
#include "../include/MenuState.hpp"

void GameState::ChangeStateToMenu() {
    manager.setState(std::make_unique<MenuState>(manager, width, height));
}