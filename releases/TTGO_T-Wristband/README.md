# Release CubOS for TTGO Wristband 2021-06-08

<img alt="CubOS onM5StickC view" src="images\image2.png" height="300">
<img alt="CubOS onM5StickC view" src="images\image.png" height="300">

## Features
* RTC
* Pedometer
* Sleep time
* 1 week history
* In day history by hours for sleep and steps
* Up to 2 days on one charge with pedometer or 7 days without
* 80x160 display full framebuffer 65k colors


## Controls
<img alt="CubOS onM5StickC view" src="images\ttgo_wristband_scheme.png" width="250">

### Select button
* One click - next
* Long click - select
* Double click - back

## How to install
1. Install Arduino IDE
2. Add ESP32 boards support to Arduino IDE
3. Copy folder https://github.com/yacubovvs/CubOS/tree/main/external_libs/TFT_eSPI%20(T-Wristband%20ttgo) to Arduino libraries
4. Download and upload Arduino project https://github.com/yacubovvs/CubOS/tree/main/releases/M5StickC/cubos
