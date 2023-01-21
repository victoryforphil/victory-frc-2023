

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/DoubleTopic.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

#include <optional>
#include <memory>
#include <iostream>

class DrivetrainControlSystem : public frc2::SubsystemBase
{
public:
	DrivetrainControlSystem();

	/**
	 * Will be called periodically whenever the CommandScheduler runs.
	 */
	void Periodic() override;

	/**
	 * Will be called periodically whenever the CommandScheduler runs during
	 * simulation.
	 */
	void SimulationPeriodic() override;

	frc2::CommandPtr SetYawCommand(const double yaw);
	frc2::CommandPtr SetAccelerationCommand(const double x, const double y);

private:
	// Components (e.g. motor controllers and sensors) should generally be
	// declared private and exposed only through public methods.
	bool pending_change = false;

	std::optional<nt::NetworkTableInstance> nt_inst_;
	std::shared_ptr<nt::NetworkTable> nt_control_table_;

	std::optional<nt::DoublePublisher> pub_control_yaw_;
	std::optional<nt::DoublePublisher> pub_control_acc_x;
	std::optional<nt::DoublePublisher> pub_control_acc_y;
};
