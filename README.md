# Extended Kalman Filter Project 

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


Note that the RMSE value is very close to that of only using Lidar measurements but the RMSE value is higher. This is because Radar Sensor is affected by more noise than the Lidar Sensor. Radar Sensor provides a non-linear function in our calculations, the linearisation process of computing the Jacobian Matrix itself is an example of extra noise being incorporated into the calculation due to the slight inaccuracy. This is the reason why Unscented Kalman Filter (UKF) has been recommended to be use for non-linear cases.


#### Lidar and Radar (Sensor fusion)

An example of the car tracking the bicycle using both Lidar and Radar sensor measurements:



Note that the RMSE value is the lowest when both sensor data are fused as this reduces the uncertainty in our sensor measurements which provides better estimation on the states of the bicycle. 


## Discussion

As mentioned in the Radar Sensor Measurement section, UKF are better than EKF when non-linear equations needs to be computed. Please read this paper [**HERE**](https://www.seas.harvard.edu/courses/cs281/papers/unscented.pdf) to gain the understanding and proves. Therefore, I am looking forward to implementing UKF soon for my next project!

It has been shown that when Lidar and Radar sensors are both used together, the RMSE value is the lowest. The estimation provided was the best because by fusing both sensor data together, the sensor data can in a way "cross-check" each other to lower the overall uncertainty. An analogy would be us  opening two eyes at once instead of opening one at all times when we navigate around the world. With two eyes open, we are more confident with navigating around the world.

Head over to [HERE](https://github.com/udacity/CarND-Extended-Kalman-Filter-Project) to try out the project yourself. All the best and have a great day!
