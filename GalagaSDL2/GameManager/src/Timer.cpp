/**
 * @file Timer.cpp
 * @author
 * @brief Timer class source file.
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

#include "Timer.h"

Timer *Timer::sInstance = nullptr;

/******************************************************************************/
Timer* Timer::Instance()
{
    if (nullptr == sInstance)
    {
        sInstance = new Timer();
    }

    return sInstance;
}

/******************************************************************************/
void Timer::Release()
{
    delete sInstance;
    sInstance = nullptr;
}

/******************************************************************************/
Timer::Timer()
{
     mTimeScale = 0.001f;
     mStartTicks = 0;
     mElapsedTicks = 0;
     mDeltaTime = 0;
}

/******************************************************************************/
Timer::~Timer()
{
    std::cout << "GameManager Distructor called" << std::endl;
}

/******************************************************************************/
void Timer::Reset()
{
    mStartTicks = SDL_GetTicks();
    mElapsedTicks = 0;
    mDeltaTime = 0;
}

/******************************************************************************/
void Timer::Update()
{
    mElapsedTicks = SDL_GetTicks() - mStartTicks;
    mDeltaTime = mElapsedTicks * mTimeScale;
}

/******************************************************************************/
float Timer::DeltaTime()
{
    return mDeltaTime;
}

/******************************************************************************/
void Timer::TimeScale(float timeScale)
{
    mTimeScale = timeScale;
}

/******************************************************************************/
float Timer::TimeScale()
{
    return mTimeScale;
}