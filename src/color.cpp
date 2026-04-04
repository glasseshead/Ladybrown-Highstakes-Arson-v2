#include "color.hpp"

void checkColor() {
    // set detected to the largest "blob" of color detected
    vision_object_s_t detected = vision_sensor.get_by_size(0);

    // if the signature is red:
    if (detected.signature == redSignature) {
        break;
    }
    // if the signature is blue:
    else if (detected.signature == blueSignature) {
        break;
    }
}