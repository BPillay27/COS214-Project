filesToDelete =Demo unitTesting testingMain Aggregate Arrangement Bonsai Command Condition Customer Dead Employee Espalier Gardener Inventory InventoryManager Kokedama main mainwindow Maturity Namer Normal Nursery Order OrderComponent OrderState Plant Request Salesman Supplier Topiary
filesToCompile = unitTesting.cpp Aggregate.cpp Arrangement.cpp Bonsai.cpp Command.cpp Condition.cpp Customer.cpp Dead.cpp Employee.cpp Espalier.cpp Gardener.cpp Inventory.cpp InventoryManager.cpp Kokedama.cpp Maturity.cpp Namer.cpp Normal.cpp Nursery.cpp Order.cpp OrderComponent.cpp OrderState.cpp Plant.cpp Request.cpp Salesman.cpp Supplier.cpp Topiary.cpp
filesInCoverageReport = unitTesting Aggregate Arrangement Bonsai Command Condition Customer dashboard Dead Employee Espalier Gardener Inventory InventoryManager Kokedama mainwindow Maturity Namer Normal Nursery Order OrderComponent OrderState Plant Request Salesman Supplier Topiary

filesToDemo = Demo.cpp Aggregate.cpp Arrangement.cpp Bonsai.cpp Command.cpp Condition.cpp Customer.cpp Dead.cpp Employee.cpp Espalier.cpp Gardener.cpp Inventory.cpp InventoryManager.cpp Kokedama.cpp Maturity.cpp Namer.cpp Normal.cpp Nursery.cpp Order.cpp OrderComponent.cpp OrderState.cpp Plant.cpp Request.cpp Salesman.cpp Supplier.cpp Topiary.cpp
unitTesting: ${filesToCompile}
	g++ -g -std=c++11  -Wextra ${filesToCompile} -o unitTesting

Demo: ${filesToDemo}
	g++ -g -std=c++11 ${filesToDemo} -o Demo

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.gz *.html *.css unitTestingOutput.txt  output.txt coverage.txt ${filesToDelete}

coverage:
	make clean
	g++ -g --coverage -dumpbase '' ${filesToCompile} -o main
	./main #> outputXD.txt
	gcov -f -m -r -j ${filesInCoverageReport} > coverage.txt 
	gcovr --html-details output.html

valgrind:
	make clean
	make
	valgrind --track-origins=yes --leak-check=full --keep-stacktraces=alloc-and-free --error-exitcode=1  ./unitTesting #> output.txt

test: unitTesting
	./unitTesting > unitTestingOutput.txt

Demos: Demo
	./Demo

vDemo: Demo
	valgrind --track-origins=yes --leak-check=full --keep-stacktraces=alloc-and-free --error-exitcode=1  ./Demo

demo:
	./Demo

