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
    icg = result.stdout.split("__icg__")
    target = icg.stdout.split("__mips__")

    data = {
        "message": "Code checked.",
        "data": {
            "lex": result.stderr,
            "sem": result.stdout,
            "icg": icg[1] if len(icg) > 1 else "error",
            "target": target[1] if len(target) > 1 else "error"
        }
    }

    return data