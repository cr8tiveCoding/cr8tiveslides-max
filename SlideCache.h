#ifndef CREATIVESLIDES_SLIDECACHE_H
#define CREATIVESLIDES_SLIDECACHE_H


#include <string>
#include <vector>
#include "Slide.h"

class SlideCache {
private:
    std::vector<Slide*> slides;
public:
    explicit SlideCache(const char* dir);
    void loadImages(const char* dir);
    int size() const;
    Slide* getSlide(int index) const;
};


#endif //CREATIVESLIDES_SLIDECACHE_H
