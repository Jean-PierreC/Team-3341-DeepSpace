/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
//test pulling
DriveTrain* Robot::m_drive;
Piston* Robot::m_piston;
HatchServo* Robot::m_hatchServo;
PressureControl* Robot::m_compressor;
AHRS* Robot::navx;
Arduino* Robot::colorSensors;
NetworkTables* Robot::cv;
CargoDoor* Robot::cargo;
OI* Robot::m_oi;

void Robot::RobotInit() {
  cs::UsbCamera camera1 = CameraServer::GetInstance()->StartAutomaticCapture();
  camera1.SetResolution(240, 180);
  camera1.SetFPS(60);
  camera1.SetBrightness(50);


  // m_chooser.AddDefault("Default Auto", &m_defaultAuto);
  // m_chooser.AddObject("My Auto", &m_myAuto);
  // frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  m_drive = new DriveTrain();
  m_piston = new Piston();
  m_hatchServo = new HatchServo();
  m_compressor = new PressureControl();
  navx = new AHRS(frc::I2C::Port::kMXP);
  colorSensors = new Arduino();  
  cv = new NetworkTables();
  cargo = new CargoDoor();
  m_oi = new OI();

  
  navx->Reset();
  navx->ResetDisplacement();
  navx->ZeroYaw();
  
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  

  //std::cout << colorSensors->readSensors() << std::endl;
  
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.  
 */
void Robot::DisabledInit() {
  
}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
  // std::string autoSelected = frc::SmartDashboard::GetString(
  //     "Auto Selector", "Default");
  // if (autoSelected == "My Auto") {
  //   m_autonomousCommand = &m_myAuto;
  // } else {
  //   m_autonomousCommand = &m_defaultAuto;
  // }



  m_autonomousCommand = m_chooser.GetSelected();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Start();
  }
}

void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

void Robot::TeleopPeriodic() {
  frc::Scheduler::GetInstance()->Run(); 
  //colorSensors->readSensors();   
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
START_ROBOT_CLASS(Robot)
#endif
