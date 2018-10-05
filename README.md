# Kolonial Klikk

PRO200-17 Smidig prosjekt gruppe 13

## ESP8266 ESP-01 EN

PRO200-17-13/programmering/Arduino/KolonialKlikkAlpha is the latest version. 

PRO200-17-13/programmering/Arduino/KolonialKlikkBeta is an earlier version. 

### Prerequisites

To run the code you will need the Arduino IDE, or an IDE compatible with .ino, .h and .cpp files. You will need to set up the IDE to work with the ESP8266 - https://github.com/esp8266/Arduino will explain how to install the Arduino core for ESP8266. 

### Installing

 - Download zip
 - Unpack the folder
 - Open 'KolonialKlikkAlpha.ino in Arduino
    - If you get the message "KolonialKlikkAlpha needs to be inside a folder named KolonialKlikkAlpha", click OK. 
 - The Arduino IDE will also open all C++ files
 

### Setting up the ESP8266 module

To upload code to the module
 - Open PRO200-17-13/programmering/Arduino/Schemantics/ESP8266_To_Upload.png / ESP8266_To_Upload.fzz
 - Connect wires as shown
 - To upload code to the module the GPIO0 pin has to be connect to GND when the upload starts. Remove this connection after the upload has started. 
 - Connect an USB cabel from FTDI to your computer
 - Connect the ESP8266 module to a 3.3v power supply. Do not connect the module to 5v, this could damage it!
 
After the code has been uploaded
 - Open PRO200-17-13/programmering/Arduino/Schemantics/ESP8266_After_Upload.png / ESP8266_After_Upload.fzz
 - Connect wires as shown
 - Be shure the GPIO0 pin is isn't connected to GND. 
 - Connect the ESP8266 module to a 3.3v power supply. Do not connect the module to 5v, this could damage it!

### Running the code

Under 'Tools' in the Arduino IDE
 - Choose 'Board'
    - Choose 'Generic ESP8266 Module'
 - Choose 'Upload speed'
    - Choose '115200'
 - Choose 'Port'
    - Choose the port the ESP8266 module is connected to the computer
    - If you are uncertain which port the module is connected to, unplug it and see which port dissapear, reconnect the module and choose the port that shows up. 
    
Connect the ESP8266 module to upload code, remember to connect GPIO0 to GND before the upload. When the upload has started this can be removed. 

After an upload the module has to be restarted one time before it works normally. This is done by simple pushing the button. 

Now you can remove all wires for uploading code, follow shemantics by ESP8266_After_Upload. The module is now ready to be used!

### How it works

 - The ESP8266 module will set up an soft access point if it cant connect to a network. You will then be able to see a network named 'KolonialKlikk'. 
 - When you connect to this network the module will redirect all network requests to its own IP address. If you enter an URL address with HTTPS security this will not work. 
 - The site will list up all available networks and you will have to input a password (if any), and click 'Sett opp'. 
 - The module will now restart and try to connect to the selected network. If it doesn't work it will start the soft access point again, and follow the same process. If it connected successfully it will execute a SQL query to a database to notify the setup is complete. 
 - The module will now go to deepsleep for an hour before it wakes up and sends an SQL query to notify it is still working, before it goes back to sleep. 
 - When the button is pushed the power is cut off and when the button is released the power comes back on, forcing the module to restart. 


