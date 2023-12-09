#include <iostream>

#include "GameManager.h"

int main(int argc, char* argv[]) {
    
    std::cout << "GalagaSDL2 main file : hello" << std::endl;

    GameManager *game = GameManager::Instance();

    game->Run();

    GameManager::Release();
    game = nullptr;

    return 0;
}