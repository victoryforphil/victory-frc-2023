// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DrivetrainSubsystem.h"

DrivetrainSubsystem::DrivetrainSubsystem() {
    // Implementation of subsystem constructor goes here.
    nt_inst_ = nt::NetworkTableInstance::GetDefault();
   

    if(!nt_inst_->IsConnected()){
        //nt_inst_ = std::nullopt;
        std::cout << "[DrivetrainSubystem] Failed to init NT instance. Not connected" << std::endl;
    }

    if(nt_inst_){
        nt_control_table_ = nt_inst_->GetTable("drivetrain/control");
        std::cout << "[DrivetrainSubsystem] Connected to drivetrain/control" << std::endl;

        sub_control_yaw_ = nt_control_table_->GetDoubleTopic("desired_yaw").Subscribe(0.0);
        sub_control_acc_x= nt_control_table_->GetDoubleTopic("desired_accel_x").Subscribe(0.0);
        sub_control_acc_y = nt_control_table_->GetDoubleTopic("desired_accel_x").Subscribe(0.0);

    }
}

void DrivetrainSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
 

  
}

void DrivetrainSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
