/**
 * @file motor_driver.h
 * @brief Motor device driver definition based on Miguel Grimberg's one
 * @author Javier Perez
 */

namespace Robotcar
{
  class MotorDriver
  {
  public:
    /**
     * @brief Change the speed of motor
     * @param speed The new speed of motor
     *  Valid values are between -255 and 255
     *  Use positive values to run motor forward
     *  negative values to run it backwards or
     *  zero to stop motor
     */
    virtual void setSpeed(int speed) = 0;

    /**
     * @brief Return the current speed of motor
     * @return Current speed of motor in range (-255, 255)
     */
    virtual int getSpeed() const = 0;
  };
};
