import board
import busio
from adafruit_pca9685 import PCA9685
from flask import Flask, render_template_string, request, jsonify
from typing import Final

app = Flask(__name__)

# --- Configuration ---
PWM_FREQ: Final[int] = 50
# PCA9685 uses 12-bit resolution (0 to 4095)
# Standard servos usually operate between 2.5% and 12.5% duty cycle
MIN_DUTY_PCT: Final[float] = 2.5
MAX_DUTY_PCT: Final[float] = 12.5

# --- Hardware Initialization ---
i2c = busio.I2C(board.SCL, board.SDA)
pca = PCA9685(i2c)
pca.frequency = PWM_FREQ

def calculate_duty(degrees: float) -> int:
    """Converts degrees (0-180) to PCA9685 duty cycle."""
    # Clamp degrees between 0 and 180
    degrees = max(0, min(180, degrees))
    # Linear interpolation: 0 degrees -> 2.5%, 180 degrees -> 12.5%
    percentage = MIN_DUTY_PCT + (degrees / 180.0) * (MAX_DUTY_PCT - MIN_DUTY_PCT)
    return int((percentage / 100.0) * 4096)

@app.route('/')
def index():
    return render_template_string(HTML_PAGE)

@app.route('/move', methods=['POST'])
def move_servo():
    data = request.json
    servo_id = data.get('servo_id')
    degrees = data.get('degrees')

    if servo_id is not None and degrees is not None:
        duty = calculate_duty(degrees)
        pca.pwm(servo_id, duty)
        return jsonify({"status": "success", "duty": duty})

    return jsonify({"status": "error", "message": "Invalid data"}), 400

if __name__ == "__main__":
    # Run on Raspberry Pi's local IP or localhost
    # host='0.0.0.0' allows access from other devices on your WiFi
    app.run(host='0.0.0.0', port=5000)
