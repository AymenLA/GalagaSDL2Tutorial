/**
 * @file Timer.h
 * @author
 * @brief Timer class header file.
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "SDL.h"

class Timer
{

    /*
     * Private member variables declaration.
     */
    private:

        static Timer* sInstance;

        unsigned int mStartTicks;
        unsigned int mElapsedTicks;
        float mDeltaTime;
        float mTimeScale;

    /*
     * Public member methods declaration, mostly static methods 
     * respecting the singloton design pattern.
     */
    public:

        static Timer* Instance();
        static void Release();

        void Reset();
        float DeltaTime();

        void TimeScale(float timeScale);
        float TimeScale();

        void Update();

    private:

        Timer();
        ~Timer();

};

