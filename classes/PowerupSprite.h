// Contains powerup sprite class declaration
#ifndef CURVE_POWERUPSPRITE
#define CURVE_POWERUPSPRITE
// Headers
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "../functions/general.h"
//
class PowerupSprite{
    sf::Texture texture;// The texture that has all powerups
public:
    sf::Sprite fastGreen,fastRed;
    sf::Sprite slowGreen,slowRed;
    sf::Sprite smallGreen,smallRed;
    sf::Sprite bigGreen,bigRed;
    sf::Sprite angleGreen,angleRed;
    sf::Sprite clearBlue;
    sf::Sprite invisibleGreen;
    sf::Sprite wallsAwayBlue;
    sf::Sprite morePowerupsBlue;
    sf::Sprite invertedRed;
    sf::Sprite questionMarkBlue;
    sf::Sprite darknessBlue;
    sf::Sprite gapRed;
    sf::Sprite bombBlue;
    sf::Sprite sineRed;
    sf::Sprite glitchBlue;
    sf::Sprite radiusBlue;
    // Constructor
    PowerupSprite(const Config &config);
};
#endif // CURVE_POWERUPSPRITE