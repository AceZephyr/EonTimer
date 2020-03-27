//
// Created by Dylan Meadows on 2020-03-20.
//

#ifndef EONTIMER_ENTRALINKTIMER_H
#define EONTIMER_ENTRALINKTIMER_H

#include "DelayTimer.h"
#include <memory>
#include <vector>

namespace service::timer {
    class EntralinkTimer {
    private:
        const DelayTimer *delayTimer;
    public:
        explicit EntralinkTimer(const DelayTimer *delayTimer);

        const std::shared_ptr<std::vector<int>>
        createStages(int targetDelay, int targetSecond, int calibration, int entralinkCalibration) const;

        const int createStage1(int targetDelay, int targetSecond, int calibration) const;

        const int createStage2(int targetDelay, int calibration, int entralinkCalibration) const;

        int calibrate(int targetDelay, int delayHit) const;
    };
}

#endif //EONTIMER_ENTRALINKTIMER_H
