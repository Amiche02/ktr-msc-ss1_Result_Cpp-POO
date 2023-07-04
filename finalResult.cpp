#include <iostream>
#include <string>

class Movable {
public:
    virtual void moveRight() const = 0;
    virtual void moveLeft() const = 0;
    virtual void moveBack() const = 0;
    virtual void moveForward() const = 0;
};

class Exception {
protected:
    std::string m_message;

public:
    Exception(const std::string& message) : m_message(message) {}

    std::string getMessage() const {
        return m_message;
    }
};

class WeaponException : public Exception {
public:
    WeaponException(const std::string& message) : Exception(message) {}
};

class Character {
protected:
    std::string m_name;
    const std::string m_RpgClass;
    int m_life;
    int m_agility;
    int m_strength;
    int m_wit;

public:
    Character(const std::string& name, const std::string& RpgClass)
        : m_name(name), m_RpgClass(RpgClass), m_life(50), m_agility(2), m_strength(2), m_wit(2) {}

    void attack(const std::string& weapon) const {
        std::cout << m_name << ": Rrrrrrrr..." << std::endl;
        if (weapon.empty()) {
            throw WeaponException(m_name + ": I refuse to fight with my bare hands.");
        } else {
            std::cout << m_name << ": I don't need this stupid " << weapon << "! Don't misjudge my powers!" << std::endl;
        }
    }

    void unsheathe() const {
        std::cout << m_name << ": unsheathes his weapon." << std::endl;
    }

    std::string getName() const {
        return m_name;
    }

    std::string getRpgClass() const {
        return m_RpgClass;
    }

    int getLife() const {
        return m_life;
    }

    int getAgility() const {
        return m_agility;
    }

    int getStrength() const {
        return m_strength;
    }

    int getWit() const {
        return m_wit;
    }
};

class Warrior : public Character, public Movable {
public:
    Warrior(const std::string& name) : Character(name, "Warrior") {
        std::cout << m_name << ": My name will go down in history!" << std::endl;
        m_life = 100;
        m_strength = 10;
        m_agility = 8;
        m_wit = 3;
    }

    void moveRight() const override {
        std::cout << m_name << ": moves right like a bad boy." << std::endl;
    }

    void moveLeft() const override {
        std::cout << m_name << ": moves left like a bad boy." << std::endl;
    }

    void moveBack() const override {
        std::cout << m_name << ": moves back like a bad boy." << std::endl;
    }

    void moveForward() const override {
        std::cout << m_name << ": moves forward like a bad boy." << std::endl;
    }

    void tryToAttack(const std::string& weapon) const {
        try {
            attack(weapon);
        } catch (const WeaponException& e) {
            std::cout << e.getMessage() << std::endl;
        }
    }
};

class Mage : public Character, public Movable {
public:
    Mage(const std::string& name) : Character(name, "Mage") {
        std::cout << m_name << ": May the gods be with me." << std::endl;
        m_life = 70;
        m_strength = 3;
        m_agility = 10;
        m_wit = 10;
    }

    void moveRight() const override {
        std::cout << m_name << ": moves right furtively." << std::endl;
    }

    void moveLeft() const override {
        std::cout << m_name << ": moves left furtively." << std::endl;
    }

    void moveBack() const override {
        std::cout << m_name << ": moves back furtively." << std::endl;
    }

    void moveForward() const override {
        std::cout << m_name << ": moves forward furtively." << std::endl;
    }

    void tryToAttack(const std::string& weapon) const {
        try {
            attack(weapon);
        } catch (const WeaponException& e) {
            std::cout << e.getMessage() << std::endl;
        }
    }
};

int main() {
    Warrior warrior("Jean-Luc");
    Mage mage("Robert");

    warrior.tryToAttack("screwdriver");
    mage.tryToAttack("hammer");
    warrior.tryToAttack("hammer");
    try {
        mage.attack("");
    } catch (const WeaponException& e) {
        std::cout << e.getMessage() << std::endl;
    }

    return 0;
}
