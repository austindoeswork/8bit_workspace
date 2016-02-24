// windows.cpp

#include <windows.h>
#include <iostream>
#include <string>

#include <thread>
#include <chrono>

std::string GetActiveWindowTitle()
{
 char wnd_title[256];
 HWND hwnd=GetForegroundWindow(); // get handle of currently active window
 GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
 return wnd_title;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
 if(IsWindowVisible(hwnd)) // check whether window is visible
 {
	char wnd_title[256];
	GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
	std::cout << wnd_title << std::endl;
 }
 return true; // function must return true if you want to continue enumeration
}

int main(int argc, char const *argv[])
{
    // EnumWindows(EnumWindowsProc,0);
    while(true){

    for (int i=5; i>0; --i) {
	    std::cout << i << std::endl;
	    std::this_thread::sleep_for (std::chrono::seconds(1));
  	}
    std::cout << GetActiveWindowTitle() << std::endl;
    }
	return 0;
}
