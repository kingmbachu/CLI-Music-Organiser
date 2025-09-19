# Playlist Shuffler and Sorter (C)

## Overview

This project implements a **playlist shuffler and sorter** in C.  
It provides functions to input songs, sort them alphabetically, and shuffle them while respecting additional constraints to avoid repetition.  

---

## Implementation Details

### 1. Input Function
- **Function used:** `fgets()`  
- **Reasoning:**  
  - Allows specifying a maximum number of characters to prevent buffer overflow.  
  - Unlike `scanf()`, it reads the entire line (including spaces), which is useful for multi-word song names.  
  - Reads the newline character (`\n`), which can then be removed for cleaner input handling.  

---

### 2. Sorting Algorithm
- **Algorithm used:** **QuickSort** via the standard library function `qsort()`.  
- **Details:**  
  - QuickSort has an average-case time complexity of **O(n log n)**, making it efficient for sorting.  
  - Implemented with a custom comparison function using `strcmp()` to sort songs alphabetically.  
  - Straightforward to use and suitable for relatively small playlists.  

---

### 3. Shuffling Algorithm
- **Algorithm used:** **Modified Fisher-Yates Shuffle**  
- **Goal:** Ensure that no song repeats within 5 positions in the shuffled playlist.  

#### Steps:
1. **Duplicate the List**  
   - Each song is duplicated, creating an extended list.  
   - Provides enough entries to shuffle while respecting the non-repetition rule.  

2. **Apply Fisher-Yates Shuffle**  
   - Classic in-place shuffle algorithm.  
   - Iterates backward through the array, swapping each element with a randomly chosen element before it.  

3. **Ensure No Repetition Within 5 Positions**  
   - After shuffling, the algorithm checks that no song appears in the same 5-position window.  
   - If a conflict is found, the shuffle reorders until the constraint is satisfied.  

4. **Output the Shuffled Playlist**  
   - The final shuffled playlist is printed to the console.  

---

## Algorithms Used

- **QuickSort (`qsort`)** → For efficient alphabetical sorting.  
- **Fisher-Yates Shuffle** → For unbiased random shuffling.  
- **Custom Repetition Constraint** → Ensures no song repeats within the last 5 positions.  

---

## Conclusion

This program successfully implements:  
- A safe and flexible **input mechanism** with `fgets()`.  
- A reliable and efficient **sorting algorithm** with `qsort()`.  
- A robust **shuffling mechanism** using Fisher-Yates shuffle, extended to handle non-repetition rules.  

The combination of these approaches ensures both efficiency and correctness in handling playlist sorting and shuffling.  

Clone the repository and run the executable file main:


## Installation & Usage

```bash
git clone https://github.com/kingmbachu/CLI-Music-Organiser.git
cd CLI-Music-Organiser
chmod +x main
./main
