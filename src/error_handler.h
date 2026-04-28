// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - Error Handler Module
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// ---------------------------------------------------------------------------------------------------------------------

#pragma once

#include "common.h"

namespace ErrorHandler {
    /**
     * @brief Преобразует код ошибки AppError в строковое описание
     * @param error Код ошибки
     * @return Указатель на строку с описанием ошибки
     */
    const wchar_t* GetAppErrorMessage(AppError error);

    /**
     * @brief Получает системное сообщение об ошибке по коду
     * @param errorCode Код системной ошибки
     * @param buffer Буфер для сообщения (должен быть освобожден через LocalFree)
     * @return true если сообщение получено успешно
     */
    bool GetSystemErrorMessage(DWORD errorCode, wchar_t** buffer);

    /**
     * @brief Отображает диалог с сообщением об ошибке
     * @param error Код ошибки приложения
     * @param title Заголовок диалога (по умолчанию название приложения)
     * @param parentWindow Родительское окно (по умолчанию nullptr)
     */
    void ShowErrorDialog(AppError error, const wchar_t* title = APP_NAME, HWND parentWindow = nullptr);

    /**
     * @brief Отображает диалог с системной ошибкой
     * @param systemError Код системной ошибки
     * @param title Заголовок диалога (по умолчанию название приложения)
     * @param parentWindow Родительское окно (по умолчанию nullptr)
     */
    void ShowSystemErrorDialog(DWORD systemError, const wchar_t* title = APP_NAME, HWND parentWindow = nullptr);

    /**
     * @brief Преобразует AppError в системный код ошибки
     * @param error Код ошибки приложения
     * @return Соответствующий системный код ошибки
     */
    DWORD AppErrorToSystemError(AppError error);
}