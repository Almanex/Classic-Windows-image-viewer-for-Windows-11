# Classic Windows Photo Viewer Benutzerhandbuch — Wiederherstellen und Verwenden unter Windows 11

> [!NOTE]
> Classic Windows Photo Viewer is ein leichtgewichtiges Open-Source-Dienstprogramm, das die originale, schnelle Benutzeroberfläche der Windows-Fotoanzeige auf modernen Windows 10- und 11-Systemen wiederherstellt. Dieses Handbuch enthält Schritt-für-Schritt-Anleitungen zum Herunterladen, Installieren und Einrichten von Dateizuordnungen.

Mit dem Dienstprogramm **Shell Image Viewer** können Sie die langsamere Standard-Windows-Fotos-App einfach umgehen und die gewohnte, schnelle Bildanzeige ohne komplexe Registrierungsänderungen wiederherstellen.

<p align="center">
  <img src="../screenshots/cover.png" alt="Shell Image Viewer" width="95%" />
</p>

## Schnellstartanleitung

1. **Schritt 1: Anwendung herunterladen** — Gehen Sie zum Release-Bereich auf GitHub und laden Sie die ausführbare Datei `PhotoViewer.exe` der neuesten Version herunter:
   * [Shell Image Viewer Releases auf GitHub](https://github.com/Almanex/Classic-Windows-image-viewer-for-Windows-11/releases)
2. **Schritt 2: Ausführbare Datei platzieren** — Verschieben Sie die heruntergeladene Datei `PhotoViewer.exe` in einen beliebigen permanenten Ordner auf Ihrem Computer (z. B. in das Stammverzeichnis von Laufwerk `C:\` oder in `C:\Program Files\PhotoViewer\`).
   > [!WARNING]
   > **Windows Defender SmartScreen beim ersten Start:**
   > Beim ersten Start oder der Dateizuordnung zeigt Windows Defender möglicherweise eine Warnung an: **„Der Computer wurde durch Windows geschützt“**.
   > Dies ist eine Standardreaktion von Microsoft Defender auf neue Open-Source-Dienstprogramme, die keine kostenpflichtige digitale Signatur haben.
   > So führen Sie das Programm aus:
   > 1. Klicken Sie auf den Link **„Weitere Informationen“** (More info).
   > 2. Klicken Sie auf die Schaltfläche **„Trotzdem ausführen“** (Run anyway).
3. **Schritt 3: App zum Öffnen von Bildern auswählen** — Klicken Sie mit der rechten Maustaste auf eine beliebige Bilddatei (z. B. `.jpg` or `.png`) und wählen Sie **„Öffnen mit“** (Open with) → **„Andere App auswählen“** (Choose another app).
4. **Schritt 4: PhotoViewer.exe suchen** — Scrollen Sie in der Programmliste nach unten, klicken Sie auf **„Weitere Apps“** (More apps), und wählen Sie dann **„Andere App auf diesem PC suchen“** (Look for another app on this PC). Navigieren Sie im Explorer-Fenster zu dem Ordner, in dem Sie `PhotoViewer.exe` gespeichert haben (aus Schritt 2), wählen Sie die Datei aus und klicken Sie auf **„Öffnen“** (Open).
5. **Schritt 5: Dateitypen zuordnen** — Wählen Sie aus, wie Sie die Anwendung verwenden möchten. Um dieses Programm immer für diesen Dateityp zu verwenden, klicken Sie auf **„Immer“** (Always). Um es nur einmal zu verwenden, klicken Sie auf **„Nur einmal“** (Just once).
   > [!TIP]
   > **Weitere Formate zuordnen:**
   > Wiederholen Sie die Zuordnungsschritte (Schritte 3–5) für die wichtigsten Bildformate, die Sie verwenden: `.jpg`, `.jpeg`, `.png`, `.bmp`, `.gif`, `.tiff`.

## Quelle

Dieses Handbuch basiert auf dem Artikel:
- [So stellen Sie den klassischen Bildbetrachter in Windows 11 auf G-ek.com wieder her](https://g-ek.com/klassicheskoe-sredstvo-prosmotra-fotografij-v-windows-11)

## Community & Unterstützung

- **Projekt unterstützen**: Wenn Ihnen das Tool gefällt, geben Sie uns bitte einen Stern auf [GitHub](https://github.com/Almanex/Classic-Windows-image-viewer-for-Windows-11)!
- **Fehler melden**: Haben Sie einen Fehler gefunden oder eine Idee? Erstellen Sie ein Issue auf unserer GitHub-Projektseite.
- **Mitwirken**: Pull Requests sind jederzeit herzlich willkommen. Helfen Sie uns, das Projekt für alle noch besser zu machen!
