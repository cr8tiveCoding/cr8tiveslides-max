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
        back = std::clamp(back, 0.7f, 10.f);

        currentSlide->getSprite()->move(-back, 0);
        transitionSprite->move(-back, 0);

        window->draw(*transitionSprite);

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
