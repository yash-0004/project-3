# 🚌 SM Bus Reservation System (C++ Console Project)

The **SM Bus Reservation System** is a terminal-based C++ project that simulates real-world bus booking functionalities. This system helps users reserve bus seats, cancel bookings, and check availability efficiently — just like real-life bus ticket counters, but in code!

It’s an excellent mini-project for **beginners in C++** to practice key concepts like **object-oriented programming**, **arrays**, **file handling**, and **STL containers** like `map` and `vector`.

---

## ✅ Features at a Glance

- ✍️ **Add Bus Details** (Number, Driver, Route, Timings)  
- 🪑 **Reserve Seats (1–32)** with passenger name  
- 🚫 **Cancel Seat Reservation**  
- 📋 **Show Available or Reserved Seats**  
- 🔎 **Search Bus by Route, Time or Availability**  
- 📚 **Booking History** tracking for each passenger  
- 💾 **File Handling** to save and load data across sessions  

---

## 🛠️ Tech Stack and Concepts

| Concept / Tool         | Usage |
|------------------------|-------|
| 🧱 **C++**              | Core programming language |
| 🔁 **OOP (Classes)**    | Bus logic encapsulated in class `a` |
| 📚 **STL - map**        | Tracks booking history for each passenger |
| 🧵 **STL - vector**     | Stores multiple seat reservations per user |
| 🗃️ **2D Array**         | Manages 32 seats per bus as `seat[8][4]` |
| 🧾 **File I/O**         | Persistent storage of bus and seat data |
| 🛣️ **Array of Objects** | Holds multiple bus entries: `a bus[25]` |

---

## 🧩 How Data is Structured

### 🎫 Seat Arrangement
- Each bus has `8 rows × 4 columns` = **32 seats**
- Stored in `char seat[8][4][10]` for names
- All initialized to `"Empty"` at first

### 🚍 Bus Details
Each bus object holds:
- Bus Number  
- Driver Name  
- Arrival & Departure Time  
- From & To Locations  
- Seat Matrix  

### 🗂️ Booking History
- Stored in a `map<string, vector<string>> bookingHistory`
- Each passenger name maps to a list of their seat labels (e.g., `Bus123-Seat21`)

---

## 🔍 Functionalities Explained

### 1. Add New Bus
- Takes details: Bus number, Driver, Route, Arrival & Departure time
- Initializes all seats to `"Empty"`

### 2. Reserve Seat
- Input bus number and seat number (1–32)
- Name is stored at corresponding seat
- Also updates `bookingHistory` with seat label

### 3. Show Available Seats
- Lists empty and reserved seats with passenger names
- Displays total available seats in that bus

### 4. Show All Buses
- Displays all registered buses with their details

### 5. Search by Route
- Filters and shows buses from a specific source to destination

### 6. Search by Time
- Filters buses by Arrival or Departure time

### 7. Search by Availability
- Lists all buses with remaining available seats

### 8. Cancel Reservation
- Input bus number, seat number, and passenger name
- If match is found, resets seat to `"Empty"` and removes from history

### 9. Booking History
- View all booked seats for a particular passenger

### 10. Exit
- Saves all bus and seat data to `busData.txt` for persistence

---

## 🗃️ File Handling

Data is **saved to and loaded from `busData.txt`**:
- On exit: Bus and seat info is written
- On startup: Data is loaded automatically so previous session continues

---

## 📌 Implementation Insights

### 🔹 About Project
A terminal-based C++ app that allows users to manage bus seat bookings, cancellations, and data persistence. Great for practicing key C++ concepts and working with real-world simulation logic.

### 🔹 Local Setup Instructions
1. Clone or download this repository.
2. Compile the code using a C++ compiler:  
   ```bash
   g++ main.cpp -o BusReservation
   ```
3. Run the executable:  
   ```bash
   ./BusReservation
   ```

### 🔹 Basic Working
- System starts with existing data (if any).
- Users can add buses, reserve or cancel seats, search buses, and check availability.
- All actions are reflected in the persistent storage file (`busData.txt`).

### 🔹 Data Structures Used
- **Class `a`**: Represents each bus
- **Array of Objects**: `a bus[25]` stores all buses
- **2D Array**: `seat[8][4][10]` for seat names
- **`map<string, vector<string>>`**: Booking history by passenger name

### 🔹 Project Modeling
- Every bus is modeled as an object.
- Seats are tracked via a 2D char array with passenger names.
- History is tracked using STL containers.
- File I/O ensures data is retained across sessions.

### 🔹 Future Work
- GUI using libraries like Qt or SFML
- Admin/User role separation
- Online syncing or database backend
- SMS/email notification simulation
- More robust error handling and edge case management
- For all different functions we will create each header file

---



