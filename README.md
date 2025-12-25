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
