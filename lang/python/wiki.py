# -*- coding: utf-8 -*- 

import wikipedia
import pyttsx
f = open(r"../data.txt",'w')
query  = raw_input("Enter the string to fetch details\n")
stri = wikipedia.page(query)
print stri.title
print stri.content.encode('utf-8')
speech = pyttsx.init('sapi5')
speech.setProperty('rate',150)
string = stri.title.encode('utf-8')
speech.say(string)
speech.runAndWait()