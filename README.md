<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
<div>
  <span># literbox Fenix</span><br>
  <span>Hey, I have an idea, if you like to "bug" with, well, go head.</span><br>
  <span>I'm totally new to programming/electrical/ect, I'm no one.</span><br>
  <span>I will need a lot of help if  you are interested in helping me? you are welcome to help.</span><br>
  <span>I have no idea what I'm doing here or what is what but I have an idea that I really like to do.</span><br>
  <span>it is a self-cleaning litter box for cats, </span></div><br>
  <a target="_blank" rel="noopener noreferrer" href="https://github.com/Mackan2023/Literbox-of-Fenix/doc/">
  <span>Literbox-of-Fenix-doc</span></a></div>
<div>
  <span>it should be fun to do something I'm not good at :)</span><br>
  <span>about me: I'm not an electrician/programmer/etc/ sometimes it's hard to understand.</span><br>&nbsp;
  <span>2, stepper motor &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;(mor info coming)</span>
  <span>1, stepper motor driver &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</span><a target="_blank" rel="noopener noreferrer" href="https://www.pololu.com/file/0J450/a4988_DMOS_microstepping_driver_with_translator.pdf" download="file"><span>A4988</span></a>
  <span>1, (2), optical reader</span><span> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; (more info coming.)</span></div>
		  <span>1, HX711 weight sensor &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</span><a target="_blank" rel="noopener noreferrer" href="https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf" download="file"><span>HX711</span></a>
  <span>1, Blue Pill &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</span> <a target="_blank" rel="noopener noreferrer" href="https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html"> <span>STM32F103C8T6</span></a></div>
<div>
  <span>1, Esp-01s &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</span><a target="_blank" rel="noopener noreferrer" href="https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf" download="file"><span>PDF</span></a></div>
<div>
  <span>****************************************************************************************</span>
  <span>1 - firmware &lt;first step to take with stm32f1&gt;.</span>
  <span>2 - Idé or worth to make it in software.</span>
  <span>3 - main &lt;start from main read from -startup ?&gt;</span>
  <span>"/////////////////////////Raspberry as PROGRAMMER\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"</span>
  <span>if flash STM32F103C8T6 start here.</span><br>
  <span>first check first cmd line “sudo nano /boot/cmdline.txt”</span><br>
  <span>then remove this "console=serial0,115200"</span>
  <span>/dont foreget to reboot after all tools are done\</span>
  <span>“install flashtool”</span><br>
  <span>git clone https://git.code.sf.net/p/stm32flash/code stm/u (soon new adress here)</span><br>
  <span>cd stm/u</span><br>
  <span>make</span><br>
  <span>sudo make install</span><br>
  <span>cd ../</span><br>
  <span>this is not needed but use unsafe working bootloader go a head</span><br>
  <span>git clone https://github.com/rogerclarkmelbourne/STM32duino-bootloader boot</span><br>&nbsp;
  <span>check if u have connected stm to right on pi by "/dev/serial0"</span>
  <span> command, 0 if its connected there</span><br>
  <span>"burn in file over RX&amp;TX" stm32flash -v -w ./boot/bootloader_only_binaries/ generic_boot20_pc13 bin /dev/serial0 "erase firmware" stm32flash -o /dev/serial0</span><br>
  <span>“/////////////////////////EPS PROGRAMMER USB\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\”</span><br>
  <a target="_blank" rel="noopener noreferrer" href="https://cdn.sparkfun.com/datasheets/Wireless/WiFi/ESP8266ModuleV1.pdf" download="file"><span>ESP8266Module.pdf</span></a>&nbsp; &nbsp; &nbsp;
  <span>if use ESP-01s (ESP8266EX) on raspberrypi os with programer</span><br>
  <span>"install tool"</span> &nbsp; &nbsp; &nbsp;<span>sudo pip install esptool</span><br>
  <span>Burn bin file to usb0 if its usb0 (dev/usb* command)" </span>
  <span>esptool.py --port /dev/ttyUSB0 write_flash 0 ftp/thebinfile.bin</span><br>
  <span>"erase firmware"</span> &nbsp; &nbsp; &nbsp;<span>esptool.py --port /dev/ttyUSB0 erase_flash</span></div>
