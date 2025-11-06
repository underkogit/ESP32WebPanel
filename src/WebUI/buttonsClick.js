function btnClick( va , hesh ) {
    fetch('/btnClick?hesh=' + hesh + '&id='+ va )
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => console.log('Toggle response:', data))
        .catch(error => console.error('Fetch error:', error));
}
