#This is a server that processes the user request for a bus 
#imporitng the necessary modules
from flask import Flask, request
from datetime import datetime

#Creating a Flask application instance 
#__name__ tells Flask where this file is located 
app = Flask(__name__)

# Define an API endpoint (route)
# When someone sends a POST request to /button-press,
# this function will execute
@app.route('/button-press', methods=['POST'])
def button_press():
    # Extract stop_id from the JSON body of the request
    # Example JSON sent: {"stop_id": 23}
    stop_id = request.json.get("stop_id")

     # Capture the exact time the request was received
    timestamp = datetime.now()

     # Print a message to the server console
    # This simulates logging the bus stop request
    print(f"User pressed the button at Stop {stop_id} at {timestamp}")

    # Send a JSON response back to the client
    # 200 means success
    return {"status": "received"}, 200

# Start the server
# This runs the app on your local machine at port 5000
if __name__ == '__main__':
    app.run(port=5000)

