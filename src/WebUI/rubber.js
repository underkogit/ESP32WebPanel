function toggle() {
    fetch('/toggle')
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => console.log('Toggle response:', data))
        .catch(error => console.error('Fetch error:', error));
}

// Функция для отправки запроса на '/start'
function start() {
    fetch('/start')
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => console.log('Start response:', data))
        .catch(error => console.error('Fetch error:', error));
}