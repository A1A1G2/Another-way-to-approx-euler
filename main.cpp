#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <limits>
double calculate_magic(double x, int base){
    double exp = base / x;
    return pow(x, exp);
}
struct Magic{
    double x;
    double magic;
};

struct Bounds{
    double lower_bound;
    double upper_bound;
};

std::vector<double> create_divided_array(double start, double end, int count){
    std::vector<double> divided_array;
    double step = (end - start) / (count - 1);
    for(int i = 0; i < count-1; i++){
        divided_array.push_back(start + i * step);
    }
    divided_array.push_back(end);
    return divided_array;
}

bool double_equals(double a, double b, double epsilon = 0.00001)
{
    return std::abs(a - b) < epsilon;
}

std::vector<Magic>calculate_magic_vector(std::vector<double> divided_array, int base){
    std::vector<Magic> magic_vector;
    for(int i = 0; i < divided_array.size(); i++){
        Magic magic;
        magic.x = divided_array[i];
        magic.magic = calculate_magic(divided_array[i], base);
        magic_vector.push_back(magic);
    }
    return magic_vector;
}

Bounds find_bounds(std::vector<Magic> magic_vector){
    double max_magic = 0;
    double second_max_magic = 0;
    int max_index = 0;

    for(int i = 0; i < magic_vector.size(); i++){
        if(magic_vector[i].magic > max_magic){
            max_magic = magic_vector[i].magic;
            max_index = i;
        }
    }

    Bounds bounds;
    bounds.lower_bound = magic_vector[(max_index -1) < 0 ? 0 : (max_index -1)].x; 
    bounds.upper_bound = magic_vector[(max_index + 1) > magic_vector.size() ? magic_vector.size() : (max_index + 1)].x; 
    return bounds;
}

int main(){
    int base_number = 10, div_count = 100;
    double lim_neg = 2, lim_pos = base_number;
    int approx_count = 1000;

    for(int i = 0; i < approx_count; i++){
        std::vector<double> divided_array = create_divided_array(lim_neg, lim_pos, div_count);
        std::vector<Magic> magic_vector = calculate_magic_vector(divided_array, base_number);
        Bounds bounds = find_bounds(magic_vector);
        lim_neg = bounds.lower_bound;
        lim_pos = bounds.upper_bound;

        std::cout << "Iteration: " << i << " | " << lim_neg << " | " << lim_pos << std::endl;
    }
    std::cout << "The number that maximizes the function is: " << std::setprecision(std::numeric_limits<double>::digits10) << lim_neg << std::endl;
}
