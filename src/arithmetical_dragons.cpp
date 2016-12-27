#include <iostream>
#include <sstream>
#include <cstdlib>
#include <list>

#include "unit.h"
#include "hero.h"
#include "dragon.h"

using namespace std;


void showHealth(const Hero &hero, const Dragon &dragon)
{
    cout << "Ваше здоровье: " << hero.getHealth()
        << ", Здоровье дракона: " << dragon.getHealth() << endl;
}

list<Dragon*> generateDragonList()
{
    list<Dragon*> competitors;
    competitors.push_back(new GreenDragon());
    competitors.push_back(new RedDragon());
    competitors.push_back(new BlackDragon());

    return competitors;
}


bool playGame(Hero &hero, list<Dragon*> &dragons)
{
    bool gameOver = false;

    for (list<Dragon*>::iterator dragon = dragons.begin();
            dragon != dragons.end(); dragon++)
    {
        cout << "Вы встретили дракона " << (*dragon)->color() << " цвета. Пора умертвить его!" << endl;

        while ((*dragon)->isAlive() && hero.isAlive())
        {
            hero.attack(**dragon);
        }
        if (!hero.isAlive())
        {
            gameOver = true;
            break;
        }
        else // dragon was killed!
        {
            hero.addScores(Dragon::c_killScores);
            cout << "Ееее! Дракон повержен!" << endl;
        }
    }
    return gameOver;
}


int main()
{
    Hero hero;
    list<Dragon*> dragons = generateDragonList();
    bool gameResult = playGame(hero, dragons);

    if (gameResult)
    {
        cout << "Игра окончена. Ваш счет: " << hero.getScores() << endl;
    }
    else
    {
        cout << "Победа! Ваш счет: " << hero.getScores() << endl;
    }
    for (list<Dragon*>::iterator dragon = dragons.begin();
            dragon != dragons.end(); dragon++)
        delete *dragon;
    return 0;
}
