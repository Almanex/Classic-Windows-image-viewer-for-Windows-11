// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - UI Dialogs Module
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// ---------------------------------------------------------------------------------------------------------------------

#pragma once

#include "common.h"

namespace UIDialogs {
    /**
     * @brief Отображает диалог с информацией о программе
     * @param parentWindow Родительское окно (по умолчанию nullptr)
     */
    void ShowAboutDialog(HWND parentWindow = nullptr);

    /**
     * @brief Отображает диалог справки с информацией об использовании
     * @param parentWindow Родительское окно (по умолчанию nullptr)
     */
    void ShowHelpDialog(HWND parentWindow = nullptr);

    /**
     * @brief Отображает диалог с информацией о поддерживаемых форматах
     * @param parentWindow Родительское окно (по умолчанию nullptr)
     */
    void ShowSupportedFormatsDialog(HWND parentWindow = nullptr);

    /**
     * @brief Отображает диалог выбора файла для открытия
     * @param parentWindow Родительское окно
     * @param selectedPath Буфер для выбранного пути (должен быть достаточно большим)
     * @param bufferSize Размер буфера для пути
     * @return true если файл был выбран
     */
    bool ShowOpenFileDialog(HWND parentWindow, wchar_t* selectedPath, size_t bufferSize);

    /**
     * @brief Отображает простое информационное сообщение
     * @param message Текст сообщения
     * @param title Заголовок диалога (по умолчанию название приложения)
     * @param parentWindow Родительское окно (по умолчанию nullptr)
     */
    void ShowInfoMessage(const wchar_t* message, const wchar_t* title = APP_NAME, HWND parentWindow = nullptr);

    /**
     * @brief Отображает предупреждающее сообщение
     * @param message Текст сообщения
     * @param title Заголовок диалога (по умолчанию название приложения)
     * @param parentWindow Родительское окно (по умолчанию nullptr)
     */
    void ShowWarningMessage(const wchar_t* message, const wchar_t* title = APP_NAME, HWND parentWindow = nullptr);

    /**
     * @brief Отображает диалог подтверждения (Да/Нет)
     * @param message Текст сообщения
     * @param title Заголовок диалога (по умолчанию название приложения)
     * @param parentWindow Родительское окно (по умолчанию nullptr)
     * @return true если пользователь выбрал "Да"
     */
    bool ShowConfirmationDialog(const wchar_t* message, const wchar_t* title = APP_NAME, HWND parentWindow = nullptr);
}