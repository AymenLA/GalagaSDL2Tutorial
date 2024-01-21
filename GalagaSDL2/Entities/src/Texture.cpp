/**
 * @file Texture.cpp
 * @author Source for Texture Class.
 * @brief 
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Texture.h"


/******************************************************************************/
Texture::Texture(std::string path)
{
    mGraphics = Graphics::Instance();

    mTex = mGraphics->LoadTexture(path);
}

/******************************************************************************/
Texture::~Texture()
{
    SDL_DestroyTexture(mTex);

    mTex = nullptr;
    mGraphics = nullptr;
}

/******************************************************************************/
void Texture::Render()
{
    mGraphics->DrawTexture(mTex);
}