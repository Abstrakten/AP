#pragma once
#include <vector>

namespace exercise_one
{
    class TimeSeries{
        public:
            static TimeSeries MakeRandom(int length);
            void push_back(const int& val);
            int amplitude() const;
            friend TimeSeries operator+(TimeSeries lhs, const TimeSeries& rhs);
            TimeSeries& operator+=(const TimeSeries& rhs);
            bool operator<(const TimeSeries& ts);
            const std::vector<int> getSeries() const;

        private:
            std::vector<int> series;
            int minVal = 0;
            int maxVal = 0;
    };

    inline TimeSeries operator+(TimeSeries lhs, const TimeSeries& rhs){

    return lhs+=rhs;
}
}
