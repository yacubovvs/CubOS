# Release CubOS for TTGO Wristband 2021-11-29

<img alt="CubOS onM5StickC view" src="images\image_photo.png" max-width="400">

## Features
* RTC
* Pedometer
* Sleep time
* 1 week history
* In day history by hours for sleep and steps
* Up to 2 days on one charge with pedometer or 7 days without
* 80x160 display full framebuffer 65k colors
* Sync with phone

## Android APP
Android apk file: https://github.com/yacubovvs/CubOS/tree/main/tools/CubOSBLEApp/releases <br>
Android app source: https://github.com/yacubovvs/CubOS/tree/main/tools/CubOSBLEApp
<img alt="CubOS android app screenshot" src="images\screenshots\android_app_screenshot.png" max-width="600">

## Controls
<img alt="CubOS onM5StickC view" src="images\ttgo_wristband_scheme.png" width="250">

### Select button
* One tap - next
* Long tap - select
* Double tap - back

## How to install
1. Install Arduino IDE
2. Add ESP32 boards support to Arduino IDE
3. Select board - ESP32 Dev Module
4. Set PSRAM to "Disable"
5. Copy folder https://github.com/yacubovvs/CubOS/tree/main/external_libs/TFT_eSPI%20(T-Wristband%20ttgo) to Arduino libraries
6. Download and upload Arduino project https://github.com/yacubovvs/CubOS/tree/main/releases/TTGO_T-Wristband/T-Wristband_LiLyGo/cubos
