<<<<<<< HEAD
# Sensor Haptic Guitar with Quantum Probabilistic Data Analysis

**Research Question**  
*Does introducing real quantum measurement into a human-conditioned control loop produce measurable temporal structure beyond classical randomness?*

---

## Project Overview

This project investigates a human-in-the-loop cyber-physical system in which continuous human motion is coupled to a probabilistic quantum process. A wearable, IMU-based virtual guitar captures high-dimensional gesture data from the performer and maps it into a stable classical latent control space. This latent state then parameterizes a quantum measurement process whose outcomes modulate musical realization in real time.

The system is designed to study **how structured human input interacts with irreducible probabilistic behavior**, and whether this interaction produces temporal structure that cannot be explained by classical randomness alone. Sound serves as the output modality, allowing probabilistic behavior to be perceived, analyzed, and interacted with in real time.

This is not a study of musical performance. It is an experimental platform for exploring **human–probabilistic interaction**, **measurement-driven variability**, and **emergent temporal structure** in closed-loop systems.

---

## Conceptual Framework

### Classical Latent Gesture Space

Human motion is captured using a wearable network of inertial measurement units (IMUs) mounted on the hand, fingers, and wrist. Rather than reconstructing absolute position or a virtual fretboard, the system encodes gesture as a **high-dimensional vector state** composed of relative orientations, angular velocities, and temporal dynamics.

These vectors are transformed into a **latent gesture space** that is:

- deterministic and repeatable  
- invariant to small execution differences  
- capable of clustering similar hand postures and motion trajectories  

This classical layer provides **structure, stability, and control**. It represents *what the human is doing* in a continuous, relational sense.

---

### Quantum Probabilistic Modulation Layer

The latent gesture state does not directly determine system output. Instead, it **biases parameters of a quantum circuit** implemented using Qiskit. Gesture-derived features modulate elements such as:

- rotation angles  
- circuit depth  
- entanglement configuration  

The circuit is executed on a quantum simulator or hardware backend, and **measurement outcomes introduce irreducible probabilistic variation** into musical realization.

The quantum layer is intentionally constrained:

- it does not replace classical structure  
- it does not determine musical validity  
- it modulates outcomes within bounded, musically coherent spaces  

The quantum process provides **uncertainty**, not control. The classical and quantum layers are coupled but distinct.

---

## System Architecture

[ IMU Network ]
->
[ ESP32 Microcontroller ]
->
[ Serial / MIDI Stream ]
->
[ Python Processing Layer ]
->
[ Qiskit Quantum Module ]
->
[ Generative Musical Engine ]
->
[ MIDI Output + Visualization ]

**Wearable IMU Network**  
Captures multi-axis motion and orientation data defining the gesture state.

**ESP32 Microcontroller**  
Handles sensor polling, basic filtering, and real-time data transmission.

**Python + Qiskit Layer**  
Constructs latent gesture vectors and maps them to constrained quantum circuit parameters.

**Sound Engine**  
Converts measurement-modulated outputs into MIDI events routed to DAWs or synthesizers.

---

## Hypotheses

**H1 (Coupling Effect)**  
As quantum coupling strength increases, the joint human–quantum system exhibits statistically significant changes in output structure (e.g., entropy, autocorrelation, clustering, predictability) compared to matched classical random baselines.

**H2 (Time-Lag Effect)**  
Quantum measurement outcomes are better explained by a lagged version of the latent gesture state, `x(t−τ)`, than by the instantaneous state `x(t)`, indicating nontrivial temporal dependency rather than pure noise.

---

## Design Evolution

Early prototypes attempted explicit virtual fretboard reconstruction using spatial mapping. These approaches were abandoned due to strict positional accuracy requirements and an implicit treatment of uncertainty as error.

Subsequent iterations explored distributed and backpack-mounted configurations that improved electrical stability but interfered with embodied playability.

The final design adopts a **gesture-centered, IMU-only architecture**, encoding hand geometry and motion entirely through vector relationships rather than absolute position. This shift allowed invariant gestures to cluster naturally in latent space while preserving expressive variation.

This evolution motivated the final two-layer architecture:

- a **classical deterministic layer** for structure and control  
- a **quantum probabilistic layer** for bounded, irreducible variability  

---

## Data Logging and Analysis

All gesture vectors, circuit parameters, and quantum measurement outcomes are timestamped and logged in real time. This enables:

- immediate playback and visualization  
- longitudinal analysis of temporal structure  
- comparison against classical RNG and shuffled-input baselines  

Planned analysis metrics include:

- entropy and divergence measures  
- autocorrelation and cross-correlation  
- latent-output clustering stability  
- predictability under lagged input models  

---

## Visualization Strategy

The system includes parallel visualization layers for classical and quantum components. Keeping these representations distinct allows direct comparison between deterministic structure and probabilistic modulation.

Visualizations are used as analytical tools, supporting:

- comparison of temporal structure  
- identification of regime changes  
- interpretation of coupling effects  

---

## Hardware Components

- ESP32 microcontroller  
- MPU-6050 IMUs (hand and finger mounted)  
- TCA9548A I2C multiplexer  
- Potentiometers and rocker switches for parameter control  
- Custom 3D-printed wearable interface (Fusion-based design)  
- USB-C rechargeable power supply (10,000 mAh)  

---

## Software Stack

- Arduino IDE for ESP32 firmware  
- Python for data processing and MIDI routing  
- Qiskit for quantum circuit construction and measurement  
- DAW-compatible MIDI output  
- Data logging and visualization tools  

---

## Interpretation and Context (Non-Technical)

Sound and quantum systems are both governed by wave phenomena evolving under constraints. While physically distinct, both exhibit structured patterns emerging from underlying dynamics.

In this project, sound functions as a **perceptual interface**, making probabilistic behavior audible and interactive. The goal is not to explain quantum mechanics through music, but to explore how humans perceive, adapt to, and influence probabilistic systems through embodied interaction.

Noise is treated not as failure, but as a resource whose structure can be studied.

---

## Scope and Limitations

This project does **not** claim:

- quantum computational advantage  
- new physical effects  
- foundational quantum results  

It is an exploratory system designed to study **interaction, coupling, and temporal structure** in human-conditioned probabilistic processes.

---

## Future Work (Speculative)

Potential extensions include:

- comparison between simulator and hardware backends  
- expanded human learning studies  
- alternative probabilistic models  
- richer visualization and analysis tools  

More advanced quantum experiments are intentionally deferred until the current system is fully characterized.

---

## Installation and Usage

Documentation will be added once hardware and software interfaces stabilize.
=======
# **Sensor Haptic Guitar with Quantum Probabilistic Data Analysis**

## <ins>**Project Overview**</ins>
This project explores a wearable, sensor-based virtual guitar system that fuses embodied human gesture with classical and quantum-inspired algorithms to drive generative sound. Using MIDI, real-time sensor input, and probabilistic quantum modeling, the system investigates how structured harmony and controlled randomness can coexist at the boundary between deterministic music theory and quantum unpredictability.

At its core, this is an experiment in human-probability co-creation: how physical motion biases probabilistic systems, and how those probabilities become perceptible through sound.
</br>

## <ins>**Background & Intuitive Ideas**</ins>

### Real-time Musical Interaction
(Can human movement meaningfully guide a generative instrument in real time?)

Users perform on a virtual guitar using a wearable sensor system composed of finger rings and wrist-mounted sensors.
Gestures such as strums, proximity, and finger positions are converted into timestamped MIDI data.
These inputs drive algorithmic recommendations of musically viable next steps using classical music theory rules such as:
- chord compatibility
- scale membership
- rhythmic continuity

This creates a feedback loop between the player’s body and the evolving musical structure
--- 

### Data Analysis and Quantum
(What does probabilistic logic feel like when you can hear it?)

Qiskit-based quantum circuits introduce probabilistic variation into the system.
Classical sensor input biases:
- rotation angles
- entanglement strength
- circuit depth

Measurement outcomes introduce structured randomness into:
- chord selection
- rhythmic subdivision
- timbral modulation

The same gesture may produce subtly different results each time, creating a living probability field rather than a fixed algorithm.

---

### Visualization and Human Expression
(How do we make quantum behavior feel tangible?)

Think of the system as a duet between performer and probability.
- Interactive: real-time gesture control with audible feedback
- Accessible: built from DIY electronics and open-source software
- Educational: turns abstract quantum ideas into something you can hear, see, and play with
The goal is not to “simplify” quantum mechanics, but to make its statistical behavior perceptible through embodied interaction.

## <ins>System Architecture</ins>

The system is designed around modular interaction hardware and software layers communicating in real time.  

[ Sensor Input ] → [ ESP32 Harness ] → [ MIDI / Serial Output ] →
[ Python + Qiskit ] → [ Generative Response ] → [ MIDI Out ] → [ Sound + Visualization ]

Wearable sensor network: captures human motion and proximity
ESP32 microcontroller: thresholds, filtering, and data transmission
Python + Qiskit layer: maps motion to probabilistic quantum parameters
Sound engine: routes output to synths or DAWs for audio generation

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

## <ins>Quantum Integration (with Qiskit)</ins>

Circuit construction: gates such as Hadamard, Ry, and CNOT are classically biased by sensor features
Measurement: qubit collapse determines note, chord, effect, or silence
Variation space: introduces non-repeating micro-structure into the music
Rather than treating randomness as error, it is treated as texture.

A gesture becomes a probability cloud.
A note becomes a collapsed distribution.

## <ins>Data Flow and Analysis</ins>

All gesture data and quantum measurement outcomes are timestamped and logged in real time.
Sessions can be replayed, allowing direct comparison between classical and quantum-driven decisions and visualization of long-term musical trends.
Planned extensions include:
- Applying weighted bias to specific quantum measurement outcomes for guided randomness
- Adding a feedback loop where past outcomes influence future gate parameters, allowing the system to evolve its behavior over time

## <ins>Visualization Plans: Classical vs Quantum</ins>  
To better understand how each logic engine behaves, the system will feature two parallel visualization layers, one for the classical engine and one for the quantum engine.
These visualizations will be used to further explore how sound emerges from different logical structures and how probabilistic behavior differs from rule-based systems.
This project isn’t just about sound it’s about how logic becomes sound. Keeping the visualizations separate:
- Makes it easier to compare structure vs. randomness
- Shows that both engines can produce musical results through completely different processes
- Helps audiences feel the contrast between the stability of music theory and the uncertainty of quantum probability

## <ins>Goals & Hypotheses</ins> 
Human motion can meaningfully bias probabilistic systems in real time.
Quantum-driven variation produces musical structures not reproducible by purely deterministic algorithms.
Users can develop an intuitive “feel” for probabilistic behavior without formal training in quantum mechanics.
Potential applications include:
- Experimental composition
- Live performance
- Interactive education
- Research into human–probabilistic interfaces

Both sound and quantum behavior are governed by waves evolving through time and space.

Sound waves are pressure oscillations in air.
Quantum wavefunctions are mathematical probability amplitudes.

Though physically different, both encode structure through resonance, interference, and superposition.

When a string resonates, harmonics emerge.
When a quantum state evolves, energy modes emerge.
In both cases, order arises from vibration constrained by boundary conditions.

This project uses sound as a perceptual bridge to explore those normally invisible statistical structures.

---
## <ins>Harmonics and Connection</ins>

In both music and quantum mechanics, wave behavior governs how energy moves and how structure emerges from what initially appears chaotic.
---

### A Structured Waveform

When you pluck a string, you are not hearing a single frequency. You are hearing a layered blend of frequencies called harmonics or overtones.

The fundamental frequency is the base pitch you perceive (e.g., A = 440 Hz).

Harmonics are integer multiples of this base frequency (880 Hz, 1320 Hz, etc.).

Together, these overtones define the instrument’s timbre, or tone color.

This structure is mathematically precise:

A vibrating string of length L, fixed at both ends, supports standing waves at L/n, producing frequencies fₙ = n · f₁, where n = 1, 2, 3...

At the microscopic level, the string’s motion is complex. At the macroscopic level, resonance imposes order.
---

### Quantum Wavefunctions: Probability with Structure

In quantum mechanics, particles are described by wavefunctions mathematical objects that encode all possible information about a system.

Solutions to the Schrödinger equation often resemble standing waves, similar to vibrating strings.

In models such as the particle in a box, quantized energy levels arise from boundary constraints, just as harmonic frequencies emerge from a fixed string.

These states are also indexed by discrete modes n = 1, 2, 3..., with higher modes containing additional nodes (points of zero amplitude).

In both music and quantum physics, discrete resonance patterns emerge from continuous wave equations.
---

### <ins>Research Connections</ins> 
Physicists and mathematicians have long noted this connection:

- **Fourier analysis** the same tool used to decompose sound into frequencies, is foundational in quantum theory for analyzing wavefunctions.
- **Quantum harmonic oscillators** a standard model in quantum mechanics, mirror the math of vibrating strings and sound waves solutions are built from Hermite polynomials layered over Gaussian envelopes.
- Recent work in **quantum chaos theory** examines how deterministic quantum systems (like perturbed harmonic oscillators) can still produce statistically random patterns akin to **inharmonic overtones** in acoustics.

---

### <ins>Why This Matters</ins>
Quantum systems appear random, yet they obey deep mathematical order. Music often sounds emotional and chaotic, yet it is governed by rigid physical laws. This instrument lives at that overlap. It asks:

Can randomness be expressive rather than destructive?
Can probabilistic systems feel intentional?
What does structure sound like when certainty is removed?

Noise here is not failure.
It is complexity made audible.

## <ins>Installation / Running (Coming soon...)</ins>
(I'll write this once I stabilize the code and hardware)

Basic plan:  
- Install Qiskit and required MIDI libraries  
- Upload Arduino firmware to ESP32  
- Run the Python bridge script  
- Connect to DAW or audio engine
- Visualize

Additional ideas while researching:

(due to stochastic)
- Demonstrate CHSH violation and sonify it as musical tension.
- Show stochastic resonance by finding a noise level where quantum-driven switches synchronize with rhythm, quantitatively and audibly.
- Prototype measurement-based control, where basis choices from gesture steer musical structure.
- Treat decoherence parameters as musical knobs, turning lab-grade error models into sound design.
>>>>>>> e9d7fc5 (Reestablished project structure: ESP32 Firmware, analysis and research)
