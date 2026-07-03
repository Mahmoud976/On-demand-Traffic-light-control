# 🚦 On-Demand Traffic Light Control System

<p align="center">
  <img src="https://shields.io" alt="ATmega32">
  <img src="https://shields.io" alt="Embedded C">
  <img src="https://shields.io" alt="Architecture">
  <img src="https://shields.io" alt="License">
</p>

---

## 📌 Project Overview
An advanced embedded system firmware that controls an intelligent, pedestrian-responsive traffic light system. It manages state transitions dynamically based on user interaction (Push Button via External Interrupts) while adhering to strict safety protocols for both drivers and pedestrians.

---

## 🏗️ Architectural Structure (Static Design)
The software follows a robust **Layered Architecture** pattern to guarantee hardware independence, modularity, and compliance with SOLID principles.

```mermaid
graph TD
    subgraph Application_Layer [Application Layer]
        APP[app.c / app.h]
    end

    subgraph ECUAL_Layer [ECUAL - Hardware Abstraction]
        LED[led.c / led.h]
        BTN[button.c / button.h]
    end

    subgraph MCAL_Layer [MCAL - Processor Abstraction]
        DIO[dio.c / dio.h]
        TIMER[timer.c / timer.h]
        EXTI[ext_interrupt.c / ext_interrupt.h]
    end

    subgraph Utilities_Layer [Infrastructure]
        UTILS[types.h / registers.h / bit_math.h]
    end

    %% Dependencies Direction
    APP --> ECUAL_Layer
    ECUAL_Layer --> MCAL_Layer
    MCAL_Layer -.-> Utilities_Layer
    ECUAL_Layer -.-> Utilities_Layer
    APP -.-> Utilities_Layer
```

---

## ⚙️ Algorithms & System Flowcharts

### 1. Normal Mode Cycle
In default state, the system continuously transitions the cars' traffic lights sequentially every **5 seconds**.

```mermaid
graph LR
    G[🟢 Cars Green<br>Ped Red] -- 5s --> Y1[🟡 Cars Yellow Blinking<br>Ped Red]
    Y1 -- 5s --> R[🔴 Cars Red<br>Ped Green]
    R -- 5s --> Y2[🟡 Cars Yellow Blinking<br>Ped Red]
    Y2 -- 5s --> G
```

### 2. Pedestrian On-Demand Handling (Interrupt Service Routine)
When the pedestrian presses the crosswalk button (**INT0**), the system executes the following algorithm depending on the current state:

```mermaid
flowchart TD
    Start([Pedestrian Button Pressed - INT0]) --> CheckState{Which Light is Active?}
    
    %% Case 1: Cars Red
    CheckState -- Cars Red is ON? --> RedActive[Pedestrian crosses immediately]
    RedActive --> HoldRed[Keep Cars Red & Pedestrian Green ON for 5s]
    HoldRed --> EndRoutine
    
    %% Case 2: Cars Green or Yellow
    CheckState -- Cars Green or Yellow? --> GreenYellowActive[Pedestrian must wait]
    GreenYellowActive --> TurnPedRed[Turn Pedestrian Red ON]
    TurnPedRed --> BlinkBoth[Blink both Yellow LEDs for 5 seconds]
    BlinkBoth --> SwapLanes[Turn Cars Red ON & Pedestrian Green ON for 5s]
    SwapLanes --> EndRoutine
    
    %% Reset Sequence
    EndRoutine[Sequence Finishes] --> ResetYellow[Blink both Yellow LEDs for 5s to alert drivers]
    ResetYellow --> ReturnNormal[Turn Cars Green & Pedestrian Red ON]
    ReturnNormal --> Back([Return to Normal Mode Sequence])
```

---

## 🔌 Hardware Configurations & Mapping
* **MCU Platform:** ATmega32 8-bit Microcontroller
* **External Interrupt Pin:** `PORTD Pin 2 (INT0)` -> Connected to Pedestrian Button.
* **Cars' LEDs:** `PORTA` -> Pin 0 (Green), Pin 1 (Yellow), Pin 2 (Red).
* **Pedestrians' LEDs:** `PORTB` -> Pin 0 (Green), Pin 1 (Yellow), Pin 2 (Red).

---

## 🧪 Mitigation & Safety Features (User Stories)
* **Double Press:** Instantly ignores any secondary button trigger while a cross sequence is ongoing to prevent state corruption.
* **Long Press:** The system triggers exclusively on the falling/rising edge of a pulse, safely treating long presses as a single action.

---

## 🚀 Getting Started & Execution
1. Open the project toolchain inside **Microchip Studio**.
2. Build the project to get the `.hex` file.
3. Open the schematic located inside the `/proteus` folder using Labcenter Proteus.
4. Run the interactive simulation.

---

## 📜 License
Distributed under the **MIT License**. See `LICENSE` for more information. This project is completely free to use for educational and commercial purposes.
