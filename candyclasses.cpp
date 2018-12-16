#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

struct Candy {
    string name;
    double weight;
    int calories;
    
    Candy(){
        name = "none";
        weight = 0;
        calories = 0;
    }
};

struct CandyBag{
    double maxWeight;
    Candy c[5];
    int bagWeight;
};

int weighBag(CandyBag *c2)
{
    return c2 -> bagWeight;
}

int main()
{
    Candy twix;
    twix.calories = 70;
    twix.name = "Twix";
    twix.weight = 0.5;
    
    Candy snickers;
    snickers.calories = 85;
    snickers.name = "Snickers";
    snickers.weight = 0.6;
    
    Candy sucker;
    sucker.calories = 65;
    sucker.name = "Sucker";
    sucker.weight = 0.3;
    
    CandyBag bag;
    bag.maxWeight = 5;
    bag.c[0] = twix;
    bag.c[1] = snickers;
    bag.c[3] = sucker;
    
    CandyBag *c1 = &bag;
    weighBag(c1);
    
    Candy *refVar = &twix;
    bag.c[4] = *refVar;

    for(int i = 0; i < 5; i++){
        bag.bagWeight = bag.c[i].weight++;
    }
    
    // The weighbag() fucntion is fooled because it's a reference to the candy, and it adds the full weight of the candy to the bag again, even though it's just a reference- not another candy. The weight should remain the same even after the reference was added.
}



