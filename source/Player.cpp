#include <SFML/Window/Keyboard.hpp>
#include <Player.h>
#include <Map.h>
using sf::Keyboard;

Player::Player()
    : Tank(244, 600, 13, 13, "battle-city-src/media/playerSprites.png") {
    mSprite.setScale(3.2f, 3.2f);
    mSpeed = 100;
}

void Player::move() {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        mDir = 1;
        mSpeed = 0.1f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        mDir = 0;
        mSpeed = 0.1f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        mDir = 3;
        mSpeed = 0.1f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        mDir = 2;
        mSpeed = 0.1f;
    }
}

void Player::update(const float &time, Map &map) {
    move();

    switch (mDir) {
        case 0:
            mDx = mSpeed;
            mDy = 0;
            break;

        case 1:
            mDx = -mSpeed;
            mDy = 0;
            break;

        case 2:
            mDx = 0;
            mDy = mSpeed;
            break;

        case 3:
            mDx = 0;
            mDy = -mSpeed;
            break;
    }
    mX += mDx * time;
    mY += mDy * time;

    mSpeed = 0;
    mSprite.setPosition(mX, mY);
    animate(time);
    map_interaction(map);
}
