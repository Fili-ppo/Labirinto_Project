#include "menu.h"
Menu::Menu(){
    diff=0;
    finestra=new sf::RenderWindow(sf::VideoMode(1300,1000), "Menù iniziale");
    font.loadFromFile("Font\\upheavtt.ttf");
    text[0].setString("Facile");
    text[1].setString("Medio");
    text[2].setString("Difficile");
    sfondoT.loadFromFile("Images\\sfondo.png");
    sfondo.setTexture(sfondoT);
    pulsante.loadFromFile("Images\\pulsante.png");
    for(int i=0; i<3; i++){
        pulsanti[i].setTexture(pulsante);
        text->setPosition(i*433+70, 820);
        text->setScale(0.5, 0.5);
        pulsanti[i].setScale(0.6, 0.6);
        pulsanti[i].setPosition(i*433+60,800);
    }
    cursore.setFillColor(sf::Color::Red);
    cursore.setSize({10.f, 10.f});
}

void Menu::display(){
    while(finestra->isOpen()){ //quando la finestra è aperta il gioco continua
        sf::Event azione;
        while(finestra->pollEvent(azione)){
            if(azione.type==sf::Event::Closed) finestra->close(); //se premo la x, fermo il programma e chiudo la finestra
        }
        finestra->draw(sfondo);
        update();
        finestra->draw(cursore);
        if(salvato==false){
            for(int i=0; i<3; i++){
            finestra->draw(pulsanti[i]);
            finestra->draw(text[i]);
            }
            diff=selezionaDiff();
        }
        else diff=4;
        if(diff!=0) finestra->close();
        finestra->display();
    }
}
int Menu::selezionaDiff(){
    if(cursore.getGlobalBounds().intersects(pulsanti[0].getGlobalBounds()) && Mouse::isButtonPressed(Mouse::Left)){
        return 1;
    }
    else if(cursore.getGlobalBounds().intersects(pulsanti[1].getGlobalBounds()) && Mouse::isButtonPressed(Mouse::Left)){
        return 2;
    }
    else if(cursore.getGlobalBounds().intersects(pulsanti[2].getGlobalBounds()) && Mouse::isButtonPressed(Mouse::Left)){
        return 3;
    }
    else return 0;
}
void Menu::checkSalvataggio(string s){
    salvataggio.open(s);
    int i;
    salvataggio>>i;
    if(i==1){
        salvato=true;
    } else if(i==0){
        salvato=false;
    }
}
void Menu::update(){
    cursore.setPosition(Mouse::getPosition(*finestra).x, Mouse::getPosition(*finestra).y);
}