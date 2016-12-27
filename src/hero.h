#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include <string>
#include <iostream>

#include "dragon.h"

class Hero: public Unit
{
    int scores;
public:
    static const int default_health = 100;
    static const int default_attackForce = 20;

    Hero(int health = default_health, int aForce = default_attackForce)
            :Unit(health, aForce), scores(0)
    {}
    void attack (Dragon &drago)
    {
        std::string q = drago.generateQuestion();
        std::cout << "вопрос: " << q;
        int answer;
        std::cin >> answer;
        if (drago.checkAnswer(answer))
        {
            drago.getDamage(attackForce);
            std::cout << "Получай, дракон!" << std::endl;
        }
        else
        {
            getDamage(drago.attackForce);
            std::cout << "Герой огребает" << std::endl;
        }
    }
    int getScores(){
        return scores;
    }
    void addScores(int scores){
        scores+=1;
    }

};

#endif // HERO_H_INCLUDED
