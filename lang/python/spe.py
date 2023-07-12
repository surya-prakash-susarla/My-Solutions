import pyttsx

spe_eng = pyttsx.init('sapi5')
spe_eng.setProperty('rate', 150)
spe_eng.say("This is a tester of the speaking ability")
spe_eng.runAndWait()