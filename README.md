# CPP Module 02

Fixed-point number class implementation in C++98 as part of the 42 school curriculum.
This module explores operator overloading, the Orthodox Canonical Form,
and fixed-point arithmetic through three progressive exercises.

## Technologies

- C++98
- Makefile

## Build Instructions

Each exercise is self-contained in its own directory. To compile:

```bash
cd ex00  # or ex01, ex02
make
```

Available Makefile targets:

| Command       | Description                  |
|---------------|------------------------------|
| `make`        | Compile the project          |
| `make clean`  | Remove object files          |
| `make fclean` | Remove object files + binary |
| `make re`     | Full recompile               |

## Usage

After building, run the executable from the corresponding exercise directory:

```bash
./Fixed
```

## Exercises

- **ex00** -- Orthodox Canonical Form: default constructor, copy constructor,
  copy assignment operator, destructor, and raw bits accessors.
- **ex01** -- Int/float constructors, `toFloat()` and `toInt()` conversion
  methods, and `operator<<` overload for stream output.
- **ex02** -- Full operator overloading: comparison (`>`, `<`, `>=`, `<=`,
  `==`, `!=`), arithmetic (`+`, `-`, `*`, `/`), increment/decrement
  (pre and post), and static `min`/`max` functions.

## Key Concepts

- **Fixed-point arithmetic**: 8 fractional bits stored in an `int`, enabling
  fractional representation without floating-point types.
- **Orthodox Canonical Form**: every class implements the four required
  special member functions.
- **Operator overloading**: custom behavior for comparison, arithmetic,
  increment/decrement, and stream insertion operators.
