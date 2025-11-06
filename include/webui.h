
#ifndef WEBUI_H
#define WEBUI_H
const char* htmlContent = R"rawliteral(
<!DOCTYPE html><title>123</title><h1>крипт для ожидания!</h1><button onclick='btnClick(1,"12mmm")'>Toggle LED</button> <button onclick='btnClick(2,"12mmm")'>Toggle LED</button> <button onclick='btnClick(3,"12mmm")'>Toggle LED</button> <button onclick='btnClick(4,"12mmm")'>Toggle LED</button> <button onclick='btnClick(5,"12mmm")'>Toggle LED</button> <button onclick='btnClick(6,"12mmm")'>Toggle LED</button> <h1 id=hidtext>0</h1><style>button{background-color:#4caf50;color:#fff;border:0;padding:15px 32px;text-align:center;text-decoration:none;display:inline-block;font-size:16px;margin:4px 2px;cursor:pointer;border-radius:5px;transition:background-color .3s ease}button:hover{background-color:#45a049}</style><script>function settext(n){document.getElementById("hidtext").innerText=n}function btnClick(n,t){fetch("/btnClick?hesh="+t+"&id="+n).then(n=>{if(!n.ok)throw new Error("Network response was not ok");return _count++,settext(_count),n.json()}).then(n=>{console.log("Toggle response:",n)}).catch(n=>console.error("Fetch error:",n))}let _count=0</script>
)rawliteral";
#endif
