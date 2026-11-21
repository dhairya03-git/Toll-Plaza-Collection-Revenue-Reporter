
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Structure
struct Transaction {
    string vehicleNumber;
    string vehicleType;
    int lane;
    string timeSlot;
    double amount;
    bool returnJourney;
};

class TollPlaza {
private:
    Transaction t[100];
    int count;

    double getRate(string type) {
        if (type == "Car") return 100;
        else if (type == "Bike") return 50;
        else if (type == "Bus") return 200;
        else if (type == "Truck") return 300;
        else return 0;
    }

public:
    static int totalVehicles;

    TollPlaza() {
        count = 0;
    }

    // Record transaction
    void addTransaction() {
        if (count >= 100) {
            cout << "Transaction limit reached!\n";
            return;
        }

        cout << "\nEnter Vehicle Number: ";
        cin >> t[count].vehicleNumber;

        cout << "Vehicle Type (Car/Bike/Bus/Truck): ";
        cin >> t[count].vehicleType;

        cout << "Enter Lane Number (1-3): ";
        cin >> t[count].lane;

        if (t[count].lane < 1 || t[count].lane > 3) {
            cout << "Invalid lane number!\n";
            return;
        }

        cout << "Enter Time Slot: ";
        cin >> t[count].timeSlot;

        cout << "Return Journey? (1=Yes, 0=No): ";
        cin >> t[count].returnJourney;

        double rate = getRate(t[count].vehicleType);

        if (rate == 0) {
            cout << "Invalid vehicle type!\n";
            return;
        }

        t[count].amount = rate;

        if (t[count].returnJourney) {
            t[count].amount *= 0.5;
        }

        count++;
        totalVehicles++;

        cout << "\nTransaction Successful!\n";
        cout << "Toll Amount: Rs. "
             << t[count - 1].amount << endl;
    }

    // Report all lanes
    void report() {
        cout << "\n===== ALL LANES REPORT =====\n";

        for (int lane = 1; lane <= 3; lane++) {
            report(lane);
        }
    }

    // Report one lane
    void report(int lane) {
        double total = 0;

        cout << "\nLane " << lane << " Report\n";

        for (int i = 0; i < count; i++) {
            if (t[i].lane == lane) {
                cout << t[i].vehicleNumber << " "
                     << t[i].vehicleType << " Rs. "
                     << t[i].amount << endl;

                total += t[i].amount;
            }
        }

        cout << "Total Collection: Rs. "
             << total << endl;
    }

    // Report lane and vehicle type
    void report(int lane, string type) {
        double total = 0;
        int vehicles = 0;

        cout << "\nLane " << lane
             << " - " << type << " Report\n";

        for (int i = 0; i < count; i++) {
            if (t[i].lane == lane &&
                t[i].vehicleType == type) {

                cout << t[i].vehicleNumber
                     << " Rs. " << t[i].amount << endl;

                total += t[i].amount;
                vehicles++;
            }
        }

        cout << "Total Vehicles: " << vehicles << endl;
        cout << "Total Revenue: Rs. " << total << endl;
    }

    // Vehicle type wise report
    void vehicleTypeReport() {
        string types[] = {"Car", "Bike", "Bus", "Truck"};

        cout << "\n===== VEHICLE TYPE REPORT =====\n";

        for (int j = 0; j < 4; j++) {
            double total = 0;
            int vehicles = 0;

            for (int i = 0; i < count; i++) {
                if (t[i].vehicleType == types[j]) {
                    total += t[i].amount;
                    vehicles++;
                }
            }

            cout << types[j]
                 << " Vehicles: " << vehicles
                 << " Revenue: Rs. " << total << endl;
        }
    }

    // Save report to file
    void saveToFile() {
        ofstream file("shift_report.txt");

        if (!file) {
            cout << "File opening error!\n";
            return;
        }

        double grandTotal = 0;

        file << fixed << setprecision(2);
        file << "===== TOLL PLAZA SHIFT REPORT =====\n";

        for (int i = 0; i < count; i++) {
            file << "\nVehicle Number: "
                 << t[i].vehicleNumber;

            file << "\nVehicle Type: "
                 << t[i].vehicleType;

            file << "\nLane: " << t[i].lane;

            file << "\nTime Slot: "
                 << t[i].timeSlot;

            file << "\nReturn Journey: "
                 << (t[i].returnJourney ? "Yes" : "No");

            file << "\nAmount Paid: Rs. "
                 << t[i].amount;

            file << "\n--------------------------\n";

            grandTotal += t[i].amount;
        }

        file << "\nTotal Vehicles: " << count;
        file << "\nTotal Revenue: Rs. " << grandTotal;

        file.close();

        cout << "\nReport saved successfully!\n";
    }
};

// Static member definition
int TollPlaza::totalVehicles = 0;

// Main function
int main() {
    TollPlaza plaza;
    int choice;

    do {
        cout << "\n===== TOLL PLAZA SYSTEM =====\n";
        cout << "1. Record Transaction\n";
        cout << "2. Report All Lanes\n";
        cout << "3. Report Particular Lane\n";
        cout << "4. Report Lane and Vehicle Type\n";
        cout << "5. Vehicle Type Report\n";
        cout << "6. Total Vehicles\n";
        cout << "7. Save Shift Report\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                plaza.addTransaction();
                break;

            case 2:
                plaza.report();
                break;

            case 3: {
                int lane;
                cout << "Enter Lane: ";
                cin >> lane;

                if (lane >= 1 && lane <= 3)
                    plaza.report(lane);
                else
                    cout << "Invalid Lane!\n";
                break;
            }

            case 4: {
                int lane;
                string type;

                cout << "Enter Lane: ";
                cin >> lane;

                cout << "Enter Vehicle Type: ";
                cin >> type;

                if (lane >= 1 && lane <= 3)
                    plaza.report(lane, type);
                else
                    cout << "Invalid Lane!\n";
                break;
            }

            case 5:
                plaza.vehicleTypeReport();
                break;

            case 6:
                cout << "Total Vehicles: "
                     << TollPlaza::totalVehicles << endl;
                break;

            case 7:
                plaza.saveToFile();
                break;

            case 0:
                plaza.saveToFile();
                cout << "Program Closed!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
