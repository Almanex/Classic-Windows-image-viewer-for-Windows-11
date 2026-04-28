// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - Main Application Entry Point
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// 
// Классическое и легковесное средство просмотра изображений для Windows 10/11
// ---------------------------------------------------------------------------------------------------------------------

#include "common.h"
#include "file_utils.h"
#include "dll_loader.h"
#include "error_handler.h"
#include "ui_dialogs.h"

using namespace FileUtils;
using namespace DllLoader;
using namespace ErrorHandler;
using namespace UIDialogs;

/**
 * @brief Обрабатывает специальные параметры командной строки
 * @param arg Аргумент командной строки
 * @return true если аргумент был обработан как специальный параметр
 */
bool HandleSpecialArguments(const wchar_t* arg) {
    if (!arg) return false;

    if (wcscmp(arg, L"/?") == 0 || wcscmp(arg, L"--help") == 0) {
        ShowHelpDialog();
        return true;
    }
    
    if (wcscmp(arg, L"--about") == 0) {
        ShowAboutDialog();
        return true;
    }
    
    if (wcscmp(arg, L"--formats") == 0) {
        ShowSupportedFormatsDialog();
        return true;
    }

    return false;
}

/**
 * @brief Проверяет и обрабатывает путь к файлу изображения
 * @param imagePath Путь к файлу
 * @param fullPath Буфер для полного пути
 * @param bufferSize Размер буфера
 * @return Код ошибки
 */
AppError ValidateImagePath(const wchar_t* imagePath, wchar_t* fullPath, size_t bufferSize) {
    if (!imagePath || !fullPath || bufferSize == 0) {
        return InvalidArguments;
    }

    // Получаем полный путь к файлу
    if (!FileUtils::GetFullPath(imagePath, fullPath)) {
        return FileNotFound;
    }

    // Проверяем существование файла
    if (!FileUtils::FileExists(fullPath)) {
        return FileNotFound;
    }

    // Проверяем, является ли файл изображением
    if (!FileUtils::IsImageFile(fullPath)) {
        return UnsupportedFormat;
    }

    return Success;
}

/**
 * @brief Главная функция приложения
 * @param hInstance Дескриптор экземпляра приложения
 * @param hPrevInstance Дескриптор предыдущего экземпляра (не используется)
 * @param lpCmdLine Командная строка
 * @param nCmdShow Режим отображения окна
 * @return Код завершения
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Получаем аргументы командной строки в Unicode
    int argc;
    wchar_t** argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    
    if (!argv) {
        ErrorHandler::ShowErrorDialog(SystemError, APP_NAME);
        return static_cast<int>(SystemError);
    }

    // Проверка аргументов командной строки
    if (argc < 2) {
        // Если нет аргументов, показываем диалог выбора файла
        wchar_t selectedFile[MAX_PATH] = {0};
        if (UIDialogs::ShowOpenFileDialog(nullptr, selectedFile, _countof(selectedFile))) {
            // Валидация выбранного файла
            wchar_t fullPath[MAX_PATH];
            AppError validationResult = ValidateImagePath(selectedFile, fullPath, _countof(fullPath));
            
            if (validationResult != Success) {
                ErrorHandler::ShowErrorDialog(validationResult, APP_NAME);
                LocalFree(argv);
                return static_cast<int>(validationResult);
            }

            // Загрузка и использование shimgvw.dll
            DllLoader::ShimgvwLoader loader;
            AppError loadResult = loader.LoadDll();
            if (loadResult != Success) {
                ErrorHandler::ShowErrorDialog(loadResult, APP_NAME);
                LocalFree(argv);
                return static_cast<int>(loadResult);
            }

            // Отображение изображения
            AppError showResult = loader.ShowImage(fullPath);
            if (showResult != Success) {
                ErrorHandler::ShowErrorDialog(showResult, APP_NAME);
                LocalFree(argv);
                return static_cast<int>(showResult);
            }
        } else {
            // Пользователь отменил выбор файла
            LocalFree(argv);
            return static_cast<int>(Success);
        }
        
        LocalFree(argv);
        return static_cast<int>(Success);
    }

    // Обработка специальных параметров
    if (HandleSpecialArguments(argv[1])) {
        LocalFree(argv);
        return static_cast<int>(Success);
    }

    // Валидация пути к изображению
    wchar_t fullPath[MAX_PATH];
    AppError validationResult = ValidateImagePath(argv[1], fullPath, _countof(fullPath));
    
    if (validationResult != Success) {
        ErrorHandler::ShowErrorDialog(validationResult, APP_NAME);
        LocalFree(argv);
        return static_cast<int>(validationResult);
    }

    // Загрузка и использование shimgvw.dll
    DllLoader::ShimgvwLoader loader;
    AppError loadResult = loader.LoadDll();
    if (loadResult != Success) {
        ErrorHandler::ShowErrorDialog(loadResult, APP_NAME);
        LocalFree(argv);
        return static_cast<int>(loadResult);
    }

    // Отображение изображения
    AppError showResult = loader.ShowImage(fullPath);
    if (showResult != Success) {
        ErrorHandler::ShowErrorDialog(showResult, APP_NAME);
        LocalFree(argv);
        return static_cast<int>(showResult);
    }

    // Освобождаем память, выделенную для argv
    LocalFree(argv);
    
    return static_cast<int>(Success);
}
