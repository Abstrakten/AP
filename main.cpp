#include <iostream>
#include <chrono>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>

void timer(std::function<void()>funcky){
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    funcky();
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void swap_ends(std::vector<int>& arr){
    for (int i = arr.size()/2 - 1, j = arr.size()-1; i>=0; --i, --j)
        std::swap(arr[i],arr[j]);
}

void swap_ends(int arr[], int size){
    for (int i = size/2 - 1, j = size -1; i>=0; --i, --j)
        std::swap(arr[i],arr[j]);
}

void swap_ends_alt1(int arr[], int size){
    for (int i = size/2 - 1, j = size -1; i>=0; --i, --j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void swap_ends_alt2(int arr[], int size){
    uint8_t buff[1000];
    memcpy(buff, arr, size/2 * sizeof(int));
    memcpy(arr, arr + (size+1)/2, size/2 * sizeof(int));
    memcpy(arr + (size+1)/2, buff, size/2 *sizeof(int));
}

void test(){
    std::cout << "hans" << std::endl;
}

int main()
{
    std::vector<int> vec {1,2,3,4,5,6,7};
    int c_arr[7] {1,2,3,4,5,6,7};
    int d_arr[7] {1,2,3,4,5,6,7};

    int e_arr[7] {1,2,3,4,5,6,7};


    auto lambdaVec = [&](){swap_ends(vec);};
    auto lambdaArr = [&](){swap_ends_alt2(c_arr,7);};
    auto lambdaArrSimple = [&](){swap_ends_alt1(d_arr,7);};
    auto lamb2dsadas = [&](){swap_ends(e_arr,7);};


    timer(lambdaVec);
    timer(lambdaArr);
    timer(lambdaArrSimple);
    timer(lamb2dsadas);
}

