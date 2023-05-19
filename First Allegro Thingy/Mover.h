#include "Ticker.h"
#include "Entities.h"
#include"Enemy.h"
#include <math.h>

#define DEGREE_TO_PI_RATIO 0.0174532925
#define PI 3.14159265359
#define PI_OVER_TWO 3.14159265359/2
#define TICK_INTERVAL_16 16
#define TICK_INTERVAL_32 32
#define TICK_INTERVAL_64 64
#define TICK_INTERVAL_128 128

using namespace std;

class Mover 
{
public:
    Mover();
    ~Mover() {}
    float dx;
    float dy;

    void randomMover( Enemy&enemy,Ticker tick);
    void linearMover(Enemy& enemy, Ticker tick);
   
    //void linearMover();
    //void curvedMover();
    //void trackedMover(Enemy& enemy, Player& player);
private:

};