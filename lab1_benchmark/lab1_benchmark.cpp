#include <iostream>
#include <chrono>
const double PERIOD = 3.0;

long long int_plus() {
    long long COUNTER = 1'000'000;

    long a1 = 1, 
        a2 = 2, 
        b1 = 0, 
        b2 = 0, 
        c1 = 3, 
        c2 = 5, 
        c3 = 7, 
        c4 = 11;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;
    long long op = 0;
    double time_left, time_pass;

    auto start = std::chrono::high_resolution_clock::now();
    do {
        for (long long i = 0; i < COUNTER; i++) {
            a1 = b1 + c1;
            a2 = b1 + c2 + i;
            b1 = a1 + c3;
            b2 = a2 + c4 + i;
            c1 = a2 + b1;
            c2 = a1 + b2 + i;
            c3 = c1 + b1;
            c4 = c2 + b2 + i;
        }
        op += COUNTER * 12;

        end = std::chrono::high_resolution_clock::now();
        diff = end - start;

        time_pass = diff.count();
        time_left = PERIOD - time_pass;
        COUNTER = time_left * op / (diff.count() * 12);

    } while (time_left > 0.0);

    return op / time_pass;
}

int main() {
    std::cout << "int + " << int_plus() << "\n";
    std::cout << "int + " << int_plus() << "\n";
    std::cout << "int + " << int_plus() << "\n";
    std::cout << "int + " << int_plus() << "\n";
    std::cout << "int + " << int_plus() << "\n";
    std::cout << "int + " << int_plus() << "\n";
    std::cout << "int + " << int_plus() << "\n";
    std::cout << "int + " << int_plus() << "\n";
}
