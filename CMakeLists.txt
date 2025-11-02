cmake_minimum_required(VERSION 3.16)
project(COS_214_Practicklers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



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

# Find Qt6 components
find_package(Qt6 COMPONENTS Core Widgets)

if(Qt6_FOUND)
    message(STATUS "Qt6 found. Building GUI application.")

# Enable Qt's automatic MOC (Meta-Object Compiler)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

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

# Add a diagnostic message to confirm the source files are being loaded.
message(STATUS "Core sources: ${CORE_SOURCES}")

# Create the main executable
add_executable(${PROJECT_NAME}
    ${CORE_SOURCES}
    ${GUI_SOURCES}
    ${GUI_FORMS}
    simulationview.cpp
    nursaryview.cpp
)

# Link Qt6 libraries if they were found.
if(Qt6_FOUND)
    target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)
endif()

# Create console-only executable for testing (without Qt)
add_executable(${PROJECT_NAME}_console
    ${CORE_SOURCES}
    ${CORE_HEADERS}
    unitTesting.cpp
    testingMain.cpp
)
target_compile_definitions(${PROJECT_NAME}_console PRIVATE NO_QT_GUI)

# Copy UI files to build directory (if needed)
    configure_file(${CMAKE_SOURCE_DIR}/dashboard.ui ${CMAKE_BINARY_DIR}/dashboard.ui COPYONLY)
else()
    message(STATUS "Qt6 not found. GUI application will not be built.")
endif()


# Google Test setup
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Create a static library for the core logic
add_library(core_logic STATIC ${CORE_SOURCES})

# Create the Google Test executable
add_executable(unit_tests
    unitTesting.cpp
)
# Link the test executable against gtest and the core logic library
target_link_libraries(unit_tests gtest_main core_logic)
