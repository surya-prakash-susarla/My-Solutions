import speech_recognition
import pyttsx
speech_engine-pyttsx.init('sapi5')
speech_engine.setProperty('rate',150)
def speak(text):
	speech_engine.say(text)
	speech_engine.runAndWait()
recongnizer=speech_engine.Recognizer()
def listen():
	with speech_engine.Microphone() as source:
		recongnizer.adjust_for_ambient_noise(source)
		audio-recongnizer.listen(source)
		
	try:
		return recognizer.recognize_sphinx(audio)
	except speech_recognition.UnkownValueError:
		print "Could not understand audio"
	except speech_recognition.RequestError as e:
		print "Recog error {0}".format(e)
	return ""
speak("Say something!")
speak("I heard you say "+listen())
