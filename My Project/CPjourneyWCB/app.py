from flask import Flask, render_template, request, jsonify
import openai

app = Flask(__name__)
openai.api_key = 'e26d179188c7446ab97f320f84ea1163'

@app.route('/api/chat', methods=['POST'])
def chat():
    data = request.get_json()
    user_message = data.get('message')

    print('Received user message:', user_message)

    response = openai.Completion.create(
        engine="text-davinci-002",
        prompt=user_message,
        max_tokens=100
    )

    ai_message = response['choices'][0]['text'].strip()

    print('Sending AI response:', ai_message)

    return jsonify({'ai_message': ai_message})

if __name__ == '__main__':
    app.run(debug=True)
