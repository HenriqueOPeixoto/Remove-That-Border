#pragma once

/*
 * WindowManager.h
 * 
 * This class is responsible for asking about open windows and managing window style.
 * 
 */

#include <Windows.h>
#include <vector>
#include <string>

class WindowManager
{
public:
	WindowManager();
	~WindowManager();
	std::vector<std::wstring> GetOpenWindows();

};

