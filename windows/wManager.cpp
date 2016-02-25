// wManager.cpp

#include "wManager.h"

#include <iostream>
#include <string>
#include <thread>	//this thread
#include <chrono>	//timing

wManager::wManager()
{
	std::cout << "I exist." << std::endl;
	//empty constructor... is that ok?
}

//member functions

// see wManager.h
// void listen( int timing, void (*f)(HWND) );
void wManager::listen( int timing, void (*f)(HWND) ){
	std::cout << "listening..." << std::endl;

	char current_title[256];
	char next_title[256];
	
	while (true){	
		HWND hwnd=GetForegroundWindow(); // get handle of currently active window
		GetWindowText(hwnd,next_title,sizeof(next_title));
		
		// std::cout << strcmp(next_title, current_title) << std::endl;

		if(strcmp(next_title, current_title) != 0 ){ //is it different?
			strcpy(current_title, next_title);
			(*f)(hwnd);
		}

		std::this_thread::sleep_for (std::chrono::milliseconds(timing));
	}

}

// std::string GetActiveWindowTitle()
// {
//  char wnd_title[256];
//  HWND hwnd=GetForegroundWindow(); // get handle of currently active window
//  GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
//  return wnd_title;
// }