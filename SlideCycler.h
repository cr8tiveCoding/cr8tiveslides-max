#ifndef CREATIVESLIDES_SLIDECYCLER_H
#define CREATIVESLIDES_SLIDECYCLER_H


#include "SlideCache.h"
#include <SFML/Graphics.hpp>

class SlideCycler {
private:
    const SlideCache* cache;
    sf::RenderWindow* window;
    sf::Clock clock;
    int slideNumber;
    float secondsPer;
public:
    SlideCycler(SlideCache const *slides, sf::RenderWindow *renderWindow, float secondsPer);
    void tick();
};


#endif //CREATIVESLIDES_SLIDECYCLER_H
