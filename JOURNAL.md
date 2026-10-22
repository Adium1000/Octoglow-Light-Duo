---
title: "Octoglow Light Duo "
github: "https://github.com/Adium1000/Octoglow-Light-Duo"
description: "A light controller based on the ESP32 S3 that can control up to two LED strips separately and can also be controlled using a standard IR LED remote control."
created_at: "2026-10-12"
total_time: "14h 18m"
---

# October 13, 2026: The main idea of this project
<!-- fabricate:entry 387 -->

So maybe you’ve come across some cheap LED controllers that use MOSFETs, have a Bluetooth app full of ads, are unstable, and break at the slightest jolt The idea behind my project is to create a reliable version that can control two sets of LEDs, has a buzzer, an IR sensor, and dedicated software that syncs with music, notifications, and other telemetry data that a user can provide all without any ads or sketchy software, running securely on your local network.

After a few moments of research and a teardown of one of these LED controllers, the idea seems pretty simple: there’s a microcontroller, a crystal, a Bluetooth antenna, and three MOSFETs—probably to amplify the power supplied by the microcontroller for better performance—as well as a spot for the IR sensor, a resistor, and an SMD capacitor; it looks like the kind of circuit that tends to fail. 

![](https://fabricate.hackclub-assets.com/61dcdd4883a0d512028f25360a0fc3492c6123a7ef0b88f4f9a2b97098328cfe/image-png/image.png)

![](https://fabricate.hackclub-assets.com/8a6e51cd0b2b5678229cb87c10905dc84275cd975eb41ee58c1f6395a49b342e/image-png/image.png)

**Total time spent: 1h 18m**

# October 14, 2026: Designed the schematics prototipe
<!-- fabricate:entry 399 -->

Created the basic schematics; right i only have the main ESP32 C3 MCU, a buzzer, and connectors for LEDs. The idea is pretty simple: we’re using some MOSFETs to signal when our MCU should control the RGB of an LED strip. i am using 10k resistors so that when the board is in bootloader mode, we don’t get flickering or random glitches, and finally, 220 resistors to avoid damaging the GPIO.

I was thinking of using the buzzer to beep in case of network issues, notifications, and other things of interest to our controller

Here is how the schematis looks for now, I gotta clean it up to look better but for now ig it is fine 

![](https://fabricate.hackclub-assets.com/b9fe1280a4d90b57a799604d3e9e76023315fb741fe9bb81aa8e488e60245248/image-png/image.png)

**Total time spent: 1h 30m**

# October 14, 2026 (entry 2): Organizing Schematics
<!-- fabricate:entry 405 -->

I tried to organize my schematics a little bit, categorizing all the components so that everything would be clear to anyone during a simple inspection. I also added a few new elements, namely a jumper pad that allows us to switch where our LEDs get their power from. I also added some copper-plated mounting holes for M3 screws to make it easier to mount the board in future designs or in places where it needs to be securely fixed

![](https://fabricate.hackclub-assets.com/9afea80205b96fccbe75983f9ff502f567ae0701068c38f68873935e4fa56103/image-png/image.png)

I also provided a footprint for each component so it would be clear what we're using

![](https://fabricate.hackclub-assets.com/bd557c5bcbcbf65695057de1953e4a948ac940f1cad1b65cbf992e7a1dba347a/image-png/image.png)

So the schematics are pretty much done for now; I just need to design the PCB, route the traces, and create a BOM.

**Total time spent: 3h**

# October 14, 2026 (entry 3): Built the first prototype of the PCB
<!-- fabricate:entry 416 -->

I arranged all the components on the PCB in a way that makes it easier for the user to understand how the PCB works; everything is very well organized, making it easy to route the copper traces later on, since we’re using a lot of THT components

When laying out the board, I had trouble placing the buzzer and the capacitor because they ended up very close to other components, but after a few rotations and adjustments, I managed to arrange them so they look good

![](https://fabricate.hackclub-assets.com/176b7c1669bc18f7b7334c4ebf48c7dbfcee4e5b43f9510fb9ce59daa54092b2/image-png/image.png)

**Total time spent: 1h**

# October 16, 2026: Routed the PCB :)
<!-- fabricate:entry 494 -->

After a few moments, I tried routing my PCB; I tried using some wider traces where I have the 5V+ power supply for the LED strips and also for the RGB outputs, and I also added my logo (Octoglow) with text on the back, and also used some copper mounting holes for the pcb placement :3 i just hope that i did not messed up something xD

![](https://fabricate.hackclub-assets.com/37849ef19039ba208c96b8599d72745d770b0b89546bcae1e6c22ed16c2e1d59/image-png/Screenshot%202026-10-16%20000756.png)
![](https://fabricate.hackclub-assets.com/531a1d92c24a8d2790a7550f4871a8940da9be31dbd35b45491ab772ce9ef2eb/image-png/Screenshot%202026-10-16%20001313.png)

**Total time spent: 2h**

# October 17, 2026: Small Changes + BOM
<!-- fabricate:entry 568 -->

I made some minor changes to the schematic, specifically: I added a separator between each quadrant of each category and slightly enlarged the squares where each component is located. I also added the logo and the project name.

![](https://fabricate.hackclub-assets.com/67e9de1b05c928bd72392417f0fd4df6a2ebaf6109bb8dc77d77c98f78741d3c/image-png/SCM_main.png)

I also created a file listing all the costs associated with building my project (bom.csv), and I tried to optimize the manufacturing costs. Unfortunately, due to new European regulations, shipping isn’t as cheap as it used to be, and I’ll end up paying $17 to JLC PCB just for that.

Here is my bom table


| Component | Quantity | Unit Price (USD) | Total Price (USD) |
|:--|--:|--:|--:|
| [100 nF 50 V X7R capacitor, 0603 (C1; JLCPCB C14663)](https://jlcpcb.com/partdetail/C14663) | 5 | $0.010800 | $0.0540 |
| [AO3400A N-channel MOSFET, SOT-23 (Q1–Q6; JLCPCB C20917)](https://jlcpcb.com/partdetail/AO3400A/C20917) | 30 | $0.097100 | $2.9130 |
| [220 Ω ±1% resistor, 0603 (R1/R3/R5/R7/R9/R11; JLCPCB C22962)](https://jlcpcb.com/partdetail/0603WAF2200T5E/C22962) | 30 | $0.003300 | $0.0990 |
| [10 kΩ ±1% resistor, 0603 (R2/R4/R6/R8/R10/R12; JLCPCB C25804)](https://jlcpcb.com/partdetail/0603WAF1002T5E/C25804) | 30 | $0.002400 | $0.0720 |
| [1 kΩ ±1% resistor, 0603 (R13; JLCPCB C21190)](https://jlcpcb.com/partdetail/0603WAF1001T5E/C21190) | 5 | $0.003000 | $0.0150 |
| [KF301-2P 2-pin screw terminal block, 5 mm](https://sigmanortec.ro/Conector-PCB-2-pini-KF301-2P-5mm-p136284289) | 5 | $0.259330 | $1.2966 |
| [ESP32-C3 SuperMini development board](https://sigmanortec.ro/placa-dezvoltare-esp32-c3-supermini-33v-wifi-bluetooth) | 1 | $5.625132 | $5.6251 |
| [Passive 5 V buzzer](https://sigmanortec.ro/Buzzer-pasiv-5v-p172425809) | 1 | $0.305714 | $0.3057 |
| [PCB fabrication](https://jlcpcb.com/) | 1 | $14.067000 | $14.0670 |
| [Sigmanortec shipping (14.95 RON)](https://sigmanortec.ro/) | 1 | $3.152013 | $3.1520 |
| [JLCPCB shipping](https://jlcpcb.com/) | 1 | $16.110000 | $16.1100 |
| **GRAND TOTAL** | | | **$43.7095** |

**Total time spent: 1h**

# October 18, 2026: Finished Firmware prototipe + Readme
<!-- fabricate:entry 609 -->

I've finished writing the README, making it as clear as possible. I tried to include all the necessary information requested, and I also created the firmware, which is currently very simple and only tests the board's functionality


![](https://fabricate.hackclub-assets.com/dabbf37a5c0f302d9828b6c6e4fc1a63b5bd78c8c12247494a469f6134dd47ea/image-png/image.png)
 

![](https://fabricate.hackclub-assets.com/3c52d9131c3906a067c923ed375812f2c1d1ad94a03ac1dbc24c95f08f3bb32b/image-png/image.png)

**Total time spent: 2h 30m**

# October 22, 2026: Maked a Case
<!-- fabricate:entry 807 -->

Since my project didn't meet the TIER 4 requirements, I decided to design a case to make the project more interesting. 

![](https://fabricate.hackclub-assets.com/f72bef086f7fba80f45dc281cf13abe77b10ee6f28d3de663c54074eb565f4f7/image-png/Octoglow_assembly%20-%20Copy.png)


The case features a mounting system with nuts that are meant to be glued to the case, with the PCB and mounting screws placed over them, 

![](https://fabricate.hackclub-assets.com/f5ff000cb6c9356b01a2611d3ccf369bf109a4af0eb534031c975a39c825417b/image-png/image.png)

and the enclosure lid, which has the necessary openings for all the wires, features clips to facilitate maintenance or in case of unforeseen incidents. 

![](https://fabricate.hackclub-assets.com/7b41166f292a26b00959b77707ac2f245a946f689d617577790682a61562533b/image-png/image.png)


The enclosure also comes with two brackets for mounting on walls or desks using screws to keep everything organized.

![](https://fabricate.hackclub-assets.com/c95b433d780a4451d780eceae5415a8a821611e286ae0d25cfcc7a70a74b938e/image-png/image.png)

**Total time spent: 2h**
