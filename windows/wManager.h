// wManager.h
#ifndef WMANAGER_H
#define WMANAGER_H


#include <windows.h>

#include <iostream>
#include <string>

class wManager{

	public:
	//constructor
		wManager();
	//members
		//listen:
		//on change of window, runs the passed-in function passing in the name
		//	params:
		// 	- int timing 
		// 		= every how many milliseconds should I check for a change?
		// 	- void function
		// 		= is run when the main app changes.
		// 		= function will be passed the HWND of the currently open window  
		void listen( int timing, void (*f)(HWND) );

};


#endif