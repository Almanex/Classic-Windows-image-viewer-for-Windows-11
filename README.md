# Shell Image Viewer

Classic Windows image viewer for Windows 10/11.

## Overview

Microsoft has removed the classic Windows Photo Viewer interface in Windows 10 and 11, but the underlying system library `shimgvw.dll` remains to support legacy functionality. 

`PhotoViewer.exe` is a tiny launcher that calls `ImageView_FullscreenW` from `shimgvw.dll` to bring back the familiar full-screen viewing experience.

If your system version lacks `shimgvw.dll` (common in some lite or "N" editions), you can find compatible versions in the `DLL/` directory of this project.

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
# Classic-Windows-image-viewer-for-Windows-11
