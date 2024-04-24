//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <iostream>
#include <functional>

template <typename T>
T find_minimum(T first_arg) {
    return first_arg;
}

template <typename T, typename... Args>
T find_minimum(T first_arg, Args... args) {
    T rest_min = find_minimum(args...);
    return (first_arg < rest_min) ? first_arg : rest_min;
}

template <typename T, typename Compare>
T find_minimum_custom( Compare comp, T first_arg) {
    return first_arg;
}

template <typename T, typename Compare, typename... Args>
T find_minimum_custom( Compare comp, T first_arg, Args... args) {
    T rest_min = find_minimum_custom(comp, args...);
    return comp(first_arg, rest_min) ? first_arg : rest_min;
}


int main() {
    int min_int = find_minimum(5, 2, 8, 1, 10);
    double min_double = find_minimum(3.14, 1.23, 2.71, 0.99);

    int c_min_int = find_minimum_custom(std::less<>(), 5, 2, 8, 1, 10);
    double c_min_double = find_minimum_custom(std::less<>(), 3.14, 1.23, 2.71, 0.99);

    std::cout << "Minimum integer value: " << min_int << std::endl;
    std::cout << "Minimum double value: " << min_double << std::endl;
    std::cout << "Custom Minimum integer value: " << c_min_int << std::endl;
    std::cout << "Custom Minimum double value: " << c_min_double << std::endl;

    return 0;
}
