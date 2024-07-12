
# Operating System Simulator

## 📃 Project Overview
This repository contains an operating system simulator designed to model CPU scheduling. It supports multiple scheduling algorithms including Round Robin, Priority (both preemptive and non-preemptive), Shortest Job First (SJF), and Shortest Remaining Time First (SRTF). The simulator allows configuration of scheduling parameters to simulate tasks and evaluate performance metrics like average waiting time, turnaround time, and response time.

## ✨ Key Features
- **Multiple Scheduling Algorithms:** Implements Round Robin, Priority (preemptive and non-preemptive), SJF, and SRTF.
- **Dynamic Scheduling:** Users can configure scheduling parameters such as quantum time for Round Robin and priority levels for processes.
- **Visualization Tools:** Includes Gantt charts to visually represent the scheduling process and results.
- **Error Handling:** Robust error handling to manage incorrect inputs and system failures.
- **Extensive Documentation:** Detailed documentation for understanding system operations and usage.

## 🕒 Scheduling Algorithms
This section details the scheduling algorithms implemented in this simulator, how they operate, and their typical use cases.

### First-Come, First-Served (FCFS)
Processes are dispatched according to their arrival time. The first process to arrive is the first to be executed.

### Shortest Job First (SJF)
Prioritizes processes with the shortest estimated running time, reducing the average waiting time.

### Priority Scheduling
Processes are served based on priority. Higher priority processes interrupt lower priority ones in preemptive mode, whereas, in non-preemptive mode, a running process will complete irrespective 

### Round Robin (RR)
Each process is assigned a time slice (quantum), and processes are executed cyclically.

### Shortest Remaining Time First (SRTF)
An extension of SJF, this preemptive version switches to the process with the shortest estimated remaining time.


## ⚙️ Visualization
For each scheduling algorithm, the simulator generates a Gantt chart that visually represents the order and duration of process execution. This can aid in understanding the temporal dynamics and efficiency of each scheduling approach.


## ▶️ Getting Started
### 📋 Prerequisites
- GCC Compiler or any compatible C compiler installed on your system.

### ⬇️ Installation
Clone the repository to your local machine:
```bash
git clone https://github.com/yourusername/Operating-System-Simulator.git
cd Operating-System-Simulator
