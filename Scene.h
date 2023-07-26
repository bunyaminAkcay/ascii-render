#pragma once
#include "Camera.h"
#include "Object.h"
#include <iostream>
#include <list>
#include <stdlib.h>
#include <Windows.h>

// Mingw headers are wrong. GetCurrentConsoleFont and _CONSOLE_FONT_INFO is not declared.
// if you are using any c++ compiler instead of mingw. This part is not needed probably.
typedef struct _CONSOLE_FONT_INFO {
    DWORD  nFont;
    COORD  dwFontSize;
} CONSOLE_FONT_INFO, *PCONSOLE_FONT_INFO;

#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,BOOL bMaximumWindow,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
#ifdef __cplusplus
}
#endif
// end of fix.

struct Console{
    short consoleSizeX;
    short consoleSizeY;
    short fontSizeX;
    short fontSizeY;
};

class Scene{
private:

    float angle = 90;


    Console getConsoleInfo(){
        HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        struct Console console;
        if (hConsoleOutput != INVALID_HANDLE_VALUE){
            PCONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
            CONSOLE_FONT_INFO fontInfo;

            bool a = GetCurrentConsoleFont(hConsoleOutput, false, &fontInfo);
            bool b = GetConsoleScreenBufferInfo(hConsoleOutput, screenBufferInfo);
            console = { (short)(screenBufferInfo->srWindow.Right - screenBufferInfo->srWindow.Left), (short)(screenBufferInfo->srWindow.Bottom - screenBufferInfo->srWindow.Top), fontInfo.dwFontSize.X, fontInfo.dwFontSize.Y};
        
        }
        return console;
    }

    void clearScreen(){
        system("cls");
    }   
    
public:
    Camera* camera;
    std::list<Object*> objects;

    Scene(Camera* camera){
        this->camera = camera;
    }

    void addObject(Object* object){
        objects.push_back(object);
    }

    void RenderScene(){
        
        std::string shot = "";
        struct Console console = getConsoleInfo();
        
        for (int i = 0; i < console.consoleSizeY; i++){
            for (int j = 0; j < console.consoleSizeX; j++){
                shot.append("@");
            }
            shot.append("\n");
        }
        
        clearScreen();
        std::cout << shot;
    }

};