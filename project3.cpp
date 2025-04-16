#include <bits/stdc++.h>
#include <fstream>
std::map<std::string, std::vector<std::string>> bookingHistory;
using namespace std;

int p = 0; // Total number of buses

class a {
private:
    char busn[5], driver[10], arrival[10], depart[10], from[10], to[10], seat[8][4][10];

public:
    void addNewBus();
    void allotmentOfSeatToPassenger();
    void empty();
    void showAvailableBusSeats();
    void showAvailableBuses();
    void showReservedBusSeats(int i);

    const char* getBusNo() const { return busn; }
    const char* getDriver() const { return driver; }
    const char* getArrival() const { return arrival; }
    const char* getDepart() const { return depart; }
    const char* getFrom() const { return from; }
    const char* getTo() const { return to; }
    char* getSeat(int i, int j) { return seat[i][j]; }

    void setBusNo(const char* val) { strcpy(busn, val); }
    void setDriver(const char* val) { strcpy(driver, val); }
    void setArrival(const char* val) { strcpy(arrival, val); }
    void setDepart(const char* val) { strcpy(depart, val); }
    void setFrom(const char* val) { strcpy(from, val); }
    void setTo(const char* val) { strcpy(to, val); }
    void setSeat(int i, int j, const char* name) { strcpy(seat[i][j], name); }
} bus[25];

void vline(char ch) {
    for (int i = 75; i > 0; i--) cout << ch;
    cout << endl;
}

void a::addNewBus() {
    string input;
    cout << "Enter bus no: ";
    cin >> input; setBusNo(input.c_str());

    cout << "\nEnter Driver's name: ";
    cin >> input; setDriver(input.c_str());

    cout << "\nArrival time: ";
    cin >> input; setArrival(input.c_str());

    cout << "\nDeparture time: ";
    cin >> input; setDepart(input.c_str());

    cout << "\nFrom: ";
    cin >> input; setFrom(input.c_str());

    cout << "\nTo: ";
    cin >> input; setTo(input.c_str());

    empty();
    p++;
}

void a::allotmentOfSeatToPassenger() {
    char number[5];
top:
    cout << "Bus no: ";
    cin >> number;

    int n;
    for (n = 0; n < p; n++) {
        if (strcmp(bus[n].getBusNo(), number) == 0) break;
    }

    if (n >= p) {
        cout << "Enter correct bus no.\n";
        goto top;
    }

    int count;
    cout << "How many seats do you want to reserve? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        int seat;
        cout << "\nEnter seat number (1-32): ";
        cin >> seat;

        if (seat > 32 || seat < 1) {
            cout << "Invalid seat number. There are only 32 seats available.\n";
            continue;
        }

        int row = (seat - 1) / 4;
        int col = (seat - 1) % 4;

        if (strcmp(bus[n].getSeat(row, col), "Empty") == 0) {
            cout << "Enter passenger's name for seat " << seat << ": ";
            string pname;
            cin >> pname;
            bus[n].setSeat(row, col, pname.c_str());

            // Add to booking history
            string seatLabel = string(bus[n].getBusNo()) + "-Seat" + to_string(seat);
            bookingHistory[pname].push_back(seatLabel);

            cout << "Seat " << seat << " reserved successfully for " << pname << ".\n";
        } else {
            cout << "Seat " << seat << " is already reserved for " << bus[n].getSeat(row, col) << ".\n";
        }
    }
}

void a::empty() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            setSeat(i, j, "Empty");
}

void a::showAvailableBusSeats() {
    int n;
    char number[5];
    while (true) {
        cout << "Enter bus no: ";
        cin >> number;
        for (n = 0; n < p; n++) {
            if (strcmp(bus[n].getBusNo(), number) == 0)
                break;
        }
        if (n < p) break;
        else cout << "Incorrect bus no. Please try again.\n";
    }

    vline('*');
    cout << "\nBus no: \t" << bus[n].getBusNo()
         << "\nDriver: \t" << bus[n].getDriver()
         << "\tArrival: \t" << bus[n].getArrival()
         << "\tDeparture: " << bus[n].getDepart()
         << "\nFrom: \t\t" << bus[n].getFrom()
         << "\tTo: \t\t" << bus[n].getTo() << "\n";
    vline('*');

    bus[n].showReservedBusSeats(n);

    int seatNo = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            if (strcmp(bus[n].getSeat(i, j), "Empty") != 0) {
                cout << "\nThe seat no " << seatNo << " is reserved for " << bus[n].getSeat(i, j) << ".";
            }
            seatNo++;
        }
    }
}

void a::showReservedBusSeats(int l) {
    int s = 1, h = 0;
    for (int i = 0; i < 8; i++) {
        cout << "\n";
        for (int j = 0; j < 4; j++) {
            cout.width(5); cout.fill(' ');
            cout << s << ".";
            cout.width(10); cout.fill(' ');
            cout << bus[l].getSeat(i, j);
            if (strcmp(bus[l].getSeat(i, j), "Empty") == 0) h++;
            s++;
        }
    }
    cout << "\n\nThere are " << h << " seats empty in Bus No: " << bus[l].getBusNo();
}

void a::showAvailableBuses() {
    for (int n = 0; n < p; n++) {
        vline('*');
        cout << "Bus no: \t" << bus[n].getBusNo()
             << "\nDriver: \t" << bus[n].getDriver()
             << "\tArrival: \t" << bus[n].getArrival()
             << "\tDeparture: \t" << bus[n].getDepart()
             << "\nFrom: \t\t" << bus[n].getFrom()
             << "\tTo: \t\t" << bus[n].getTo() << "\n";
        vline('*');
        vline('_');
    }
}

// ----------- New Search Functions ------------------

void searchBusByRoute() {
    string source, destination;
    cout << "Enter source location: ";
    cin >> source;
    cout << "Enter destination location: ";
    cin >> destination;

    bool found = false;
    for (int i = 0; i < p; i++) {
        if (strcmp(bus[i].getFrom(), source.c_str()) == 0 &&
            strcmp(bus[i].getTo(), destination.c_str()) == 0) {
            vline('*');
            cout << "Bus no: " << bus[i].getBusNo()
                 << ", Driver: " << bus[i].getDriver()
                 << ", Arrival: " << bus[i].getArrival()
                 << ", Departure: " << bus[i].getDepart() << endl;
            vline('*');
            found = true;
        }
    }

    if (!found)
        cout << "No buses found for this route.\n";
}

void searchBusByTime() {
    string time;
    int type;
    cout << "Search by:\n1. Arrival Time\n2. Departure Time\nChoice: ";
    cin >> type;
    cout << "Enter time (e.g., 10:30AM): ";
    cin >> time;

    bool found = false;
    for (int i = 0; i < p; i++) {
        if ((type == 1 && strcmp(bus[i].getArrival(), time.c_str()) == 0) ||
            (type == 2 && strcmp(bus[i].getDepart(), time.c_str()) == 0)) {
            vline('*');
            cout << "Bus no: " << bus[i].getBusNo()
                 << ", Driver: " << bus[i].getDriver()
                 << ", Arrival: " << bus[i].getArrival()
                 << ", Departure: " << bus[i].getDepart()
                 << ", Route: " << bus[i].getFrom() << " -> " << bus[i].getTo() << endl;
            vline('*');
            found = true;
        }
    }

    if (!found)
        cout << "No buses found for the given time.\n";
}

void searchBusByAvailability() {
    bool found = false;
    for (int i = 0; i < p; i++) {
        int emptySeats = 0;
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 4; col++) {
                if (strcmp(bus[i].getSeat(row, col), "Empty") == 0) {
                    emptySeats++;
                }
            }
        }

        if (emptySeats > 0) {
            vline('*');
            cout << "Bus no: " << bus[i].getBusNo()
                 << ", From: " << bus[i].getFrom()
                 << ", To: " << bus[i].getTo()
                 << ", Available Seats: " << emptySeats << endl;
            vline('*');
            found = true;
        }
    }

    if (!found)
        cout << "All buses are fully booked.\n";
}

void cancelReservation() {
    string busNo, pname;
    int seat;
    cout << "Enter Bus Number: ";
    cin >> busNo;
    cout << "Enter Seat Number to Cancel (1-32): ";
    cin >> seat;
    cout << "Enter Passenger Name: ";
    cin >> pname;

    for (int i = 0; i < p; i++) {
        if (strcmp(bus[i].getBusNo(), busNo.c_str()) == 0) {
            int row = (seat - 1) / 4;
            int col = (seat - 1) % 4;

            if (strcmp(bus[i].getSeat(row, col), pname.c_str()) == 0) {
                bus[i].setSeat(row, col, "Empty");
                cout << "Reservation for " << pname << " at seat " << seat << " has been cancelled.\n";

                // Remove from booking history
                string label = busNo + "-Seat" + to_string(seat);
                auto &bookings = bookingHistory[pname];
                bookings.erase(remove(bookings.begin(), bookings.end(), label), bookings.end());

                return;
            } else {
                cout << "No reservation found at that seat for " << pname << ".\n";
                return;
            }
        }
    }
    cout << "Bus number not found.\n";
}

void showBookingHistory() {
    string pname;
    cout << "Enter passenger name to view history: ";
    cin >> pname;

    if (bookingHistory.find(pname) != bookingHistory.end() && !bookingHistory[pname].empty()) {
        cout << pname << "'s Booking History:\n";
        for (const string& seat : bookingHistory[pname]) {
            cout << " - " << seat << "\n";
        }
    } else {
        cout << "No booking history for " << pname << ".\n";
    }
}

// --------- File Handling ---------

void saveData() {
    ofstream ofs("busData.txt");
    if (!ofs) {
        cerr << "Error opening file for saving data." << endl;
        return;
    }
    ofs << p << "\n";
    for (int i = 0; i < p; i++) {
        ofs << bus[i].getBusNo() << "\n";
        ofs << bus[i].getDriver() << "\n";
        ofs << bus[i].getArrival() << "\n";
        ofs << bus[i].getDepart() << "\n";
        ofs << bus[i].getFrom() << "\n";
        ofs << bus[i].getTo() << "\n";
        for (int row = 0; row < 8; row++)
            for (int col = 0; col < 4; col++)
                ofs << bus[i].getSeat(row, col) << "\n";
    }
    ofs.close();
}

void loadData() {
    ifstream ifs("busData.txt");
    if (!ifs) return;
    ifs >> p;
    ifs.ignore();
    for (int i = 0; i < p; i++) {
        string temp;
        getline(ifs, temp); bus[i].setBusNo(temp.c_str());
        getline(ifs, temp); bus[i].setDriver(temp.c_str());
        getline(ifs, temp); bus[i].setArrival(temp.c_str());
        getline(ifs, temp); bus[i].setDepart(temp.c_str());
        getline(ifs, temp); bus[i].setFrom(temp.c_str());
        getline(ifs, temp); bus[i].setTo(temp.c_str());
        for (int row = 0; row < 8; row++)
            for (int col = 0; col < 4; col++) {
                getline(ifs, temp);
                bus[i].setSeat(row, col, temp.c_str());
            }
    }
    ifs.close();
}

// ---------------- Main Program ----------------

int main() {
    int choice;

    loadData();

    vline('-');
    cout << "\t\t\t\t*SM Bus Travel Agency*" << endl << endl;
    vline('-');

    while (1) {
        cout << endl;
        vline('*');
        cout << "\n\n";
        cout << "\t1. Add new Bus Details:\n"
             << "\t2. Reserve your seats:\n"
             << "\t3. Show the available seats in a bus:\n"
             << "\t4. Buses Available Now:\n"
             << "\t5. Search Bus by Route:\n"
             << "\t6. Search Bus by Time:\n"
             << "\t7. Search Bus by Availability:\n"
             << "\t8. cancel Reservation:\n"
             << "\t9. Show Booking History:\n"
             << "\t10. For Logout:\n";
        vline('*');
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        vline('*');

        switch (choice) {
            case 1: bus[p].addNewBus(); break;
            case 2: bus[0].allotmentOfSeatToPassenger(); break;
            case 3: bus[0].showAvailableBusSeats(); break;
            case 4: bus[0].showAvailableBuses(); break;
            case 5: searchBusByRoute(); break;
            case 6: searchBusByTime(); break;
            case 7: searchBusByAvailability(); break;
            case 8: cancelReservation(); break;
            case 9: showBookingHistory(); break;
            case 10:
                saveData();
                cout << "Successfully Logged out. Visit Again!\n";
                exit(0);
            default: cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
