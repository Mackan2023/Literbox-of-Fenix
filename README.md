<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Literbox Fenix</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            color: #333;
            margin: 0;
            padding: 0;
        }

        #header {
            background-color: #1f272a;
            color: #dae3e3;
            text-align: center;
            padding: 20px 0;
        }

        #container {
            max-width: 800px;
            margin: 20px auto;
            padding: 20px;
            background-color: #fff;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }

        #container p {
            margin: 0 0 15px;
            line-height: 1.5;
        }

        #container a {
            color: #007bff;
            text-decoration: none;
        }

        #container a:hover {
            text-decoration: underline;
        }

        #container hr {
            border: 0;
            border-top: 1px solid #ddd;
            margin: 20px 0;
        }

        #container .section {
            margin-bottom: 20px;
        }

        #container .section-title {
            font-size: 1.2em;
            font-weight: bold;
            margin-bottom: 10px;
        }

        #container .info-list {
            padding-left: 20px;
        }

        #container .info-list li {
            margin-bottom: 5px;
        }
    </style>
</head>
<body>
    <div id="header">
        <h1>Literbox Fenix</h1>
    </div>

    <div id="container">
        <div class="section">
            <p>Hey, I have an idea, if you like to "bug" with, well, go head. I'm totally new to programming/electrical/etc., I'm no one.</p>
            <p>I will need a lot of help if you are interested in helping me? you are welcome to help. I have no idea what I'm doing here or what is what but I have an idea that I really like to do.</p>
            <p>It is a self-cleaning litter box for cats, <a href="https://github.com/Mackan2023/Literbox-of-Fenix/doc/" target="_blank" rel="noopener noreferrer">Literbox-of-Fenix-doc</a>.</p>
        </div>

        <div class="section">
            <p>It should be fun to do something I'm not good at :)</p>
            <p>About me: I'm not an electrician/programmer/etc., sometimes it's hard to understand.</p>
        </div>

        <div class="section">
            <h2 class="section-title">Components:</h2>
            <ul class="info-list">
                <li>2, stepper motor <span>(more info coming)</span></li>
                <li>1, <a href="https://www.pololu.com/file/0J450/a4988_DMOS_microstepping_driver_with_translator.pdf" target="_blank" rel="noopener noreferrer">stepper motor driver A4988</a></li>
                <li>1, (2), optical reader <span>(more info coming)</span></li>
                <li>1, <a href="https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf" target="_blank" rel="noopener noreferrer">HX711 weight sensor</a></li>
                <li>1, <a href="https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html" target="_blank" rel="noopener noreferrer">Blue Pill, STM32F103C8T6</a></li>
                <li>1, <a href="https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf" target="_blank" rel="noopener noreferrer">Esp-01s</a></li>
            </ul>
        </div>

        <hr>

        <div class="section">
            <p>****************************************************************************************</p>
            <p>1 - firmware &lt;first step to take with stm32f1&gt;.</p>
            <p>2 - Idé or worth to make it in software.</p>
            <p>3 - main &lt;start from main read from 4-startup ?&gt;</p>
        </div>

        <div class="section">
            <h2 class="section-title">Raspberry as PROGRAMMER</h2>
            <p>First check first cmd line <code>sudo nano /boot/cmdline.txt</code>, then remove this <code>"console=serial0,115200"</code>.</p>
            <p>Don't forget to reboot after all tools are done.</p>
            <p>Install flashtool:</p>
            <p><code>git clone https://git.code.sf.net/p/stm32flash/code stm/u (soon new adress here)</code></p>
            <!-- More steps can be added here -->
        </div>

        <div class="section">
            <h2 class="section-title">EPS PROGRAMMER USB</h2>
            <p>If use ESP-01s (ESP8266EX) on raspberrypi os with programmer:</p>
            <p>Install tool: <code>sudo pip install esptool</code></p>
            <!-- More steps can be added here -->
        </div>
    </div>
</body>
</html>
