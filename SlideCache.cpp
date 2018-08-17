#include <utility>

#include "SlideCache.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

SlideCache::SlideCache(const char* dir) {
    loadImages(dir);
}

void SlideCache::loadImages(const char* dir) {
    for (auto& p : fs::directory_iterator(dir))
        slides.emplace_back(new Slide(p.path().string().c_str()));

    if (slides.empty())
        throw std::runtime_error("No images were loaded");
}

int SlideCache::size() const {
    return static_cast<int>(slides.size());
}

Slide* SlideCache::getSlide(int index) const {
    return slides[index];
}
