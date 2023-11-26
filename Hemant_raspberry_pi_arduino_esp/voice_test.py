import pyttsx3
en = pyttsx3.init()
en.setProperty('voice', 'en-us')
en.setProperty('pitch', 0.8)
en.setProperty('rate', 150) # speed of speech
voices = en.getProperty('voices')
print(voices)
# en.setProperty('voice', voices[0].id)
# en.setProperty('voice', voices[1].id)
for i in voices:
    en.setProperty('voice', i.id)
    en.say("hello my name is , what is your name")
    en.runAndWait()
# en.save_to_file('Hello, world!', 'output.mp3')
# en.runAndWait()

