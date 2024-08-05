from flask import Flask, request, jsonify
from flask_cors import CORS
app = Flask(__name__)
CORS(app, supports_credentials=True)

@app.route('/cf-parser/testcases/', methods=['OPTIONS'])
def handle_options():
    return jsonify({"message": "Options request received"}), 200

@app.route('/cf-parser/testcases/', methods=['POST'])
def handle_request():
    print(request.headers)
    print("Data has been received")
    data = request.get_json()
    print(data)
    return jsonify({"message": "Data received"}), 200

if __name__ == '__main__':
    app.run(debug=True)

# // Question: https://codeforces.com/contest/1987/F1
# // int main() {
# hello world is working fine as I said