# GalagaSDL2 Architecture overview

This document lists all the classes of the application and gives a small description of their role in the structure of the application. For more detailed information about each class please refer to the doxygen documentation on each header file.

## Table of content 

  - [Graphics class ](#graphics-class)
  - [GameManager class ](#gamemanager-class)
  - [Timer class ](#timer-class)

## Graphics class <a name="graphics-class"></a>

This class uses the singleton design pattern (no constructor, unique instance, static methods to access members), it has the responsability of defining the Graphics properties of the application such as screen width and hieght, the SDL_Window and SDL_Surface. It is this class' responsability to initialize the SDL Library as well as to call SDL_Quit() at the end when the class destructor is called.

- Here is a UML view of of the class: 

<p align="center">
  <img src="uml_screenshots/uml-Graphics-class.png" width=50% height=50% />
</p>

- Here is the equivalent UML code :

```
@startuml
package "Graphics" #DDDDDD {
    class Graphics {
        + SCREEN_WIDTH
        + SCREEN_HEIGHT
        - sInstance
        - bInitialized
        - mWindow
        - mBackBuffer
        + Instance()
        + Release()
        + Initilized()
        - Grqphics()
        - ~Graphics()
        - Init()
    }

    note right of Graphics 
        This class is a Sigleton
        with low level accesses to SDL Library
    end note
}
@enduml
```
## GameManager class <a name="gamemanager-class"></a>

This class uses the singleton design pattern, this class will create in its constructor an instance of the object Graphics. It is this class responsibility to insure that the Graphics are initialized and to run the renderring. This class will also call the SDL_PollEvent() in a loop in order to monitor the events (user inputs, ...).

It uses Graphics and Timer classes to create members instances and handles their release too.

- Here is a UML view of of the class: 

<p align="center">
  <img src="uml_screenshots/uml-GameManager-class.png" width=50% height=50% />
</p>

- Here is the equivalent UML code :

```
@startuml
package "GameManager" #DDDDDD {
    class GameManager {
        - sInstance
        - mQuit
        - mGraphics
        - mTimer
        - mEvents
        + Instance()
        + Release()
        + Run()
        - GameManager()
        - ~GameManager()
    }

    note right of GameManager 
        This class is a Sigleton
        it has low level accesses to SDL Library
    end note
}
@enduml
```

## Timer class <a name="timer-class"></a>

This class uses the singleton design pattern, it uses SDL_GetTicks() to get an integer number that represents the milliseconds since SDL_Init(). This class gives access to a member DeltaTime() that tracks the milliseconds count since last time we've updated the timer.

- Here is a UML view of of the class: 

<p align="center">
  <img src="uml_screenshots/uml-Timer-class.png" width=50% height=50% />
</p>

- Here is the equivalent UML code :

```
@startuml
package "Timer" #DDDDDD {
    class Timer {
        - sInstance
        - mStartTicks
        - mDeltaTime
        - mTimeScale
        + Instance()
        + Release()
        + Reset()
        + TimeScale(float)
        + TimeScale()
        + Update()
        - Timer()
        - ~Timer()
    }

    note right of Timer 
        This class is a Sigleton
        it has low level accesses to SDL Library
    end note
}
@enduml
```
