// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DrivetrainControlSystem.h"

DrivetrainControlSystem::DrivetrainControlSystem()
{
    // Implementation of subsystem constructor goes here.
    nt_inst_ = nt::NetworkTableInstance::GetDefault();

    if (!nt_inst_->IsConnected())
    {
        //nt_inst_ = std::nullopt;
        std::cout << "[DrivetrainControlSystem] Failed to init NT instance. Not connected" << std::endl;
    }

    if (nt_inst_)
    {
        nt_control_table_ = nt_inst_->GetTable("drivetrain/control");
        std::cout << "[DrivetrainControlSystem] Connected to drivetrain/control" << std::endl;

        pub_control_yaw_ = nt_control_table_->GetDoubleTopic("desired_yaw").Publish();
        pub_control_acc_x = nt_control_table_->GetDoubleTopic("desired_accel_x").Publish();
        pub_control_acc_y = nt_control_table_->GetDoubleTopic("desired_accel_x").Publish();
    }
}

void DrivetrainControlSystem::Periodic()
{
    // Implementation of subsystem periodic method goes here.

}

frc2::CommandPtr DrivetrainControlSystem::SetYawCommand(const double yaw) {
  // implicitly require `this`
  return this->RunOnce(
      [this, yaw] {pub_control_yaw_->Set(yaw); });
}
frc2::CommandPtr DrivetrainControlSystem::SetAccelerationCommand(const double x, const double y) {
  // implicitly require `this`
  return this->RunOnce(
      [this, x, y] {
        pub_control_acc_x->Set(x); 
        pub_control_acc_y->Set(y);
      });
}
void DrivetrainControlSystem::SimulationPeriodic()
{
    // Implementation of subsystem simulation periodic method goes here.
}
