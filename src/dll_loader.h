// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - DLL Loader Module
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// ---------------------------------------------------------------------------------------------------------------------

#pragma once

#include "common.h"

namespace DllLoader {
    /**
     * @brief Класс для управления загрузкой и выгрузкой DLL
     */
    class ShimgvwLoader {
    private:
        HMODULE m_hModule;
        SHIMGVW_PROC m_imageViewProc;
        bool TryLoadSystemDll();
        bool TryLoadLocalDll();

    public:
        ShimgvwLoader();
        ~ShimgvwLoader();

        /**
         * @brief Загружает shimgvw.dll и получает указатель на функцию
         * @return AppError::Success если успешно, иначе код ошибки
         */
        AppError LoadDll();

        /**
         * @brief Выгружает DLL
         */
        void UnloadDll();

        /**
         * @brief Проверяет, загружена ли DLL
         * @return true если DLL загружена и функция доступна
         */
        bool IsLoaded() const;

        /**
         * @brief Запускает просмотр изображения
         * @param imagePath Путь к изображению
         * @param showWindow Режим отображения окна
         * @return AppError::Success если успешно, иначе код ошибки
         */
        AppError ShowImage(const wchar_t* imagePath, int showWindow = SW_SHOWDEFAULT);

        // Запрет копирования
        ShimgvwLoader(const ShimgvwLoader&) = delete;
        ShimgvwLoader& operator=(const ShimgvwLoader&) = delete;
    };

}
