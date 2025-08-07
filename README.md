# 🎮 Gaming Controller – Final (LeoJoy Version)

This version builds on the final design using the *LeoJoy library, allowing the **Arduino Pro Micro* to emulate a USB game controller instead of keyboard/mouse.

## 🚀 Features
- HID-compliant USB game controller
- Joysticks mapped to analog movement
- Buttons mapped to standard gamepad inputs
- Works natively on Windows (no driver installation)

## 🔧 Tools & Technologies
- Arduino Pro Micro or Leonardo
- Arduino IDE
- LeoJoy firmware
- PCB with joystick + button layout

## 🛠 Setup Instructions
1. Flash the Pro Micro with LeoJoy firmware.
2. Open the Arduino sketch and upload to the board.
3. The board will be detected as a USB game controller by Windows.
4. Test input using “Game Controllers” in Control Panel.

## ✅ Advantages
- Better for games that support gamepad input natively
- More accurate analog joystick control
- Clean, soldered final design

## 📂 Other Versions
- [Prototype (UnoJoy)](https://github.com/irfan7072/Gaming-Controller-Prototype-UnoJoy)
- [HID Version (Keyboard and Mouse Compatible) ](https://github.com/irfan7072/Gaming-Controller-HID)
