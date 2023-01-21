

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/DoubleTopic.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <rev/CANSparkMax.h>
#include <ctre/phoenix/sensors/CANCoder.h>


#include <optional>
#include <memory>
#include <iostream>

class SwerveModule {
 public:
  SwerveModule();

  

 private:

    std::optional<ctre::phoenix::sensors::CANCoder> abs_encoder_;
    std::optional<rev::CANSparkMax> drive_motor_;
    std::optional<rev::CANSparkMax> steer_motor_;

};
