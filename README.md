# Durian Selection Program

A C++ menu-driven program that allows users to select durians from Malaysia or Thailand, calculate prices based on weight, and track total purchases.

## Features

- **Country Selection**: Choose between Malaysia and Thailand
- **Durian Varieties**: 
  - Malaysia: Musang King, D24, Red Prawn
  - Thailand: Monthong, Kan Yao, Chanee
- **Weight-based Pricing**: Enter weight in kilograms for accurate pricing
- **Running Total**: Track total cost across multiple selections
- **Input Validation**: Handles invalid inputs gracefully

## Building and Running

### Prerequisites
- g++ compiler with C++11 support
- make (optional, for using Makefile)

### Build
```bash
# Using Makefile
make

# Or compile directly
g++ -std=c++11 -Wall -Wextra -O2 -o durian_selection main.cpp
```

### Run
```bash
./durian_selection
```

### Clean
```bash
make clean
```

## Usage Example

1. Select a country (1 for Malaysia, 2 for Thailand)
2. Choose a durian type from the available options
3. Enter the weight in kilograms
4. View the calculated price and running total
5. Choose to continue selecting or finish
6. View the final order summary

## Durian Pricing

### Malaysia
- Musang King: RM 55.00/kg
- D24: RM 35.00/kg  
- Red Prawn: RM 45.00/kg

### Thailand
- Monthong: ฿175.00/kg
- Kan Yao: ฿225.00/kg
- Chanee: ฿125.00/kg