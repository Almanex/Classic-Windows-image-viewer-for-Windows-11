[README_RU](docs/README_RU.md) | [README_DE](docs/README_DE.md) | [README_EN](README.md) | [GUIDE_RU](docs/GUIDE_RU.md) | [GUIDE_DE](docs/GUIDE_DE.md) | [GUIDE_EN](docs/GUIDE_EN.md)
# Shell Image Viewer

*Classic Windows Photo Viewer launcher for Windows 10 and 11.*

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-0078d7.svg)](#)
[![Language: C++17](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](#)
[![Share](https://img.shields.io/twitter/url?style=social&url=https%3A%2F%2Fgithub.com%2FAlmanex%2FClassic-Windows-image-viewer-for-Windows-11)](https://twitter.com/intent/tweet?text=Check%20out%20this%20awesome%20project&url=https%3A%2F%2Fgithub.com%2FAlmanex%2FClassic-Windows-image-viewer-for-Windows-11)


<p align="center">
  <img src="screenshots/cover.png" alt="Shell Image Viewer" width="95%" />
</p>

---

## Overview

Microsoft has removed the classic Windows Photo Viewer interface in Windows 10 and 11, but the underlying system library `shimgvw.dll` remains to support legacy functionality.

`PhotoViewer.exe` is a tiny launcher written in C++ that calls `ImageView_FullscreenW` from `shimgvw.dll` to bring back the familiar full-screen viewing experience.

If your system version lacks `shimgvw.dll` (common in some lite or "N" editions), you can find compatible versions in the `DLL/` directory of this project and place them next to the executable.

---

## Key Features

- Fullscreen viewing of images with the original Windows Photo Viewer user interface.
- Automatic system-wide lookup of `shimgvw.dll`.
- Support for loading local `shimgvw.dll` adjacent to the executable if not found in the system.
- Open files through command-line argument passing or standard file selection dialog.
- Command-line flags to retrieve help, version information, and supported image formats.

---

## Tech Stack

| Layer / Component | Technology | Details / Purpose |
| --- | --- | --- |
| Language | C++17 | Standard compliance for modern and safe codebase |
| Build System | CMake 3.16+ | Cross-platform build configuration |
| UI Library | Win32 API / Common Dialogs | Native lightweight file picking dialog and message boxes |
| Core Dependency | shimgvw.dll | Native Windows Photo Viewer library |

---

## Getting Started

For a detailed step-by-step graphical setup guide, see the [User Guide](docs/GUIDE.md).

### Prerequisites

- Windows 10/11
- CMake 3.16+
- MinGW-w64 or MSVC with C++17 support

### Installation & Running

Run the following commands in your shell:

```powershell
git clone https://github.com/Almanex/Classic-Windows-image-viewer-for-Windows-11.git
cd Classic-Windows-image-viewer-for-Windows-11
cmake -B build -G "MinGW Makefiles"
cmake --build build --config Release
```

The resulting binary will be built at `release/PhotoViewer.exe`.

---

## Running the Tests

The project does not contain automated unit tests. Testing is conducted manually by executing the launcher with diagnostic parameters:

```powershell
release/PhotoViewer.exe /?
release/PhotoViewer.exe --about
release/PhotoViewer.exe --formats
```

---

## Deployment

To deploy the application, simply copy the compiled standalone `PhotoViewer.exe` binary to the target system.

> [!WARNING]
> **Windows Defender SmartScreen** may block the application on its first launch.
> * **Reason**: The application is unsigned (does not have a paid digital code-signing certificate), which is standard for free, open-source projects.
> * **Instruction**: To bypass this warning, click **"More info"**, and then select **"Run anyway"**.

---

## Contributing

Contributions are welcome! Feel free to open issues or submit Pull Requests for bugs, enhancements, and translation updates.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
