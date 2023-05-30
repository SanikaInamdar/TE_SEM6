import random
import re

responses = {
    "greeting": ["Hello! Welcome to our mobile repairing shop. How can I assist you today?", "Hi there! How may I help you with your mobile?", "Welcome! What seems to be the problem with your phone?"],
    "farewell": ["Thank you for choosing our mobile repairing services. Have a great day!", "Your satisfaction is our top priority. Goodbye!", "If you have any more questions, feel free to ask. Take care and goodbye!"],
    "help": ["Sure, I'm here to help. What issues are you facing with your mobile?", "How can I assist you with your mobile repair? Please let me know.", "I'm here to provide the best possible solutions for your mobile problems. What do you need help with?"],
    "screen_cracked": ["A cracked screen / display is a common issue. We can replace the screen for you. Please bring your mobile to our shop, and our technicians will take care of it.", "Oh no! A cracked screen can be quite bothersome. Don't worry, we offer screen replacement services. Visit our shop, and we'll fix it for you."],
    "battery_problem": ["If you're experiencing battery issues, we can replace your mobile's battery. Bring it to our shop, and we'll ensure it gets fixed.", "Battery problems are quite common. We can replace your mobile's battery with a new one. Please visit our shop for assistance."],
    "software_issue": ["Software issues can often be resolved by resetting your mobile or updating its software. We can assist you with that. Please bring your phone to our shop, and our technicians will help you out.", "Software problems can be frustrating. We recommend trying a software reset or update. If the issue persists, our technicians can assist you further. Just drop by our shop."],
    "water_damage": ["Water damage can be critical for mobiles. We suggest immediately turning off your device and bringing it to our shop for professional repair. Do not attempt to power it on.", "Water damage requires immediate attention. Please switch off your mobile, remove any SIM cards or memory cards, and bring it to our shop. Our experts will assess the damage and offer a suitable solution."],
    "default": ["I apologize, but I couldn't understand your request.", "Apologies, I didn't quite get that. Could you please rephrase?", "I'm still learning. Can you provide more information?"]
}

def handle_inquiry(inquiry):
    inquiry= inquiry.lower()

    if(re.search(r"\b(?:hello|hi)\b", inquiry)):
        return random.choice(responses["greeting"])
    elif re.search(r"\b(?:help|support|resolve)\b", inquiry):
        return random.choice(responses["help"])
    elif re.search(r"\b(?:battery|charge)\b", inquiry):
        return random.choice(responses["battery_problem"])
    else:
        return random.choice(responses["default"])

print("Cutomer Interaction Support")
print("Type 'exit' to end the conversation.")
while True:
    res = input("Customer: ")
    if(res.lower()=="exit"):
        break
    
    bot = handle_inquiry(res)
    print("Chatbot:" + bot)
print("Thank You")
