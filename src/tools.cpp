#include "tools.h"
#include <iostream>


using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  
    VectorXd error_current(estimations[0].size());  // same size vector 
    VectorXd error_sum(estimations[0].size());  // same size vector 
    VectorXd rmse(estimations[0].size());  // same size vector 
  
  	// Exception checking, ensure same size:
    if (estimations.size() != ground_truth.size()
      || estimations.size() == 0 || estimations[0].size() != ground_truth[0].size() )     {
    cout << "Invalid estimation or ground_truth data" << endl;
    return rmse;
    }


    for (unsigned int i = 0; i < estimations.size(); ++i) {

        error_current = (estimations[i] - ground_truth[i]).array().pow(2);
        if (i == 0) {
            error_sum = error_current;
        }
        else {
            error_sum = error_sum + error_current;
        }
    }
    rmse  = (error_sum / estimations.size()).array().sqrt();
  
  	return rmse;
  
}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
  
  MatrixXd Hj(3,4);
    
  //recover state parameters
  float px = x_state(0);
  float py = x_state(1);
  float vx = x_state(2);
  float vy = x_state(3);
    
  // Some re-used equations for matrix below
  float c1 = px * px + py * py;
  float c2 = sqrt(c1);
  float c3 = c1 * c2;
  
  //check division by zero
  if(fabs(c1) < 0.0001){
    std::cout << "Function CalculateJacobian() has Error: Division by Zero" << std::endl;
    return Hj; // out of function
  }
    
  //compute the Jacobian matrix
  Hj << (px/c2), (py/c2), 0, 0,
        -(py/c1), (px/c1), 0, 0,
        (py*(vx*py - vy*px))/c3, (px*(vy*px - vx*py))/c3, px/c2, py/c2;
    
  //return the matrix
  return Hj;
  
  
}
