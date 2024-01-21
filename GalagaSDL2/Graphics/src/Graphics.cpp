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
SDL_Texture* Graphics::LoadTexture(std::string path)
{
    SDL_Texture* tex = nullptr;

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (nullptr == surface)
    {
        std::cout << "Image Load Error: Path(" << path.c_str() << ")" <<\
                     " - Error(" << IMG_GetError() << ")" << std::endl;

        return tex;
    }

    tex = SDL_CreateTextureFromSurface(mRenderer, surface);
    if (nullptr == tex)
    {
        std::cout << "Create Texture Error: " << SDL_GetError() << std::endl;
        return tex;
    }

    SDL_FreeSurface(surface);

    return tex;
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

    SDL_DestroyRenderer(mRenderer);
    mRenderer = nullptr;

    SDL_DestroyWindow(mWindow);
    mWindow = nullptr;

    IMG_Quit();
    SDL_Quit();
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

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    if (nullptr == mRenderer)
    {
        std::cout << "SDL Renderer Creation ERROR: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    /** This might change depending on the type of image used */
    int flags = IMG_INIT_PNG;

    if (!(IMG_Init(flags) & flags))
    {
        std::cout << "IMG Initialization ERROR: " << IMG_GetError() << std::endl;
        return false; 
    }

    mBackBuffer = SDL_GetWindowSurface(mWindow);

    return true;
}


/******************************************************************************/
void Graphics::ClearBackBuffer()
{
    SDL_RenderClear(mRenderer);
}


/******************************************************************************/
void Graphics::DrawTexture(SDL_Texture* tex)
{
    SDL_RenderCopy(mRenderer, tex, nullptr, nullptr);
}


/******************************************************************************/
void Graphics::Render()
{
    SDL_RenderPresent(mRenderer);
}