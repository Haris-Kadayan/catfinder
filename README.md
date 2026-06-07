catfinder
-
A cat-themed PCB fidget toy with four Cherry MX switches and four LED lights powered by a Seeed Studio XIAO RP2040. It has a Simon Says and a button lights up LED mode. Created for the Hack Club Stasis program.

3D Render
-
This is the 3D render in KiCad with all of the components:

<img width="1439" height="930" alt="catfinder front" src="https://github.com/user-attachments/assets/aac1dfdc-fa4f-4fae-ad12-2b8631dbfa4d" />

<img width="1439" height="930" alt="catfinder side" src="https://github.com/user-attachments/assets/250fc5dc-b154-4256-b521-3cfdbd96df6c" />

I spent a while with the silkscreen :)

<img width="1439" height="930" alt="catfinder back" src="https://github.com/user-attachments/assets/72f959a8-6705-4d9d-9769-a7b79e95eedd" />

Schematic
-
This is the schematic, which shows all of the connections. This took the least amount of time to make, and to improve organization I used labels:

<img width="1152" height="546" alt="Screenshot 2026-05-30 205329" src="https://github.com/user-attachments/assets/7626a709-02da-4389-b7ab-cd1ce6f26ce1" />

PCB
-
This is the PCB, this took the most amount of time, the wiring was very dense due to the size of the board. Speaking of the size of the board, it was just under 100mm to save on cost. Because the switches were arragned side by side it was hard to fit everything in that size. It looks messy because of the dual-sided silkscreen:

<img width="1008" height="436" alt="Screenshot 2026-05-30 205258" src="https://github.com/user-attachments/assets/2ec23065-bded-42a0-a923-f9125ac5cbc8" />

Code
-
This is the code to the catfinder, this took the second most amount of time. it is programmed in C++ and it has a Simon Says and button lights up LED mode, which is switched by holding all buttons for 5 seconds. I had to figure out how to detect the presses and trigger the LEDs and switches modes. It was kind of hard since im a noob at C++:

<img width="1442" height="929" alt="image" src="https://github.com/user-attachments/assets/2b4dc97b-7f09-40e0-b12f-995780ec87f7" />

