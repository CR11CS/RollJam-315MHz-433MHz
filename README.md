# RollJam 315MHz / 433MHz (Research & How-To)
**_Listen, Jam/Listen, Replay_**

RollJam is a method of capturing a vehicle's rolling code key fob transmission by simultaneously intercepting the transmission and jamming the receivers window; giving the attacker a valid rolling code for re-transmission. The RollJam method was debuted at DEFCON 2015 by security researcher Samy Kamkar. This repository is a compilation of my research on the topic and resources to build your own RollJam device for research. 

## **< *GET TO KNOW YOUR KEY* >**

As this is my first venture into anything radio, I figured I could justify purchasing two HackRF One software defined radios (SDR) for learning. Unfortunately I didn't do my research first because RollJam requires the ability to transmit and receive simultaneously (full-duplex) but the HackRF One can either transmit or receive at one time (half-duplex). 

***But what about tying / synchronizing the two HackRF clocks to make     'one' full-duplex radio?***

While this is [officially supported and documented](https://hackrf.readthedocs.io/en/latest/multiple_device_hardware_synch.html#connect-the-clocks) by the creator of the HackRF One, I was unable to get a working full-duplex result after countless hours of troubleshooting. In a bad move by me, I purchased one official *Great Scott Gadgets* HackRF One and one nameless 'HackRF One' from Alibaba -- only to realize later that tying clocks between the two would never quite pan out due to their slight hardware differences.

***At this point, I am missing the fundamental capability that the RollJam method requires but let's investigate what a key fob transmission looks like regardless.***

To begin we first need to know what frequency our key fob transmits at. A quick Google search will tell you that most key fobs in the U.S. transmit at 315MHz and key fobs outside the U.S. transmit at 433MHz due to different radio band allocations. How can we be sure of the transmission frequency? Fortunately for us, the FCC requires registry of radio transmitters and thus requires proper testing of these devices to ensure safety compliance. After approval with the FCC, each device is assigned a searchable 'FCC ID' which can be found on our key fob (typically somewhere inside).

***FCC ID: CWTWB1U840***

![We find FCC ID: CWTWB1U840](https://user-images.githubusercontent.com/96323936/183130590-bd276cc8-567b-432e-bfe2-e087617d6f84.png)

**Now we can plug this FCC ID into [FCC.io](http://fcc.io/), a website made to simplify FCC ID search.**
You may have two or more results for the same FCC ID if that key fob is designed with both a 315MHz and 433MHz transmitter for different markets. Take note of the 'Upper Frequency' column to the right to find which one correlates to your device or market.

**Under "Details" you'll find a test report document of the key fob which includes all the transmitter info we need.**
![Key fob details from FCC test report](https://user-images.githubusercontent.com/96323936/183133782-0ec5ec20-5a8a-436d-ba66-ac179d9bac88.PNG)

> **We now know that our key fob:**
>  - Transmits at 314.975MHz
>  - Uses Frequency Shift Keying (FSK) for signal modulation
>  - Has a clock frequency of 2MHz
> 
> *P.S. "Receiver Part" with a frequency of 125kHz is for the Passive Keyless Entry System (possible future writeup?)*

## **< *SEE YOUR TRANSMISSION* >**
*Now that we're familiarized with our transmitter, lets see what our actual transmission looks like.*

**First, download [AIRSPY SDR#](https://airspy.com/download/) software to use your SDR of choice to view the transmission.** 

After installing AIRSPY, open the [settings](https://user-images.githubusercontent.com/96323936/183137801-b62e935a-cc0a-4f03-a89f-d6c64b670f5c.PNG) icon in the top left corner and select your SDR device from the dropdown. Sample rate will vary by your radio but I recommend 20 MSPS if possible. Hit the play button to the left of the settings icon to begin listening. You will need to navigate to either 315MHz or 433MHz by clicking the frequency selector at the top of the window. Hover over the white text (325.000.000 below) and you will find up and down arrows to enter your frequency.

You should see something similar to the below image. The top pane is your spectrum analyzer which displays signals in decibels and the bottom pane is a waterfall display that shows signals as a heat map over time (Y axis). If your waterfall looks unusual, you may need to tweak your waterfall display settings or receiver gain.

***First look at our key transmission***
![AIRSPY SDR# key transmission waterfall](https://user-images.githubusercontent.com/96323936/183130224-309b4729-6ef3-4d2e-afc5-cc88dfde028d.PNG)
The waterfall display shows us our key transmission for the 'lock' button. It appears to send three transmissions broken by brief moments of pause. After several key presses, this transmission maintained this same pattern.

This view of our transmission isn't a great way to analyze what is going on but is a quick way to get a high-level peek at how our key fob transmits. Some key fobs will transmit at three frequencies near to the center frequency (315MHz / 433MHz) simultaneously to provide some protection against a RollJam attack.

## **< *ANALYZE YOUR TRANSMISSION* >**


We're going to attempt to capture and decode our transmission. **For this, we are going to download [Universal Radio Hacker (URH)](https://github.com/jopohl/urh) software which includes ability to record, analyze and view signals in detail.**

1.) Open URH, click 'File' -> 'Record signal'

2.) From 'Device' select your SDR then click the green refresh icon for 'Device Identifier'

3.) Set frequency to your frequency (315MHz / 433MHz)

*Sample frequency is recommended to be at least double your maximum frequency; for our use the default value is fine.*

**Have your key fob handy and press record when ready.** 

After capturing your transmission, we'll move to the interpretation tab of URH. After some adjustments to our view, we can see the below signal represented as a waveform and the hexadecimal representation of the encoded data.

After some looking around at our signal, we can see sections of our waveform appear more 'dense' than others. This is due to the use of frequency shift keying to modulate the signal. URH has demodulated this signal for us in the bottom pane. It appears that each transmission is a repeat of the same data to ensure the vehicle receives the command from the key fob; with a long preamble transmission to synchronize with the receiver. 

![FSK modulated signal](https://user-images.githubusercontent.com/96323936/183130294-a952f790-0553-405a-9041-89fc9280d4d1.PNG)
## **< *ACQUIRE HARDWARE* >**
*With a fresh new view and understanding of our key fob, it's time to assemble the actual RollJam device.*

> **Components:** 
> 2xCC1101 Transceivers &
> 1xTeeny 3.2 Microcontroller

![2 CC1101 transceivers and a Teensy 3.2 microcontroller](https://user-images.githubusercontent.com/96323936/183158392-34d8a656-a860-4dff-a624-b9e0d59a9b9a.png)


**Hardware References:**
https://www.pjrc.com/teensy/first_use.html - Teensy Microcontroller first use and beginner info
https://www.pjrc.com/store/teensy32.html  - Teensy 3.2 Pinouts, communications, etc.
https://www.ti.com/product/CC1101            - CC1101 Datasheet & antenna guide

> *With our hardware acquired, it's time for the nitty-gritty of figuring out what these components are capable of, how they can
> inter-communicate, and how they need to be programmed.*

**Communications:**
By reading the Teensy 3.2 page and reading through the CC1101 datasheet, we will have a pretty good understanding of the component pinouts and communications. For our Teensy to communicate to our CC1101 transceivers, we will be using serial peripheral interface (SPI) which provides full-duplex, high-speed communications using:
-   SCK: Serial Clock (output from master)
-   MOSI: Master Out Slave In (data output from master)
-   MISO: Master In Slave Out (data output from slave)

https://en.wikipedia.org/wiki/Serial_Peripheral_Interface

**With SPI in mind, here is our wiring diagram for the RollJam**

![RollJam wiring diagram](https://user-images.githubusercontent.com/96323936/183197750-d840c506-c1c0-4f0d-9c44-2f2616529e69.png)
## **< *ACQUIRE SOFTWARE* >**

**Programming:**
Unfortunately I don't have the knowledge to write in C++ or any other languages useful for embedded systems programming -- Fortunately, someone else has already published their C++ for RollJam. Huge thank you to Erik Liddell for publishing the code to his [GitHub](https://github.com/eliddell1/RollJam).

Because his code is written for 433MHz transmission, we have to adapt it to 315MHz which means altering some registry values... but which ones? Looking through our [CC1101 datasheet](https://www.ti.com/lit/ds/symlink/cc1101.pdf?ts=1659597888845&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FCC1101), we find the following registers:

|Address| Register | Description |
|--|--|--|
| 0x0D | FREQ2 | Frequency control word, high byte |
| 0x0E | FREQ1 | Frequency control word, middle byte |
| 0x0F | FREQ0 | Frequency control word, low byte |

*Now to determine our values for a desired transmission at 315MHz (or any other frequency)*

With our registers in hand, we need to figure out what values are necessary for our desired frequency. We have two options to find these values:

**1.) Do the math**
![say no to math](https://user-images.githubusercontent.com/96323936/183130218-412f6160-f3be-45c3-bb65-6143cef4a03b.PNG)
**OR**

**2.) Use Texas Instruments' Software**
![Thank you Texas Instruments](https://user-images.githubusercontent.com/96323936/183130291-48296390-ac03-43ba-9d98-3b777aa8b3b2.PNG)We'll go with the obvious choice here. Download SmartRF Studio below then navigate in the welcome screen to CC1101.

**SmartRF Studio:**
https://www.ti.com/tool/SMARTRFTM-STUDIO

With this software we can generate configurations and do testing of our CC1XXX or CC2XXX transceivers. For our use, we simply need to plug in our desired frequency in the 'Base Frequency' field and our new register values are on the right. We'll also generate registry values for our jamming frequency near to 315MHz within a few megahertz. 

**In this repository are the *.ino* files for both 315MHz and 433MHz RollJam.**

Push the .ino code to your Teensy Microcontroller using the [Teensy Loader Application](https://www.pjrc.com/teensy/loader.html)

## **< *EXECUTE THE ATTACK* >**
Finally, we researched the theory, we've analyzed a key fob in a practical way and we have a strong grasp of how all the pieces fit together. Now to test our fully-built RollJam device.

DISCLAIMER: 
***Federal law prohibits the operation, marketing, or sale of any type of jamming equipment that interferes with authorized radio communications in the United States.***

If you are intent on testing such jamming devices or experimental radio transmission in general, I suggest you look into obtaining a HAM Radio license to broaden your knowledge and use a professional Faraday cage RF enclosure to keep your transmissions localized to your testing. I personally enjoy [Ramsey Boxes](https://ramseytest.com/).

**Conclusion:**
My testing of the RollJam device worked for most vehicle key fobs in my test environment but I did encounter what appears to be some protection mechanisms in place for a couple of Mercedes and Infiniti vehicles. My best guess from viewing transmissions with these protections in place is that their transmissions occur across 3 separate frequencies near 315MHz to ensure the receiving end has a better chance to receive and less chance to jam. 

![Security mechanisms in place?](https://user-images.githubusercontent.com/96323936/183219754-41dbe024-12e0-4b63-80d4-c26e5bca5011.PNG)
