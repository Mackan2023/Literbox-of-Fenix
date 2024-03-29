# literbox Fenix

Hey, I have an idea, if you like to "bug" with, well, go head.

I'm totally new to programming/electrical/ect, I'm no one.

I will need a lot of help if you are interested in helping me? you are welcome to help.

I have no idea what I'm doing here or what is what but I have an idea that I really like to do.

it is a self-cleaning litter box for cats,

2 , stepper motor -> a driver   https://www.pololu.com/file/0J450/a4988_DMOS_microstepping_driver_with_translator.pdf

1, optical reader              

1(2), HX711 weight sensor      https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf

1, Blue Pill, STM32F103C8T6    https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html

1, Esp-01s                     https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf


it should be fun to do something I'm not good at :)

about me:

I'm not an electrician/programmer/etc/ sometimes it's hard to understand.


1 - firmware <first step to take with stm32f1>.

2 - Idé or worth to make it in software.

3 - main <start from main read from 4-startup ?>

"/////////////////////////Raspberry as PROGRAMMER\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"
check first cmd line
sudo nano /boot/cmdline.txt
remove this "console=serial0,115200"

if use STM32F103C8T6

"install tool"
cd /tmp
git clone https://git.code.sf.net/p/stm32flash/code stm/u (soon here)
cd stm/u
make
sudo make install
cd ../
git clone https://github.com/rogerclarkmelbourne/STM32duino-bootloader boot (no need for it but save and sorry)
"no need for this burn in file over RX&TX" stm32flash -v -w ./boot/bootloader_only_binaries/generic_boot20_pc13.bin /dev/serial0

"erase firmware" stm32flash -o /dev/serial0

"/////////////////////////EPS PROGRAMMER USB\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"

https://cdn.sparkfun.com/datasheets/Wireless/WiFi/ESP8266ModuleV1.pdf

if use ESP-01s (ESP8266EX) on raspberrypi os with programer

"install tool" sudo pip install esptool

"Burn bin file to usbx" esptool.py --port /dev/ttyUSB0 write_flash 0 ftp/thebinfile.bin

"erase firmware" esptool.py --port /dev/ttyUSB0 erase_flash
