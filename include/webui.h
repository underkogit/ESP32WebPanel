
#ifndef WEBUI_H
#define WEBUI_H
const char* htmlContent = R"rawliteral(
<!DOCTYPE html><title>331223</title><h1>крипт для ожидания!</h1><button onclick='btnClick("btn1")'>Toggle LED</button> <button onclick='btnClick("btn2")'>Toggle LED</button> <button onclick='btnClick("btn3")'>Toggle LED</button> <button onclick='btnClick("btn4")'>Toggle LED</button> <button onclick='btnClick("btn5")'>Toggle LED</button> <h1 id=hidtext>0</h1><style>button{background-color:#4caf50;color:#fff;border:0;padding:15px 32px;text-align:center;text-decoration:none;display:inline-block;font-size:16px;margin:4px 2px;cursor:pointer;border-radius:5px;transition:background-color .3s ease}button:hover{background-color:#45a049}</style><script>function setText(n){document.getElementById("hidtext").innerText=n}function btnClick(n){fetch("/btnClick?id="+n).then(n=>{if(!n.ok)throw new Error("Network response was not ok");return n.json()}).then(n=>{console.log("Toggle response:",n)}).catch(n=>console.error("Fetch error:",n))}</script>
)rawliteral";
#endif
