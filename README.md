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

---

## 🤖 AI Log Analyzer Agent

This repository includes an AI-powered agent that analyzes log files, identifies errors, proposes fixes, and creates GitHub Pull Requests.

### Quick Start

```bash
# 1. Install dependencies
pip install -r requirements.txt

# 2. Run setup wizard
python -m agent.main setup

# 3. Analyze a log file
python -m agent.main analyze "logs for reference/log_sample.o"
```

### Features

- **Error Detection**: Parses logs and extracts ERROR/CRITICAL entries
- **AI Analysis**: Uses Google Gemini to analyze root causes
- **Smart Classification**: Distinguishes code bugs from config/data issues
- **Fix Generation**: Proposes code changes or config/data fixes
- **GitHub Integration**: Creates PRs with fixes automatically

### Commands

| Command | Description |
|---------|-------------|
| `analyze <log>` | Analyze a log file interactively |
| `analyze <log> --dry-run` | Analyze without creating PRs |
| `analyze <log> --batch` | List errors without interactive prompts |
| `config` | Show current configuration |
| `setup` | Interactive setup wizard |

### Configuration

Copy `.env.example` to `.env` and configure:

```env
GOOGLE_API_KEY=your_gemini_api_key    # Get from: https://aistudio.google.com/apikey
GITHUB_TOKEN=your_github_token        # Create at: https://github.com/settings/tokens
GITHUB_REPO=owner/repo                 # Your repository
```

### Architecture

```
agent/
├── main.py          # CLI entry point
├── graph.py         # LangGraph state machine
├── nodes/           # Processing nodes
│   ├── log_parser.py
│   ├── error_analyzer.py
│   ├── fix_generator.py
│   └── github_integration.py
├── models/          # Data models
└── prompts/         # LLM prompts
```
