import streamlit as st
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import numpy as np

# Define sample phrases for each intent
intent_examples = {
    "greeting": ["hello", "hi", "hey", "good morning"],
    "menu": ["what's on the menu", "show me the drinks", "what do you serve"],
    "order": ["i want to order", "can i get a coffee", "i'd like to have a tea"],
    "hours": ["when do you open", "what are your hours", "closing time"],
    "goodbye": ["bye", "goodbye", "see you later"],
    "thanks": ["thank you", "thanks a lot", "thanks"],
    "reservation": ["book a table", "i need a reservation", "reserve for two"],
    "location": ["where are you located", "what's your address", "location of the cafe"],
    "wifi": ["do you have wifi", "internet available", "wifi password"],
    "delivery": ["do you deliver", "home delivery", "can i order from home"]
}

# Predefined responses
intent_responses = {
    "greeting": "Welcome to Brew Café! What can I get for you today?",
    "menu": "Here's our menu:\n☕ Coffee\n🍵 Tea\n🥐 Croissant\n🍰 Cake",
    "order": "Sure! What would you like to order?",
    "hours": "We're open from 8 AM to 8 PM every day!",
    "goodbye": "Thanks for visiting Brew Café. Have a great day!",
    "thanks": "You're welcome! 😊",
    "reservation": "Sure! We can reserve a table for you. For how many people?",
    "location": "We're located at 123 Coffee Street, Brewtown ☕📍",
    "wifi": "Yes! Free Wi-Fi is available. The password is `brewcoffee123`.",
    "delivery": "Yes, we offer home delivery within 5 km. 🍽️"
}

# Combine all examples into a single list
all_examples = []
intent_tags = []

for intent, examples in intent_examples.items():
    all_examples.extend(examples)
    intent_tags.extend([intent] * len(examples))

# Fit the vectorizer
vectorizer = TfidfVectorizer()
example_vectors = vectorizer.fit_transform(all_examples)

# Streamlit UI
st.title("☕ Brew Café Chatbot")

user_input = st.text_input("Ask something:")

if user_input:
    input_vector = vectorizer.transform([user_input])
    similarity = cosine_similarity(input_vector, example_vectors)
    
    best_match_index = np.argmax(similarity)
    best_match_intent = intent_tags[best_match_index]
    best_score = similarity[0][best_match_index]

    # Confidence threshold (optional)
    if best_score < 0.3:
        response = "I'm sorry, I didn't understand that. Could you rephrase?"
    else:
        response = intent_responses[best_match_intent]

    st.markdown(f"**🤖 Bot:** {response}")
    
