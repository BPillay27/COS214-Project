cmake_minimum_required(VERSION 3.16)
project(COS_214_Practicklers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Enable Qt's automatic MOC (Meta-Object Compiler)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Source files - Core classes (non-Qt)
set(CORE_SOURCES
    Plant.cpp
    Aggregate.cpp
    Arrangement.cpp
    Bonsai.cpp
    Command.cpp
    Condition.cpp
    Customer.cpp
    Dead.cpp
    Employee.cpp
    Espalier.cpp
    Gardener.cpp
    Inventory.cpp
    InventoryManager.cpp
    Kokedama.cpp
    Maturity.cpp
    Namer.cpp
    Normal.cpp
    Nursery.cpp
    Order.cpp
    OrderComponent.cpp
    OrderState.cpp
    Request.cpp
    Salesman.cpp
    Supplier.cpp
    Topiary.cpp
)

# Source files - Core headers (non-Qt)
set(CORE_HEADERS
    Plant.h
    Aggregate.h
    Arrangement.h
    Bonsai.h
    Command.h
    Condition.h
    Customer.h
    Dead.h
    Employee.h
    Espalier.h
    Gardener.h
    GreenHouseCare.h
    Inventory.h
    InventoryManager.h
    Iterator.h
    Kokedama.h
    Maturity.h
    Namer.h
    Normal.h
    Nursery.h
    Order.h
    OrderComponent.h
    OrderState.h
    Request.h
    Salesman.h
    Supplier.h
    Topiary.h
    VectorIterator.h
)

# Qt GUI files
set(GUI_SOURCES
    main.cpp
    mainwindow.cpp
    dashboard.cpp
)

set(GUI_HEADERS
    mainwindow.h
    dashboard.h
)

set(GUI_FORMS
    mainwindow.ui
    dashboard.ui
)

# Create the main executable
add_executable(${PROJECT_NAME}
    ${CORE_SOURCES}
    ${CORE_HEADERS}
    ${GUI_SOURCES}
    ${GUI_HEADERS}
    ${GUI_FORMS}
    simulationview.h simulationview.cpp simulationview.ui
    nursaryview.h nursaryview.cpp nursaryview.ui
)

# Link Qt6 libraries
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)

# Create console-only executable for testing (without Qt)
add_executable(${PROJECT_NAME}_console
    ${CORE_SOURCES}
    ${CORE_HEADERS}
    testingMain.cpp
)

# Console version doesn't need Qt
target_compile_definitions(${PROJECT_NAME}_console PRIVATE NO_QT_GUI)

# Copy UI files to build directory (if needed)
configure_file(${CMAKE_SOURCE_DIR}/dashboard.ui ${CMAKE_BINARY_DIR}/dashboard.ui COPYONLY)
