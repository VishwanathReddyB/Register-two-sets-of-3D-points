# 📌 Register Two Sets of 3D Points

This project demonstrates how to align (register) two sets of 3D points using **C++** and the **Eigen** library. It includes two methods:

- ✅ **Method 1:** SVD-Based Registration (Rotation + Translation)
- ✅ **Method 2:** Translation-Only Registration (No Rotation)

These techniques are widely used in **computer vision**, **robotics**, **3D modeling**, and **point cloud alignment**.

---

## 📂 Project Structure

Register-two-sets-of-3D-points/ 
│
├── .vscode/ # VSCode configuration (optional) 
├── eigen-3.4.0/ # Eigen library folder
├── README.md # Project documentation │ 
├── test.cpp # Method 1: SVD-based registration 
├── test.exe # Compiled executable (Windows) │ 
├── test1.cpp # Method 2: Translation-only registration 
└── test1.exe # Compiled executable (Windows)

---

## 🧠 Methods

### 🔹 Method 1: SVD-Based Registration

This method finds the best transformation (rotation + translation) that aligns one point set to another.

**Steps:**
1. Compute the centroids of both point sets.
2. Center both sets by subtracting the centroids.
3. Compute the **covariance matrix** `H`.
4. Apply **Singular Value Decomposition (SVD)** on `H`.
5. Compute the rotation matrix `R = V * Uᵀ`.
6. Correct reflection (if needed).
7. Compute the translation vector `t = centroid2 - R * centroid1`.
8. Apply rotation and translation to all points in Set 1.

📄 **File:** `test.cpp`

---

### 🔹 Method 2: Translation-Only Registration

This simplified approach shifts Set 1 to match the position of Set 2 without rotating it.

**Steps:**
1. Compute the centroids of both point sets.
2. Calculate the translation vector `t = centroid2 - centroid1`.
3. Apply the translation to each point in Set 1.

📄 **File:** `test1.cpp`

---

## 🛠️ Dependencies

| Dependency     | Version   | Description                                   |
|----------------|-----------|-----------------------------------------------|
| C++ Compiler   | C++11+    | Required for Eigen and modern C++ features    |
| Eigen          | 3.4.0     | C++ linear algebra library (header-only)      |

### ⚙️ Install Eigen

1. Download from [https://eigen.tuxfamily.org](https://eigen.tuxfamily.org)
2. Extract and place it in the `eigen-3.4.0/` directory.
3. Include it like:

#include <eigen-3.4.0/Eigen/Dense>


⚙️ **Compilation Instructions**

🔧 Compile with g++
Method 1: SVD-based (test.cpp)

g++ test.cpp -I eigen-3.4.0 -o test
./test

Method 2: Translation-only (test1.cpp)

g++ test1.cpp -I eigen-3.4.0 -o test1
./test1
On Windows (Command Prompt)

g++ test.cpp -I eigen-3.4.0 -o test.exe
test.exe
📈 Output Example

Average of Set 1: 4 5 6
Average of Set 2: 5 2 7

Rotation Matrix:
1  0  0
0  0 -1
0  1  0

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

🧪 **Applications**
Aligning 3D scans from different angles

Sensor calibration in robotics

Merging LIDAR point clouds

Pose estimation from keypoints

🧾**License**
This project is open-source and intended for educational/demo purposes.
Use it freely for academic or personal projects.

✍️**Author**
Submitted as part of a technical coding assignment
Author: Vishwanath Reddy B
Date: April 2025
