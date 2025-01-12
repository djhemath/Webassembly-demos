#include <emscripten.h>
#include <vector>

extern "C" {

  // C++ function to apply grayscale
  EMSCRIPTEN_KEEPALIVE
  void applyGrayscale(uint8_t* data, int length) {
    for (int i = 0; i < length; i += 4) {
      uint8_t r = data[i];
      uint8_t g = data[i + 1];
      uint8_t b = data[i + 2];

      uint8_t gray = static_cast<uint8_t>(0.299 * r + 0.587 * g + 0.114 * b);

      data[i] = data[i + 1] = data[i + 2] = gray; // Set R, G, B to gray value
    }
  }
}
