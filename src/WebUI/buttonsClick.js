let _count = 0;

function settext(number) {
   document.getElementById("hidtext").innerText = number;
}

function btnClick(va, hesh) {
   fetch("/btnClick?hesh=" + hesh + "&id=" + va)
      .then((response) => {
         if (!response.ok) {
            throw new Error("Network response was not ok");
         }
         _count++;

         settext(_count);

         return response.json();
      })
      .then((data) => {
         console.log("Toggle response:", data);
      })
      .catch((error) => console.error("Fetch error:", error));
}
