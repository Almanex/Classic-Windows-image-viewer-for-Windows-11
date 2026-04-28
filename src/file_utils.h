// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - File Utilities Module
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// ---------------------------------------------------------------------------------------------------------------------

#pragma once

#include "common.h"

namespace FileUtils {
    /**
     * @brief Получает полный путь к файлу
     * @param relativePath Относительный путь к файлу
     * @param fullPath Буфер для полного пути (должен быть размером MAX_PATH)
     * @return true если успешно, false в случае ошибки
     */
    bool GetFullPath(const wchar_t* relativePath, wchar_t* fullPath);

    /**
     * @brief Проверяет существование файла
     * @param filePath Путь к файлу
     * @return true если файл существует, false если нет
     */
    bool FileExists(const wchar_t* filePath);

    /**
     * @brief Проверяет, является ли файл изображением по расширению
     * @param filePath Путь к файлу
     * @return true если файл является изображением, false если нет
     */
    bool IsImageFile(const wchar_t* filePath);

    /**
     * @brief Получает расширение файла
     * @param filePath Путь к файлу
     * @return Указатель на расширение файла (включая точку) или nullptr
     */
    const wchar_t* GetFileExtension(const wchar_t* filePath);
}