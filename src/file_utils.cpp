// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - File Utilities Module Implementation
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// ---------------------------------------------------------------------------------------------------------------------

#include "file_utils.h"
#include <algorithm>
#include <string>

namespace FileUtils {

bool GetFullPath(const wchar_t* relativePath, wchar_t* fullPath) {
    if (!relativePath || !fullPath) {
        return false;
    }

    DWORD result = GetFullPathNameW(relativePath, MAX_PATH, fullPath, nullptr);
    return (result > 0 && result < MAX_PATH);
}

bool FileExists(const wchar_t* filePath) {
    if (!filePath) {
        return false;
    }
    return PathFileExistsW(filePath) != FALSE;
}

bool IsImageFile(const wchar_t* filePath) {
    const wchar_t* extension = GetFileExtension(filePath);
    if (!extension) {
        return false;
    }

    // Список поддерживаемых расширений изображений
    const wchar_t* supportedExtensions[] = {
        L".bmp", L".gif", L".png", L".jpg", L".jpeg", 
        L".tif", L".tiff", L".ico", L".wmf", L".emf"
    };

    std::wstring ext(extension);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::towlower);

    for (const auto& supportedExt : supportedExtensions) {
        if (ext == supportedExt) {
            return true;
        }
    }

    return false;
}

const wchar_t* GetFileExtension(const wchar_t* filePath) {
    if (!filePath) {
        return nullptr;
    }

    const wchar_t* lastDot = wcsrchr(filePath, L'.');
    const wchar_t* lastSlash = wcsrchr(filePath, L'\\');
    const wchar_t* lastForwardSlash = wcsrchr(filePath, L'/');

    // Убеждаемся, что точка находится после последнего слеша
    const wchar_t* lastSeparator = (lastSlash > lastForwardSlash) ? lastSlash : lastForwardSlash;
    
    if (lastDot && (!lastSeparator || lastDot > lastSeparator)) {
        return lastDot;
    }

    return nullptr;
}

} // namespace FileUtils