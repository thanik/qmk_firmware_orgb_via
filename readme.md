# Quantum Mechanical Keyboard Firmware

This is a keyboard firmware based on the [qmk firmware](https://github.com/qmk/qmk_firmware). But this fork introduced unofficial OpenRGB protocol with VIA support.

See [dztech/dz65rgb/keymaps/via_orgb_hybrid](https://github.com/thanik/qmk_firmware_orgb_via/tree/feature/thanik/keyboards/dztech/dz65rgb/keymaps/via_orgb_hybrid) for implementation example to use for your keyboard as I own only this keyboard.

Pull requests are welcome :)

## # Define
- **VIA_OPENRGB_HYBRID_APPEND_COMMAND** - enable for real hybrid VIA and OpenRGB by appending OpenRGB command IDs to VIA one. This needs adding number of VIA command IDs to OpenRGB QMK command IDs as well.
- **VIA_OPENRGB_HYBRID_CUSTOM_KEYCODE** - enable for having a custom keycode for switching between OpenRGB and VIA raw HID mode. (Currently doesn't work)
- **ORGB_SWITCH_KEYCODE** - Specify keycode for the button to switch between OpenRGB and VIA raw HID mode.
- **ORGB_SWITCH_KEYCODE_LAYER** - Specify layer for above keycode for the button to switch between OpenRGB and VIA raw HID mode.
- **ORGB_SWITCH_KEYCODE_MOD_LAYER** - Specify layer for above for showing the current mode light status. (On = OpenRGB, Off = VIA)
## Credits
- [HorrorTroll's fork on QMK OpenRGB](https://github.com/HorrorTroll/qmk_firmware/tree/openrgb_develop)
- [Changes for VIA OpenRGB Hybrid](https://github.com/gloryhzw/qmk_tool/wiki/Changes-for-VIA-OpenRGB-Hybrid)

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
