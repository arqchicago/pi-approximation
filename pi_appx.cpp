/******************************************************************************
Created on Sat Mar 27 12:22:02 2020

@author: Ahmad

# Pi approximation using Monte Carlo simulation
*******************************************************************************/

#include <iostream>
#include<tuple>
#include <string> 
#include <cmath> 

using namespace std;

float gen_random_number(int min, int max) {
    float random_num;
    random_num = min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
    return(random_num);
}

float euclidean_distance(tuple <float, float> point1_coords, tuple <float, float> point2_coords) {
    float distance;
    float x1, x2, y1, y2;
    
    x1 = get<0>(point1_coords); y1 = get<1>(point1_coords);
    x2 = get<0>(point2_coords); y2 = get<1>(point2_coords);
    distance = pow(((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)), 0.50);
    
    return(distance);
}

bool point_in_circle(float dist, float radius) {
    bool inside_circle = false;
    
    if (dist<=radius)
        inside_circle = true;
        
    return(inside_circle);
}


int main()
{
	// defining origin and random point
    tuple <float, float> origin=make_tuple(0.0,0.0); 
    tuple <float, float> rand_point;
	
	// defining the circle of radius 1 unit, square with sides of 2 units
    float circle_radius=1, square_side=2, square_area, random_num, distance, pi_value;
	int simulations=10001, circle_counter=0, min=-1, max=1;
    bool in_circle;

    square_area = square_side * square_side;
    
    for (int i = 0; i < simulations; i++) {

		// obtain random (x,y) point within the square
        get<0>(rand_point) = gen_random_number(min, max);
        get<1>(rand_point) = gen_random_number(min, max);
		
		// get distance of the random point from the origin
        distance = euclidean_distance(origin, rand_point);
		
		// if the point is inside the circle, increment circle_counter
        in_circle = point_in_circle(distance, circle_radius);
        
        if (in_circle)
            circle_counter += 1;
            
		// approximate pi by multiplying ratio of points inside circle to the area of square
        pi_value = (circle_counter *1.0/ i) * square_area;
        cout<<pi_value<<endl;
    }

    return 0;
}