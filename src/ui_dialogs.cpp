// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - UI Dialogs Module Implementation
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// ---------------------------------------------------------------------------------------------------------------------

#include "ui_dialogs.h"
#include <commdlg.h>

namespace UIDialogs {

void ShowAboutDialog(HWND parentWindow) {
    wchar_t aboutText[1024];
    swprintf_s(
        aboutText,
        _countof(aboutText),
        L"%s %s\n\n"
        L"Классическое средство просмотра изображений для Windows 10/11\n\n"
        L"© 2018-2024 Community Project\n"
        L"Приложение использует системную shimgvw.dll из Windows,\n"
        L"а при ее отсутствии может загрузить локальную копию\n"
        L"из папки рядом с PhotoViewer.exe.\n\n"
        L"Поддерживаемые форматы:\n"
        L"• BMP, DIB, RLE\n"
        L"• JPEG, JPG, JPE, JFIF\n"
        L"• GIF\n"
        L"• PNG\n"
        L"• TIFF, TIF\n"
        L"• WMF, EMF\n"
        L"• ICO\n\n"
        L"Лицензия: MIT License",
        APP_NAME,
        APP_VERSION
    );

    MessageBoxW(parentWindow, aboutText, L"О программе", MB_OK | MB_ICONINFORMATION);
}

void ShowHelpDialog(HWND parentWindow) {
    const wchar_t* helpText =
        L"Использование:\n\n"
        L"PhotoViewer.exe <путь_к_изображению>\n\n"
        L"Примеры:\n"
        L"• PhotoViewer.exe \"C:\\Pictures\\photo.jpg\"\n"
        L"• PhotoViewer.exe photo.png\n"
        L"• PhotoViewer.exe /?\n\n"
        L"Параметры:\n"
        L"• /? или --help - показать эту справку\n"
        L"• --about - показать информацию о программе\n"
        L"• --formats - показать поддерживаемые форматы\n\n"
        L"Сначала приложение ищет системную shimgvw.dll в Windows.\n"
        L"Если она недоступна, можно положить shimgvw.dll рядом\n"
        L"с PhotoViewer.exe и программа попробует загрузить ее.\n";

    MessageBoxW(parentWindow, helpText, L"Справка", MB_OK | MB_ICONINFORMATION);
}

void ShowSupportedFormatsDialog(HWND parentWindow) {
    const wchar_t* formatsText =
        L"Поддерживаемые форматы изображений:\n\n"
        L"• BMP (Windows Bitmap)\n"
        L"• DIB (Device Independent Bitmap)\n"
        L"• RLE (Run Length Encoded Bitmap)\n"
        L"• JPEG, JPG, JPE, JFIF (JPEG Image)\n"
        L"• GIF (Graphics Interchange Format)\n"
        L"• PNG (Portable Network Graphics)\n"
        L"• TIFF, TIF (Tagged Image File Format)\n"
        L"• WMF (Windows Metafile)\n"
        L"• EMF (Enhanced Metafile)\n"
        L"• ICO (Windows Icon)\n\n"
        L"Поддержка зависит от установленных в системе кодеков изображений.";

    MessageBoxW(parentWindow, formatsText, L"Поддерживаемые форматы", MB_OK | MB_ICONINFORMATION);
}

bool ShowOpenFileDialog(HWND parentWindow, wchar_t* selectedPath, size_t bufferSize) {
    if (!selectedPath || bufferSize == 0) {
        return false;
    }

    OPENFILENAMEW ofn = {};
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = parentWindow;
    ofn.lpstrFile = selectedPath;
    ofn.nMaxFile = static_cast<DWORD>(bufferSize);
    ofn.lpstrFilter = L"Изображения\0*.bmp;*.jpg;*.jpeg;*.gif;*.png;*.tiff;*.tif;*.ico;*.wmf;*.emf\0"
                      L"Все файлы\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = nullptr;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = nullptr;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

    selectedPath[0] = L'\0';
    return GetOpenFileNameW(&ofn) != 0;
}

void ShowInfoMessage(const wchar_t* message, const wchar_t* title, HWND parentWindow) {
    MessageBoxW(parentWindow, message, title, MB_OK | MB_ICONINFORMATION);
}

void ShowWarningMessage(const wchar_t* message, const wchar_t* title, HWND parentWindow) {
    MessageBoxW(parentWindow, message, title, MB_OK | MB_ICONWARNING);
}

bool ShowConfirmationDialog(const wchar_t* message, const wchar_t* title, HWND parentWindow) {
    int result = MessageBoxW(parentWindow, message, title, MB_YESNO | MB_ICONQUESTION);
    return (result == IDYES);
}

} // namespace UIDialogs
