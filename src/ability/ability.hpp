#ifndef ABILITY_HPP
#define ABILTY_HPP

class Ability {
    private:
        GameState gameState;
    public:
        virtual void useAbility() const = 0;
        // getter gamstate
};

#endif