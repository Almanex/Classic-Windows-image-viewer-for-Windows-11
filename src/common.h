// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - Common Definitions
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// ---------------------------------------------------------------------------------------------------------------------

#pragma once

#define UNICODE
#define _UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <commdlg.h>
#include <stdio.h>
#include <wchar.h>

// Application constants
#define APP_NAME L"Shell Image Viewer"
#define APP_VERSION L"1.0"

// Image file filters for dialogs
#define IMAGE_FILTER L"All\0*.*\0Images\0*.BMP;*.GIF;*.PNG;*.JPG;*.JPEG;*.TIF;*.TIFF;*.ICO;*.WMF;*.EMF\0"

// Function pointer type for shimgvw.dll
typedef void (WINAPI *SHIMGVW_PROC)(HWND, HINSTANCE, LPCWSTR, int);

// Error codes
enum AppError {
    Success = 0,
    InvalidArguments = 1,
    FileNotFound = 2,
    UnsupportedFormat = 3,
    DllLoadError = 4,
    FunctionNotFound = 5,
    SystemError = 6
};