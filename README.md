<html>
# literbox Fenix

<a>Hey, I have an idea, if you like to "bug" with, well, go head.</a>I'm totally new to programming/electrical/ect, I'm no one.
I will need a lot of help if you are interested in helping me? you are welcome to help.
I have no idea what I'm doing here or what is what but I have an idea that I really like to do.

it is a self-cleaning litter box for cats, https://github.com/Mackan2023/Literbox-of-Fenix/doc/

it should be fun to do something I'm not good at :)
about me: I'm not an electrician/programmer/etc/ sometimes it's hard to understand.

2, stepper motor            (mor info coming)
1, stepper motor driver     https://www.pololu.com/file/0J450/a4988_DMOS_microstepping_driver_with_translator.pdf
1, (2), optical reader       (more info coming.)
1, HX711 weight sensor      https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf
1, Blue Pill, STM32F103C8T6 https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html
1, Esp-01s                  https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf
****************************************************************************************
1 - firmware <first step to take with stm32f1>.
2 - Idé or worth to make it in software.
3 - main <start from main read from 4-startup ?>

"/////////////////////////Raspberry as PROGRAMMER\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"
first check first cmd line "sudo nano /boot/cmdline.txt" then remove this "console=serial0,115200" /dont foreget to reboot after all tools are done\

if flash STM32F103C8T6 start here.

"install flashtool"

git clone https://git.code.sf.net/p/stm32flash/code stm/u (soon new adress here)

cd stm/u

make

sudo make install

cd ../

this is not needed but use unsafe working bootloader go a head

git clone https://github.com/rogerclarkmelbourne/STM32duino-bootloader boot

check if u have connected stm to right on pi by "/dev/serial0" command, 0 if its connected there

"burn in file over RX&TX" stm32flash -v -w ./boot/bootloader_only_binaries/generic_boot20_pc13.bin /dev/serial0

"erase firmware" stm32flash -o /dev/serial0

"/////////////////////////EPS PROGRAMMER USB\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"

https://cdn.sparkfun.com/datasheets/Wireless/WiFi/ESP8266ModuleV1.pdf

if use ESP-01s (ESP8266EX) on raspberrypi os with programer

"install tool" sudo pip install esptool

"Burn bin file to usb0 if its usb0 (dev/usb* command)" esptool.py --port /dev/ttyUSB0 write_flash 0 ftp/thebinfile.bin

"erase firmware" esptool.py --port /dev/ttyUSB0 erase_flash
</html>
