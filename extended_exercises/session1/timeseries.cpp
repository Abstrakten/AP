#include "timeseries.h"
#include <algorithm>
#include <random>

using namespace exercise_one;

void TimeSeries::push_back(const int& val){

    if(series.empty()){
        minVal = maxVal = val;
    }else if(maxVal < val){
        maxVal = val;
    }else if(minVal > val) {
        minVal = val;
    }

    series.push_back(val);
}

int TimeSeries::amplitude() const {
    return maxVal - minVal;
}

const std::vector<int> TimeSeries::getSeries() const {
    return series;
};

TimeSeries& TimeSeries::operator+=(const TimeSeries& rhs){

    std::vector<int> rhsSeries = rhs.getSeries();

    int lhsLen = series.size();
    int rhsLen = rhsSeries.size();

    int firstLoop = std::min(lhsLen,rhsLen);

    int i;

    for (i = 0; i < firstLoop; i++) {
        series[i] += rhsSeries[i];
    }

    if (lhsLen < rhsLen){

        for (; i < rhsLen; i++) {
            series.push_back(rhsSeries[i]);
        }
    }

    return *this;

}

bool TimeSeries::operator<(const TimeSeries& rhs){

    return amplitude() < rhs.amplitude();

}

TimeSeries TimeSeries::MakeRandom(int length){

    TimeSeries t{};

    for(int i = 0; i < length; i++){
        t.push_back(std::rand());
    }
    
    return t;
}
