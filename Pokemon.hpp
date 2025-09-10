#include <iostream>

class Pokemon {
    private:

        int id{};
        std::string name;
        double hitPoint{};
        double attack{};
        double defense{};
        int generation{};

    public:

        Pokemon(const int id,
            const std::string name,
            const double hitPoint,
            const double attack,
            const double defense,
            const int generation) const;
        Pokemon(const Pokemon &base) const;

        ~Pokemon() const;

        void displayInfo() const;
        
        double getAttack() const;
        double getDefense() const;
        double getHitPoint() const;

        void takeStrike(double damages) const;
        
        void attackOther(Pokemon &other) const;
};