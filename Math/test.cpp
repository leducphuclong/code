#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

// Function to normalize the eigenvector
VectorXd normalize(const VectorXd &vec) {
    double sum = vec.sum();
    return vec / sum;
}

// Function to find the stationary distribution
vector<VectorXd> findStationaryDistributions(const MatrixXd &P) {
    EigenSolver<MatrixXd> solver(P.transpose());

    vector<VectorXd> stationaryDistributions;
    for (int i = 0; i < solver.eigenvalues().size(); ++i) {
        if (abs(solver.eigenvalues()[i].real() - 1.0) < 1e-10 && solver.eigenvalues()[i].imag() == 0.0) {
            VectorXd eigenvector = solver.eigenvectors().col(i).real();
            stationaryDistributions.push_back(normalize(eigenvector));
        }
    }

    return stationaryDistributions;
}

int main() {
    // Define the Markov matrix
    MatrixXd P(3, 3);
    P << 0.9, 0.1, 0.0,
         0.5, 0.5, 0.0,
         0.0, 0.0, 1.0;

    cout << "Markov matrix P:" << endl;
    cout << P << endl;

    // Find the stationary distributions
    vector<VectorXd> stationaryDistributions = findStationaryDistributions(P);

    cout << "Stationary distributions:" << endl;
    for (const auto& dist : stationaryDistributions) {
        cout << dist.transpose() << endl;
    }

    return 0;
}
