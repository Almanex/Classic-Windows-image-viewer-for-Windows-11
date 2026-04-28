# Shell Image Viewer

Classic Windows image viewer for Windows 10/11.

## Overview

`PhotoViewer.exe` launches the classic Windows full-screen image viewer through `ImageView_FullscreenW` from `shimgvw.dll`.

## Usage

```powershell
PhotoViewer.exe "C:\Pictures\photo.jpg"
PhotoViewer.exe
```

## Build

Requirements:
- Windows 10/11
- CMake 3.16+
- MinGW-w64 or MSVC with C++17 support

```powershell
cmake -B build -G "MinGW Makefiles"
cmake --build build --config Release
```

Result: `release/PhotoViewer.exe`

## Supported formats

BMP, JPG, JPEG, PNG, GIF, TIF, TIFF, ICO, WMF, EMF

## License

MIT