# IoT-Data-Acquisition-And-Cloud-Monitoring-System

🌡️ IoT-Based Temperature Monitoring System
📌 Overview
This project implements an IoT-based temperature monitoring system using the LPC2129 microcontroller and ESP-01 Wi-Fi module. It measures real-time temperature using an LM35 sensor, displays it locally on an LCD, and uploads the data to the cloud (ThingSpeak) for remote monitoring.

🚀 Features


🌡️ Real-time temperature measurement using LM35


📟 Local display on 16x2 LCD


📡 Wireless data transmission using ESP-01 (Wi-Fi)


☁️ Cloud data logging via ThingSpeak


🔄 Continuous monitoring system


⚡ Low-cost and efficient design



🛠️ HARDWARE COMPONENTS:

->LPC2129 Microcontroller
->LM35 Temperature Sensor
->ESP-01 Wi-Fi Module (ESP8266)
->16x2 LCD Display
->MCP3208 ADC (for analog to digital conversion)
->Power Supply Unit
->Connecting wires and breadboard


💻 SOFTWARE REQUIREMENTS;

->Embedded C
->Keil uVision IDE
->Flash Magic (for programming LPC2129)
->ThingSpeak Platform


⚙️ Working Principle

->The LM35 sensor senses ambient temperature and produces an analog voltage.

->The MCP3208 ADC converts this analog signal into digital data.

->The LPC2129 microcontroller reads the digital value and processes it.

->Temperature is:

1)Displayed on the LCD

2)Sent to the ESP-01 module

3)The ESP-01 uploads the data to ThingSpeak cloud via Wi-Fi.

4)Users can monitor temperature remotely in real time.



🔌 Circuit Description


LM35 output → MCP3208 ADC input


MCP3208 → SPI interface with LPC2129


LCD → Connected to Port 1 of LPC2129


ESP-01 → UART communication with LPC2129



📊 Output

Real-time temperature displayed on LCD

Live graph plotted on ThingSpeak dashboard


📈 Applications


Industrial temperature monitoring


Smart homes


Weather stations


Server room monitoring


Healthcare environments



🔮 Future Enhancements


Add alert system (SMS/Email)


Mobile app integration


Multi-sensor support


Data analytics and prediction



👨‍💻 Author


Yuvaraj K



📄 License
This project is open-source and available under the MIT License.


