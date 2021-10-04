<template>
  <div class="container">
    <div class="top-editor">
      <p class="top-bar-title">Decaf Editor</p>
      <div class="top-bar-button yellow" @click="showModal = !showModal"></div>
      <div
        class="top-bar-button red"
        style="margin-right: 16px"
        @click="clearCode"
      ></div>
    </div>
    <div class="tab-bar">
      <div
        class="tab-item"
        v-for="t in tabs"
        :key="t.id"
        @click="changeTab(t.id)"
      >
        {{ t.title }}
      </div>
    </div>
    <prism-editor
      v-if="activeTab == 0"
      class="my-editor middle-editor"
      style="height: 50vh"
      v-model="code"
      :highlight="highlighter"
      line-numbers
      :readonly="activeTab != 0"
    ></prism-editor>
    <prism-editor
      v-if="activeTab == 1"
      class="my-editor middle-editor"
      style="height: 50vh"
      v-model="intermmediateCode"
      :highlight="highlighter"
      line-numbers
      :readonly="activeTab != 0"
    ></prism-editor>
    <prism-editor
      readonly
      class="my-editor bottom-editor"
      style="height: 15vh"
      v-model="filteredOutput"
      :highlight="analysisHighligther"
      line-numbers
    ></prism-editor>

    <!-- buttons -->
    <button class="kc_fab_main_btn" @click="postData">compile</button>
    <button class="choose-file-button" @click="triggerInput">open file</button>
    <input ref="fileInput" hidden @change="handleFile" type="file" accept="*" />

    <!-- notification -->
    <div
      class="notification"
      v-bind:class="{
        'notification-active': showNotification,
        green: notificationType == 'success',
        'red-2': notificationType == 'danger',
      }"
    >
      <div>
        <img
          class="icon-done"
          src="@/assets/img/icon_done.svg"
          alt=""
          v-if="notificationType == 'success'"
        />
        <img
          class="icon-done"
          src="@/assets/img/icon_close.svg"
          alt=""
          v-else
        />
      </div>
      <div>{{ notificationText }}</div>
    </div>

    <!-- about modal -->
    <div class="modal" v-if="showModal">
      <div style="display: flex; justify-content: flex-end; margin-right: 8px">
        <div class="top-bar-button red" @click="showModal = false"></div>
      </div>
      <div class="modal-content">
        <p>{</p>
        <p>&emsp;"author": "sebastian arriola",</p>
        <p>
          &emsp;"description": "Decaf language lexical and semantic analysis and
          soon a complete compiler.",
        </p>
        <p>&emsp;"tools": [</p>
        <p>&emsp;&emsp;"c++",</p>
        <p>&emsp;&emsp;"antlr4"</p>
        <p>&emsp;]</p>
        <p>}</p>
      </div>
    </div>
  </div>
</template>

<style lang="scss">
$green: #80e0a7;
$red: #ff5733;
$red-2: #f07167;
$yellow: #ffb703;
$borderRadius: 16px;
$borderWidth: 2px;
$blackest: #1d1d1d;
$black0: #292929;
$black1: #1f1f1f;
$black2: #292929;
$black3: #474747;
$black4: #5c5c5c;

.kc_fab_main_btn {
  font-family: "Roboto Mono", monospace;
  padding: 8px 16px 8px 16px;
  position: fixed;
  bottom: 16px;
  right: 16px;
  background-color: $black0;
  border-radius: 16px;
  background: $black0;
  border: none;
  outline: none;
  color: $green;
  font-size: 36px;
  box-shadow: 0 3px 6px rgba(0, 0, 0, 0.16), 0 3px 6px rgba(0, 0, 0, 0.23);
  transition: 0.3s;
  -webkit-tap-highlight-color: rgba(0, 0, 0, 0);

  &:hover {
    transform: translateY(-0.25em);
  }
}

.choose-file-button {
  font-family: "Roboto Mono", monospace;
  padding: 8px 16px 8px 16px;
  position: fixed;
  bottom: 16px;
  left: 16px;
  background-color: $black0;
  border-radius: 16px;
  background: $black0;
  border: none;
  outline: none;
  color: $green;
  font-size: 36px;
  box-shadow: 0 3px 6px rgba(0, 0, 0, 0.16), 0 3px 6px rgba(0, 0, 0, 0.23);
  transition: 0.3s;
  -webkit-tap-highlight-color: rgba(0, 0, 0, 0);

  &:hover {
    transform: translateY(-0.25em);
  }
}

.container {
  display: flex;
  flex-flow: column;
  justify-content: center;
  align-items: center;
  height: 100vh;
  background-color: $blackest;
}

/* required class */
.my-editor {
  margin: 0;
  padding-top: 16px;
  /* we dont use `language-` classes anymore so thats why we need to add background and text color manually */
  background: $black0;
  color: #ccc;

  /* you must provide font-family font-size line-height. Example: */
  font-family: Fira code, Fira Mono, Consolas, Menlo, Courier, monospace;
  font-size: 14px;
  line-height: 1.5;

  width: 75vw;
}

/* optional class for removing the outline */
.prism-editor__textarea:focus {
  outline: none;
}

.middle-editor {
  border-left: $borderWidth solid $green;
  border-right: $borderWidth solid $green;
}

.bottom-editor {
  border-top: $borderWidth solid $green;
  border-radius: 0 0 $borderRadius $borderRadius;
  border-bottom: $borderWidth solid $green;
  border-left: $borderWidth solid $green;
  border-right: $borderWidth solid $green;
}

.top-editor {
  width: 75%;
  background-color: $black3;
  height: 32px;
  border-top: $borderWidth solid $green;
  border-left: $borderWidth solid $green;
  border-right: $borderWidth solid $green;
  border-radius: $borderRadius $borderRadius 0 0;
  display: flex;
  align-items: center;
}

.tab-bar {
  width: 75%;
  height: 40px;
  background-color: $black3;
  border-left: $borderWidth solid $green;
  border-right: $borderWidth solid $green;
  display: flex;
  justify-content: center;
  align-items: center;
}

.tab-item {
  flex-grow: 1;
  height: 100%;
  cursor: pointer;
  color: $green;
  display: flex;
  justify-content: center;
  align-items: center;
  &:hover {
    background-color: $black0;
  }
}

.top-bar-title {
  flex-grow: 1;
  margin-left: 16px;
  color: $green;
}

.top-bar-button {
  width: 16px;
  height: 16px;
  border-radius: 100%;
  margin: 8px;
  cursor: pointer;
  &:hover {
    transform: scale(1.25);
  }
}

.green {
  background-color: $green;
}

.red {
  background-color: $red;
}

.red-2 {
  background-color: $red-2;
}

.yellow {
  background-color: $yellow;
}

.notification {
  position: fixed;
  top: 32px;
  right: 16px;
  width: 300px;
  height: 75px;
  border-radius: $borderRadius;
  color: black;
  display: flex;
  justify-content: space-around;
  align-items: center;
  padding: 8px;
  transform: translateX(332px);
  transition: transform 1s;
}

.notification-active {
  transform: translateX(0px);
}

.icon-done {
  height: 32px;
  width: 32px;
  color: black;
}

.modal {
  position: fixed;
  top: 50%;
  left: 50%;
  transform: translate(-50%, -50%);
  width: 600px;
  height: 400px;
  background-color: $black3;
  border: $borderWidth solid $green;
  border-radius: $borderRadius;
}

.modal-content {
  margin: 16px;
  color: $green;
}

@keyframes notify-in {
  100% {
    transform: translateX(-300px);
  }
}

@keyframes notify-out {
  0% {
    transform: translateX(-300px);
  }
}
</style> 

<script>
import { PrismEditor } from "vue-prism-editor";
import "vue-prism-editor/dist/prismeditor.min.css";

import { highlight, languages } from "prismjs/components/prism-core";
import "prismjs/components/prism-clike";
import "prismjs/components/prism-javascript";
import "prismjs/themes/prism-funky.css";

export default {
  components: {
    PrismEditor,
  },
  data() {
    return {
      code: "class Program \n{\n\tint a;\n\n\tvoid main()\n\t{\n\t\ta = 1;\n\t}\n}",
      intermmediateCode: "",
      output: "",
      errorLines: [],
      red: "#FF5733",
      green: "#33FF57",
      showModal: false,
      showNotification: false,
      successImg: "@/assets/img/icon_done.svg",
      dangerImg: "@/assets/img/icon_close.svg",
      notificationImg: "",
      // apiUrl: "https://48f7-181-209-150-146.ngrok.io",
      apiUrl: "http://127.0.0.1:8081",
      activeTab: 0,
      tabs: [
        { id: 0, title: "Source Program" },
        { id: 1, title: "Intermmediate Code" },
        { id: 2, title: "Assembly (MIPS)" },
      ],
    };
  },
  mounted() {
    this.topEditorCode = this.code;
  },
  methods: {
    highlighter(code) {
      const prism = highlight(code, languages.js);

      const errorCss = `style="text-decoration: ${this.red} wavy underline 1.5px;"`;
      const lines = prism.split("\n");
      this.errorLines.forEach((lineNum) => {
        const codeLine = `<span ${errorCss}">${lines[lineNum - 1]}</span>`;
        lines[lineNum - 1] = codeLine;
      });

      return lines.join("\n");
    },
    analysisHighligther(code) {
      this.errorLines = [];

      let formatted = "";
      const red = `color:${this.red}`;
      const green = `color:${this.green}`;

      code.split("\n").forEach((line) => {
        if (line.indexOf("[ERROR]") >= 0) {
          // [ERROR]
          const a = line.substring(0, 7);
          // (in line xx)
          const prIndex = line.indexOf(")") + 1;
          const b = line.substring(7, prIndex);
          // rest of line
          const c = line.substring(prIndex, line.length);

          // (in line x)
          let num = line[16];
          for (let i = 17; i < line.indexOf(")"); i++) {
            num += line[i];
          }
          this.errorLines.push(Number(num));

          formatted += `<span style="${red}">${a}</span><span style="${green}">${b}</span><span>${c}</span>\n`;
        }

        if (line && line.length) {
          const found = line.match(
            /(?<line>line (?<line1>[0-9])+:[0-9]+)(?<rest>.*)/
          );
          if (found) {
            let num = line[5];
            for (let i = 6; i < line.length; i++) {
              if (line[i] == ":") break;
              num += line[i];
            }
            this.errorLines.push(Number(num));
            formatted += `<span style="${red}">[ERROR]</span><span style="${green}">(in line ${found.groups.line1})</span> =>${found.groups.rest}\n`;
          }
        }
      });

      return formatted;
    },
    postData() {
      this.axios
        .post(this.apiUrl, {
          data: this.code,
        })
        .then(({ data }) => {
          this.showNotification = true;
          setTimeout(() => {
            this.showNotification = false;
          }, 3000);

          this.output = data.data.lex;
          this.output += data.data.sem;
          this.intermmediateCode = data.data.icg;
        });
    },
    clearCode() {
      this.code = "class Program \n{\n}";
      this.output = "";
    },
    triggerInput() {
      this.$refs.fileInput.click();
    },
    handleFile(event) {
      if (event.target.files && event.target.files.length) {
        const reader = new FileReader();
        reader.onload = function () {
          this.code = reader.result;
        }.bind(this);
        reader.readAsText(event.target.files[0]);
      }
    },
    changeTab(index) {
      this.activeTab = index;
    },
  },
  computed: {
    filteredOutput() {
      let filtered = "";
      this.output.split("\n").forEach((line) => {
        if (line.indexOf("[ERROR]") >= 0) {
          filtered += line + "\n";
        } else if (line.match(/line \d+:\d+/)) {
          filtered += line + "\n";
        }
      });
      return filtered;
    },
    notificationType() {
      return this.errorLines.length ? "danger" : "success";
    },
    notificationText() {
      return this.errorLines.length
        ? "Program has errors."
        : "Program is valid!";
    },
  },
};
</script>
