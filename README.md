<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#dae3e3;"># literbox Fenix</span></div>
    <div>&nbsp;</div>
</div>
<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#dae3e3;">Hey, I have an idea, </span><span style="color:#c586c0;">if</span><span style="color:#dae3e3;"> you like to </span><span style="color:#7fcbcd;">"bug"</span><span style="color:#dae3e3;"> with, well, go </span><span style="color:#f39c12;">head</span><span style="color:#dae3e3;">. </span><span style="color:#f39c12;">I</span><span style="color:#dae3e3;">'m totally new to programming/electrical/ect, I'm no one.</span></div>
    <div><span style="color:#dae3e3;">I will need a lot of help </span><span style="color:#c586c0;">if</span><span style="color:#dae3e3;"> you are interested in helping me? you are welcome to help.</span></div>
    <div><span style="color:#dae3e3;">I have no idea what I'm doing here or what is what but I have an idea that I really like to do.</span></div>
    <div>&nbsp;</div>
</div>
<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#dae3e3;">it is a self-cleaning litter box for cats, </span><a target="_blank" rel="noopener noreferrer" href="https://github.com/Mackan2023/Literbox-of-Fenix/doc/"><span style="color:#dae3e3;">https://github.com/Mackan2023/Literbox-of-Fenix/doc/</span></a></div>
    <div>&nbsp;</div>
</div>
<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#dae3e3;">it should be fun to do something I'm not good at :)</span></div>
    <div><span style="color:#dae3e3;">about me: I'm not an electrician/programmer/etc/ sometimes it's hard to understand.</span></div>
    <div><br>&nbsp;</div>
</div>
<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#7fcbcd;">2</span><span style="color:#dae3e3;">, stepper </span><span style="color:#f39c12;">motor</span><span style="color:#dae3e3;"> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;(mor info coming)</span></div>
    <div><span style="color:#7fcbcd;">1</span><span style="color:#dae3e3;">, stepper motor driver &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;https:</span><span style="color:#7f8c8d;">//www.pololu.com/file/0J450/a4988_DMOS_microstepping_driver_with_translator.pdf</span></div>
    <div><span style="color:#7fcbcd;">1</span><span style="color:#dae3e3;">, (</span><span style="color:#7fcbcd;">2</span><span style="color:#dae3e3;">), optical </span><span style="color:#f39c12;">reader</span><span style="color:#dae3e3;"> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; (more info coming.)</span></div>
    <div><span style="color:#7fcbcd;">1</span><span style="color:#dae3e3;">, HX711 weight sensor &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; https:</span><span style="color:#7f8c8d;">//cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf</span></div>
    <div><span style="color:#7fcbcd;">1</span><span style="color:#dae3e3;">, Blue Pill, STM32F103C8T6 &nbsp; &nbsp;https:</span><span style="color:#7f8c8d;">//stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html</span></div>
    <div><span style="color:#7fcbcd;">1</span><span style="color:#dae3e3;">, Esp-0</span><span style="color:#7fcbcd;">1</span><span style="color:#dae3e3;">s &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;https:</span><span style="color:#7f8c8d;">//www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf</span></div>
    <div><span style="color:#dae3e3;">****************************************************************************************</span></div>
    <div><span style="color:#7fcbcd;">1</span><span style="color:#dae3e3;"> - firmware &lt;first step to take with stm32f1&gt;.</span></div>
    <div><span style="color:#7fcbcd;">2</span><span style="color:#dae3e3;"> - Idé or worth to make it in software.</span></div>
    <div><span style="color:#7fcbcd;">3</span><span style="color:#dae3e3;"> - main &lt;start from main read from </span><span style="color:#7fcbcd;">4</span><span style="color:#dae3e3;">-startup ?&gt;</span></div>
    <div><br>&nbsp;</div>
</div>
<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#7fcbcd;">"/////////////////////////Raspberry as PROGRAMMER\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"</span></div>
    <div><span style="color:#c586c0;">if</span><span style="color:#dae3e3;"> flash STM32F103C8T6 start here.</span></div>
    <div><span style="color:#dae3e3;">first check first cmd line </span><span style="color:#7fcbcd;">“sudo nano /boot/cmdline.txt”</span></div>
    <div><span style="color:#dae3e3;">then remove this </span><span style="color:#7fcbcd;">"console=serial0,115200"</span><span style="color:#dae3e3;"> /dont foreget to reboot after all tools are done</span><span style="color:#7fcbcd;">\</span></div>
    <div>&nbsp;</div>
    <div><span style="color:#7fcbcd;">“install flashtool”</span><br><span style="color:#dae3e3;">git clone https:</span><span style="color:#7f8c8d;">//git.code.sf.net/p/stm32flash/code stm/u (soon new adress here)</span><br><span style="color:#dae3e3;">cd stm/u</span><br><span style="color:#dae3e3;">make</span><br><span style="color:#dae3e3;">sudo make install</span><br><span style="color:#dae3e3;">cd ../</span></div>
    <div>&nbsp;</div>
</div>
<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#dae3e3;">this is not needed but use unsafe working bootloader go a head</span><br><span style="color:#dae3e3;">git clone https:</span><span style="color:#7f8c8d;">//github.com/rogerclarkmelbourne/STM32duino-bootloader boot</span><br>&nbsp;</div>
    <div><span style="color:#dae3e3;">check </span><span style="color:#c586c0;">if</span><span style="color:#dae3e3;"> u have connected stm to right on pi by </span><span style="color:#7fcbcd;">"/dev/serial0"</span><span style="color:#dae3e3;"> command, </span><span style="color:#7fcbcd;">0</span><span style="color:#dae3e3;"> </span><span style="color:#c586c0;">if</span><span style="color:#dae3e3;"> its connected there</span><br>&nbsp;</div>
</div>
<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#7fcbcd;">"burn in file over RX&amp;TX"</span><span style="color:#dae3e3;"> stm32flash -v -w ./boot/bootloader_only_binaries/</span><span style="color:#f39c12;">generic_boot20_pc13</span><span style="color:#dae3e3;">.</span><span style="color:#f39c12;">bin</span><span style="color:#dae3e3;"> /dev/serial0</span><br><span style="color:#7fcbcd;">"erase firmware"</span><span style="color:#dae3e3;"> stm32flash -o /dev/serial0</span><br>&nbsp;</div>
    <div><span style="color:#7fcbcd;">“/////////////////////////EPS PROGRAMMER USB\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\”</span><br><span style="color:#dae3e3;">https:</span><span style="color:#7f8c8d;">//cdn.sparkfun.com/datasheets/Wireless/WiFi/ESP8266ModuleV1.pdf</span><br>&nbsp;</div>
</div>
<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#c586c0;">if</span><span style="color:#dae3e3;"> use ESP-0</span><span style="color:#7fcbcd;">1</span><span style="color:#dae3e3;">s (ESP8266EX) on raspberrypi os with programer</span><br>&nbsp;</div>
</div>
<div style="background-color:#1f272a;color:#dae3e3;font-family:Consolas, 'Courier New', monospace;font-size:14px;font-weight:normal;line-height:19px;white-space:pre;">
    <div><span style="color:#7fcbcd;">"install tool"</span><span style="color:#dae3e3;"> sudo pip install esptool</span><br><span style="color:#7fcbcd;">"Burn bin file to usb0 if its usb0 (dev/usb* command)"</span><span style="color:#dae3e3;"> </span><span style="color:#f39c12;">esptool</span><span style="color:#dae3e3;">.</span><span style="color:#f39c12;">py</span><span style="color:#dae3e3;"> --port /dev/ttyUSB0 write_flash </span><span style="color:#7fcbcd;">0</span><span style="color:#dae3e3;"> ftp/</span><span style="color:#f39c12;">thebinfile</span><span style="color:#dae3e3;">.</span><span style="color:#f39c12;">bin</span><br><span style="color:#7fcbcd;">"erase firmware"</span><span style="color:#dae3e3;"> </span><span style="color:#f39c12;">esptool</span><span style="color:#dae3e3;">.</span><span style="color:#f39c12;">py</span><span style="color:#dae3e3;"> --port /dev/ttyUSB0 erase_flash</span></div>
</div>
