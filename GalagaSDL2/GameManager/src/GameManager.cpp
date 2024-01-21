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
#include "Timer.h"

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
        mTimer->Update();

        while (0 != SDL_PollEvent(&mEvents))
        {
            if (SDL_QUIT == mEvents.type)
            {
                std::cout << "SDL Event SDL_QUIT" << std::endl;
                mQuit = true;
            }
        }

        if ((1.0f / FRAME_RATE) <= mTimer->DeltaTime())
        {
            mGraphics->ClearBackBuffer();

            mTex->Render();
            
            mGraphics->Render();

            mTimer->Reset();
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

    mTimer = Timer::Instance();

    std::string path = SDL_GetBasePath();
    path.append("Assets/galaga-game-collection.png");
    mTex = new Texture(path);
}

/******************************************************************************/
GameManager::~GameManager()
{
    std::cout << "GameManager Distructor called" << std::endl;

    Graphics::Release();
    mGraphics = nullptr;

    Timer::Release();
    mTimer = nullptr;

    delete mTex;
    mTex = nullptr;
}