from flask import Flask, request
from flask_cors import CORS
import subprocess

app = Flask(__name__)
CORS(app)

@app.route("/", methods=['POST'])
def api():

    data = request.get_json()['data']

    command = ["./src/main", data]
    result = subprocess.run(command, capture_output=True, encoding='utf-8')

    return {
        "message": "Code checked.",
        "data": {
            "lex": result.stderr,
            "sem": result.stdout,
        }
    }