#ifndef LLMR_RENDERER_FRAME_HISTORY
#define LLMR_RENDERER_FRAME_HISTORY

#include <deque>
#include <cassert>
#include <cmath>

#include <llmr/platform/platform.hpp>
#include <llmr/util/time.hpp>

namespace llmr {

struct FrameSnapshot {
    explicit inline FrameSnapshot(time timestamp, float z) : timestamp(timestamp), z(z) {}
    float timestamp;
    float z;
};

class FrameHistory {
public:
    // Record frame history that will be used to calculate fading params
    void record(time now, float zoom);

    bool needsAnimation(time duration) const;

public:
    std::deque<FrameSnapshot> history;
};

}

#endif
