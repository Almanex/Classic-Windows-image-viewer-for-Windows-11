// ---------------------------------------------------------------------------------------------------------------------
// Shell Image Viewer v1.0 - DLL Loader Module Implementation
// GitHub: https://github.com/Almanex/Sredstvo_prosmotra_fotografij
// ---------------------------------------------------------------------------------------------------------------------

#include "dll_loader.h"

namespace DllLoader {

namespace {
bool GetExecutableDirectory(wchar_t* buffer, size_t bufferSize) {
    if (!buffer || bufferSize == 0) {
        return false;
    }

    DWORD length = GetModuleFileNameW(nullptr, buffer, static_cast<DWORD>(bufferSize));
    if (length == 0 || length >= bufferSize) {
        return false;
    }

    return PathRemoveFileSpecW(buffer) != FALSE;
}
} // namespace

ShimgvwLoader::ShimgvwLoader() : m_hModule(nullptr), m_imageViewProc(nullptr) {
}

ShimgvwLoader::~ShimgvwLoader() {
    UnloadDll();
}

AppError ShimgvwLoader::LoadDll() {
    if (m_hModule) {
        return Success;
    }

    if (!TryLoadSystemDll() && !TryLoadLocalDll()) {
        return DllLoadError;
    }

    m_imageViewProc = reinterpret_cast<SHIMGVW_PROC>(GetProcAddress(m_hModule, "ImageView_FullscreenW"));
    if (!m_imageViewProc) {
        UnloadDll();
        return FunctionNotFound;
    }

    return Success;
}

bool ShimgvwLoader::TryLoadSystemDll() {
    m_hModule = LoadLibraryExW(L"shimgvw.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    return (m_hModule != nullptr);
}

bool ShimgvwLoader::TryLoadLocalDll() {
    wchar_t dllPath[MAX_PATH] = {0};
    if (!GetExecutableDirectory(dllPath, _countof(dllPath))) {
        return false;
    }

    if (!PathAppendW(dllPath, L"shimgvw.dll")) {
        return false;
    }

    m_hModule = LoadLibraryW(dllPath);
    return (m_hModule != nullptr);
}

void ShimgvwLoader::UnloadDll() {
    if (m_hModule) {
        FreeLibrary(m_hModule);
        m_hModule = nullptr;
        m_imageViewProc = nullptr;
    }
}

bool ShimgvwLoader::IsLoaded() const {
    return (m_hModule != nullptr && m_imageViewProc != nullptr);
}

AppError ShimgvwLoader::ShowImage(const wchar_t* imagePath, int showWindow) {
    if (!IsLoaded()) {
        AppError loadResult = const_cast<ShimgvwLoader*>(this)->LoadDll();
        if (loadResult != Success) {
            return loadResult;
        }
    }

    if (!imagePath) {
        return InvalidArguments;
    }

    STARTUPINFOW si = {0};
    si.cb = sizeof(si);
    GetStartupInfoW(&si);

    int finalShowWindow = showWindow;
    if (si.dwFlags & STARTF_USESHOWWINDOW) {
        finalShowWindow = si.wShowWindow;
    }

    m_imageViewProc(nullptr, m_hModule, imagePath, finalShowWindow);
    return Success;
}

} // namespace DllLoader
