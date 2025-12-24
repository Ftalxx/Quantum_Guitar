# Sensor Haptic Guitar with Quantum Probabilistic Data Analysis

## <ins>Project Overview</ins>

This project explores a wearable, IMU-based virtual guitar system that fuses embodied human gesture with classical and quantum-inspired algorithms to drive generative sound. Using MIDI, real-time motion sensing, and probabilistic quantum modeling, the system investigates how structured harmony and controlled randomness can coexist at the boundary between deterministic music theory and quantum unpredictability.

At its core, this is an experiment in human–probability co-creation: how physical motion biases probabilistic systems, and how those probabilities become perceptible through sound.
</br>

## <ins>Background & Intuitive Ideas</ins>

</br>
### Real-time Musical Interaction

(Can human movement meaningfully guide a generative instrument in real time?)

Users perform on a virtual instrument using a wearable sensor system composed of finger-mounted and wrist-mounted MPU-6050 IMUs, integrated into a custom, body-conforming interface. Rather than reconstructing a physical fretboard or relying on absolute position, the system interprets multi-axis motion and orientation data as high-dimensional gesture vectors.

Strumming dynamics, hand orientation, and finger articulation are captured as continuous time-series data and converted into timestamped MIDI control signals. These signals bias a musically constrained generative engine informed by classical music theory principles such as:

harmonic compatibility

scale and mode coherence

rhythmic continuity

This creates a closed feedback loop between embodied motion and evolving musical structure, allowing performers to develop stable control through repeated interaction while retaining expressive flexibility.

### Data Analysis and Quantum

(What does probabilistic logic feel like when you can hear it?)

Qiskit-based quantum circuits introduce probabilistic variation as a secondary modulation layer acting on an already stable, gesture-defined control space. IMU-derived motion vectors bias:

rotation angles

entanglement strength

circuit depth

Measurement outcomes introduce structured variability into:

harmonic realization within constrained chord families

rhythmic subdivision and micro-timing

timbral modulation

The same gesture may produce subtly different realizations each time, forming a living probability field rather than a fixed algorithm, while remaining anchored to performer intent.

### Visualization and Human Expression

(How do we make quantum behavior feel tangible?)

The system is designed as a duet between performer and probability.

Interactive: real-time gesture control with immediate audible feedback

Accessible: built from DIY electronics and open-source software

Educational: probabilistic behavior becomes perceptible through sound and motion

The goal is not to simplify quantum mechanics, but to make probabilistic structure legible through embodied interaction, allowing users to develop an intuitive understanding of uncertainty without sacrificing control.

## <ins>Design Evolution and Iterative Prototyping</ins>

The current system architecture emerged through multiple design iterations that refined both the physical interface and the underlying control model. Early prototypes explored explicit virtual fretboard reconstruction, but these approaches imposed strict spatial accuracy requirements and treated uncertainty as error.

A subsequent distributed backpack-mounted prototype improved electrical stability and scalability but disrupted musical flow due to cable drag and constrained posture. This design was intentionally abandoned in favor of solutions that prioritized embodied playability.

The final transition moved to a gesture-centered, IMU-only architecture, where hand geometry and motion are encoded entirely as vector relationships rather than spatial positions. Similar gesture vectors naturally cluster within a latent space, allowing invariant hand postures to correspond to families of harmonically related outcomes.

The resulting system separates control into two layers: a deterministic classical layer that constructs a stable, repeatable latent gesture space, and a quantum-inspired probabilistic layer that introduces bounded variation without compromising control.

## <ins>System Architecture</ins>

The system is designed around modular interaction hardware and software layers communicating in real time.

[ IMU Input ] → [ ESP32 Interface ] → [ MIDI / Serial Output ] →
[ Python + Qiskit ] → [ Generative Response ] → [ MIDI Out ] → [ Sound + Visualization ]

Wearable IMU network: captures multi-axis motion and orientation vectors defining a high-dimensional gesture state

ESP32 microcontroller: sensor polling, filtering, and data transmission

Python + Qiskit layer: maps IMU-derived latent features to constrained probabilistic quantum parameters

Sound engine: routes output to DAWs or synthesizers

## <ins>Hardware & Software Components</ins>
Wearable Sensor System

ESP32 microcontroller - 
Central processing unit for reading IMU data and transmitting MIDI or serial streams

MPU-6050 IMU sensors -
Mounted on the hand and fingers
Capture acceleration and angular velocity
Combined into a high-dimensional motion vector representing hand shape and gesture dynamics

TCA9548A I2C Multiplexer -
Enables multiple identical IMUs to operate on a single I2C bus

Potentiometers / rocker switches -
Continuous and discrete control over mode selection, probabilistic depth, or expressive parameters

Custom 3D-printed glove / prosthetic interface -
Designed in Fusion and fabricated to conform to the performer’s hand
Houses sensors, wiring, and mounting features directly on the body
Prioritizes stability, comfort, and minimal interference with natural motion

USB-C rechargeable power bank (10,000 mAh) - 
Provides portable power for extended sessions

### Software Stack

Arduino IDE – ESP32 firmware and sensor streaming

Python desktop application – vector processing, MIDI routing, quantum integration

Qiskit – probabilistic circuit construction and measurement

MIDI routing – DAW and virtual instrument integration

Data logging & visualization tools – entropy, gesture clustering, and system evolution analysis

## <ins>Quantum Integration (with Qiskit)</ins>

Quantum processes operate on normalized IMU-derived motion vectors rather than positional data. Circuit parameters are biased by gesture trajectories through the latent space.

Measurement collapse determines musical realizations such as articulation, harmonic color, or rhythmic variation. Randomness is treated as expressive texture rather than error.

A gesture becomes a probability cloud.
A note becomes a collapsed distribution.

## <ins>Data Flow and Analysis</ins>

All gesture data and quantum measurement outcomes are timestamped and logged in real time, enabling immediate playback and longitudinal analysis of how gesture patterns, probability distributions, and musical outcomes co-evolve.

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
