import subprocess
import sys
def sendmessage(message):
    subprocess.Popen(['notify-send', message])
    return
   
sendmessage(sys.stdin.readline())
