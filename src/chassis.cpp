#include "main.h"
#include "chassis.hpp"
#include "pros/misc.h"

pros::Motor frontRightDriveMotor(1, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor frontLeftDriveMotor(2, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor backRightDriveMotor(3, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor backLeftDriveMotor(4, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_DEGREES);

void chassisMoveIndividuals(int FRight, int FLeft, int BRight, int BLeft) {
    // Function to set voltage of each motor individually, used in opcontrol
    // This function deals in voltage, and takes arguments from -127 to 127
    frontRightDriveMotor.move(std::min(FRight, 90));
    frontLeftDriveMotor.move(std::min(FLeft, 90));
    backRightDriveMotor.move(std::min(BRight, 90));
    backLeftDriveMotor.move(std::min(BLeft, 90));
}