# Extended Kalman Filter Project 

*Self-Driving Car Engineer Nanodegree Program
---

## Objective

Utilising Lidar and Radar sensor data measurements with the Extended Kalman Filter to estimate the position of the bicycle and follow it. The usage of the EKF is to incorporate the uncertainty in the sensor measurements and fuse multiple sensor data to produce a more precise estimation that is closer to the ground truth. 


---

## Results 

#### No Sensor 
An example of the car tracking the bicycle without use any sensor data:




Note that the Root Mean Square Error (RMSE) value for the states are very high as we are not providing any estimation values yet. The RMSE value is an indication of how far off the estimated value are from the ground truth. It is obvious that without any sensor feedback, the car is unable to determine anything useful.

##### Lidar only

*Note that the **RED** circle is the Lidar measurements while the **BLUE** is the Radar measurements. **GREEN** is the estimation of the bicycle position.

An example of the car tracking the bicycle using only Lidar sensor measurements:


Note that the RMSE value has dropped tremendously as we are now estimating the states of bicycle with sensor feedback.

#### Radar only

An example of the car tracking the bicycle using only Radar sensor measurements:


Note that the RMSE value is very close to that of only using Lidar measurements but the RMSE value is higher. This is because Radar Sensor is affected by more noise than the Lidar Sensor. Radar Sensor provides a non-linear function in our calculations, the linearisation process of computing the Jacobian Matrix itself is an example of extra noise being incorporated into the calculation. This is the reason why Unscented Kalman Filter has been recommended to be use for non-linear cases.


#### Lidar and Radar (Sensor fusion)

An example of the car tracking the bicycle using both Lidar and Radar sensor measurements:


Note that the RMSE value is the lowest when both sensor data are fused as this reduces the uncertainty in our sensor measurements which provides better estimation on the states of the bicycle. 


## Discussion
