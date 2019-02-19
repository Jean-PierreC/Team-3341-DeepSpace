/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "Commands/Piston_Extend.h"
#include "Commands/Piston_Off.h"
#include "Commands/Piston_Retract.h"
#include "Commands/Servo_Extend.h"
#include "Commands/Servo_Retract.h"
#include "Commands/Hatch_Extend.h"
#include "Commands/Hatch_Retract.h"
#include "Commands/Compressor_On.h"
#include "Commands/Compressor_Off.h"
#include "Commands/readColorSensors.h"
#include "Commands/TurnToAngle.h"
#include "Commands/DriverTurn.h"
#include "Commands/MoveCargoDoor.h"
#include "Commands/ResetEncoder.h"
#include "Robot.h"
#include "RobotMap.h"
#include <frc/WPILib.h>

OI::OI() : leftJoy(new Joystick(0)), rightJoy(new Joystick(1)),
servoExtendButton(new JoystickButton(rightJoy, 3)),
/*hatchRetractButton(new JoystickButton(rightJoy, 1)),*/ 
pistonOffButton(new JoystickButton(rightJoy, 8)),
compressorOnButton(new JoystickButton(rightJoy, 10)), 
compressorOffButton(new JoystickButton(rightJoy, 9)),
readSensorsButton(new JoystickButton(leftJoy, 5)),
cargoStick(new Joystick(2)),
pistonExtendButton(new JoystickButton(cargoStick, 1)), 
pistonRetractButton(new JoystickButton(cargoStick, 2)),

lDriveTurn(new JoystickButton(leftJoy, 1)),
<<<<<<< HEAD
rDriveTurn(new JoystickButton(rightJoy, 1))
//holdCargo(new JoystickButton(cargoStick, 9)),
//resetCargo(new JoystickButton(cargoStick, 10)), resetEncoder(new JoystickButton(cargoStick, 1)), 
//releaseCargoRocket(new JoystickButton(cargoStick, 7)),
//releaseCargoShuttle(new JoystickButton(cargoStick, 8))
=======
rDriveTurn(new JoystickButton(rightJoy, 1)),
holdCargo(new JoystickButton(cargoStick, 5)),
resetCargo(new JoystickButton(cargoStick, 3)),
releaseCargoRocket(new JoystickButton(cargoStick, 4)),
releaseCargoShuttle(new JoystickButton(cargoStick, 6))
>>>>>>> bc76d93678dcc02274c8cf6c171e7d54028518a2
{
  // Process operator interface input here.
  //hatchExtendButton->WhenPressed(new Hatch_Extend());
  pistonExtendButton->WhenPressed(new Hatch_Extend());
  pistonRetractButton->WhenPressed(new Hatch_Retract());
  servoExtendButton->ToggleWhenPressed(new Servo_Extend());

	//hatchRetractButton->WhenPressed(new Hatch_Retract());
  pistonOffButton->WhenPressed(new Piston_Off());

  compressorOnButton->WhenPressed(new Compressor_On());
  compressorOffButton->WhenPressed(new Compressor_Off());

  readSensorsButton->WhenPressed(new readColorSensors());
  
  lDriveTurn->WhileActive(new DriverTurn(0.3));
  rDriveTurn->WhileActive(new DriverTurn(-0.3));

  holdCargo->ToggleWhenPressed(new
   MoveCargoDoor(0));
  resetCargo->ToggleWhenPressed(new MoveCargoDoor(-15));

  releaseCargoRocket->ToggleWhenPressed(new MoveCargoDoor(30));
  releaseCargoShuttle->ToggleWhenPressed(new MoveCargoDoor(45));

  //resetEncoder->WhenPressed(new ResetEncoder());
}

Joystick* OI::getLeft(){
  return leftJoy;
}

Joystick* OI::getRight(){
  return rightJoy;
}

Joystick* OI::getBucket(){
  return cargoStick;
}