### Dining Philosophers Problem
This is a solution to the Dining Philosophers Problem, where a group of philosophers sit at a round table, alternating between eating, thinking, and sleeping. The goal is to ensure that no philosopher starves while following specific rules.

## Problem Overview
One or more philosophers sit at a round table.\n
A large bowl of spaghetti is placed in the middle of the table.\n
Philosophers alternate between three states: eating, thinking, and sleeping.\n
While eating, a philosopher requires both the left and right forks.\n
The simulation stops when a philosopher dies of starvation.\n
The rules for philosopher behavior are as follows:\n
While eating, they are not thinking nor sleeping.\n
While thinking, they are not eating nor sleeping.\n
While sleeping, they are not eating nor thinking.\n
When done eating, they put both forks back on the table and start sleeping.\n
Once awake, they start thinking again.\n
Every philosopher needs to eat and should never starve.\n
Philosophers do not communicate with each other.\n
Philosophers are unaware if another philosopher is close to starving.\n
The ultimate goal is for philosophers to avoid starvation.\n

## Program Requirements
This repository contains solutions for the mandatory and bonus parts of the assignment.\n
Both programs adhere to the following rules:\n
No Global Variables: Global variables are forbidden.

## Input Arguments:
**number_of_philosophers:** Number of philosophers and forks.\n
**time_to_die (in milliseconds):** Time since the last meal or start of the simulation after which a philosopher dies.\n
**time_to_eat (in milliseconds):** Time required for a philosopher to eat (holding two forks).\n
**time_to_sleep (in milliseconds):** Time a philosopher spends sleeping.\n
***number_of_times_each_philosopher_must_eat (optional):*** If specified, simulation stops when all philosophers have eaten this many times.\n

## Philosopher Positions:
Philosopher 1 sits next to philosopher number_of_philosophers.
All other philosophers sit between philosopher N-1 and N+1.
## Logs Format:
All state changes of a philosopher must follow this format:

*timestamp_in_ms X has taken a fork*

*timestamp_in_ms X is eating

*timestamp_in_ms X is sleeping

*timestamp_in_ms X is thinking

*timestamp_in_ms X died*

***Replace timestamp_in_ms with the current timestamp in milliseconds and X with the philosopher number.***
Ensure messages are not mixed up!!
A death announcement should occur within 10ms of the philosopher's actual death.

## Usage
Mandatory Part
To run the mandatory part of the assignment, use the following command:
```./philo <philo_nbr> <time_to_die> <time_to_eat> <time_to_sleep> ( <number_of_times_each_philosopher_must_eat>)```

## Example:
```./philo 190 900 200 200 10```

## Note:
These programs ensure that philosophers can eat **without starving** and that the simulation **stops when all have eaten a specified number of times or when a philosopher dies**.

Remember, the primary goal is for philosophers to **avoid starvation!**
