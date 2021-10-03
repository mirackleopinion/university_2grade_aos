#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>

#ifndef _MSC_VER
typedef char __int8;
typedef short __int16;
typedef int __int32;
typedef long long __int64;
#endif

const int TESTS = 24, STARS_WIDTH = 50;
const int TEST_TIME = 60;

const double PERIOD = float(TEST_TIME) / (2 + TESTS); // время одного теста, чтобы программа работала одну минуту. с учётом "прогрева"

long long int32_plus() {
    long long COUNTER = 1'000'000;

    __int32 a1 = 1, 
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
long long int32_minus() {
    long long COUNTER = 1'000'000;

    __int32 a1 = 1,
        a2 = 2,
        b1 = 1,
        b2 = 2,
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
            a1 = b1 - c1;
            a2 = b1 - c2 - i;
            b1 = a1 - c3;
            b2 = a2 - c4 - i;
            c1 = a2 - b1;
            c2 = a1 - b2 - i;
            c3 = c1 - b1;
            c4 = c2 - b2 - i;
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
long long int32_multiplication() {
    long long COUNTER = 1'000'000;

    __int32 a1 = 1,
        a2 = 2,
        b1 = 1,
        b2 = 2,
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
            a1 = b1 * c1;
            a2 = b1 * c2 * i;
            b1 = a1 * c3;
            b2 = a2 * c4 * i;
            c1 = a2 * b1;
            c2 = a1 * b2 * i;
            c3 = c1 * b1;
            c4 = c2 * b2 * i;
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
long long int32_division() {
    long long COUNTER = 1'000'000;

    __int32 a1 = 10,
        a2 = 20,
        b1 = 10,
        b2 = 20,
        c1 = 30,
        c2 = 50;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;
    long long op = 0;
    double time_left, time_pass;

    auto start = std::chrono::high_resolution_clock::now();
    do {
        for (long long i = 1; i < COUNTER; i++) {
            a1 = b1 / c1;
            a2 = b2 / c2 / i;
        }
        op += COUNTER * 3;

        end = std::chrono::high_resolution_clock::now();
        diff = end - start;

        time_pass = diff.count();
        time_left = PERIOD - time_pass;
        COUNTER = time_left * op / (diff.count() * 3);

    } while (time_left > 0.0);

    return op / time_pass;
}

long long int8_plus() {
    long long COUNTER = 1'000'000;

    __int8 a1 = 1,
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
long long int8_minus() {
    long long COUNTER = 1'000'000;

    __int8 a1 = 1,
        a2 = 2,
        b1 = 1,
        b2 = 2,
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
            a1 = b1 - c1;
            a2 = b1 - c2 - i;
            b1 = a1 - c3;
            b2 = a2 - c4 - i;
            c1 = a2 - b1;
            c2 = a1 - b2 - i;
            c3 = c1 - b1;
            c4 = c2 - b2 - i;
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
long long int8_multiplication() {
    long long COUNTER = 1'000'000;

    __int8 a1 = 1,
        a2 = 2,
        b1 = 1,
        b2 = 2,
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
            a1 = b1 * c1;
            a2 = b1 * c2 * i;
            b1 = a1 * c3;
            b2 = a2 * c4 * i;
            c1 = a2 * b1;
            c2 = a1 * b2 * i;
            c3 = c1 * b1;
            c4 = c2 * b2 * i;
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
long long int8_division() {
    long long COUNTER = 1'000'000;

    __int8 a1 = 10,
        a2 = 20,
        b1 = 10,
        b2 = 20,
        c1 = 30,
        c2 = 50;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;
    long long op = 0;
    double time_left, time_pass;

    auto start = std::chrono::high_resolution_clock::now();
    do {
        for (long long i = 1; i < COUNTER; i++) {
            a1 = b1 / c1;
            a2 = b2 / c2 / i;

        }
        op += COUNTER * 3;

        end = std::chrono::high_resolution_clock::now();
        diff = end - start;

        time_pass = diff.count();
        time_left = PERIOD - time_pass;
        COUNTER = time_left * op / (diff.count() * 3);

    } while (time_left > 0.0);

    return op / time_pass;
}

long long int16_plus() {
    long long COUNTER = 1'000'000;

    __int16 a1 = 1,
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
long long int16_multiplication() {
    long long COUNTER = 1'000'000;

    __int16 a1 = 1,
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
            a1 = b1 * c1;
            a2 = b1 * c2 * i;
            b1 = a1 * c3;
            b2 = a2 * c4 * i;
            c1 = a2 * b1;
            c2 = a1 * b2 * i;
            c3 = c1 * b1;
            c4 = c2 * b2 * i;
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
long long int16_minus() {
    long long COUNTER = 1'000'000;

    __int16 a1 = 1,
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
            a1 = b1 - c1;
            a2 = b1 - c2 - i;
            b1 = a1 - c3;
            b2 = a2 - c4 - i;
            c1 = a2 - b1;
            c2 = a1 - b2 - i;
            c3 = c1 - b1;
            c4 = c2 - b2 - i;
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
long long int16_division() {
    long long COUNTER = 1'000'000;

    __int16 a1 = 1,
        a2 = 2,
        b1 = 0,
        b2 = 0,
        c1 = 3,
        c2 = 5;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;
    long long op = 0;
    double time_left, time_pass;

    auto start = std::chrono::high_resolution_clock::now();
    do {
        for (long long i = 1; i < COUNTER; i++) {
            a1 = b1 / c1;
            a2 = b2 / c2 / i;

        }
        op += COUNTER * 3;

        end = std::chrono::high_resolution_clock::now();
        diff = end - start;

        time_pass = diff.count();
        time_left = PERIOD - time_pass;
        COUNTER = time_left * op / (diff.count() * 3);

    } while (time_left > 0.0);

    return op / time_pass;
}

long long int64_plus() {
    long long COUNTER = 1'000'000;

    __int64 a1 = 1,
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
long long int64_minus() {
    long long COUNTER = 1'000'000;

    __int64 a1 = 1,
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
            a1 = b1 - c1;
            a2 = b1 - c2 - i;
            b1 = a1 - c3;
            b2 = a2 - c4 - i;
            c1 = a2 - b1;
            c2 = a1 - b2 - i;
            c3 = c1 - b1;
            c4 = c2 - b2 - i;
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
long long int64_multiplication() {
    long long COUNTER = 1'000'000;

    __int64 a1 = 1,
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
            a1 = b1 * c1;
            a2 = b1 * c2 * i;
            b1 = a1 * c3;
            b2 = a2 * c4 * i;
            c1 = a2 * b1;
            c2 = a1 * b2 * i;
            c3 = c1 * b1;
            c4 = c2 * b2 * i;
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
long long int64_division() {
    long long COUNTER = 1'000'000;

    __int64 a1 = 1,
        a2 = 2,
        b1 = 0,
        b2 = 0,
        c1 = 3,
        c2 = 5;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;
    long long op = 0;
    double time_left, time_pass;

    auto start = std::chrono::high_resolution_clock::now();
    do {
        for (long long i = 1; i < COUNTER; i++) {
            a1 = b1 / c1;
            a2 = b2 / c2 / i;
        }
        op += COUNTER * 3;

        end = std::chrono::high_resolution_clock::now();
        diff = end - start;

        time_pass = diff.count();
        time_left = PERIOD - time_pass;
        COUNTER = time_left * op / (diff.count() * 3);

    } while (time_left > 0.0);

    return op / time_pass;
}

long long double_plus() {
    long long COUNTER = 1'000'000;

    double a1 = 1,
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
long long double_minus() {
    long long COUNTER = 1'000'000;

    double a1 = 1,
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
            a1 = b1 - c1;
            a2 = b1 - c2 - i;
            b1 = a1 - c3;
            b2 = a2 - c4 - i;
            c1 = a2 - b1;
            c2 = a1 - b2 - i;
            c3 = c1 - b1;
            c4 = c2 - b2 - i;
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
long long double_multiplication() {
    long long COUNTER = 1'000'000;

    double a1 = 1,
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
            a1 = b1 * c1;
            a2 = b1 * c2 * i;
            b1 = a1 * c3;
            b2 = a2 * c4 * i;
            c1 = a2 * b1;
            c2 = a1 * b2 * i;
            c3 = c1 * b1;
            c4 = c2 * b2 * i;
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
long long double_division() {
    long long COUNTER = 1'000'000;

    double a1 = 1,
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
        for (long long i = 1; i < COUNTER; i++) {
            a1 = b1 / c1;
            a2 = b1 / c2 / i;
            b1 = a1 / c3;
            b2 = a2 / c4 / i;
            c1 = a2 / b1;
            c2 = a1 / b2 / i;
            c3 = c1 / b1;
            c4 = c2 / b2 / i;
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

long long float_plus() {
    long long COUNTER = 1'000'000;

    float a1 = 1,
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
long long float_minus() {
    long long COUNTER = 1'000'000;

    float a1 = 1,
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
            a1 = b1 - c1;
            a2 = b1 - c2 - i;
            b1 = a1 - c3;
            b2 = a2 - c4 - i;
            c1 = a2 - b1;
            c2 = a1 - b2 - i;
            c3 = c1 - b1;
            c4 = c2 - b2 - i;
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
long long float_multiplication() {
    long long COUNTER = 1'000'000;

    float a1 = 1,
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
            a1 = b1 * c1;
            a2 = b1 * c2 * i;
            b1 = a1 * c3;
            b2 = a2 * c4 * i;
            c1 = a2 * b1;
            c2 = a1 * b2 * i;
            c3 = c1 * b1;
            c4 = c2 * b2 * i;
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
long long float_division() {
    long long COUNTER = 1'000'000;

    float a1 = 1,
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
        for (long long i = 1; i < COUNTER; i++) {
            a1 = b1 / c1;
            a2 = b1 / c2 / i;
            b1 = a1 / c3;
            b2 = a2 / c4 / i;
            c1 = a2 / b1;
            c2 = a1 / b2 / i;
            c3 = c1 / b1;
            c4 = c2 / b2 / i;
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

    std::string test_names[TESTS] = {
    "  int8 +",
    "  int8 -",
    "  int8 *",
    "  int8 /",

    " int16 +",
    " int16 -",
    " int16 *",
    " int16 /",

    " int32 +",
    " int32 -",
    " int32 *",
    " int32 /",

    " int64 +",
    " int64 -",
    " int64 *",
    " int64 /",

    "double +",
    "double -",
    "double *",
    "double /",

    " float +",
    " float -",
    " float *",
    " float /"
    };

    std::cout << "Please wait "<< TEST_TIME << " seconds...\n";

    int8_plus(); // прогрев
    int8_minus(); // прогрев

    long long operations_per_second[TESTS] = {
        int8_plus(),
        int8_minus(),
        int8_multiplication(),
        int8_division(),

        int16_plus(),
        int16_minus(),
        int16_multiplication(),
        int16_division(),

        int32_plus(),
        int32_minus(),
        int32_multiplication(),
        int32_division(),

        int64_plus(),
        int64_minus(),
        int64_multiplication(),
        int64_division(),

        double_plus(),
        double_minus(),
        double_multiplication(),
        double_division(),

        double_plus(),
        double_minus(),
        double_multiplication(),
        double_division()
    };

    long long better = operations_per_second[0];
    for (int i = 1; i < TESTS; i++) {
        if (operations_per_second[i] > better) {
            better = operations_per_second[i];
        }
    }
    
    for (int i = 0; i < TESTS; i++) {
        int stars = int(STARS_WIDTH * operations_per_second[i] / better);
        int spaces = STARS_WIDTH - stars;
        std::cout << test_names[i]<< " " 
            << std::setw(12) << operations_per_second[i] 
            << " "<< std::string(stars, 'x') << std::string(spaces, ' ') << " " 
            << std::setw(3) << int(100.0 * operations_per_second[i] / better) << "%" 
            << std::endl;

    };
}
