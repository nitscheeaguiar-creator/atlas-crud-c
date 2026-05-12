# ATLAS — Sistema de Cadastro de Pessoas (CRUD em C)

Academic project developed in C as part of the ATLAS initiative  
at UNIALFA — Systems Analysis & Development (ADS), 2026.

## 📋 About

Terminal-based people registration system using structs, dynamic ID generation,  
and a menu-driven interface. The project is being built incrementally across  
academic milestones (M1 → MF).

## ✅ Current Features (M1)

- Register a person (name + CPF + auto-generated ID)
- List all registered people in a formatted table
- Input handling with `fgets` and `scanf`
- Limit of 100 records (`#define MAX 100`)

## 🚧 Upcoming Features

- [ ] Search by name or CPF
- [ ] Edit existing record
- [ ] Delete record
- [ ] File persistence (save/load from `.dat` file)
- [ ] Modular architecture (`.h` / `.c` files + Makefile)

## 🛠️ Tech Stack

- Language: C (C99)
- Compiler: GCC
- OS: Windows / Linux

## ▶️ How to Run

```bash
gcc main.c -o atlas
./atlas
```

## 📁 Project Structure

```
atlas-crud-c/
├── main.c        ← main file (current)
└── README.md
```

## 👤 Author

Nitsche Aguiar Araújo dos Santos  
github.com/nitscheeaguiar-creator
