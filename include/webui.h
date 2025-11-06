
#ifndef WEBUI_H
#define WEBUI_H
const char* htmlContent = R"rawliteral(
<!doctype html><html><head><title>123</title></head><body><h1>крипт для ожидания!</h1><button onclick="btnClick(1, '12mmm')">Toggle LED</button> <button onclick="btnClick(2, '12mmm')">Toggle LED</button> <button onclick="btnClick(3, '12mmm')">Toggle LED</button> <button onclick="btnClick(4, '12mmm')">Toggle LED</button> <button onclick="btnClick(5, '12mmm')">Toggle LED</button> <button onclick="btnClick(6, '12mmm')">Toggle LED</button><script>function btnClick(o,e){fetch("/btnClick?hesh="+e+"&id="+o).then(o=>{if(!o.ok)throw new Error("Network response was not ok");return o.json()}).then(o=>console.log("Toggle response:",o)).catch(o=>console.error("Fetch error:",o))}</script></body></html>
)rawliteral";
#endif
