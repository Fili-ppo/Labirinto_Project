#include "quiz.h"
using namespace std;
//Quiz::Quiz(){

//}
int Quiz::interazione(Personaggio *p){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        giaInteragito=true;
        p->aumenta();
        return 1;     
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        return 2;
    }
    else return 0;
}