#include "chassis.hpp"
#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	while (true) {
		// pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                  (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                  (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

        int rightX = master.get_analog(ANALOG_RIGHT_X);
        int rightY = master.get_analog(ANALOG_RIGHT_Y);
        int leftX = master.get_analog(ANALOG_LEFT_X);
        int leftY = master.get_analog(ANALOG_LEFT_Y);

        if (abs(rightX) < 5) rightX = 0; 
        if (abs(rightY) < 5) rightY = 0; 
        if (abs(leftX) < 5) leftX = 0; 
        if (abs(leftY) < 5) leftY = 0; 
        rightX = (rightX * 1);
        rightY = (rightY * 1);
        leftX = (leftX * 1);
        leftY = (leftY * 1);
        
        chassisMoveIndividuals(rightY, leftY, rightY, leftY);


		pros::delay(20);
	}
}
