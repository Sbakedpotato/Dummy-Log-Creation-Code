# Payment Switch System - Reconstructed C++ Source

This repository contains C++ source files reconstructed from log file analysis.
The code simulates the payment switch system's logging behavior and control flow.

## Files Structure

### Core Utilities
- `logger.h` - Logging utility with format matching the original logs
- `configuration.h/.cpp` - Configuration parameter management

### Data Classes
- `message.h/.cpp` - Message representation and operations
- `saf.h/.cpp` - Store and Forward mechanism
- `safstore.h/.cpp` - SAF persistent storage

### Database & Cache
- `dbconnmgr.h/.cpp` - Database connection manager (Oracle)
- `redisconnectionmgr.h/.cpp` - Redis connection manager
- `rediscache.h/.cpp` - Redis cache wrapper

### Business Logic
- `transactionprocess.h/.cpp` - Main transaction processing entry point
- `transactionmgr.h/.cpp` - Transaction manager
- `transaction.h/.cpp` - Transaction representation
- `imd.h/.cpp` - Issuer Master Data (BIN lookup)
- `ruleengine.h/.cpp` - Business rule engine
- `paymentnetwork.h/.cpp` - Payment network configurations

### Translation Layer
- `translationmgr.h/.cpp` - Translation manager
- `translator.h/.cpp` - Base translator class
- `translatoriso.h/.cpp` - ISO 8583 translator
- `translatormastercard.h/.cpp` - Mastercard-specific translator
- `ientity.h/.cpp` - Dynamic entity/library loading

### Entry Point
- `main.cpp` - Application entry point

## Building

To compile the project (requires C++11 or later):

```bash
g++ -std=c++11 -I. *.cpp -o payment_switch
```

## Running

```bash
./payment_switch
```

The simulation will output logs in the same format as the original system.
