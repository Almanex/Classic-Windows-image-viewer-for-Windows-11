# Project Context - Shell Image Viewer

This document serves as a guide for AI agents and developers interacting with the codebase of the **Shell Image Viewer** project.

---

## 1. Project Overview

**Shell Image Viewer** (`PhotoViewer.exe`) is a lightweight launcher utility for Windows 10/11 designed to restore the classic Windows Photo Viewer interface.
Microsoft officially disabled the visual entry points to the classic photo viewer, but the core system library `shimgvw.dll` is still present to support backward compatibility. This launcher dynamically loads `shimgvw.dll` and invokes `ImageView_FullscreenW` to open the specified image in the original full-screen view.

---

## 2. Directory Structure

- `CMakeLists.txt` - CMake build configuration (requires C++17, links system Windows libraries, defines `PhotoViewer.exe` output).
- `LICENSE` - Project license (MIT).
- `README.md` - Primary English readme.
- `Project_CONTEXT.md` - This file, explaining the codebase context for agents.
- `docs/` - Localized readmes:
  - [README_RU.md](file:///d:/Develop/Classic-Windows-image-viewer/docs/README_RU.md) (Russian translation)
  - [README_DE.md](file:///d:/Develop/Classic-Windows-image-viewer/docs/README_DE.md) (German translation)
- `DLL/` - Embedded compatibility DLLs (`shimgvw.dll` variants from WinXP and Win7) for Windows editions lacking the DLL.
- `src/` - Application source code:
  - [common.h](file:///d:/Develop/Classic-Windows-image-viewer/src/common.h) - Common definitions, app configuration, error codes, and formats list.
  - [main.cpp](file:///d:/Develop/Classic-Windows-image-viewer/src/main.cpp) - WinMain entry point, command-line parsing, validation, execution orchestrator.
  - [dll_loader.h](file:///d:/Develop/Classic-Windows-image-viewer/src/dll_loader.h) / [dll_loader.cpp](file:///d:/Develop/Classic-Windows-image-viewer/src/dll_loader.cpp) - Handles dynamic loading of `shimgvw.dll` (system first, fallback to local directory) and function pointer invocation.
  - [file_utils.h](file:///d:/Develop/Classic-Windows-image-viewer/src/file_utils.h) / [file_utils.cpp](file:///d:/Develop/Classic-Windows-image-viewer/src/file_utils.cpp) - File existence validation, absolute path resolution, extension support checks.
  - [error_handler.h](file:///d:/Develop/Classic-Windows-image-viewer/src/error_handler.h) / [error_handler.cpp](file:///d:/Develop/Classic-Windows-image-viewer/src/error_handler.cpp) - Maps `AppError` enum codes to system modal dialog messages.
  - [ui_dialogs.h](file:///d:/Develop/Classic-Windows-image-viewer/src/ui_dialogs.h) / [ui_dialogs.cpp](file:///d:/Develop/Classic-Windows-image-viewer/src/ui_dialogs.cpp) - Implements about, help, formats, and `GetOpenFileNameW` shell dialogs.
  - `shimgvw.ico` - Application icon (extracted from original system resources).
  - `shimgvw.manifest` - Application manifest declaring UI styles and compatibility options.
  - `shimgvw.rc` - Resource file embedding the manifest and icon.

---

## 3. Key Components and Logic Flow

### Initialization & Entry Point
- Entry point: `WinMain` in `src/main.cpp`.
- Retrieves command line arguments in Unicode via `CommandLineToArgvW`.
- If no arguments are provided, `WinMain` calls `UIDialogs::ShowOpenFileDialog` to display a native Win32 dialog for picking an image.
- If help/about/format flags are passed (`/?`, `--help`, `--about`, `--formats`), the corresponding modal message boxes are shown and the application exits.

### Validation & Execution
1. **File Validation** (`file_utils.cpp`):
   - Converts input path to a full canonical absolute path.
   - Checks if the file exists on disk.
   - Matches the extension against a hardcoded list of supported image formats (BMP, JPG, JPEG, PNG, GIF, TIF, TIFF, ICO, WMF, EMF).
2. **DLL Loading** (`dll_loader.cpp`):
   - Tries `LoadLibraryW` on the system name `shimgvw.dll` (which searches standard Windows system directories).
   - If that fails, it resolves the directory where `PhotoViewer.exe` resides and attempts to load `shimgvw.dll` locally from that directory.
   - Obtains the function pointer to `ImageView_FullscreenW` (or `ImageView_Fullscreen` as a fallback) via `GetProcAddress`.
3. **Execution**:
   - Invokes the resolved DLL function: `void(HWND, HINSTANCE, LPCWSTR, int)`.
   - The system DLL handles the fullscreen viewer UI in a separate window.

---

## 4. Error Codes

Defined in `src/common.h`:
- `Success` (0)
- `InvalidArguments` (1) - Argument parameters are missing or corrupted.
- `FileNotFound` (2) - Specified image file does not exist.
- `UnsupportedFormat` (3) - File is not on the supported formats list.
- `DllLoadError` (4) - Could not load system or local `shimgvw.dll`.
- `FunctionNotFound` (5) - Could not locate `ImageView_FullscreenW` inside the loaded DLL.
- `SystemError` (6) - General fallback system/Win32 error.

---

## 5. Development Guidelines

- **Encoding**: Source files must remain UTF-8. Resource compiler `/c65001` is configured in CMake to compile resources properly under UTF-8.
- **Dependencies**: Zero external dependencies except for native Windows API.
- **Standard**: C++17 (configured via `CMAKE_CXX_STANDARD 17`).
- **Linking**: Executable links statically to Win32 helper libraries (`comdlg32`, `comctl32`, `shlwapi`, etc.) to run as a standalone portable binary.
