import  serial
from twilio.rest import Client
arduino= serial.Serial('com12',9600)
while (True):
    print('a')
    if(arduino.inWaiting()>0):
        data=arduino.readLine()
        if(data=='doubleTap'):
           account_sid = "AC827c5466ca988990090d1a5b383ece75"
            auth_token = "25e816974d07ee2ff552ec10f703c277"

            client = Client(account_sid, auth_token)

            client.api.account.messages.create(
                to="+15106465571",
                from_="+14155349438",
                body="Emergency!! Your friend needs your HELP. HURRY!!")
