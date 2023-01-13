#include "WindowManager.h"

BOOL CALLBACK ListOpenWindows(HWND hwnd, LPARAM lparam)
{
    WCHAR winTitle[256];
    if (GetWindowTextW(hwnd, winTitle, 256) == 0) // just want windows with names
    {
        return true;
    }

    std::vector<std::wstring>& winTitles = *reinterpret_cast<std::vector<std::wstring>*>(lparam);

    winTitles.push_back(winTitle);

    //std::wcout << L"Título: " << winTitle << L"(" << hwnd << L")" << std::endl;



    return true;
}

WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
}

std::vector<std::wstring> WindowManager::GetOpenWindows()
{
    std::vector<std::wstring> winTitles;
    EnumWindows(ListOpenWindows, reinterpret_cast<LPARAM>(&winTitles));

    return winTitles;
}

void WindowManager::RemoveBorderFromWindow(std::wstring windowName)
{
    HWND winHandle = FindWindowW(NULL, windowName.c_str());
    LONG style = GetWindowLong(winHandle, GWL_STYLE);

    // Remove the border and caption from the window style
    style &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);

    // Set the new window style
    SetWindowLong(winHandle, GWL_STYLE, style);

    // Update the window
    SetWindowPos(winHandle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}
