//
// Created by Dylan Meadows on 2020-03-09.
//

#ifndef EONTIMER_GEN4TIMERPANE_H
#define EONTIMER_GEN4TIMERPANE_H

#include <QWidget>
#include <services/settings/Gen4TimerSettings.h>
#include <services/timers/DelayTimer.h>
#include <services/CalibrationService.h>
#include <QSpinBox>

namespace gui::timer {
    class Gen4TimerPane : public QWidget {
    Q_OBJECT
    private:
        service::settings::Gen4TimerSettings *settings;
        const service::timer::DelayTimer *delayTimer;
        const service::CalibrationService *calibrationService;
        QSpinBox *delayHit;
    public:
        Gen4TimerPane(service::settings::Gen4TimerSettings *settings,
                      const service::timer::DelayTimer *delayTimer,
                      const service::CalibrationService *calibrationService,
                      QWidget *parent = nullptr);

        std::shared_ptr<std::vector<int>> createStages();

        void calibrate();

    private:
        void initComponents();

        int getCalibration() const;
    };
}


#endif //EONTIMER_GEN4TIMERPANE_H
