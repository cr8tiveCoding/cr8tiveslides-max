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
    int size();
    Slide* getSlide(int index);
};


#endif //CREATIVESLIDES_SLIDECACHE_H
