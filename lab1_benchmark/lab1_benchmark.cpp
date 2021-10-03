#include <iostream>
#include <chrono>
const double PERIOD = 1;

long long int32_plus() {
    long long COUNTER = 1'000'000;

    int a1 = 1, 
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

    int a1 = 1,
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

    int a1 = 1,
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

    int a1 = 10,
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
;
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
    int8_plus(); // прогрев
    int8_minus(); // прогрев



    std::cout << "int8 + " << int8_plus() << "\n";
    std::cout << "int8 - " << int8_minus() << "\n";
    std::cout << "int8 * " << int8_multiplication() << "\n";
    std::cout << "int8 / " << int8_division() << "\n" << "\n";

    std::cout << "int16 + " << int16_plus() << "\n";
    std::cout << "int16 - " << int16_minus() << "\n";
    std::cout << "int16 * " << int16_multiplication() << "\n";
    std::cout << "int16 / " << int16_division() << "\n" << "\n";

    std::cout << "int32 + " << int32_plus() << "\n";
    std::cout << "int32 - " << int32_minus() << "\n";
    std::cout << "int32 * " << int32_multiplication() << "\n";
    std::cout << "int32 / " << int32_division() << "\n" << "\n";

    std::cout << "int64 + " << int64_plus() << "\n";
    std::cout << "int64 - " << int64_minus() << "\n";
    std::cout << "int64 * " << int64_multiplication() << "\n";
    std::cout << "int64 / " << int64_division() << "\n" << "\n";

    std::cout << "double + " << double_plus() << "\n";
    std::cout << "double - " << double_minus() << "\n";
    std::cout << "double * " << double_multiplication() << "\n";
    std::cout << "double / " << double_division() << "\n" << "\n";


    std::cout << "float + " << double_plus() << "\n";
    std::cout << "float - " << double_minus() << "\n";
    std::cout << "float * " << double_multiplication() << "\n";
    std::cout << "float / " << double_division() << "\n" << "\n";
}
