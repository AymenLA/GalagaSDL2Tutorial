/**
 * @file GameEntity.cpp
 * @author 
 * @brief Sources for class GameEntity
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #include "GameEntity.h"

/******************************************************************************/
GameEntity::GameEntity(float x, float y)
{
    mPos.x = x;
    mPos.y = y;

    mRotation = 0.0f;

    mActive = true;

    mParent = nullptr;
}

/******************************************************************************/
GameEntity::~GameEntity()
{
    mParent = nullptr;
}

/******************************************************************************/
void GameEntity::Pos(Vector2 pos)
{
    mPos = pos;
}

/******************************************************************************/
Vector2 GameEntity::Pos(Space space)
{
    if ((space == Space::LOCAL) || (mParent == nullptr))
    {
        return mPos;
    }

    return mParent->Pos(Space::WORLD) + RotateVector(mPos, mParent->Rotation(Space::LOCAL));
}

/******************************************************************************/
void GameEntity::Rotation(float rotation)
{
    mRotation = rotation;

    if (mRotation > 360.0f)
    {
        mRotation -= 360.0f;
    }
    if (mRotation < 0.0f)
    {
        mRotation += 360.0f;
    }
}

/******************************************************************************/
float GameEntity::Rotation(Space space)
{
    if ((space == Space::LOCAL) || (mParent == nullptr))
    {
        return mRotation;
    }

    return mParent->Rotation(Space::WORLD) + mRotation;
}

/******************************************************************************/
void GameEntity::Active(bool active)
{
    mActive = active;
}

/******************************************************************************/
bool GameEntity::Active()
{
    return mActive;
}

/******************************************************************************/
void GameEntity::Parent(GameEntity *parent)
{
    mPos = Pos(Space::WORLD) - parent->Pos(Space::WORLD);

    mParent = parent;
}

/******************************************************************************/
GameEntity* GameEntity::Parent()
{
    return mParent;
}

/******************************************************************************/
void GameEntity::Update()
{

}

/******************************************************************************/
void GameEntity::Render()
{

}