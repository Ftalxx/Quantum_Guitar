# **Sensor Haptic Guitar with Quantum Probabilistic Data Analysis**

## <ins>**Project Overview**</ins>
This project explores a novel interactive music system that fuses wearable sensor-based instrumentation (using a midi interface) with quantum and algorithm inspired data processing. The central aim is to investigate how probabilistic quantum ouputs driven by user gestures can shape generative music and offer insight into the edge between structured harmony and controlled chaos. 
</br>

## <ins>**Background & Intuitive Ideas**</ins>

### Real-time Musical Interaction
(*Can I use the input from the client to give recommendations of possible songs that might sound good?*)
<br>
- Users play a **virtual guitar** instrument using a wearable sensor system (finger rings and wrist-mounted ToF sensors).
- Inputs (strums, finger positions) are converted to MIDI signals and timestamped for **data logging**.
- These sensor values guide algorithmic recommendations of **musically viable follow-ups** based on classical **music theory rules** (chord progressions, scale compatibility, rhythmic flow).

--- 

### Data Analysis and Quantum
( *What does "quantum logic" sound like? Can we hear the "texture" of quantum unpredictability?*)
</br>
- Introduces **Qiskit-based quantum circuits**, where classical input biases gate rotations or entanglements.
- Measurement results from these circuits introduce **probabilistic variation** into:
  - Chord choice
  - Rhythm pattern
  - Timbre modulation

---

### Visualization and Human Expression
(*Can we showcase in an easy way for people to digest? Humanize the idea of quantum slightly or find a way this project might help people understand?*)
> Think of it as a duet between player and improviser.
-  **Interactive**: Real-time feedback from gestures + visualizations.
-  **Affordable**: DIY electronics using ESP32, sensors, and open-source code.
-  **Educational**: Makes quantum ideas tangible through audio-visual feedback.

## <ins>System Architecture</ins>

The system is designed around modular interaction—hardware and software layers communicating in real time.  

- **Wearable sensor network**: ToF sensors and potentiometers mounted on finger rings and wristbands capture motion, proximity, and “strumming” gestures.  
- **ESP32 microcontroller**: Reads sensor values, processes thresholds, and sends MIDI data or serial output.  
- **Laptop interface (Python/Qiskit)**: Interprets MIDI/serial data, biases a quantum circuit, and reads the measurement outcomes.  
- **Sound engine**: Outputs audio via MIDI to a DAW or synth (Ableton, Logic, or FluidSynth for open-source setups).  

[ sensor input ] → [ ESP32 harness ] → [ MIDI / serial output ] → [ Python + Qiskit ] → [ generative response / MIDI out ] → [ Visualization / Terminal ]

## <ins>Hardware & Software Components</ins>

### Wearable Sensor System

- **ESP32 microcontroller**  
  - Central processing unit for reading sensor inputs and sending MIDI/serial data

- **VL53L0X ToF (Time-of-Flight) distance sensors**  
  - Mounted on finger rings for sensing fret-style finger positions  
  - Optional palm-mounted version for strumming detection

- **TCA9548A I2C Multiplexer**  
  - Allows multiple identical I2C sensors (VL53L0X) to communicate with ESP32  
  - Necessary for managing up to 8 sensor channels

- **Potentiometers / knobs (rotary)**  
  - For controlling modes, pitch bend, or effects in real-time

- **Rocker switches**  
  - Toggle between algorithmic/quantum modes or change presets

- **JST connectors and harnesses**  
  - Used for modular, detachable sensor wiring through the wearable harness

- **Braided sleeving & heat-shrink tubing**  
  - Protect and organize cables; used along harness straps and finger connections

- **Carbon-fiber or hard foam-core backplate**  
  - Mounting platform for ESP32, battery pack, and multiplexer  
  - May be integrated into a wearable “cyber gear” styled harness

- **Velcro strap harness (rewearable)**  
  - Holds cables and sensor modules in place, body-worn design

- **USB-C rechargeable power bank (10,000 mAh)**  
  - Powers the ESP32 and sensors; chosen for portability and longevity

---

### Software Stack

- **Arduino IDE**  
  - Used to write and upload firmware to the ESP32  
  - Manages sensor reading, data smoothing, and MIDI or serial output

- **Python (desktop app)**  
  - Reads sensor data via USB or serial  
  - Converts input to MIDI or triggers algorithmic/quantum responses

- **Qiskit (IBM Quantum)**  
  - Simulates or runs quantum circuits using classical sensor input as gate parameters  
  - Collapses qubits to generate musical decisions (notes, chords, effects)

- **MIDI output (via pyMIDI or rtmidi-python)**  
  - Connects to DAW or external synth for audio generation  
  - May route to software like:
    - **Ableton Live**
    - **Logic Pro**
    - **GarageBand**
    - **FluidSynth / virtual instruments**

- **Data Logging & Visualization Tools**  
  - Logs timestamped inputs, decisions, and outputs  
  - Optional visualization with:
    - **Matplotlib / Seaborn** (for waveform/entropy plots)
    - **Processing or P5.js** (for real-time visuals)
    - **Qiskit Visualizations** (for circuit + histogram)

---

### Planned Enhancements

- **Force-sensitive resistors (FSRs)** – For finer dynamic control
- **Gyroscope / IMU** – To detect hand orientation or gestural strumming angles
- **Bluetooth MIDI module** – For wireless control
- **OLED display** – Mounted to backplate or wrist to show mode/status

---

## Assembly Overview (coming soon...)

- Modular JST-connected sensor rings
- Center harness routes to ESP32 & power on backplate
- USB-C port for charging + live MIDI/serial data



## <ins>Sensor Hardware Overview</ins>
The physical setup is designed to feel as close to "air-guitar" as possible but with embedded intelligence.  

- **Finger rings**: Carry ToF sensors to detect string-like proximity gestures.  
- **Palm/wrist-mounted strum sensor**: Detects active strumming motion via directional proximity or IR break-beam.  
- **ESP32**: Connects all sensors through a multiplexer (TCA9548A) and communicates over USB or Bluetooth MIDI.  
- **Power**: Rechargeable 10,000 mAh USB-C bank mounted on a carbon-fiber or foam-core backplate.  
- **Harness**: Braided JST cables routed through Velcro straps for rewearability.  

---

### Optional add-ons:  
- Rocker switches for mode shifting  
- Potentiometer knobs for pitch bend or effect control  

## <ins>Classical Algorithm Visualization</ins>
- Structured, hierarchical—like a **tree of decision nodes** based on music theory.
- Shows:
  - Key
  - Recent chord or note
  - Weighted probabilities of possible next steps
- Might use a **flow chart** or dynamic chord map that highlights the chosen path in real time.

## <ins>Quantum Integration (with Qiskit)</ins>

Quantum algorithms are introduced to explore new patterns of variation:  

- **Circuit construction**: Quantum gates (e.g., Hadamard, Ry, CX) are applied with classical sensor biasing.  
- **Measurement**: Each quantum output (|0⟩ or |1⟩) represents a branching note choice, chord, effect, or silence.  
- **Variation space**: The same gesture may produce different outputs depending on quantum collapse, creating a unique musical texture.  

The result? Controlled unpredictability. The particles / guitar are *playing with you*.  

> A gesture becomes a probability cloud. A note becomes a wavefunction collapsed.

## <ins>Data Flow and Analysis</ins>

- All gestures and quantum outcomes are **logged** with timestamps.  
- You can **replay sessions**, compare classical vs quantum decisions, or visualize note trends.  
- Future plans include:  
  - Assigning **weight** to certain measurement outcomes (guided randomness)  
  - Implementing a **feedback loop**, where outcomes bias future gates (musical learning over time)
 
## <ins>Visualization Plans: Classical vs Quantum</ins>  
- To help users—and myself—understand what’s really happening, I’ll be building **two distinct visualizations**, one for each engine (classical vs. quantum)
- I'll then utilize the data to go deeper into research regarding the sound of quantum and the universe.

This project isn’t just about sound—it's about *how different kinds of logic create sound*. Keeping the visualizations separate:
- Makes it easier to compare **structure vs randomness**
- Shows that both engines can be musical, but in very different ways
- Helps audiences *feel* the weirdness of quantum vs the stability of music theory


## <ins>Goals & Hypotheses</ins> 

- Human + quantum co-creation will lead to novel generative music patterns not reproducible by deterministic algorithms alone. Users can develop a *feel* for how quantum biasing behaves over time—without ever needing to understand quantum math.  

This system could be used for:  
- Experimental music composition  
- Live performances with quantum improvisation  
- Educational demos to make abstract quantum mechanics *feel* tangible  

## <ins>Sound and Quantum Waves: The Hidden Language of the Universe</ins>

Both **sound** and **quantum behavior** are expressions of waves—vibrations moving through time and space.  

- Sound waves are **vibrations in air** that we perceive with our ears.  
- Quantum waves (like wavefunctions) are **probability amplitudes**, abstract but real, describing how particles behave.  

Neither one is fully visible to us but we interact with both constantly.

> When you play a note, you vibrate the air.  
> When a particle is in superposition, its state *vibrates* in possibility space.

I’ve always felt there was a kind of **cosmic meaning** in this. Like maybe the universe *is* humming and quantum physics and music are just two different ways we try to understand its melody.  

This project asks:
- *What if we could listen to quantum behavior the same way we listen to a song?*
- *What if collapsing a quantum wave felt like resolving a chord progression?*
- *What if uncertainty wasn’t chaos—but harmony we haven’t learned to hear yet?*

By using sound as a medium for quantum interaction, I’m not just building a tool, I’m trying to **bridge two invisible worlds**. One that we’ve studied through physics, and one we’ve lived through music. Even if that music is not culturally pleasing to us there is some kind of noise being made.

In this system, noise isn’t failure. It’s **the signal of complexity**.  

- Quantum outcomes may generate dissonant or unpredictable sounds.
- Sensor inputs may drift or collide in ways that don’t “make sense.”
- The result might feel broken—or maybe it's just unfamiliar.

The goal isn’t to make a perfectly tuned instrument—it’s to ask:
- *Can randomness be emotionally resonant?*
- *What if we stopped filtering out the weird?*
- *Can we build an instrument that listens back—one that meets us with its own logic?*

## Harmonics and Connection

In both music and quantum mechanics, **wave behavior** governs how energy moves and how structure emerges from what looks like chaos.

---

### A Structured Waveform  
When you pluck a string, you're not just hearing a single frequency—you're hearing a blend of frequencies layered on top of each other, called **harmonics** or **overtones**.

- The **fundamental frequency** is the base note you hear (e.g., A = 440 Hz).
- **Harmonics** are integer multiples of this base frequency (880 Hz, 1320 Hz, etc.).
- These overtones give each instrument its **timbre**, or tone color.

The pattern is mathematically precise:  
> A vibrating string of length *L* fixed at both ends has natural modes where standing waves form at **L/n**, producing frequencies **fₙ = n·f₁**, where n = 1, 2, 3...

In short: a string is chaotic at the micro level—but when it resonates, order emerges.

---

### Quantum Wavefunctions: Probability with Structure  
Similarly, in **quantum mechanics**, particles are described by **wavefunctions** mathematical functions that hold all possible information about the system.

- Solutions to the **Schrödinger equation** often resemble **standing waves**, like the vibrating string.
- In systems like the **particle in a box**, **quantized energy levels** arise due to boundary constraints, just like harmonic frequencies on a string.
- These are also described by **n = 1, 2, 3...** modes, with higher modes having more nodes (points of zero amplitude).

So both musical notes and quantum particles show **discrete resonance patterns** emergent from continuous wave equations.

---

### <ins>Research Connections</ins> 
Physicists and mathematicians have long noted this connection:

- **Fourier analysis** the same tool used to decompose sound into frequencies, is foundational in quantum theory for analyzing wavefunctions.
- **Quantum harmonic oscillators** a standard model in quantum mechanics, mirror the math of vibrating strings and sound waves—solutions are built from Hermite polynomials layered over Gaussian envelopes.
- Recent work in **quantum chaos theory** examines how deterministic quantum systems (like perturbed harmonic oscillators) can still produce statistically random patterns—akin to **inharmonic overtones** in acoustics.

---

### <ins>Why This Matters</ins>
In this project, the quantum engine may look “random” but it could still contain **hidden resonance patterns**:

- Recurring outcomes in Qiskit simulations might behave like overtones of gesture input.
- A hand movement might “pluck” a quantum state that resonates with the prior measurement, creating a **musical feedback loop**.
- Visualization of **frequency domains** of outcomes could reveal **stable patterns** within noise.

This system aims to **listen** for that order. To treat quantum randomness like a waveform, not a glitch. To ask:
- Are we collapsing the wrong harmonics?
- What *else* is vibrating?

## <ins>Installation / Running (Coming soon...)</ins>
(I'll write this once I stabilize the code and hardware)

Basic plan:  
- Install Qiskit and required MIDI libraries  
- Upload Arduino firmware to ESP32  
- Run the Python bridge script  
- Connect to DAW or audio engine
- Visualize
