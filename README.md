# Wireless-temperature-data-collection-and-storing-using-MQTT
You may refer to the video tutorials here - https://youtube.com/playlist?list=PLhrvBKyDzmRlxWfILF5Y58v7cU-1IMhBz

Mqtt setup
1. Install mosquitto https://mosquitto.org/download/
2. Install mqtt explorer  http://mqtt-explorer.com/
3. Change config file for mosquitto
4. Add rule in defender
5. Run Commands in command prompt
6. Create localhost using mqtt explorer

When in doubt visit the website https://tiagohorta1995.medium.com/mosquitto-mqtt-broker-and-esp8266-communcation-in-6-easy-steps-5ea0efae5a10 for the cmd commands

DONE :)

Arduino Setup(Arduino ide has to be installed)
1. Preference- http://arduino.esp8266.com/stable/package_esp8266com_index.json
2. Copy and paste libraries that can be found in this drive folder - https://drive.google.com/drive/folders/1x0LPMp53VNQvJMe4wP7EKm_GjjCyCwgh?usp=sharing
3. Board manager- esp and install 
4. Select board
5. Change WIFI credenditals and IP in the arduino code
6. Connect the esp using usb port and upload the sketch

The mqtt explorer is recieving the messages from esp8266. 
Setup done :)

Python setup (Python has to be installed)
1. python -m pip install paho-mqtt   -Run this command
2. open and run the python file in data folder
3. Find the text file that is storing the dATA (Same folder as the code folder)

Done :) 

Make sure to reset the esp once the work is finished. It is easy to reset the esp.
press and hold the reset button.
press and hold the program button.
release the reset button, the ESP will boot in program mode.
release the program button.

Finished!!!
