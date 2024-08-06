from flask import Flask, request, jsonify
from flask_cors import CORS
import os

CPM_PROJECT = False

app = Flask(__name__)
CORS(app, supports_credentials=True)

@app.route('/cf-parser/testcases/', methods=['POST'])
def handle_request():
    data = request.get_json()
    url = data["url"]
    testcases = data["testcases"]
    parts = url.split("/")
    if len(parts) < 6:
        return jsonify({"message": "Data received"}), 200
    if parts[3] == "contest":
        question = "C" + parts[-3] + parts[-1]
    else:
        question = "P" + parts[-2] + parts[-1]
    
    if CPM_PROJECT:
        for i in range(len(testcases)):
            with open(f"testcases/input_{question}_{i+1}.txt", "w") as f:
                f.write(testcases[i]['input'])
            with open(f"testcases/output_{question}_{i+1}.txt", "w") as f:
                f.write(testcases[i]['output'])
        os.system(f"cpm start {url}")

    print(data)
    return jsonify({"message": "Data received"}), 200

if __name__ == '__main__':
    if os.path.exists("testcases") and os.path.exists("lib"):
        CPM_PROJECT = True
    app.run(debug=True)

# // Question: https://codeforces.com/contest/1987/F1
# // int main() {
# hello world is working fine as I said