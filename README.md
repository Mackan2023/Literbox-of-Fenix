<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>literbox Fenix</h1>

<p> Hey, I have an idea, if you like to "bug" with, well, go head.
    I'm totally new to programming/electrical/ect, I'm no one.
    I will need a lot of help if you are interested in helping me? you are welcome to help.
    I have no idea what I'm doing here or what is what but I have an idea that I really like to do.

<p>It is a self-cleaning litter box for cats, <a href="https://github.com/Mackan2023/Literbox-of-Fenix/doc/">Literbox-of-Fenix</a>.</p>

<p>It should be fun to do something I'm not good at :)<br>
About me: I'm not an electrician/programmer/etc. Sometimes it's hard to understand.</p>
<ul>
    <li>2, stepper motor (more info coming)</li>
    <li>1, stepper motor driver 
<a href="https://www.pololu.com/file/0J450/a4988_DMOS_microstepping_driver_with_translator.pdf">Datasheet</a></li>
    <li>1, (2), optical reader (more info coming)</li>
    <li>1, HX711 weight sensor 
<a href="https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf">Datasheet</a></li>
    <li>1, Blue Pill, STM32F103C8T6 
<a href="https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html">Board Info</a></li>
    <li>1, ESP-01s 
<a href="https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf">Datasheet</a></li>
</ul>
<ol>
    <li>firmware ? (first step to take with stm32f1)..</li>
    <li>Idé or worth to make it (in software.)?</li>
    <li>main all start from main (read from 4-startup) ?</li>
</ol>
<hr>
/////////////////////////Raspberry as PROGRAMMER/STM connected\\\\\\\\\\\\<br>
First, check the first command line by entering<br>
<code>sudo nano /boot/cmdline.txt</code> then remove <code>console=serial0,115200</code>.<br>
Don't forget to <code>reboot</code>after all tools are installed.
<hr>
/////////////////////////start here STM32F103C8T6\\\\\\\\\\\\\\\\\\\\\\\\\<br>
<ul>
If you're flashing STM32F103C8T6<br>
install flashtool <code>git clone https://git.code.sf.net/p/stm32flash/code stm/u</code> (soon new adress here)<br>
<code>cd stm/u<br>
make<br>
sudo make install<br>
cd ../</code><br>

this is not needed but use unsafe working bootloader go a head<br>
<code>git clone https://github.com/rogerclarkmelbourne/STM32duino-bootloader boot</code><br>
check if u have connected stm to right pins, <code>/dev/serial0</code> command, 0 if its connected there<br>
burn in file over RX&TX <code>stm32flash -v -w ./boot/bootloader_only_binaries/generic_boot20_pc13.bin /dev/serial0</code>

erase firmware <code>stm32flash -o /dev/serial0</code>
<hr>
/////////////////////////ESP PROGRAMMER USB\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
If you're using ESP-01s (ESP8266EX) on Raspberry Pi OS with a programmer, follow these steps:<br>
Install tool: <code>sudo pip install esptool</code><br>
Burn bin file to usb <code>dev/ttyUSB*</code> (are command to check usb):<br>
<code>esptool.py --port /dev/ttyUSB0 write_flash 0 ftp/thebinfile.bin</code><br>
Erase firmware: <code>esptool.py --port /dev/ttyUSB0 erase_flash</code></p>
</ul>

</body>
</html>
c Mackan2024@github
