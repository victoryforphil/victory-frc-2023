

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

class DrivetrainSubsystem : public frc2::SubsystemBase {
 public:
  DrivetrainSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  std::optional<nt::NetworkTableInstance> nt_inst_;
  std::shared_ptr<nt::NetworkTable> nt_control_table_;

  std::optional<nt::DoubleSubscriber> sub_control_yaw_;
  std::optional<nt::DoubleSubscriber> sub_control_acc_x;
  std::optional<nt::DoubleSubscriber> sub_control_acc_y;

  std::optional<ctre::phoenix::sensors::CANCoder> cancoder_;

};
