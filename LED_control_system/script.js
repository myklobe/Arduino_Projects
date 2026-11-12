let port;
let writer;

const connectBtn = document.getElementById('connectBtn');
const controls = document.getElementById('controls');
const statusText = document.getElementById('status');

connectBtn.addEventListener('click', async () => {
    try {
        // Request the port from the user
        port = await navigator.serial.requestPort();

        // Open the port at 9600 baud
        await port.open({ baudRate: 9600 });

        writer = port.writable.getWriter();

        statusText.innerText = "Status: Connected";
        statusText.style.color = "green";
        connectBtn.style.display = "none";
        controls.style.display = "flex"; // so the tiles stay horizontal

    } catch (error) {
        console.error(error);
        statusText.innerText = "Error: " + error.message;
        statusText.style.color = "red";
    }
});

async function sendCommand(command) {
    if (writer) {
        const data = new TextEncoder().encode(command + '\n');
        await writer.write(data);
        console.log("Sent: " + command);
    }
}