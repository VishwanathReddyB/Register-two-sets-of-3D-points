# Register-two-sets-of-3D-points
# 3D Point Set Registration in C++

This repository contains two C++ implementations for aligning (registering) two sets of 3D points:

- **Method 1: SVD-Based Registration**
- **Method 2: Translation-Only Registration**

These methods are commonly used in computer vision, 3D reconstruction, robotics, and motion tracking applications.

---

## 🚀 Overview

Given two sets of corresponding 3D points, the goal is to transform Set 1 so it aligns as closely as possible with Set 2.  
This transformation may include translation and/or rotation.

---

## 📂 Contents

| File | Description |
|------|-------------|
| `svd_registration.cpp` | Implements registration using rotation and translation (via SVD) |
| `translation_only.cpp` | Implements registration using only translation |
| `README.md` | Project overview and instructions |
| `results/` | Output logs and visualizations (optional) |
| `docs/` | Includes a detailed PDF explanation and algorithm |

---

## 🧠 Method 1: SVD-Based Registration

This method calculates both **rotation** and **translation** using the **Singular Value Decomposition (SVD)** technique.

### Steps:
1. Compute centroids of both point sets.
2. Center both sets by subtracting their centroids.
3. Construct a covariance matrix `H`.
4. Perform SVD on `H`: `H = UΣVᵗ`
5. Compute rotation: `R = VUᵗ`
6. Compute translation: `T = centroid2 - R * centroid1`
7. Apply `R` and `T` to Set 1.

This method minimizes the root mean square error between corresponding points.

---

## ➡️ Method 2: Translation-Only Registration

This is a simplified version of registration that only shifts Set 1 to match the centroid of Set 2.

### Steps:
1. Compute centroids of both sets.
2. Compute translation: `T = centroid2 - centroid1`
3. Apply `T` to all points in Set 1.

It is fast but assumes both sets are already oriented similarly.

---

## 📦 Dependencies

- [Eigen](https://eigen.tuxfamily.org/) (for matrix operations)

> ⚠️ Make sure you update the Eigen include path in your code as needed.

---

## 🛠️ Build & Run

### Compile:

```bash
g++ svd_registration.cpp -I /path/to/eigen -o svd_registration
g++ translation_only.cpp -I /path/to/eigen -o translation_only
