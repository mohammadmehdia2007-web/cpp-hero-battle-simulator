# Hero Battle Simulator

A turn-based hero battle simulator built with C++ using Object-Oriented Programming (OOP) principles. Instead of using generic archetype classes like a standard "Warrior," this project focuses on custom combat logic, an energy-management system, and unique abilities tailored for each specific hero.

## How It Works
The game runs entirely in the terminal (CLI). After launching, you choose your heroes and engage in a turn-based tactical battle. Every hero comes with their own unique stats, Health Points (HP), and a distinct energy system that regulates their moves. Winning requires careful energy management and using your abilities at the right moment.

## Key Features
* Distinct Hero Classes: Every hero has unique abilities and behaviors rather than just being a reskin of another class.
* Energy-Based Combat: Powerful skills require energy, meaning you have to plan ahead and manage your resources wisely.
* OOP-Driven Architecture: Leverages inheritance, polymorphism, and clean memory management to handle combat states and hero instances.
* Multi-File Structure: The codebase is split into dedicated header (.h) and implementation (.cpp) files to keep things clean and modular.

## Project Structure
Here are the core components of the project:
* Hero.h / Hero.cpp: The base class containing core attributes like HP, energy, and fundamental methods for attacking and taking damage.
* Derived Hero Classes: Individual hero implementations, each overriding behaviors to define their unique combat mechanics.
* Main.cpp: Handles user inputs, sets up the CLI interface, and drives the main battle loop.

## Getting Started
To run the simulator, you just need to compile the source files using a C++ compiler (like g++). 

If you are using a terminal, you can compile and run it with the following commands:

```bash
g++ -std=c++11 Main.cpp Hero.cpp <other_hero_cpp_files> -o simulator
./simulator
