#include <utility>

#include "SlideCache.h"
#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

SlideCache::SlideCache(const char* dir) {
    loadImages(dir);
}

void SlideCache::loadImages(const char* dir) {
    for (auto& p : fs::directory_iterator(dir)) {
        slides.emplace_back(new Slide(p.path().string().c_str()));
    }
}

unsigned long SlideCache::size() {
    return slides.size();
}

Slide* SlideCache::getSlide(int index) {
    return slides[index];
}
