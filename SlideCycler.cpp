#include <iostream>
#include "SlideCycler.h"

SlideCycler::SlideCycler(SlideCache const *slides, sf::RenderWindow *renderWindow, float secondsPer) {
    cache = slides;
    window = renderWindow;
    this->secondsPer = secondsPer;
    slideNumber = 0;
    inTransition = false;
    currentSlide = new Slide(*cache->getSlide(0));
    desktopWidth = sf::VideoMode::getDesktopMode().width;
}

void SlideCycler::tick() {
    if (inTransition) {
        auto transitionSprite = transitionSlide->getSprite();
        float back;
        float transitionX = transitionSprite->getPosition().x;

        back = transitionX * (transitionX / (desktopWidth * 5));
        if (back > 10) back = 10;
        if (back < 0.7) back = 0.7;

        currentSlide->getSprite()->move(-back, 0);
        transitionSprite->move(-back, 0);

        window->draw(*transitionSlide->getSprite());

        if (transitionSprite->getPosition().x < 1) {
            delete currentSlide;
            currentSlide = new Slide(*transitionSlide);
            delete transitionSlide;
            inTransition = false;
            clock.restart();
        }

    } else if (clock.getElapsedTime().asSeconds() >= secondsPer) {
        slideNumber = (slideNumber + 1) % cache->size();
        inTransition = true;
        transitionSlide = new Slide(*cache->getSlide(slideNumber));
        transitionSlide->getSprite()->move(desktopWidth, 0);
        clock.restart();
    }
    window->draw(*currentSlide->getSprite());
}
