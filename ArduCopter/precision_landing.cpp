/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

//
// functions to support precision landing
//

#include "Copter.h"

#if PRECISION_LANDING == ENABLED

void Copter::init_precland()
{
    precland.init();
}

void Copter::update_precland()
{
    float final_alt = current_loc.alt;
    int16_t offset_sensor_alt = 3;

    // use range finder altitude if it is valid
    if (sonar_enabled && (sonar_alt_health >= SONAR_ALT_HEALTH_MAX)) {
        final_alt = float(sonar_alt - offset_sensor_alt);
    }

    copter.precland.update(final_alt);

    // log output
    Log_Write_Precland();
}

#endif
