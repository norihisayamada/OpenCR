/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Darby Lim */

#ifndef OPEN_MANIPULATOR_CHAIN_H_
#define OPEN_MANIPULATOR_CHAIN_H_

// Necessary library
#include <OpenManipulator.h>

// User-defined library
#include <OMKinematics.h>
#include <OMDynamixel.h>
#include <OMPath.h>

#define WORLD 0
#define COMP1 1
#define COMP2 2
#define COMP3 3
#define COMP4 4
#define TOOL 5

#define NONE -1

#define X_AXIS OM_MATH::makeVector3(1.0, 0.0, 0.0)
#define Y_AXIS OM_MATH::makeVector3(0.0, 1.0, 0.0)
#define Z_AXIS OM_MATH::makeVector3(0.0, 0.0, 1.0)

Manipulator chain;

void initConnect()
{

}

void initManipulator()
{
  OPEN_MANIPULATOR::MANAGER::addWorld(&chain,
                                      WORLD,
                                      COMP1);

  OPEN_MANIPULATOR::MANAGER::addComponent(&chain,
                                          COMP1,
                                          WORLD,
                                          COMP2,
                                          OM_MATH::makeVector3(-0.2016, 0.0, 0.017),
                                          Eigen::Matrix3f::Identity(3, 3),
                                          Z_AXIS,
                                          1);

  OPEN_MANIPULATOR::MANAGER::addComponent(&chain,
                                          COMP2,
                                          COMP1,
                                          COMP3,
                                          OM_MATH::makeVector3(0.0, 0.0, 0.058),
                                          Eigen::Matrix3f::Identity(3, 3),
                                          Y_AXIS,
                                          2);

  OPEN_MANIPULATOR::MANAGER::addComponent(&chain,
                                          COMP3,
                                          COMP2,
                                          COMP4,
                                          OM_MATH::makeVector3(0.024, 0.0, 0.128),
                                          Eigen::Matrix3f::Identity(3, 3),
                                          Y_AXIS,
                                          3);

  OPEN_MANIPULATOR::MANAGER::addComponent(&chain,
                                          COMP4,
                                          COMP3,
                                          TOOL,
                                          OM_MATH::makeVector3(0.124, 0.0, 0.0),
                                          Eigen::Matrix3f::Identity(3, 3),
                                          Y_AXIS,
                                          4);
  OPEN_MANIPULATOR::MANAGER::addTool(&chain,
                                     TOOL,
                                     COMP4,
                                     OM_MATH::makeVector3(0.0536, 0.0, 0.0),
                                     Eigen::Matrix3f::Identity(3, 3),
                                     5,
                                     0.001); // Change unit to `mm`

  OM_KINEMATICS::CHAIN::forward(&chain, COMP1);
  OPEN_MANIPULATOR::MANAGER::checkManipulatorSetting(&chain);
}

#endif //OPEN_MANIPULATOR_CHAIN_H_