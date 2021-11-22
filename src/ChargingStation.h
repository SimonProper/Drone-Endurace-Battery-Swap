#include <StepperWrapper.h>

class ChargingstationController{
    public:
        ChargingstationController();
        int get_last_station();
        void NextStation();
    private:
    //Amount of chargingstations, change if more stations
        ChargingStation stations[4]; 

        

};

struct ChargingStation
{
    int station_number;
    
};
