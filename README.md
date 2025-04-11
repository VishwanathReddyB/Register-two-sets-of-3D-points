
# Register Two Sets of 3D Points

This project demonstrates how to align two sets of 3D points using two different methods:

1. SVD-Based Registration – Includes rotation and translation  
2. Translation-Only Registration – Only shifts the points  

---

## Install Eigen

1. Download Eigen from https://eigen.tuxfamily.org  
2. Extract it and place it in the `eigen-3.4.0/` directory  
3. Include the header like this in your code:
   #include <eigen-3.4.0/Eigen/Dense>

---


## 📁 Project Structure

```
Register-two-sets-of-3D-points/
├── .vscode/              # VSCode configuration (optional)
├── eigen-3.4.0/          # Eigen library folder
├── README.md             # Project documentation
├── test.cpp              # Method 1: SVD-based registration
├── test.exe              # Compiled executable (Windows) - Method 1
├── test1.cpp             # Method 2: Translation-only registration
└── test1.exe             # Compiled executable (Windows) - Method 2
```


---

## ⚙️ Compilation Instructions

### Method 1: SVD-Based Registration (test.cpp)
```
g++ test.cpp -I eigen-3.4.0 -o test
./test
```
### Method 2: Translation-Only Registration (test1.cpp)
```
g++ test1.cpp -I eigen-3.4.0 -o test1
./test1
```
### On Windows (Command Prompt)
```
g++ test.cpp -I eigen-3.4.0 -o test.exe
g++ test1.cpp -I eigen-3.4.0 -o test1.exe
```
---

## 📈 Output Example
```
Average of Set 1: 4 5 6  
Average of Set 2: 5 2 7  

Rotation Matrix:
1  0  0  
0 -1  0  
0  0  1  

Translation Vector:
1 -3 1  

Transformed Points from Set 1:
Point 0: 2 1 4  
Point 1: 5 2 7  
Point 2: 8 3 10  

Original Set 2:
Point 0: 2 1 4  
Point 1: 5 2 7  
Point 2: 8 3 10
```
---

## 🧪 Applications

- Aligning 3D scans from different angles  
- Sensor calibration in robotics  
- Augmented reality object placement  
- Object tracking and motion capture

---



## 🧾 License

This project is provided for educational and demonstration purposes.

## ✍️ Author

Submitted as part of a technical coding assignment

Author:Vishwanath Reddy B

Date: April 2025
