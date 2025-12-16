# Payment Switch System - Reconstructed C++ Source

This directory contains C++ source files reconstructed from log file analysis.
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
- `transactionstore.h/.cpp` - In-memory transaction storage (Redis)
- `transactionprofile.h/.cpp` - Transaction timeout and profile configuration
- `imd.h/.cpp` - Issuer Master Data (BIN lookup)
- `ruleengine.h/.cpp` - Business rule engine
- `paymentnetwork.h/.cpp` - Payment network configurations

### Channel & Routing
- `channelmgr.h/.cpp` - Channel manager for failsafe and destination handling
- `routing.h/.cpp` - Transaction routing based on BIN/routing tags
- `loadbalancer.h/.cpp` - Connection load balancing and status

### Card Management (CCA/CMS)
- `cca.h/.cpp` - Card/Customer Account manager (limits, blacklist, validation)
- `cmschannel.h/.cpp` - CMS channel configuration

### Product Configuration
- `product.h/.cpp` - Product manager
- `productdetail.h/.cpp` - Product details
- `productchannel.h/.cpp` - Product channel configuration
- `productchanneltran.h/.cpp` - Product channel transaction configuration
- `productaccounttran.h/.cpp` - Product account transaction configuration
- `productalerts.h/.cpp` - Product alerts configuration
- `productcardvalidity.h/.cpp` - Product card validity

### Translation Layer
- `translationmgr.h/.cpp` - Translation manager
- `translator.h/.cpp` - Base translator class
- `translatoriso.h/.cpp` - ISO 8583 translator
- `translatormastercard.h/.cpp` - Mastercard-specific translator
- `translator1linkiso.h/.cpp` - 1Link ISO 8583 translator
- `ientity.h/.cpp` - Dynamic entity/library loading

### 1Link Processing
- `onelinkiss.h/.cpp` - 1Link issuer processing
- `onelinkissnonfinancial.h/.cpp` - 1Link non-financial transactions
- `onelinkbalanceinquiry.h/.cpp` - 1Link balance inquiry

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

## Coverage Status

The dummy code files now cover the **critical** source files frequently referenced in the log files:

| Category | Files | Status |
|----------|-------|--------|
| Core Transaction Processing | transactionprocess, transactionmgr, transaction | ✅ Covered |
| Translation Layer | translationmgr, translator, translatoriso, translatormastercard | ✅ Covered |
| Channel/Routing | channelmgr, routing, loadbalancer | ✅ Covered |
| Card/Account Management | cca, cmschannel | ✅ Covered |
| Product Configuration | product, productdetail, productchannel, productchanneltran, productaccounttran, productalerts, productcardvalidity | ✅ Covered |
| 1Link Processing | onelinkiss, onelinkissnonfinancial, onelinkbalanceinquiry, translator1linkiso | ✅ Covered |
| Transaction Storage | transactionstore, transactionprofile | ✅ Covered |
| Database/Cache | dbconnmgr, rediscache, redisconnectionmgr | ✅ Covered |
| Utility | configuration, message, imd, saf, safstore, ruleengine, paymentnetwork | ✅ Covered |
