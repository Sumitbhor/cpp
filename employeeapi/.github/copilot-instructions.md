## Purpose
Help AI coding agents be productive in this repository by describing the architecture, conventions, build/run steps, and important implementation patterns.

## High-level architecture
- This is a small C++ REST API server using `httplib.h` for HTTP routing (`main.cpp`).
- Major layers (files/dirs):
  - `entitity/` — domain models (note: folder name is `entitity`, not `entity`). Example: `entitity/employee.h`.
  - `SQL_repository/` — data access using MySQL C API. Example: `SQL_repository/EmployeeRepository.cpp`.
  - `services/` — service/business layer that depends on `IEmployeeRepository`. Example: `services/EmployeeServices.cpp`.
  - `Controller/` — translates HTTP params to service calls. Example: `Controller/EmployeeController.cpp`.
  - `Router/` — registers routes on `httplib::Server`. Example: `Router/EmployeeRouter.cpp`.
  - `Database/` — low-level DB connection wrapper. Example: `Database/connection.h`.

Why this shape: controllers handle request/response, services encapsulate business rules and call repository interfaces, and repository implements persistence. The `main.cpp` wires concrete implementations together (manual DI) and starts the `httplib` server.

## Important implementation patterns and gotchas
- Dependency injection is manual: `main.cpp` constructs `EmployeeRepository`, passes pointer to `EmployeeServices`, which is passed (by reference) to `EmployeeController` and then `Router`.
- Interfaces: look for `IEmployeeRepository.h` (used by `EmployeeServices`) — prefer changes through interfaces to avoid breaking consumers.
- SQL construction uses C-style `sprintf`/`snprintf` with raw values in `SQL_repository/EmployeeRepository.cpp` (easy to locate). These are direct SQL strings using MySQL C API (`mysql_query`, `mysql_store_result`).
- DB connection: `Database/connection.h` (`dbmanager`) calls `mysql_real_connect` with hardcoded credentials (`localhost`, `root`, `root123`, `Employee`). Any DB changes likely require updating this file and ensuring the `byte` macro workaround remains (see file top-level macros).
- Windows + MySQL header quirks: code uses `#define byte win_byte_override` and `#undef byte` around `windows.h` and `mysql.h` to avoid symbol conflicts. Preserve this pattern when editing includes.
- CORS is enabled in `main.cpp` and `OPTIONS` handler returns HTTP 204 — do not remove unless intentionally altering cross-origin behavior.

## HTTP routes (examples)
- GET `/api/Employees` -> `EmployeeController::getAllEmployees` -> `services::getAllemployees` -> `SQL_repository::getAllEmployees`
- POST `/api/Employee/add` -> controller `addEmployee` (reads params via `req.get_param_value`)
- DELETE `/api/Employee/delete` and PUT `/api/Employee/update` follow the same param-driven pattern.

## Build & run (project-specific)
- The repository does not include a build system; use the g++ command embedded in `main.cpp` comments on Windows (MinGW/WSL) and ensure MySQL client include/lib paths are correct. Example from `main.cpp`:

```bash
g++ main.cpp ./services/EmployeeServices.cpp ./SQL_repository/EmployeeRepository.cpp ./Controller/EmployeeController.cpp ./Router/EmployeeRouter.cpp -o server.exe -D_WIN32_WINNT=0x0A00 -lws2_32 -lwsock32 -I "C:\Program Files\MySQL\MySQL Server 8.0\include" -L "C:\Program Files\MySQL\MySQL Server 8.0\lib" -lmysql
```

- The server listens on `localhost:9000`; confirm MySQL service is running and the `Employee` database exists (see `employeedatabase.sql` in repo).

## Conventions for edits
- Keep public function signatures in `Controller`, `services`, and repository interfaces stable where possible; tests and HTTP routes rely on them.
- When changing DB code, preserve the `dbmanager` usage pattern (`MYSQL* conn = db.getConnection()`), and maintain the `byte` macro workaround.
- Use `req.get_param_value("name")` style when interacting with HTTP parameters (controller code expects this format).

## Files to inspect when modifying behavior
- Routing: `Router/EmployeeRouter.cpp`
- Controllers: `Controller/EmployeeController.cpp`
- Services: `services/EmployeeServices.cpp`, `services/IEmployeeServices.h`
- Persistence: `SQL_repository/EmployeeRepository.cpp`, `SQL_repository/IEmployeeRepository.h`
- DB config: `Database/connection.h`
- Entrypoint & wiring: `main.cpp`

## Safety notes for agents
- Do not change hardcoded DB credentials without explicit user instruction — notify and propose secure alternatives (env vars, config file).
- Avoid removing the `byte` macro guards; they are required for successful builds on Windows with these headers.
- If replacing raw SQL with parameterized queries, update both `add`, `update`, and `getAll` methods and ensure compilation with MySQL client libs.

## Example quick tasks an agent can perform
- Add a small README with build/run steps (if requested).
- Extract DB credentials into a single config header and document usage.
- Replace `sprintf` SQL with `mysql_stmt` prepared statements (large change — explain migration and run tests).

## Questions for the repo owner
- Do you want DB credentials moved to environment variables or left as-is?
- Which compiler/toolchain should be considered the canonical build environment (MinGW, MSVC, WSL)?

---
If any section is unclear or you want additional examples (e.g., step-by-step build on Windows or a minimal `CMakeLists.txt`), tell me which to add.
