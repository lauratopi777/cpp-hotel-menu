#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

const int MAX = 100;

// Struktura e rezervimit
struct Reservation {
    string guestName;
    string roomType;
    string checkInDate;
    string checkOutDate;
};

Reservation reservations[MAX];
int reservationCount = 0;

// Kontrollon nese string ka vetem shkronja dhe hapesira
bool isOnlyLetters(const string& text) {
    if (text.empty()) return false;

    for (int i = 0; i < text.length(); i++) {
        if (!isalpha(text[i]) && text[i] != ' ')
            return false;
    }
    return true;
}

// Kontrollon nese data ka vetem numra dhe -
bool isValidDate(const string& date) {
    if (date.empty()) return false;

    for (int i = 0; i < date.length(); i++) {
        if (!isdigit(date[i]) && date[i] != '-')
            return false;
    }
    return true;
}

// Shto rezervim
void addReservation() {
    if (reservationCount >= MAX) {
        cout << "Nuk mund te shtohen me shume rezervime.\n";
        return;
    }

    // Emri
    do {
        cout << "Emri i mysafirit: ";
        getline(cin, reservations[reservationCount].guestName);
        if (!isOnlyLetters(reservations[reservationCount].guestName))
            cout << "Provoje perseri!\n";
    } while (!isOnlyLetters(reservations[reservationCount].guestName));

    // Dhoma
    cout << "Lloji i dhomes: ";
    getline(cin, reservations[reservationCount].roomType);

    // Data hyrjes
    do {
        cout << "Data e hyrjes (DD-MM-YYYY): ";
        getline(cin, reservations[reservationCount].checkInDate);
        if (!isValidDate(reservations[reservationCount].checkInDate))
            cout << "Provoje perseri daten e hyrjes!\n";
    } while (!isValidDate(reservations[reservationCount].checkInDate));

    // Data daljes
    do {
        cout << "Data e daljes (DD-MM-YYYY): ";
        getline(cin, reservations[reservationCount].checkOutDate);
        if (!isValidDate(reservations[reservationCount].checkOutDate))
            cout << "Provoje perseri daten e daljes!\n";
    } while (!isValidDate(reservations[reservationCount].checkOutDate));

    reservationCount++;
    cout << "Rezervimi u shtua me sukses!\n";
}

// Shfaq rezervimet
void viewReservations() {
    if (reservationCount == 0) {
        cout << "Nuk ka rezervime.\n";
        return;
    }

    for (int i = 0; i < reservationCount; i++) {
        cout << "\nRezervimi " << i + 1 << endl;
        cout << "Emri: " << reservations[i].guestName << endl;
        cout << "Dhoma: " << reservations[i].roomType << endl;
        cout << "Hyrja: " << reservations[i].checkInDate << endl;
        cout << "Dalja: " << reservations[i].checkOutDate << endl;
    }
}

// Kerko rezervim
void searchReservation() {
    string name;
    cout << "Shkruaj emrin per kerkimin: ";
    getline(cin, name);

    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].guestName == name) {
            cout << "\nRezervim u gjet:\n";
            cout << "Dhoma: " << reservations[i].roomType << endl;
            cout << "Hyrja: " << reservations[i].checkInDate << endl;
            cout << "Dalja: " << reservations[i].checkOutDate << endl;
            return;
        }
    }

    cout << "Rezervimi nuk u gjet.\n";
}

// Anulo rezervim
void cancelReservation() {
    string name;
    cout << "Shkruaj emrin per anulim: ";
    getline(cin, name);

    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].guestName == name) {
            for (int j = i; j < reservationCount - 1; j++) {
                reservations[j] = reservations[j + 1];
            }
            reservationCount--;
            cout << "Rezervimi u anulua me sukses.\n";
            return;
        }
    }

    cout << "Rezervimi nuk u gjet.\n";
}

// Programi kryesor
int main() {
    int choice;

    while (true) {
        cout << "\n=== MENAXHIMI I REZERVIMEVE ===\n";
        cout << "1. Shto rezervim\n";
        cout << "2. Shiko rezervimet\n";
        cout << "3. Kerko rezervim\n";
        cout << "4. Anulo rezervim\n";
        cout << "5. Dil\n";
        cout << "Zgjedhja: ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: addReservation(); break;
            case 2: viewReservations(); break;
            case 3: searchReservation(); break;
            case 4: cancelReservation(); break;
            case 5:
                cout << "Programi u mbyll.\n";
                return 0;
            default:
                cout << "Zgjedhje e gabuar.\n";
        }
    }
}

