#include "timeseries.h"
#include <iostream>

using namespace std;
using namespace exercise_one;

void printeren(const TimeSeries& t){
        for(auto elm : t.getSeries()){
        cout << elm << ","; }

        cout << endl;

}

int main(int argc, char const *argv[]) {

    auto hans = TimeSeries();
    auto grete = TimeSeries();

    hans.push_back(1);
    hans.push_back(2);

    grete.push_back(1);

    hans+=grete;

    printeren(hans);

    printeren(hans+hans);

    cout << (hans < hans+hans) << endl;

    printeren(TimeSeries::MakeRandom(10));


    return 0;
}
