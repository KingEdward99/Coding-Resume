#This program is an implementation of a chatbot  

import os
import openai


openai.Model.list()

def chat_with_gpt(prompt): 
    response = openai.ChatCompletion.create(
        model = "gpt-3.0-turbo",
        message = [{"role": "user", "content": prompt}], 
    )

    return response.choices[0].message.content.strip()

if __name__ == "__main__":
    while True:
        user_input = input("You: ")
        if user_input.lower() in ["quit", "exit", "goodbye"]:
            break
       
        response = chat_with_gpt(user_input)
        print("Chatbot:", response)
        