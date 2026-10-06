# CarWashTerminals

**CarWashTerminals** is a software suite for managing self-service car wash terminals. The project is implemented using C++ (Qt/QML) and supports PostgreSQL and SQLite databases, as well as integration with YooKassa and QR code generation.

## Main Features

- User registration and authorization by phone number
- User balance management and top-up via terminal
- Data synchronization between local and central DB
- Top-up and transaction history
- Integration with YooKassa for online payments
- QR code generation for payment
- Modern QML interface with Material Design support
- Work with two DB types: PostgreSQL (central) and SQLite (local)
- Adaptation for touch terminals (fullscreen, large elements)

## Project Structure

- `IPS4MCO/` — main application source code (C++/QML)
  - `accountmanager/` — user management, registration, authorization, top-up history
  - `db_manager/`, `engine/`, `controller/`, `pilotnt/` — auxiliary modules
  - `qml/` — QML UI components (screens, buttons, forms)
  - `images/`, `fonts/` — UI resources
- `config_manager/` — module for working with configurations and data types
- `qt-qrcode/` — library for QR code generation (C++/QML)
- `audio/` — sound files for the terminal
- `config/` — configuration files (colors, UI, modbus)
- `build-*/` — build directories (created automatically during compilation)

## Quick Start

1. **Requirements:**
   - Qt 6.9+ (Qt Quick, Qt SQL, Qt Network)
   - CMake or qmake
   - PostgreSQL server (for central DB)
   - C++17+ compiler

2. **Build:**
   - Open `IPS4MCO.pro` in Qt Creator or use qmake:
     ```
     qmake IPS4MCO.pro
     make
     ```
   - To build the QR library, use the project in `qt-qrcode/`.

3. **Run:**
   - Run the built binary.
   - To work with the central DB, specify connection parameters in `accountmanager.cpp` (host, user, password, dbname).
   - For testing, you can use only SQLite (locally).

4. **Configuration:**
   - Modify the configs in `config/` as needed.
   - For YooKassa integration, specify your ShopId and SecretKey in `main.cpp`.

## Main Files

- `IPS4MCO/main.cpp` — entry point, initialization of engine, QML, providers
- `IPS4MCO/main.qml` — main QML window, screen navigation
- `IPS4MCO/accountmanager/accountmanager.cpp` — user and balance logic
- `qt-qrcode/` — QR code generation for payment

## License

The project is distributed under the MIT license. See the `LICENSE` file for details.
