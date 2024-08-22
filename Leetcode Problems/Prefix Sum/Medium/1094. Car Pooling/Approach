Problem Statement -:

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off 
are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

Example 1 -:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Example 2 -:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true

Problem Constraints -:

1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 105

Topic Tags -: Array, Sorting, Heap (Priority Queue), Simulation, Prefix Sum

Approach -:

The questions says that we have a car of capacity let's say 'c' and n number of trips, each trip has numPassengers that can travel in their respective time period. We need to find that whether the car can complete
all trips or not. The most important thing in this question is that we are given trip timing of passengers, this information will help us in building timeline of each trip and we can easily keep track of number of
passengers in each trip.
We will create a timeline having starting point as minimum value of fromi and ending point as maximum of toi. This means we will create an array of size (max(toi) - min(fromi) + 1). Fortunately our constraints are 
also not too large. This timeline will contain the count of passengers at a particular time. So whenever some passengers start a trip there count will be added at that time and whenever some passengers end a trip
their count is subtracted from that time. This is how we will keep track of passenger count at each point of timeline. Then we will aggregate the count with the help of prefix sum this will help us in keeping
track of total passengers at given time. If running sum > capacity at any point of time then the car cannot complete all the trips and our answer will be false.
