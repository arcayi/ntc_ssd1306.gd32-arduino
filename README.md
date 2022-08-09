<!-- <p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://i.imgur.com/FxL5qM0.jpg" alt="Bot logo"></a>
</p> -->

<h3 align="center">TMCC</h3>

<div align="center">

[![Platform](https://img.shields.io/badge/platform-Arduino_GD32-blue.svg)](https://github.com/arcayi/ArduinoCore-GD32/tree/gd32e23x-support)
[![GitHub stars](https://img.shields.io/github/stars/arcayi/ntc_ssd1306.gd32-arduino)](https://github.com/arcayi/ntc_ssd1306.gd32-arduino/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/arcayi/ntc_ssd1306.gd32-arduino)](https://github.com/arcayi/ntc_ssd1306.gd32-arduino/network)
[![GitHub issues](https://img.shields.io/github/issues/arcayi/ntc_ssd1306.gd32-arduino)](https://github.com/arcayi/ntc_ssd1306.gd32-arduino/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/kylelobo/The-Documentation-Compendium.svg)](https://github.com/arcayi/ntc_ssd1306.gd32-arduino/pulls)
![GitHub](https://img.shields.io/github/license/arcayi/ntc_ssd1306.gd32-arduino)
</div>

---

<p align="center"> 🤖 Temperature Monitor and Cooling Controller
    <br> 
</p>

## 📝 Table of Contents

- [📝 Table of Contents](#-table-of-contents)
- [🧐 About <a name = "about"></a>](#-about-)
- [🎥 Demo / Working <a name = "demo"></a>](#-demo--working-)
- [🏁 Current state <a name = "current_state"></a>](#-current-state-)
- [⛏️ Built Using <a name = "built_using"></a>](#️-built-using-)
- [✍️ Authors <a name = "authors"></a>](#️-authors-)
- [🎉 Acknowledgements <a name = "acknowledgement"></a>](#-acknowledgements-)

## 🧐 About <a name = "about"></a>

This desigh applys temperature monitoring and contolling on both cool side and hot side of TEC water cooling system.

When water cooling the CPU, GPU, south bridge, it might be an efficient way to cool the water using TEC (thermo-electric cooler or Peltier element) to exchange heat to the fans. but TEC is easy to **burn** if the temperature of the hot side rise to high. That is why it need both side monitorring。

## 🎥 Demo / Working <a name = "demo"></a>

![Working](asset/GD32E230_OLED.jpg)



## 🏁 Current state <a name = "current_state"></a>


Legend:

✔️ = working
❌ = not working at all
⚠️ = some features not working
⁉️ = untested
⛏️ = WIP

| Name                    | Works? | Notes                             |
| ----------------------- | ------ | --------------------------------- |
| ntc sensor              | ✔️      | Tested on NTC 10K 3950            |
| display                 | ✔️      | Tested on SSD1306 I2C 128x32 OLED |
| temperature controlling | ⛏️      |                                   |





## ⛏️ Built Using <a name = "built_using"></a>

- [ArduinoCore-GD32](https://github.com/CommunityGD32Cores/ArduinoCore-GD32) - GD32 arduino framework
- [platform-gd32](https://github.com/CommunityGD32Cores/platform-gd32) - PlatformIO platform for ARM-based GD32{F,E,L,W} chips. 
- [platformio](https://github.com/platformio/platformio-vscode-ide) - PlatformIO IDE for VSCode: The next generation integrated development environment for IoT
- [easyeda or lceda](https://easyeda.com/) - An Easier and Powerful
Online PCB Design Tool

## ✍️ Authors <a name = "authors"></a>

- [@arcayi](https://github.com/arcayi) - Idea & Initial work

See also the list of [contributors](https://github.com/arcayi/ntc_ssd1306.gd32-arduino/contributors) who participated in this project.

## 🎉 Acknowledgements <a name = "acknowledgement"></a>

