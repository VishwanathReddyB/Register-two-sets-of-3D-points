#include <iostream>
#include <vector>
#include <Eigen\Dense> 

using namespace std;
using namespace Eigen;

int main() {
    // Define two sets of 3D points
    vector<Vector3d> pointSet1 = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    vector<Vector3d> pointSet2 = {
        {2.0, 4.0, 6.0},
        {5.0, 7.0, 9.0},
        {8.0, 10.0, 12.0}
    };

    // Step 1: Calculate the centroids of each set
    Vector3d centroid1 = Vector3d::Zero();
    Vector3d centroid2 = Vector3d::Zero();

    for (size_t i = 0; i < pointSet1.size(); ++i) {
        centroid1 += pointSet1[i];
        centroid2 += pointSet2[i];
    }

    centroid1 /= pointSet1.size();
    centroid2 /= pointSet2.size();

    cout << "Centroid of Set 1: " << centroid1.transpose() << endl;
    cout << "Centroid of Set 2: " << centroid2.transpose() << endl;

    // Step 2: Calculate translation vector (shift)
    Vector3d translation = centroid2 - centroid1;

    cout << "Translation Vector: " << translation.transpose() << endl;

    // Step 3: Apply translation to pointSet1
    cout << "\nTransformed Set 1:\n";
    for (size_t i = 0; i < pointSet1.size(); ++i) {
        Vector3d transformedPoint = pointSet1[i] + translation;
        cout << "Point " << i << ": " << transformedPoint.transpose() << endl;
    }

    cout << "\nOriginal Set 2:\n";
    for (size_t i = 0; i < pointSet2.size(); ++i) {
        cout << "Point " << i << ": " << pointSet2[i].transpose() << endl;
    }

    return 0;
}
