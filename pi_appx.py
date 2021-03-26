# -*- coding: utf-8 -*-
"""
Created on Thu Dec 31 12:22:02 2020

@author: Ahmad

# Pi approximation using Monte Carlo simulation
"""

import random
import math

def distance(point1_coords, point2_coords):
    '''  returns distance between two points:  distance = sqrt( (x2-x1) + (y2-y1) )  '''
    
    x1, y1 = point1_coords[0], point1_coords[1]
    x2, y2 = point2_coords[0], point2_coords[1]
    
    return ((x2-x1)**2 + (y2-y1)**2)**0.50


def point_in_circle(dist, radius):
    '''  returns True if point is inside the circle, False otherwise  '''

    inside_circle = False

    if dist<=radius:
        inside_circle = True
    
    return inside_circle


if __name__ == '__main__':
    origin = (0,0)
    circle_radius = 1
    square_area = 4

    random_sub_add = [-1, 1]
    
    #random_point = (round(random.choice(random_sub_add)*random.random(), 4), round(random.choice(random_sub_add)*random.random(), 4))
    #point_dist = round(distance(origin, random_point), 4)   
    #in_circle = point_in_circle(point_dist, circle_radius)
    
    # monte-carlo simulation
    simulations = 1001
    num_points_in_circle = 0

    for i in range(1,simulations):
        # obtain a random point within the square
        random_point = (round(random.choice(random_sub_add)*random.random(), 4), round(random.choice(random_sub_add)*random.random(), 4))
        
        # calculate its distance from the center
        point_dist = round(distance(origin, random_point), 4)
        
        # is the point inside or outside the circle
        in_circle = point_in_circle(point_dist, circle_radius)
        
        # if inside, increment the counter for points inside the circle
        if in_circle:
            num_points_in_circle += 1
        
        # approximate PI by calculating percentage of square area in which points fall inside the circle 
        pi_appx = num_points_in_circle/i * square_area

        print(f'Simulation {i}:  random point={random_point},   distance={point_dist},   points inside circle={num_points_in_circle},  PI appx={pi_appx}')
        
    
    print(f'\nFinal PI approximation = {pi_appx}')