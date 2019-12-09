
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algoritm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Obserwator{
    public:
Obserwator(const char* s) : nazwa{s?s:"nieznany"} {/* nic nie robi */}

virtual ~Obserwator() { } // wirtualny destruktor
const char* id() const {return nazwa.c_str();}
virtual void update() = 0; //metoda czysto wirtualna


    private:
string nazwa;

}


class Manager{
 
 public:
 
 void dodaj(obserwator* p);
 void usun(obserwator* p);
 void powiadom();
 void obserwatorzy() const;



 private:

 list<obserwator*> klient;



}

void Manager::obserwatorzy() const{
if (klient.empty()) cout <<"brak obserwatorow\n";
auto if = klient.cbegin(); //poczatek listy
while (it != klient.cend()){
    cout<<"Obserwator "<<(*it)->id() <<endl;
    ++it;
}

}

void Manager::powiadom(){
for (auto p : klient) p->update();

}

void Manager::dodaj(Obserwator* p){
if (find(klient.begin(),klient.end(),p )==klient,end()){
    klient.push_back(p);

} else {
    cout<<"Obserwator  "<<p->id()<< " jest juz na liscie"<<endl;

}
}

void Manager::usun(obserwator* p){
klient.erease(find(klient.begin(),klient.end(),p));
}

class Meteo : public Manager{

public:
double getT( ) const {return t;}
void operator(){size_t n}; // n liczba losowan


private:
double t { 0. };
double losuj(int a, int b);


}

double Meteo::losuj(int a, int b){
    return static_cast<double>(rand() % (b-a+1) + a);
}

void Meteo::operator()(size_t n){
    while (n--){
        t = losuj(5,25);
        powiadom();
    }
}



int main() {

/*

 Meteo stacja;
 Obserwator *p1 = new Tchwilowa("PWSZ",stacja);
 Obserwator *p2 = new Tchwilowa("NOWY SACZ",stacja);
 Obserwator *p3 = new Tsrednia("KRAKOW",stacja);
 Obserwator *p4 = new Tsrednia("WARSZAWA",stacja);
 stacja.obserwatorzy(); 
 stacja.dodaj(p1);
 stacja.dodaj(p2);
 stacja.dodaj(p3);
 stacja.dodaj(p4);
 stacja.obserwatorzy();

stacja(2); //dwa losowania
stacja.dodaj(p1);
stacja.usun(p3);
stacja(2); //losowania bez p3
delete p1;
delete p2;
delete p3;
delete p4;



}
