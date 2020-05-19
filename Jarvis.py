import pyttsx3 #pip install pyttsx3
import speech_recognition as sr #pip install speechRecognition
import datetime
import wikipedia #pip install wikipedia
import webbrowser
import os
import smtplib

print("Initializing Kingsley")

MASTER = "Sir"

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)

#speak function will pronounce the string which is passed into it
def speak(text):
    engine.say(text)
    engine.runAndWait()

#will greet you as per the current time
def wishMe():
    hour = int(datetime.datetime.now().hour)
    #print(hour)

    if hour >= 0 and hour < 12:
        speak("Good Morning" + MASTER)

    elif hour >= 12 and hour <= 18:
        speak("Good Afternoon" + MASTER)

    else:
        speak("Good Evening" + MASTER)

    speak(" How may I help you today" + MASTER + "?")
#this function will take command from the microphone
def takeCommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        audio = r.listen(source)

    try :
        print("Recognizing...")
        query = r.recognize_google(audio, language = 'en-us')
        print(f"user said: {query}\n")

    except Exception as e:
        print("Say that again please")
        query = None

    return query


#Main program starts here
def main():
    num = 0
    speak("Initializing... Kingsley is ready...")
    wishMe()
    query = takeCommand()

    #logic for executing basic tasks based on query
    while query != 'exit':
        if 'wikipedia' in query.lower():
            speak('searching wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences = 2)
            print(results)
            speak(results)
            num = 1
            #main()

        elif 'open youtube' in query.lower():
            speak('What would you like to search for on youtube?')
            youtube = takeCommand()
            speak('searching youtube for ' + youtube)
            url = "https://www.youtube.com/results?search_query=" + youtube
            chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'
            webbrowser.get(chrome_path).open(url)
            num = 1
            #main()

        elif 'google' in query.lower():
            speak('What would you like to search?')
            google = takeCommand()
            speak('searching google...')
            url = "https://google.com/search?q=" + google
            chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'
            webbrowser.get(chrome_path).open(url)
            num = 1
            #main()

        elif 'stackoverflow' in query.lower():
            url = "stackoverflow.com"
            chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'
            webbrowser.get(chrome_path).open(url)
            num = 1
            #main()

        elif 'open gmail' in query.lower():
            url = "gmail.com"
            chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'
            webbrowser.get(chrome_path).open(url)
            num = 1
            #main()

        elif 'open linkedin' in query.lower():
            url = "https://www.linkedin.com/feed/"
            chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'
            webbrowser.get(chrome_path).open(url)
            num = 1
            #main()

        elif 'the time' in query.lower():
            strTime = datetime.datetime.now().strftime("%H:%M")
            speak(f"{MASTER} the time is {strTime}")
            num = 1
            #main()

        elif 'open' and 'code' in query.lower():
            codePath = "C:\\Users\\brijs\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
            os.startfile(codePath)
            num = 1
            #main()

        elif 'open' and 'spotify' in query.lower():
            codePath = "C:\\Users\\brijs\\AppData\\Roaming\\Spotify\\Spotify.exe"
            os.startfile(codePath)
            num = 1
            #main()

        elif 'open' and 'discord' in query.lower():
            codePath = "C:\\Users\\brijs\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Discord Inc\\Discord.lnk"
            os.startfile(codePath)
            num = 1
            #main()

        elif 'microsoft word' or 'word' in query.lower():
            #codePath = "C:\\Users\\brijs\\OneDrive\\Desktop\\Word.lnk"
            codePath = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Word.lnk"
            os.startfile(codePath)
            num = 1
            #main()

        elif 'microsoft excel' or 'excel' in query.lower():
            #codePath = "C:\\Users\\brijs\\OneDrive\\Desktop\\Word.lnk"
            codePath = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Excel.lnk"
            os.startfile(codePath)
            num = 1
            #main()

        elif 'microsoft outlook' or 'outlook' in query.lower():
            #codePath = "C:\\Users\\brijs\\OneDrive\\Desktop\\Word.lnk"
            codePath = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Outlook.lnk"
            os.startfile(codePath)
            num = 1
            #main()
        speak('What else can I do for you?' + MASTER)
        query = takeCommand()
        if 'exit' in query.lower():
            speak("Okay, goodbye! I shall see you tomorrow" + MASTER)
            exit()

main()

