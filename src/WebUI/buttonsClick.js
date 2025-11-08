 

function setText(number) {
   document.getElementById("hidtext").innerText = number;
}

function btnClick( buttonId ) {
   fetch("/btnClick?id=" + buttonId)
      .then((response) => {
         if (!response.ok) {
            throw new Error("Network response was not ok");
         }
         return response.json();
      })
      .then((data) => {
         console.log("Toggle response:", data);
      })
      .catch((error) => console.error("Fetch error:", error));
}
