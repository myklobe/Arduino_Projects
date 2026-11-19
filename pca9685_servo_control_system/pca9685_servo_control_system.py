import time
import board
import busio
from adafruit_pca9685 import PCA9685
from typing import Final

# Constants for configuration

# PCA9685 Channel configuration (0-15)
SERVO_1_CH: Final[int] = 0
SERVO_2_CH: Final[int] = 1

PWM_FREQ: Final[int] = 50

# PCA9685 uses 12-bit resolution (0 to 4095)
# Calculation: (Percentage / 100) * 4096
DUTY_0: Final[int] = int((2.5 / 100) * 4096)        # 0 degrees
DUTY_45: Final[int] = int((5.0 / 100) * 4096)       # 45 degrees
DUTY_NEUTRAL: Final[int] = int((7.5 / 100) * 4096)  # 90 degrees (Neutral)
DUTY_135: Final[int] = int((10.0 / 100) * 4096)     # 135 degrees
DUTY_180: Final[int] = int((12.5 / 100) * 4096)     # 180 degrees

def main() -> None:
    # Initialize I2C bus
    i2c = busio.I2C(board.SCL, board.SDA)
    # Initialize PCA9685
    pca = PCA9685(i2c)

    # Set the frequency for all channels
    pca.frequency = PWM_FREQ

    print(f"Starting Dual Servo Control. Press CTRL+C to stop.")

    try:
        while True:
            # Move both to 0 degrees
            pca.pwm(SERVO_1_CH, DUTY_0)
            pca.pwm(SERVO_2_CH, DUTY_0)
            print("Both: 0 degrees")
            time.sleep(2)

            # Move both to 45 degrees
            pca.pwm(SERVO_1_CH, DUTY_45)
            pca.pwm(SERVO_2_CH, DUTY_45)
            print("Both: 45 degrees")
            time.sleep(2)

            # Move both to Neutral (90 degrees)
            pca.pwm(SERVO_1_CH, DUTY_NEUTRAL)
            pca.pwm(SERVO_2_CH, DUTY_NEUTRAL)
            print("Both: Neutral")
            time.sleep(2)

            # Move both to 135 degree
            pca.pwm(SERVO_1_CH, DUTY_135)
            pca.pwm(SERVO_2_CH, DUTY_135)
            print("Both: 135 degrees")
            time.sleep(2)

            # Move both to 180 degrees
            pca.pwm(SERVO_1_CH, DUTY_180)
            pca.pwm(SERVO_2_CH, DUTY_180)
            print("Both: 180 degrees")
            time.sleep(2)

    except KeyboardInterrupt:
        print("\nStopping program...")
    finally:
        # PCA9685 is an I2C device; it stays in its last state
        # until power is removed, so explicit cleanup is usually unnecessary.
        print("Program exited.")

if __name__ == "__main__":
    main()
