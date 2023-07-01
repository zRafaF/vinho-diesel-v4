// Copyright 2023 Rafael Farias
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include <Arduino.h>

#include "GlobalConsts.h"
#include "QuickPID.h"
#include "SensorArray.h"

class LineFollower {
   public:
    LineFollower(SensorArray& sensArrRef);

   private:
    void run();

    /*
        Receives an array of booleans representing the current
        reading of each sensor and returns the average of them.
    */
    float calculateInput(bool sensorsDigital[N_OF_SENSORS]);

    SensorArray* sensorArray;
    QuickPID quickPID;

    float setPoint = 4.5f;  // Target
    float input;            // PID input
    float output;           // PID output

    float Kp = 2, Ki = 5, Kd = 1;
};

#endif  // LINE_FOLLOWER_H