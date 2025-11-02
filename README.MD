### Practicklers — Nursery Simulation

This Repository contains a small nursery simulation.
It models plants, employees, customers, inventory and orders, and includes a Qt GUI to view and run the simulation.

(i dont know if we should still include this part :P)
[our live planning google doc.](https://docs.google.com/document/d/1fn1Ovq9XsSEPPt1roBBJOnbE4E4_Todo_keBedztCA0/edit?usp=sharing)

## Typical user flow:

1. Start the app. The main window launches and you can open the dashboard, nursery view or simulation view.
2. In the simulation view you can step thruogh the simulation. Plants age and may generate requests (water/prune/fertilise/moving).
3. Requests are handled by employees (gardener, inventory manager, salesman) delegated by the chain of responsibility.
4. Customers can create orders using the GUI; orders use commands and composite/decorator patterns to build complex items (Wrapping or Decorated Pots, special arrangements) and finally to check out.

## Design patterns used (what, where, and why)

(W.I.P.)

## File map

- Plants & states, 
	- `Plant.*`, `Maturity.*`, `Condition.*`, `GreenHouseCare.*`, `Supplier.*`
- Inventory & suppliers
	- `Inventory.*`, `Supplier.*`, `InventoryManager.*`
- Orders & customers
	- `Order.*`, `OrderComponent.*`, `Command.*`, `Customer.*`, `Namer.*`
- Employees & requests
	- `Employee.*`, `Request.*`, `Gardener.*`, `Salesman.*`, `InventoryManager.*`
- Iterator / aggregates
	- `Iterator.h`, `VectorIterator.h`, `Aggregate.h`
- GUI
	- `main.cpp`, `mainwindow.*`, `dashboard.*`, `simulationview.*`, `nursaryview.*` (yes we have .ui files in the repo)

## Team members:

- Byron Pillay, u21516261
- Tshepiso Makelana, u23588579
- Mulondi Makhado, u24739163
- Arran Lamond, u23655675
- Keegan Lewis, u24594522
- Michael Neto, u24641342
- Ndamulelo Vele, u23554607
