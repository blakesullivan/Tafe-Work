#include "fish.h"

void showAges(fish[]);

int main()
{
    fish myFish[3];
 
    showAges(myFish);
    cout << endl;
 
    myFish[0].setAge(10);
    myFish[1].setAge(20);
    myFish[2].setAge(30);
 
    showAges(myFish);
 
    cin.get();
    return 0;
}

void showAges(fish fishes[])
{
    cout << "fish 1 age is: " << fishes[0].getAge() << endl;
    cout << "fish 2 age is: " << fishes[1].getAge() << endl;
    cout << "fish 3 age is: " << fishes[2].getAge() << endl;
}