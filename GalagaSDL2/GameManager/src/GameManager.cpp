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
            mParent->Rotation(mParent->Rotation(GameEntity::Space::LOCAL) + 0.1f);
            std::cout << "Parent rotation: " << mParent->Rotation(GameEntity::Space::LOCAL) << std::endl;
            std::cout << "Child local pos: (" << mChild->Pos(GameEntity::Space::WORLD).x << ", "<< mChild->Pos(GameEntity::Space::WORLD).y  << ")" << std::endl;
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

    mParent = new GameEntity(100.0f, 400.0f);
    mChild = new GameEntity(100.0f, 500.0f);

    std::cout << "Child local pos: (" << mChild->Pos(GameEntity::Space::WORLD).x << ", "<< mChild->Pos(GameEntity::Space::WORLD).y  << ")" << std::endl;

    mChild->Parent(mParent);

    std::cout << "Child local pos: (" << mChild->Pos(GameEntity::Space::WORLD).x << ", "<< mChild->Pos(GameEntity::Space::WORLD).y  << ")" << std::endl;

}

/******************************************************************************/
GameManager::~GameManager()
{
    std::cout << "GameManager Distructor called" << std::endl;

    Graphics::Release();
    mGraphics = nullptr;

    Timer::Release();
    mTimer = nullptr;

    delete mParent;
    delete mChild;
}