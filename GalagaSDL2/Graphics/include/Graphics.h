/**
 * @file Graphics.h
 * @author
 * @brief Header file for Graphics class.
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "Constants.h"

/**
 *  Graphics class. Defines the graphic properties of the application.
 *  gives access to an instance of the Graphics object and handles the 
 *  rendering.
 */
class Graphics
{
    /*
     * Public member variables declaration.
     */
    public:

        static const int SCREEN_WIDTH = APPLICATION_WINDOW_WIDTH;    /**< SDL Window width in pixels. */ 
        static const int SCREEN_HEIGTH = APPLICATION_WINDOW_HEIGTH;   /**< SDL Window height in pixels. */ 

    /*
     * Private member variables declaration.
     */
    private:

        static Graphics *sInstance;    /**< Graphics class instance. */ 
        static bool bInitialized;      /**< Graphics class initialization indicator. */ 

        SDL_Window* mWindow;        /**< SDL window used by the application. */ 
        SDL_Surface* mBackBuffer;   /**< SDL surface used by the application, to be embedded in the application window. */ 

        SDL_Renderer* mRenderer;    /**< SDL renderer used by the application, to render the content of the surface. */

    /*
     * Public member methods declaration, mostly static methods 
     * respecting the singloton design pattern.
     */
    public:

        /**
         * @brief Returns an instance of the object Graphics.
         *
         *        This methods creates and instance of the class Graphics, if none already exists, 
         *        by calling it constructor. Graphics constructor calls SDL_Init, SDL_CreateWindow
         *        and SDL_GetWindowSurface, if one of these functions fails the instance will not
         *        be generated and an error message based on SDL_GetError will be displayed, please
         *        refer to SDL library user manual to get more information about the error.
         * 
         * @return Graphics* 
         */
        static Graphics* Instance();

        static void Release();

        static bool Initialized();

        SDL_Texture* LoadTexture(std::string path);

        void ClearBackBuffer();

        void DrawTexture(SDL_Texture* tex);

        void Render();

    /*
     * Private member methods declaration.
     */
    private:

        Graphics();
        ~Graphics();

        bool Init();

};
