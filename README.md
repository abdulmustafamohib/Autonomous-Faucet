# Autonomous Faucet Robot 🚿🤖

A smart faucet automation system built with LEGO EV3 and programmed in ROBOTC (a C-like language for robotics). This system fully automates the handwashing process — detecting hands, adjusting water temperature, activating faucet motors, displaying real-time feedback, and even dispensing soap based on sensor input.

---

## 🎯 Features

- 🧼 **Touchless activation** via ultrasonic sensors
- 🌡️ **Dynamic water temperature control** using IR and distance sensors
- 🧠 **Autonomous soap dispensing**
- 📊 **Live display bars** for temperature and handwashing timer on EV3 screen
- 💾 **Save/load preferred temperature** to/from file using EV3 PC File IO
- ⛔ **Emergency stop** via EV3 touch sensor

---

## 🧱 File Structure

```bash
.
├── main.c                 # Main task loop and sensor polling
├── faucet.c              # Faucet handle motor control
├── soapDispenser.c       # Soap dispensing logic via encoders
├── temperature.c         # Hand distance → temperature logic
├── display.c             # EV3 screen UI (temperature + timer bars)
├── file.c                # Read/write preferred temp via PC File IO
├── PC_FileIO.c           # File I/O helpers (read/write to EV3 filesystem)
```

## 🛠 Hardware + Dependencies
- LEGO Mindstorms EV3 Brick

- ROBOTC IDE and firmware

- Ultrasonic sensors (S1, S2), IR sensor (S3), touch sensor (S4)

- Motors:

- motorA, motorD: faucet handle control

- motorB, motorC: soap plunger control

- PC File IO library (PC_FileIO.c) for reading/writing temperature preferences

## 🧠 Key Modules
turnOnFaucetHandles(int temperature)
- Activates hot/cold motors based on selected temperature
- Monitors hand presence and retracts motors once hands are removed or timeout reached

dispenseSoap()
- Automates soap dispensing motion via dual motor encoders
- Waits, lowers plunger, returns after dispense

displayTemperatureBar(int temperature) + displayTimerBar(float timePassed)
- Visual EV3 feedback: live bars drawn for heat and time

getWaterTemperature()
- Maps hand proximity → 0°C / 50°C / 100°C logic

savePreferredTemp() / getPreferredTemp()
- Stores or retrieves preferred handwashing temp from temp.txt

## 🧪 Example Scenario
- User puts hand near sensor (S1) → faucet turns on

- Water temperature adjusts based on last proximity reading (S2)

- Soap is dispensed if user waves hand near soap zone (S3)

- A timer bar shows handwashing time; faucet turns off after 2s of no detection

- User can save or load preferred temperature using brick buttons

## 💡 Design Notes
- Timer-based logic prevents water waste and enhances hygiene

- Modular structure separates control, display, and IO logic

- Safety failsafes via E-stop (S4) across all motor loops

- Supports temperature persistence across sessions
