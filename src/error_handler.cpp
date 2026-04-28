// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - Error Handler Module Implementation
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// ---------------------------------------------------------------------------------------------------------------------

#include "error_handler.h"

namespace ErrorHandler {

const wchar_t* GetAppErrorMessage(AppError error) {
    switch (error) {
        case Success:
            return L"Операция выполнена успешно";
        case InvalidArguments:
            return L"Неверные аргументы командной строки";
        case FileNotFound:
            return L"Файл не найден";
        case UnsupportedFormat:
            return L"Неподдерживаемый формат файла";
        case DllLoadError:
            return L"Не удалось загрузить shimgvw.dll из Windows или из папки приложения";
        case FunctionNotFound:
            return L"Функция ImageView_FullscreenW не найдена в shimgvw.dll";
        case SystemError:
            return L"Системная ошибка";
        default:
            return L"Неизвестная ошибка";
    }
}

bool GetSystemErrorMessage(DWORD errorCode, wchar_t** buffer) {
    if (!buffer) {
        return false;
    }

    DWORD result = FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr,
        errorCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        reinterpret_cast<LPWSTR>(buffer),
        0,
        nullptr
    );

    return (result != 0);
}

DWORD AppErrorToSystemError(AppError error) {
    switch (error) {
        case Success: return ERROR_SUCCESS;
        case InvalidArguments: return ERROR_INVALID_PARAMETER;
        case FileNotFound: return ERROR_FILE_NOT_FOUND;
        case UnsupportedFormat: return ERROR_NOT_SUPPORTED;
        case DllLoadError: return ERROR_MOD_NOT_FOUND;
        case FunctionNotFound: return ERROR_PROC_NOT_FOUND;
        case SystemError: return ERROR_GEN_FAILURE;
        default: return ERROR_GEN_FAILURE;
    }
}

void ShowErrorDialog(AppError error, const wchar_t* title, HWND parentWindow) {
    const wchar_t* message = GetAppErrorMessage(error);
    MessageBoxW(parentWindow, message, title, MB_OK | MB_ICONERROR);
}

void ShowSystemErrorDialog(DWORD systemError, const wchar_t* title, HWND parentWindow) {
    wchar_t* systemMessage = nullptr;

    if (GetSystemErrorMessage(systemError, &systemMessage)) {
        if (systemMessage) {
            size_t len = wcslen(systemMessage);
            while (len > 0 && (systemMessage[len - 1] == L'\r' || systemMessage[len - 1] == L'\n')) {
                systemMessage[--len] = L'\0';
            }
        }

        wchar_t fullMessage[1024];
        swprintf_s(
            fullMessage,
            _countof(fullMessage),
            L"Системная ошибка (код %lu):\n%s",
            systemError,
            systemMessage ? systemMessage : L"Неизвестная ошибка"
        );

        MessageBoxW(parentWindow, fullMessage, title, MB_OK | MB_ICONERROR);

        if (systemMessage) {
            LocalFree(systemMessage);
        }
    } else {
        wchar_t fallbackMessage[256];
        swprintf_s(fallbackMessage, _countof(fallbackMessage), L"Системная ошибка с кодом %lu", systemError);
        MessageBoxW(parentWindow, fallbackMessage, title, MB_OK | MB_ICONERROR);
    }
}

} // namespace ErrorHandler
