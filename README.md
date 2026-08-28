# ✈️ Flight Reservation System (C-Based CLI)

A comprehensive, modular console application engineered in **C (C99 Standard)** for the **Programming for Problem Solving (PPS / CSE101)** curriculum. The project models real-world airline reservations with 2D visual seat maps, automated PNR generation, role-based administration, and persistent binary storage.

---

## 📌 Features

### 👤 Passenger Portal
- **Flight Inventory Explorer:** Real-time view of scheduled domestic routes, departure/arrival schedules, and available seats.
- **Route Search Engine:** Query available direct flights by origin and destination cities.
- **Interactive Visual Seat Allocation:** Dynamic 2D seat matrix visualizer with aisle formatting (`[O]` Available, `[X]` Occupied).
- **Automated PNR Generation:** Automatic creation of random 6-character alphanumeric PNR codes.
- **E-Ticket & Boarding Pass Viewer:** Formatted ticket retrieval with passenger metadata and pricing.
- **Reservation Cancellation & Refund Policy:** Instant seat release back to the pool with automated refund calculation (85% net refund).

### 🛠️ Administrative Control Center
- **Protected Access:** Passcode-secured administrative interface (`admin123`).
- **Schedule Management:** Add new direct flight routes with custom base pricing, origin, and destination.
- **Master Manifest Retrieval:** Centralized tabular reporting of all confirmed and cancelled bookings[cite: 1].

### 💾 Data Persistence & Architecture
- **Binary File Storage:** Automated disk read/write synchronization using `flights.dat` and `bookings.dat`[cite: 1].
- **Defensive Input Handling:** Buffer-clearing routines (`clearInputBuffer`) preventing input skips and trailing newline glitches[cite: 1].

---

## 🗂️ Project Structure

```text
flight-reservation-system/
