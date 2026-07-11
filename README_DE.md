[ English ](README.md) • [ Русский ](README_RU.md) • [ Deutsch ](README_DE.md)

# Shell-Bildbetrachter

Klassischer Windows-Bildbetrachter für Windows 10/11.

##Überblick

Microsoft hat die klassische Windows Photo Viewer-Schnittstelle in Windows 10 und 11 entfernt, aber die zugrunde liegende Systembibliothek „shimgvw.dll“ unterstützt weiterhin die Legacy-Funktionalität.

„PhotoViewer.exe“ ist ein kleiner Launcher, der „ImageView_FullscreenW“ von „shimgvw.dll“ aufruft, um das bekannte Vollbild-Anzeigeerlebnis wiederherzustellen.

Wenn Ihrer Systemversion „shimgvw.dll“ fehlt (häufig in einigen Lite- oder „N“-Editionen), finden Sie kompatible Versionen im Verzeichnis „DLL/“ dieses Projekts.

##Verwendung

```powershell
PhotoViewer.exe "C:\Pictures\photo.jpg"
PhotoViewer.exe
```

##Bauen

Anforderungen:
- Windows 10/11
- CMake 3.16+
- MinGW-w64 oder MSVC mit C++17-Unterstützung

```powershell
cmake -B build -G "MinGW Makefiles"
cmake --build build --config Release
```

Ergebnis: „release/PhotoViewer.exe“.

## Unterstützte Formate

BMP, JPG, JPEG, PNG, GIF, TIF, TIFF, ICO, WMF, EMF

## Lizenz

MIT
# Classic-Windows-Bildbetrachter-für-Windows-11