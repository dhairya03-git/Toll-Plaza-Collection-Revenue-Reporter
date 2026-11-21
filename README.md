# Toll Plaza Collection & Revenue Reporter

## About the Project
The Toll Plaza Collection & Revenue Reporter is a C++ console-based application designed to manage toll booth transactions and calculate revenue.

## Features
- Record vehicle transactions.
- Supports Car, Bike, Bus and Truck.
- Automatic toll calculation.
- 50% return journey discount.
- Lane-wise revenue reports.
- Vehicle-type-wise revenue reports.
- Function overloading for different reports.
- Static member to count total vehicles.
- File handling to save shift reports.

## Technologies Used
- C++
- Structures and Arrays
- Classes and Objects
- Function Overloading
- Static Members
- File Handling

## Toll Rates

| Vehicle | Toll |
|---|---:|
| Bike | ₹50 |
| Car | ₹100 |
| Bus | ₹200 |
| Truck | ₹300 |

Return Journey Discount: 50%

## How to Run

1. Clone or download this repository.
2. Open the project folder in VS Code.
3. Compile the program:

```bash
g++ toll.cpp -o toll
```

4. Run:

```bash
./toll
```

For Windows PowerShell:

```powershell
.\toll.exe
```

## Output
The program generates `shift_report.txt` containing transaction details and total shift revenue.

## Project Type
C++ Mini Project – Transport / Smart City

## Author
Your Name
