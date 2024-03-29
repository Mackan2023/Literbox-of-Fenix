<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>literbox Fenix</title>
</head>
<body>

<h1>literbox Fenix</h1>

<p>Hey, I have an idea, if you like to "bug" with, well, go ahead. I'm totally new to programming/electrical/etc., I'm no one.
    I will need a lot of help if you are interested in helping me? you are welcome to help.
    I have no idea what I'm doing here or what is what but I have an idea that I really like to do.</p>

<p>It is a self-cleaning litter box for cats, <a href="https://github.com/Mackan2023/Literbox-of-Fenix/doc/">Literbox-of-Fenix</a>.</p>

<p>It should be fun to do something I'm not good at :)<br>
    About me: I'm not an electrician/programmer/etc. Sometimes it's hard to understand.</p>

<ul>
    <li>2, stepper motor (more info coming)</li>
    <li>1, stepper motor driver <a href="https://www.pololu.com/file/0J450/a4988_DMOS_microstepping_driver_with_translator.pdf">Datasheet</a></li>
    <li>1, (2), optical reader (more info coming)</li>
    <li>1, HX711 weight sensor <a href="https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf">Datasheet</a></li>
    <li>1, Blue Pill, STM32F103C8T6 <a href="https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html">Board Info</a></li>
    <li>1, ESP-01s <a href="https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf">Datasheet</a></li>
</ul>

<hr>

<ol>
    <li>Firmware &lt;first step to take with STM32F1&gt;.</li>
    <li>Is it worth considering making it in software?</li>
    <li>Main &lt;start from main read from 4-startup ?&gt;</li>
</ol>

<p>"/////////////////////////Raspberry as PROGRAMMER\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"
    First, check the first command line by entering "sudo nano /boot/cmdline.txt" then remove "console=serial0,115200". Don't forget to reboot after all tools are installed.<br>
    If you're flashing STM32F103C8T6, start here.</p>

<p>Install flashtool:</p>

<code>
git clone https://git.code.sf.net/p/stm32flash/code stm/u (soon new address here)<br>
cd stm/u<br>
make<br>
sudo make install<br>
cd ../
</code>

<p>This is not necessary but use unsafe working bootloader, go ahead.</p>

<code>
git clone https://github.com/rogerclarkmelbourne/STM32duino-bootloader boot<br>
Check if you have connected STM to the right port on Raspberry Pi by using "/dev/serial0" command, 0 if it's connected there<br>
"burn in file over RX&TX" stm32flash -v -w ./boot/bootloader_only_binaries/generic_boot20_pc13.bin /dev/serial0<br>
"erase firmware" stm32flash -o /dev/serial0<br>
</code>

<p>"/////////////////////////ESP PROGRAMMER USB\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"
    If you're using ESP-01s (ESP8266EX) on Raspberry Pi OS with a programmer, follow these steps.</p>

<p>Install tool:</p>

<code>
sudo pip install esptool<br>
Burn bin file to usb0 if it's usb0 (dev/usb* command)<br>
esptool.py --port /dev/ttyUSB0 write_flash 0 ftp/thebinfile.bin<br>
Erase firmware<br>
esptool.py --port /dev/ttyUSB0 erase_flash<br>
</code>

</body>
</html>
