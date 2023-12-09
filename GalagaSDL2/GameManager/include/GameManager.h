/**
 * @file GameManager.h
 * @author
 * @brief Header file for GameManager class.
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "Graphics.h"
#include "Constants.h"


class GameManager
{
    /*
     * Private member variables declaration.
     */
    private:

        static GameManager *sInstance;

        bool mQuit;
        Graphics *mGraphics;

        SDL_Event mEvents;

    /*
     * Public member methods declaration, mostly static methods respecting the singloton design pattern.
     */
    public:

        static GameManager *Instance();
        static void Release();

        void Run();


    /*
     * Private member methods declaration.
     */
    private:

        GameManager();
        ~GameManager();

};