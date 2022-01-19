#include "PID.h"
#include <iostream>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;

  this->p_error = 0; 
  this->i_error = 0;
  this->d_error = 0;
}

void PID::UpdateError(double cte) {
  
  std::cout << p_error << " " << i_error << " " << d_error << "\n";
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {

  return Kp * p_error + Kd * d_error + Ki * i_error; 
}