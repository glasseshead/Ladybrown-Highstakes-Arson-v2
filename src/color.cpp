#include "color.hpp"

void checkColor() {
    // set detected to the largest "blob" of color detected
    pros::vision_object_s_t detected = vision.get_by_size(0);

    // if the signature is your team color, retract piston to allow it to flip down
    if (detected.signature == teamColorSignature.id) {
        colorSortPiston.set_value(false);
    }
    // if the signature is not your team color, extend piston to throw it out
    else {
        colorSortPiston.set_value(true);
    }
}