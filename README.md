# 🌐 ESP8266 Built-in LED Web Server

This project demonstrates how to control the built-in LED of an ESP8266 board through a web browser using a WiFi-based web server.

The ESP8266 hosts a web page that allows users to turn the LED ON or OFF and view its current status through a user-friendly interface.

---

## 🚀 Features

* Control ESP8266 built-in LED via web browser
* WiFi-enabled web server
* Real-time LED status indication
* Responsive web interface
* Visual LED indicator with color status
* No external components required

---

## 🧰 Hardware Requirements

* ESP8266 Board (NodeMCU, ESP-01, Wemos D1 Mini, etc.)
* USB Cable
* WiFi Network

---

## 💻 Software Requirements

* Arduino IDE
* ESP8266 Board Package

### Required Library

```cpp
#include <ESP8266WiFi.h>
```

---

## 🔌 Circuit Diagram

No external circuit is required.

The built-in LED is already connected internally to GPIO2 (D4) on most ESP8266 development boards.

```text
WiFi Network
      │
      ▼
 ESP8266 Web Server
      │
      ▼
 Built-in LED (GPIO2)
```

---

## 📋 Working Principle

1. ESP8266 connects to the configured WiFi network.
2. A web server is started on port 80.
3. The assigned IP address is displayed in the Serial Monitor.
4. Users open the IP address in a web browser.
5. The webpage displays:

   * LED Status
   * ON Button
   * OFF Button
   * LED Indicator
6. Clicking the buttons sends requests to the ESP8266.
7. The ESP8266 updates the LED state and refreshes the webpage.

---

## 📷 Web Interface Features

### LED ON

* Red glowing LED indicator
* Status displayed as "LED STATUS : ON"

### LED OFF

* Gray LED indicator
* Status displayed as "LED STATUS : OFF"

### Controls

* Green ON button
* Red OFF button

---

## ⚙️ WiFi Configuration

Update the following variables with your WiFi credentials:

```cpp
const char* ssid = "Your_WiFi_Name";
const char* password = "Your_WiFi_Password";
```

---

## ▶️ Upload and Run

1. Open Arduino IDE.
2. Install ESP8266 Board Package.
3. Select your ESP8266 board.
4. Update WiFi credentials.
5. Upload the code.
6. Open Serial Monitor (115200 baud).
7. Note the displayed IP address.

Example:

```text
WiFi Connected
Server Started
IP Address: 192.168.1.100
```

8. Open the IP address in a web browser:

```text
http://192.168.1.100
```

9. Control the built-in LED using the ON and OFF buttons.

---

<img width="1079" height="1296" alt="1001121861" src="https://github.com/user-attachments/assets/0b989207-651d-4da5-a2b4-e74c9a54dd42" />

---


## 📚 Learning Outcomes

After completing this project, you will understand:

* ESP8266 WiFi connectivity
* Web server implementation
* HTTP request handling
* GPIO control through a browser
* HTML and CSS integration with Arduino
* IoT device control over a local network

---

## 🎯 Applications

* Smart Home Automation
* IoT Device Control
* Remote Switching
* Embedded Web Servers
* ESP8266 Learning Projects
* Wireless Control Systems

---

## 📂 Project Structure

```text
ESP8266_Built-in_LED_WebServer/
│
├── ESP8266_Built-in_LED_WebServer.ino
├── README.md
└── images/
```

---

## 📜 License

This project is released under the MIT License and is free to use for educational and research purposes.

---

## 👨‍💻 Author

ddminiworld

GitHub:
https://github.com/ddminiworld
