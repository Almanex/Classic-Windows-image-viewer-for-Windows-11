# Shell Image Viewer

Классический просмотрщик изображений Windows для Windows 10/11.

## Обзор

Microsoft удалила классический интерфейс средства просмотра фотографий Windows (Windows Photo Viewer) в Windows 10 и 11, но базовая системная библиотека `shimgvw.dll` осталась для поддержки устаревших функций. 

`PhotoViewer.exe` — это крошечный лаунчер, который вызывает `ImageView_FullscreenW` из `shimgvw.dll`, чтобы вернуть привычный интерфейс полноэкранного просмотра.

Если в вашей версии системы отсутствует `shimgvw.dll` (часто встречается в некоторых "облегченных" версиях или "N" редакциях), вы можете найти совместимые версии в каталоге `DLL/` этого проекта.

## Использование

```powershell
PhotoViewer.exe "C:\Users\User\Pictures\photo.jpg"
PhotoViewer.exe
```

## Сборка

Требования:
- Windows 10/11
- CMake 3.16+
- MinGW-w64 или MSVC с поддержкой C++17

```powershell
cmake -B build -G "MinGW Makefiles"
cmake --build build --config Release
```

Результат: `release/PhotoViewer.exe`

## Поддерживаемые форматы

BMP, JPG, JPEG, PNG, GIF, TIF, TIFF, ICO, WMF, EMF

## Лицензия

MIT
# Классический просмотрщик изображений Windows для Windows 11
