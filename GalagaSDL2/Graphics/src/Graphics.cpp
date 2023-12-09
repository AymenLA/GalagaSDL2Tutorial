/**
 * @file Graphics.cpp
 * @author
 * @brief Source file for Graphics class.
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

#include <SDL.h>

#include "Constants.h"
#include "Graphics.h"

Graphics *Graphics::sInstance = nullptr;
bool Graphics::bInitialized = false;


/******************************************************************************/
Graphics* Graphics::Instance()
{
    if (nullptr == sInstance)
    {
        sInstance = new Graphics();
    }

    return sInstance;
}


/******************************************************************************/
void Graphics::Release()
{
    delete sInstance;
    sInstance = nullptr;

    bInitialized = false;
}


/******************************************************************************/
bool Graphics::Initialized()
{
    return bInitialized;
}

/******************************************************************************/
Graphics::Graphics()
{
    mBackBuffer = nullptr;

    bInitialized = Init();
}


/******************************************************************************/
Graphics::~Graphics()
{
    std::cout << "Graphics Distructor called" << std::endl;

    SDL_DestroyWindow(mWindow);
    mWindow = nullptr;
}


/******************************************************************************/
bool Graphics::Init()
{
    if (0 > SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL Initialization ERROR: " << SDL_GetError() << std::endl;
        return false;
    }

    mWindow = SDL_CreateWindow(
                        WINDOW_NAME.c_str(),
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        SCREEN_WIDTH,
                        SCREEN_HEIGTH,
                        SDL_WINDOW_SHOWN
                    );

    if (nullptr == mWindow)
    {
        std::cout << "SDL Window Creation ERROR: " << SDL_GetError() << std::endl;
        return false;
    }

    mBackBuffer = SDL_GetWindowSurface(mWindow);

    return true;
}


/******************************************************************************/
void Graphics::Render()
{
    SDL_UpdateWindowSurface(mWindow);
}