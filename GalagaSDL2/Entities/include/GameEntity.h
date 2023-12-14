/**
 * @file GameEntity.h
 * @author 
 * @brief Header of class GameEntity
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #pragma once

 #include "MathHelper.h"

 class GameEntity
 {

    public:
        enum Space { LOCAL = 0, WORLD = 1};

    private:

        Vector2 mPos;
        float mRotation;

        bool mActive;
        GameEntity *mParent;

    public:

        GameEntity(float x = 0.0f, float y = 0.0f);
        ~GameEntity();

        void Pos(Vector2 pos);
        Vector2 Pos(Space space = WORLD);

        void Rotation(float rotation);
        float Rotation(Space space = WORLD);

        void Active(bool active);
        bool Active();

        void Parent(GameEntity *parent);
        GameEntity* Parent();

        virtual void Update();
        virtual void Render();

 };