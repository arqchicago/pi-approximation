# Pi Approximation
In this project, Monte Carlo Simulation is used to approximate the value of pi.  

## Blog 
My blog on this project can be accessed at https://mlai1.blogspot.com/2021/06/monte-carlo-simulation-to-approximate.html.

## Monte Carlo Simulation
Monte Carlo Simulation uses repeated iterations along with randomness to solve problems and approximate answers. The simulation requires
defining domain of input values such that randomly selected values from the domain is used to perform deterministic computations and
approximate answers to problems. 

## Simulation Setup
In this simulation, a square of side 2 units is defined with its center at the origin of a two dimensional Cartesian Coordinate system. 
A circle of radius 1 unit is inscribed inside of the square sharing center at the origin. In this setup, the area of square is 
4 unit-squared.  

## Simulation Iterations
In each iteration of the Monte Carlo Simulation, a point is randomly generated inside of the square and its Euclidean Distance from the 
origin is calculated. If that distance is less than or equal to the radius, the point is contained inside of the circle. If the distance
of the point is greater than the radius, then the point is outside of the circle (but still within the square). These iterations are 
repeated 10,000 times and the percentage of points inside of the circle is calculated. This percentage can be used to approximate the
value of pi by multiplying it with 4 (area of the square). In other words, we are approximating the portion of 4 unit-squared area of square
that is contained inside of the circle. Since the radius of circle is 1 unit, this approximated area of circle should be close to the value of pi. 

## Visuals
To Be Completed.