#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <utility>
class Map;

class Tank : private sf::NonCopyable  {
protected:
    float mX, mY, mWidth, mHeight, mDx, mDy, mSpeed;
    int mDir;
    float mCurrentFrame;

    sf::String mFile;
    sf::Texture mTexture;

public:
    explicit Tank(const float &x, const float &y, const float &width, const float &height, const sf::String &file);

    sf::Sprite mSprite;

    void animate(const sf::Int64 &time);
    const sf::Sprite get_sprite() const;

    virtual void move(const sf::Int64 &time) {}
    void update(const sf::Int64 &time, Map &map, const bool &collision);
    void map_interaction(Map &map);
    void tank_interaction();
};
