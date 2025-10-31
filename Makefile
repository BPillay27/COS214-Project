
filesToDelete = unitTesting testingMain Aggregate Arrangement Bonsai Command Condition Customer dashboard Dead Employee Espalier Gardener Inventory InventoryManager Kokedama main mainwindow Maturity Namer Normal Nursery Order OrderComponent OrderState Plant Request Salesman Supplier Topiary
filesToCompile = unitTesting.cpp Aggregate.cpp Arrangement.cpp Bonsai.cpp Command.cpp Condition.cpp Customer.cpp dashboard.cpp Dead.cpp Employee.cpp Espalier.cpp Gardener.cpp Inventory.cpp InventoryManager.cpp Kokedama.cpp mainwindow.cpp Maturity.cpp Namer.cpp Normal.cpp Nursery.cpp Order.cpp OrderComponent.cpp OrderState.cpp Plant.cpp Request.cpp Salesman.cpp Supplier.cpp Topiary.cpp
filesInCoverageReport = unitTesting Aggregate Arrangement Bonsai Command Condition Customer dashboard Dead Employee Espalier Gardener Inventory InventoryManager Kokedama mainwindow Maturity Namer Normal Nursery Order OrderComponent OrderState Plant Request Salesman Supplier Topiary

main:
	g++ -g -std=c++11 ${filesToCompile} -o unitTesting

clean:
	rm *.o *.gcov *.gcda *.gcno *.gz *.html *.css output.txt coverage.txt -f ${filesToDelete}

coverage:
	make clean
	g++ -g --coverage -dumpbase '' ${filesToCompile} -o main
	./main > outputXD.txt
	gcov -f -m -r -j ${filesInCoverageReport} > coverage.txt 
	gcovr --html-details output.html
	#make clean

valgrind:
	make clean
	make
	valgrind --track-origins=yes --leak-check=full --keep-stacktraces=alloc-and-free --error-exitcode=1 --log-file=valgrind.txt ./unitTesting > output.txt
