#ifndef NURSERY_H
#define NURSERY_H

#include "Plant.h"
#include "Aggregate.h"
#include <vector>
#include <string>


/**
 * @file Nursery.h
 * @class Nursery
 * @ingroup Nursery
 *
 * @brief A class representing a nursery that manages a collection of plants.
 * This class provides different functionalities like add, remove, and manage plants within the nursery.
 * As well as helper function to display plant information.
 * 
 * @author Keegan Lewis
 * @date October 2025
 */

class Nursery {
    private:
        PlantArea* greenHouse;
        std::vector<Plant*> salesArea;
        int capacity;
        int walk;
        bool walking;
    public:
        /**
         * @brief Adds a plant to the green house.
         * @param plant A pointer to the Plant object to be added.
         * @return true if the plant was successfully added, false otherwise.
         */
        bool addPlant(Plant* plant);

        /**
         * @brief Removes a plant from the nursery.
         * @param plant A pointer to the Plant object to be removed.
         * @return true if the plant was successfully removed, false otherwise.
         */
        bool removePlant(Plant* plant);

        /**
         * @brief Destructor for the Nursery class.
         * Cleans up dynamically allocated Plant objects.
         */
        ~Nursery();
        /**
         * @brief Begins a walkthrough of the nursery, by setting the walk to 0 to show it is at salesArea[0].
         */
        void WalkThrough();

        /**
         * @brief Prints the plants that are currently in line of sight during the walkthrough.
         * @return a string representation of the plants in line of sight.
         */
        std::string printPlants();

        /**
         * @brief Moves to the next row in the walkthrough.
         * @return true if there are more rows to walk through, false if the end is reached.
         */
        bool nextRow();

        /**
         * @brief Moves to the previous row in the walkthrough.
         * @return true if there are previous rows to walk back to, false if at the beginning.
         */
        bool prevRow();

        /**
         * @brief Gets the plant at the specified index in the sales area.
         * @param index The index of the plant to retrieve.
         * @return A pointer to the Plant object at the specified index.
         */
        Plant* getPlant(int index);

        /**
         * @brief Moves a plant to the sales area.
         * @param plant A pointer to the Plant object to be moved.
         */
        bool moveToSales(std::string plantType);

        /**
         * @brief Provides recommended plant types based on current salesArea availability.
         * @return A vector of strings containing recommended plant types.
         */

        /**
         * @return A vector of strings containing recommended plant types.
         */

        std::vector<std::string> recommendations();

        /**
         * @brief Constructor for the Nursery class.
         * @param capacity The maximum capacity of the sales area of the nursery.
         */
        Nursery(int capacity);

        /**
         *  @brief Checks if there is space in the GreenHoes area.
         * @return true if there is space, false otherwise.
         */
        bool space();

        /**
        * @brief Grows all plants in the nursery.
        * @return void
        */
        void grow();

        /**
         * @brief Examines all plants in the nursery and prints their details.
         * @return void
         */
        void examine();

        // void pS();
};

#endif // NUSERY_H