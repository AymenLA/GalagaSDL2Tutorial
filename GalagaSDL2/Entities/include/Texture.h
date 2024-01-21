/**
 * @file Texture.h
 * @author 
 * @brief Header of Class Texture.
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #pragma once

 #include "GameEntity.h"
 #include "Graphics.h"
 #include "string"

 class Texture : public GameEntity
 {
    public:

        Texture(std::string path);
        ~Texture();

        virtual void Render();

    private:

        SDL_Texture* mTex;

        Graphics* mGraphics;
 };