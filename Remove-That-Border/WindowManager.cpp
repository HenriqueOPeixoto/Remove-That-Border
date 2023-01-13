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

std::vector<std::wstring> WindowManager::GetOpenWindows()
{
    std::vector<std::wstring> winTitles;
    EnumWindows(ListOpenWindows, reinterpret_cast<LPARAM>(&winTitles));

    return winTitles;
}
