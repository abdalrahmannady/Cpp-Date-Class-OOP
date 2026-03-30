# 📅 clsDate: Robust C++ Date Management Library

A comprehensive, Object-Oriented C++ library for date manipulation, validation, and calculations. Built with a focus on **Clean Code**, **Static vs Instance logic**, and **Operator Overloading**.

---

## 🚀 Key Features

* **Smart Parsing:** Initialize dates from strings (`DD/MM/YYYY`), specific values, or the current system time.
* **Precise Validation:** Automatic check for valid days per month, including **Leap Year** logic for February.
* **Operator Overloading:** Use intuitive syntax like `date1 < date2`, `date1 == date2`, and direct printing with `std::cout << date`.
* **Static Engine:** Core logic is accessible via static methods, allowing for utility-style usage without creating objects.
* **Arithmetic:** Calculate the exact difference in days between two dates and increment dates easily.

---

### Initialization

### 🛠️ Usage Examples

```cpp
clsDate today;                 // Current system date
clsDate birthDate(1, 1, 2000);  // Manual entry
clsDate projectDate("30/3/2026"); // From string

```

Technical Specifications

Language: C++

Paradigm: Object-Oriented Programming (OOP)

Features Used: Constructors, Static Methods, const correctness, Operator Overloading,

👨‍💻 Author
Abdelrahman Younis Self-Taught Programmer 
If this library helped you, don't forget to give it a ⭐!
