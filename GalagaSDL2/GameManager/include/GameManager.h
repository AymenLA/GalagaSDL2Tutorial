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
#include "Timer.h"
#include "GameEntity.h"

class GameManager
{
    /*
     * Private member variables declaration.
     */
    private:

        static GameManager *sInstance;    /**< GameManager class instance. */

        const int FRAME_RATE = APPLICATION_FRAME_RATE; /**< Refresh rate of the graphics. */

        bool mQuit;             /**< Boolean tracking Quit event triggered. */ 
        Graphics *mGraphics;    /**< member Graphics Instance. */

        Timer* mTimer;     /**< member Timer Instance. */

        SDL_Event mEvents;      /**< Last Event sent by SDL_PollEvent. */

        GameEntity *mParent;
        GameEntity *mChild;     

    /*
     * Public member methods declaration, mostly static methods 
     * respecting the singloton design pattern.
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