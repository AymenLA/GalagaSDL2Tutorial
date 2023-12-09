/**
 * @file GameManager.cpp
 * @author
 * @brief Source file for GameManager class. 
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

#include "GameManager.h"

GameManager *GameManager::sInstance = nullptr;

/******************************************************************************/
GameManager *GameManager::Instance()
{
    if (nullptr == sInstance)
    {
        sInstance = new GameManager();
    }

    return sInstance;
}

/******************************************************************************/
void GameManager::Release()
{
    delete sInstance;
    sInstance = nullptr;
}

/******************************************************************************/
void GameManager::Run()
{
    while (!mQuit)
    {
        while (0 != SDL_PollEvent(&mEvents))
        {
            if (SDL_QUIT == mEvents.type)
            {
                std::cout << "SDL Event SDL_QUIT" << std::endl;
                mQuit = true;
            }

            mGraphics->Render();
        }
    }
}

/******************************************************************************/
GameManager::GameManager()
{
    mQuit = false;

    mGraphics = Graphics::Instance();

    if (!Graphics::Initialized())
    {
        mQuit = true;
    }
}

/******************************************************************************/
GameManager::~GameManager()
{
    std::cout << "GameManager Distructor called" << std::endl;
    Graphics::Release();
    mGraphics = nullptr;
}