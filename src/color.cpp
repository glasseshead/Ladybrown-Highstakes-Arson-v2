#include "color.hpp"

void checkColor() {
    // set detected to the largest "blob" of color detected
    pros::vision_object_s_t detected = vision.get_by_size(0);

    // if the signature is your team color, set motor voltage lower to score
    if (detected.signature == teamColorSignature.id) {
        INTAKE_VOLTAGE = 10000;
    }
    // if the signature is not your team color, set motor voltage higher to throw them out
    else {
        INTAKE_VOLTAGE = 12000;
    }
}