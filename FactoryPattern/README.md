# Factory Design Pattern in C++

## AIM
To practise using the Factory design pattern to create objects based on a requested type.

## Chosen pattern: Factory
The Factory pattern is suitable when the program needs to create different related objects without exposing the object-construction details to the calling code. This example creates Car and Bike objects through one VehicleFactory.

## Class / object diagram

```text
             +------------------+
             |     Vehicle      |
             |------------------|
             | + showDetails()  |
             +------------------+
                 ^          ^
                 |          |
          +------+          +------+
          |                        |
+----------------+        +----------------+
|      Car       |        |      Bike      |
| showDetails()  |        | showDetails()   |
+----------------+        +----------------+

       +-------------------------+
       |     VehicleFactory      |
       |-------------------------|
       | + createVehicle(type)   |
       +-------------------------+
                  |
          creates Car or Bike
```

## Sample output
```text
VEHICLE FACTORY DEMONSTRATION
Created a Car: Four-wheeler vehicle.
Created a Bike: Two-wheeler vehicle.
Second car request: Created a Car: Four-wheeler vehicle.
```

## Use case
A vehicle booking or transport application may need to create different vehicle objects based on the user's selection. The calling code asks the factory for a vehicle and works with the common Vehicle interface.

## Benefit and trade-off
**Benefit:** Object creation is centralised, so the calling code does not need to know the construction details of each vehicle class. New vehicle types can be added with limited changes to client code.

**Trade-off:** The factory adds extra classes and code structure. For a very small program with only one object type, this may be unnecessary complexity.

## Compile and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o factory_demo
./factory_demo
```

## Result / observation
The program demonstrates the Factory design pattern by creating Car and Bike objects based on the requested type. It separates object creation from object use and returns objects through a common Vehicle interface.
