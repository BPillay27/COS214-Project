# Practicklers — Nursery Simulation

This Project contains a small nursery simulation.
It models plants, employees, customers, inventory and orders, and includes a Qt GUI to view and run the simulation.

[our live planning google doc.](https://docs.google.com/document/d/1fn1Ovq9XsSEPPt1roBBJOnbE4E4_Todo_keBedztCA0/edit?usp=sharing)

## Typical user flow:

1. Start the app. The main window launches and you can open the dashboard, nursery view or simulation view.
2. In the simulation view you can step thruogh the simulation. Plants age and may generate requests (water/prune/fertilise/moving).
3. Requests are handled by employees (gardener, inventory manager, salesman) delegated by the chain of responsibility.
4. Customers can create orders using the GUI; orders use commands and composite/decorator patterns to build complex items (Wrapping or Decorated Pots, special arrangements) and finally to check out.

## Installation & dependencies

These instructions assume a Linux environment (Ubuntu/Debian). So adjust package names for other distributions.

Required software:

- C++ with C++11 support
- latest CMake
  - installed using `sudo apt install cmake'
- Qt Creator [Installation available here](https://www.qt.io/download-qt-installer-oss)
- GoogleTest (for unit tests)

## Build (recommended: CMake)

Yeah we still figuring this one out

## Quick run

GUI build is still upcoming.

## Unit tests (GoogleTest)

This repository includes `unitTesting.cpp` which uses GoogleTest (`gtest`).

```bash
# from repo root
make unitTesting
./unitTesting
```

I don't understand how to run the gtests yet

## File map (organized by Design Patterns from UML)

### Chain of Responsibility Pattern
- `Employee.h/.cpp` - Abstract handler base class
- `Gardener.h/.cpp` - Handles plant care requests (water, prune, fertilise)
- `Salesman.h/.cpp` - Handles sales and customer interactions
- `InventoryManager.h/.cpp` - Handles inventory and restocking requests
- `Request.h/.cpp` - Request objects (Place, Water, Fertilise, Prune)

### State Pattern
- **Order States:** `OrderState.h/.cpp` - payment states
  - `AcceptPayment`, `DeclinePayment`, `ProcessingPayment`, `VerifyOrder`
- **Plant Maturity States:** `Maturity.h/.cpp` - plant lifecycle
  - `Seed`, `Sprout`, `Seedling`, `Mature`, `Dead`
- **Plant Condition States:** `Condition.h/.cpp` - plant health
  - `Healthy`, `Dehydrated`, `Malnurished`, `OverGrown`, combinations

### Command Pattern
- `Command.h/.cpp` - Abstract command interface
- `AddToOrder`, `RemoveFromOrder` - Concrete commands for order management
- `Customer.h/.cpp` - Invoker that buffers and executes commands

### Composite & Decorator Patterns
- `OrderComponent.h/.cpp` - Component interface for orders
- `Plant.h/.cpp` - Leaf component (Rose, Dandelion, AppleTree)
- `Arrangement.h/.cpp` - Composite for plant arrangements
- `PlantDecorator` - Base decorator class
- `DecorPot`, `Wrapping` - Concrete decorators

### Strategy Pattern
- `GreenHouseCare.h` - Strategy interface for plant care
- `Normal.h/.cpp`, `Bonsai.h/.cpp`, `Topiary.h/.cpp`, `Espalier.h/.cpp`, `Kokedama.h/.cpp` - Concrete care strategies

### Iterator Pattern
- `Iterator.h` - Abstract iterator interface
- `VectorIterator.h` - Concrete iterator implementation
- `Aggregate.h/.cpp` - Abstract aggregate with `PlantArea`, `PlantRow`

### Observer Pattern
- `Subject.h` - Observer interface for notifications
- Used by `Plant` and `Inventory` for request notifications

### Factory Method Pattern
- `Namer.h/.cpp` - Creator hierarchy for customer types
- `CivillianNamer`, `CommercialNamer` - Concrete creators
- Creates `Civillian`, `Commercial` customer products

### Singleton Pattern
- `Inventory.h/.cpp` - Singleton for global inventory management
- `Supplier.h/.cpp` - Plant suppliers (RoseSupplier, AppleSupplier, DandelionSupplier)

### Core Domain & Utilities
- `Nursery.h/.cpp` - Main nursery management and plant organization
- `Order.h/.cpp` - Order management and context for states
- `unitTesting.cpp` - GoogleTest unit tests covering all patterns

### GUI (Qt6 Application)
- `main.cpp`
- `mainwindow.h/.cpp/.ui`
- `dashboard.h/.cpp/.ui`
- `simulationview.h/.cpp/.ui`
- `nurseryview.h/.cpp/.ui`

## Team members

- Byron Pillay, u21516261
- Tshepiso Makelana, u23588579
- Mulondi Makhado, u24739163
- Arran Lamond, u23655675
- Keegan Lewis, u24594522
- Michael Neto, u24641342
- Ndamulelo Vele, u23554607
