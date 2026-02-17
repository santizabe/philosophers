# Philosophers

*This project has been created as part of the 42 curriculum by szapata-.*

## Description

**Philosophers** is a simulation project based on the famous "Dining Philosophers problem" by Edsger Dijkstra. The goal of this project is to learn the basics of threading a process, how to create threads, and how to discover the dangers of race conditions and deadlocks.

In this simulation:
*   One or more philosophers sit at a round table with a bowl of spaghetti in the middle.
*   The philosophers alternate between **eating**, **thinking**, and **sleeping**.
*   There are as many forks as there are philosophers.
*   To eat, a philosopher needs **two forks** (one on the left and one on the right).
*   The simulation stops when a philosopher dies of starvation or when all philosophers have eaten a specific number of times.

The project is divided into two parts:
1.  **Mandatory Part (`philo`):** Implemented using **threads** and **mutexes**. Each philosopher is a thread, and forks are protected by mutexes.
2.  **Bonus Part (`philo_bonus`):** Implemented using **processes** and **semaphores**. Each philosopher is a process, and the forks are represented by a counting semaphore.

`Note:` This repo only contemplates the mandatory part.

## Instructions

### Compilation

**Mandatory Part (Threads & Mutexes):**
To compile the mandatory part of the project:
```bash
cd philo
make
```
This will generate the `philo` executable.

### Execution

The program takes the following arguments:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

*   `number_of_philosophers`: The number of philosophers and also the number of forks.
*   `time_to_die` (in ms): If a philosopher doesn't start eating 'time_to_die' milliseconds after the beginning of their last meal (or the beginning of the simulation), they die.
*   `time_to_eat` (in ms): The time it takes for a philosopher to eat. During this time, they will need to hold two forks.
*   `time_to_sleep` (in ms): The time a philosopher will spend sleeping.
*   `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

### Usage Examples

**Example 1: The Infinite Simulation**
The philosophers should not die.
```bash
./philo 5 800 200 200
```

**Example 2: Death Simulation**
A philosopher should die after the specified time.
```bash
./philo 1 800 200 200
```

**Example 3: Meal Counter**
The simulation stops after every philosopher has eaten 7 times.
```bash
./philo 5 800 200 200 7
```

## Resources

Linux man pages

### References
*   **The Dining Philosophers Problem:** Background on the classic concurrency problem originally formulated in 1965 by Edsger Dijkstra.
*   **POSIX Threads (pthreads):** Documentation on `pthread_create`, `pthread_join`, `pthread_detach`.
*   **Mutexes:** Understanding `pthread_mutex_init`, `lock`, `unlock`, and `destroy` to prevent data races.
