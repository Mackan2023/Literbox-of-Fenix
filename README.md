<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#dae3e3;"># literbox Fenix</span></div>
    <div>&nbsp;</div>
</div>
    <div>
      <span style="color:#dae3e3;">Hey, I have an idea, if you like to "bug" with, well, go head.</span>
      <span style="color:#f39c12;">I'm totally new to programming/electrical/ect, I'm no one.</span>
      <span style="color:#dae3e3;">I will need a lot of help if  you are interested in helping me? you are welcome to help.</span>
      <span style="color:#dae3e3;">I have no idea what I'm doing here or what is what but I have an idea that I really like to do.</span></div>
    <div>&nbsp;</div>
    <div>
      <span style="color:#dae3e3;">it is a self-cleaning litter box for cats, </span>
      <a target="_blank" rel="noopener noreferrer" href="https://github.com/Mackan2023/Literbox-of-Fenix/doc/">
      <span style="color:#dae3e3;">https://github.com/Mackan2023/Literbox-of-Fenix/doc/</span></a></div>
    <div>&nbsp;</div>
    <div>
      <span style="color:#dae3e3;">it should be fun to do something I'm not good at :)</span></div>
    <div>
      <span style="color:#dae3e3;">about me: I'm not an electrician/programmer/etc/ sometimes it's hard to understand.</span></div>
    <div><br>&nbsp;</div>
    <div>
      <span style="color:#7fcbcd;">2, stepper motor &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;(mor info coming)</span></div>
    <div>
      <span style="color:#7fcbcd;">1, stepper motor driver &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</span>
      <a target="_blank" rel="noopener noreferrer" href="https://www.pololu.com/file/0J450/a4988_DMOS_microstepping_driver_with_translator.pdf" download="file">
        <span style="color:#dae3e3;">A4988</span></a></div>
    <div>
      <span style="color:#7fcbcd;">1, (2), optical reader</span>
      <span style="color:#dae3e3;"> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; (more info coming.)</span></div>
    <div>
      <span style="color:#7fcbcd;">1</span>
      <span style="color:#dae3e3;">, HX711 weight sensor &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</span>
      <a target="_blank" rel="noopener noreferrer" href="https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf" download="file">
      <span style="color:#dae3e3;">HX711</span></a></div>
    <div>
      <span style="color:#7fcbcd;">1</span>
      <span style="color:#dae3e3;">, Blue Pill &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</span>
      <a target="_blank" rel="noopener noreferrer" href="https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html">
      <span style="color:#dae3e3;">STM32F103C8T6</span></a></div>
    <div>
      <span style="color:#7fcbcd;">1, Esp-01s &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</span>
      <a target="_blank" rel="noopener noreferrer" href="https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf" download="file">
      <span style="color:#dae3e3;">PDF</span></a></div>
    <div>
      <span style="color:#dae3e3;">****************************************************************************************</span></div>
    <div>
      <span style="color:#7fcbcd;">1 - firmware &lt;first step to take with stm32f1&gt;.</span>
      <span style="color:#7fcbcd;">2 - Idé or worth to make it in software.</span>
      <span style="color:#7fcbcd;">3 - main &lt;start from main read from -startup ?&gt;</span></div>
    <div><br>&nbsp;</div>
</div>
    <div>
      <span style="color:#7fcbcd;">"/////////////////////////Raspberry as PROGRAMMER\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"</span></div>
    <div>
      <span style="color:#c586c0;">if</span>
      <span style="color:#dae3e3;"> flash STM32F103C8T6 start here.</span></div>
    <div>
      <span style="color:#dae3e3;">first check first cmd line </span>
      <span style="color:#7fcbcd;">“sudo nano /boot/cmdline.txt”</span></div>
    <div>
      <span style="color:#dae3e3;">then remove this </span>
      <span style="color:#7fcbcd;">"console=serial0,115200"</span>
      <span style="color:#dae3e3;"> /dont foreget to reboot after all tools are done</span>
      <span style="color:#7fcbcd;">\</span></div>
    <div>&nbsp;</div>
    <div>
      <span style="color:#7fcbcd;">“install flashtool”</span><br>
      <span style="color:#dae3e3;">git clone https://git.code.sf.net/p/stm32flash/code stm/u (soon new adress here)</span><br>
      <span style="color:#dae3e3;">cd stm/u</span><br>
      <span style="color:#dae3e3;">make</span><br>
      <span style="color:#dae3e3;">sudo make install</span><br>
      <span style="color:#dae3e3;">cd ../</span></div>
    <div>&nbsp;</div>
    <div>
      <span style="color:#dae3e3;">this is not needed but use unsafe working bootloader go a head</span><br>
      <span style="color:#dae3e3;">git clone https://github.com/rogerclarkmelbourne/STM32duino-bootloader boot</span><br>&nbsp;</div>
    <div>
      <span style="color:#dae3e3;">check if u have connected stm to right on pi by "/dev/serial0"</span>
      <span style="color:#dae3e3;"> command, 0 if its connected there</span><br>&nbsp;</div>
    <div>
      <span style="color:#7fcbcd;">"burn in file over RX&amp;TX" stm32flash -v -w ./boot/bootloader_only_binaries/ generic_boot20_pc13 bin /dev/serial0 "erase firmware" stm32flash -o /dev/serial0</span><br>&nbsp;</div>
    <div>
      <span style="color:#7fcbcd;">“/////////////////////////EPS PROGRAMMER USB\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\”</span><br>
      <a target="_blank" rel="noopener noreferrer" href="https://cdn.sparkfun.com/datasheets/Wireless/WiFi/ESP8266ModuleV1.pdf" download="file"><span style="color:#7f8c8d;">ESP8266Module.pdf</span></a>
      <span style="color:#c586c0;"> &nbsp; &nbsp; &nbsp;if use ESP-01s (ESP8266EX) on raspberrypi os with programer</span>
      <br>&nbsp;</div>
    <div>
      <span style="color:#7fcbcd;">"install tool"</span>
      <span style="color:#dae3e3;">sudo pip install esptool</span><br>
      <span style="color:#7fcbcd;">"Burn bin file to usb0 if its usb0 (dev/usb* command)"</span>
      <span style="color:#dae3e3;"></span>
      <span style="color:#f39c12;">esptool.py --port /dev/ttyUSB0 write_flash 0 ftp/thebinfile.bin</span><br>
      <span style="color:#7fcbcd;">"erase firmware"</span>
      <span style="color:#dae3e3;"></span>
      <span style="color:#f39c12;">esptool.py --port /dev/ttyUSB0 erase_flash</span></div>
