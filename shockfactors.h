//  shockfactors.h
//  ENGS 65 Final Project


#ifndef SHOCKFACTORS_H
#define SHOCKFACTORS_H


#include <iostream>
#include <cmath>
#include "soluteclass.h"
#include "species.h"
#include "kelp.h"
#include "urchins.h"
#include "otters.h"

 using namespace std;

class ShockFactors {

    float sealevel;             // baseline sea level, cm
    float sealevel_change;
    double IRratio;             // irradiation ratio
    float toxin_factor = 1.05;      // affects otter death rate, do
    float nutrient_factor = 1.07;   // affects kelp growth rate, r
    
    

// float r_temp;
// solutes temp;
 
public:
    // Constructor
    ShockFactors() {
        sealevel = 4000;
        sealevel_change = 0;                            // initialize to 0
    }
    
    void setSeaLevelChange(float user_input) {
        sealevel_change = user_input;
    }

    double getIRratio() {
        
        double IRold = exp(0.035*sealevel);         // irradiation from original sea level
        sealevel += sealevel_change;
        double IRnew = exp(0.035*sealevel);         // irradiation from new sea level
        IRratio = IRnew/IRold;                      // ratio new/old
    
        return IRratio;
    
    }
    
    float getToxinfactor() {
        return toxin_factor;
    }
    
    float getNutrientfactor() {
        return nutrient_factor;
    }
    

};

#endif