#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */

  VectorXd rmse(4);
  rmse << 0,0,0,0;

  if (estimations.size() == 0 || ground_truth.size() == 0) {
    cout << "RMSE: Estimation or Ground Truth matrix is empty." << endl;
    return rmse;
  }

  if (estimations.size() != ground_truth.size()) {
    cout << "RMSE: Estimation and Ground Truth matrices are different sizes." << endl;
    return rmse;
  }

  // calculate residual
  for (int i = 0; i < estimations.size(); ++i) {
    VectorXd res = (estimations[i] - ground_truth[i]);
    res = res.array() * res.array();
    rmse += res;
  }

  // mean
  rmse = rmse/estimations.size();

  // square root
  rmse = rmse.array().sqrt();

  cout << "RMSE:" << endl;
  cout << rmse << endl;

  return rmse;
}
