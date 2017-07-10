/**
 * @file L239D_motor_driver.h
 * @brief Motor driver for the L239D chip
 * @author Javier Perez
 */

# include "motor_driver.h"

namespace Robotcar
{
  class Motor : public MotorDriver
  {
  public:
    /*
     * @brief Class constuctor
     * @param number the DC motor number to control
     */
    Motor(int number)
      : MotorDriver(), motor(number), currentSpeed(0)
      {
      }
    void setSpeed(int speed)
    {
      currentSpeed = speed;
      if (speed >= 0) {
	motor.setSpeed(speed);
	motor.run(FORWARD);
      }
      else {
	motor.setSpeed(speed);
	motor.run(BACKWARD);
      }
    }

    int getSpeed() const
    {
      return currentSpeed;
    }

  private :
    AF_DCMotor motor;
    int currentSpeed;
  };
};
