from qiskit import QuantumCircuit
from qiskit import transpile
from qiskit_aer import Aer
from qiskit.circuit import CircuitInstruction
from qiskit.circuit.library import XGate
'''
# Create the circuit
qc = QuantumCircuit(2,2)

# Apply Hadamard gate
qc.h(0)
qc.h(1)

# Measure the qubit
qc.measure_all()
print(qc)

# I'm going to use a simulator to see how the qubit changes over 1000 runs (Aer simulator)


simulator = Aer.get_backend('qasm_simulator')

tqc = transpile(qc, simulator)
job = simulator.run(tqc, shots=1000)
# Get the results

result = job.result()
counts = result.get_counts(qc)
print("\nTotal count for 0 and 1 are:", counts)
'''

# Moving on to testing measurement induced randomness

qc = QuantumCircuit(2,2)

# Create randomness by measuring superposition
# q0 in (|0> + |1>)/sqrt(2)

qc.h(0)
qc.measure(0,0)

# Use the random bit to control another

ci = qc._append(XGate().to_mutable(), [qc.qubits[1]], [])
ci.condition = (qc.cregs[0], 1)

qc.measure(1,1)

#visualize
backend = Aer.get_backend('qasm_simulator')
tqc = transpile(qc, backend)
job = backend.run(tqc, shots=1000)
result = job.result()
counts = result.get_counts(qc)

print("Joint counts are:", counts)
