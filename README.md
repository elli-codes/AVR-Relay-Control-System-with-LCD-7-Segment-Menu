AVR Relay Control System with LCD & 7-Segment Menu
This project implements a menu-driven relay controller using an ATmega32, a 16x2 LCD, a 7-segment display, push buttons, and up to 4 relays.

The system allows the user to:

Navigate through a menu of relays using push buttons.

Select and activate one of four relays.

Display active relay status on both LCD and 7-segment display.

Automatically return to the menu when toggled off.

🛠 Hardware Requirements

Microcontroller: ATmega32

LCD: 16x2 character LCD (alcd.h)

7-Segment Display: Common cathode/anode connected to PORTD

Relays (x4): Connected to PORTC.0 → Relay1, PORTC.1 → Relay2, PORTC.2 → Relay3, PORTC.3 → Relay4

Push Buttons:

PA0 → Next Menu / Navigation

PA1 → Enter / Select Relay

LED indicators (optional, same pins as relay outputs)

⚙️ Software Features
Main Menu (States)

The program runs as a state machine with the following states:

state1 → Menu option Relay 1 (default)

state2 → Menu option Relay 2

state3 → Menu option Relay 3

state4 → Menu option Relay 4

Each menu screen shows two relay options, with the currently selected one marked by <<.

Sub-States (Relay Control)

sub1 → Relay 1 is ON

sub2 → Relay 2 is ON

sub3 → Relay 3 is ON

sub4 → Relay 4 is ON

In these sub-states:

LCD shows which relay is ON.

7-segment shows the corresponding relay number (1, 2, 3, 4).

The relay output pin is set HIGH.

Pressing the Enter button (PA1) again turns the relay OFF and returns to the menu.
💻 Code Written using CodeVisionAVR.

📽️ Video YouTube video link: https://youtube.com/shorts/hD-_QTvzt8k?feature=share 
