# import openpyxl
import paho.mqtt.client as mqtt
# import openpyxl as xl
import time


def remove(string):
    return string.replace(":", "-")


now_time = time.asctime(time.localtime(time.time()))
filenm = remove(now_time)+" tempvstime"+".txt"
f = open(filenm, 'a')
# now_time = time.asctime( time.localtime(time.time()) )
# filenm=now_time+" tempvstime"+"xlsx"
# wb=openpyxl.Workbook()
# Sheet_name=wb.sheetnames
# wb.save(filename=filenm)


def onConnect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to broker")
    elif rc != 0:
        print("Bad connection return code =", rc)


def onSubscribe(client, userdata, mid, granted_qos):
    print("qos =", granted_qos)


def onMessage(client, userdata, message):
    print("messages", str(message.payload.decode("utf-8")))
    data = str(message.payload.decode("utf-8"))
    f.write(data+"\n")


broker = "192.168.0.105"
client = mqtt.Client()
client.on_connect = onConnect
client.on_message = onMessage
client.on_subscribe = onSubscribe
client.connect(broker)
client.subscribe("thermocouple1/temp;time", 0)

client.loop_forever()
