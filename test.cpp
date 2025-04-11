#include <iostream>
#include <vector>  
#include <C:\Users\vishw\OneDrive\Desktop\htic\eigen-3.4.0\Eigen\Dense> // Matrix math

using namespace std;
using namespace Eigen;

int main() {
    // Step 1: Define the two sets of 3D points
    vector<Vector3d> pointSet1 = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    vector<Vector3d> pointSet2 = {
        {2.0, 1.0, 4.0},
        {5.0, 2.0, 7.0},
        {8.0, 3.0, 10.0}
    };

    // Step 2: Find the average (center) of each set
    Vector3d average1(0, 0, 0), average2(0, 0, 0);

    for (size_t i = 0; i < pointSet1.size(); i++) {
        average1 += pointSet1[i];
        average2 += pointSet2[i];
    }

    average1 /= pointSet1.size();
    average2 /= pointSet2.size();

    // Step 3: Shift all points so the average becomes (0,0,0)/(centering the points)
    MatrixXd pointsCentered1(3, pointSet1.size());
    MatrixXd pointsCentered2(3, pointSet2.size());

    for (size_t i = 0; i < pointSet1.size(); i++) {
        pointsCentered1.col(i) = pointSet1[i] - average1;
        pointsCentered2.col(i) = pointSet2[i] - average2;
    }

    // Step 4: Create matrix H using the centered points (covariance)
    Matrix3d H = pointsCentered1 * pointsCentered2.transpose();

    // Step 5: Use SVD to get the best rotation
    JacobiSVD<Matrix3d> svd(H, ComputeFullU | ComputeFullV);
    Matrix3d U = svd.matrixU();
    Matrix3d V = svd.matrixV();
    Matrix3d rotation = V * U.transpose();

    // Fix for incorrect reflection
    if (rotation.determinant() < 0) {
        V.col(2) *= -1;
        rotation = V * U.transpose();
    }

    // Step 6: Find translation to align the centers
    Vector3d translation = average2 - rotation * average1;

    // Step 7: Print results
    cout << "Rotation Matrix:\n" << rotation << endl;
    cout << "Translation Vector:\n" << translation.transpose() << endl;

    // Step 8: Show how the transformed Set 1 looks
    cout << "\nSet 1 after transformation:\n";
    for (size_t i = 0; i < pointSet1.size(); i++) {
        Vector3d newPoint = rotation * pointSet1[i] + translation;
        cout << "Point " << i << ": " << newPoint.transpose() << endl;
    }

    // Compare with Set 2
    cout << "\nOriginal Set 2:\n";
    for (size_t i = 0; i < pointSet2.size(); i++) {
        cout << "Point " << i << ": " << pointSet2[i].transpose() << endl;
    }

    return 0;
}
