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
    target = result.stdout.split("__mips__")

    try:
        icg_i = result.stdout.index("__icg__")
        mips_i = result.stdout.index("__mips__")
        icg = result.stdout[icg_i + 8 : mips_i]
        target = result.stdout[mips_i + 9 :]
    except:
        icg = "error"
        target = "error"

    data = {
        "message": "Code checked.",
        "data": {
            "lex": result.stderr,
            "sem": result.stdout,
            "icg": icg,
            "target": target,
        }
    }

    return data