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

### Data Analysis and Quantum
( *What does "quantum logic" sound like? Can we hear the "texture" of quantum unpredictability?*)
</br>
- Introduces **Qiskit-based quantum circuits**, where classical input biases gate rotations or entanglements.
- Measurement results from these circuits introduce **probabilistic variation** into:
  - Chord choice
  - Rhythm pattern
  - Timbre modulation
    
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


## <ins>Sensor Hardware Overview</ins>
The physical setup is designed to feel as close to "air-guitar" as possible but with embedded intelligence.  

- **Finger rings**: Carry ToF sensors to detect string-like proximity gestures.  
- **Palm/wrist-mounted strum sensor**: Detects active strumming motion via directional proximity or IR break-beam.  
- **ESP32**: Connects all sensors through a multiplexer (TCA9548A) and communicates over USB or Bluetooth MIDI.  
- **Power**: Rechargeable 10,000 mAh USB-C bank mounted on a carbon-fiber or foam-core backplate.  
- **Harness**: Braided JST cables routed through Velcro straps for rewearability.  

### Optional add-ons:  
- Rocker switches for mode shifting  
- Potentiometer knobs for pitch bend or effect control  

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

## Goals & Hypotheses  

- Human + quantum co-creation will lead to novel generative music patterns not reproducible by deterministic algorithms alone. Users can develop a *feel* for how quantum biasing behaves over time—without ever needing to understand quantum math.  

This system could be used for:  
- Experimental music composition  
- Live performances with quantum improvisation  
- Educational demos to make abstract quantum mechanics *feel* tangible  

## Installation / Running (Coming soon...)  
(I'll write this once I stabilize the code and hardware)

Basic plan:  
- Install Qiskit and required MIDI libraries  
- Upload Arduino firmware to ESP32  
- Run the Python bridge script  
- Connect to DAW or audio engine
- Visualize
