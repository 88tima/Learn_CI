#include <iostream>
#include <string>
using namespace std;

int ygik = -1;
int ygjk = -1;
int ygil = -1;
int ygjl = -1;
int ygis = -1;
int ygjs = -1;

int mod(int k) {
    if (k < 0) {
        k = k * (-1);
    }
    return k;
}

bool queen(string K1, string K2, int i1, int j1, int i2, int j2) {
    if ((K1[0] == K2[0]) || (K1[1] == K2[1]) || (mod(i1 - i2) == mod(j1 - j2))) {
        return true;
    }
    return false;
}

bool bishop(int i1, int j1, int i2, int j2) {
    if (mod(i1 - i2) == mod(j1 - j2)) {
        return true;
    }
    return false;
}

bool rook(string K1, string K2) {
    if ((K1[0] == K2[0]) || (K1[1] == K2[1])) {
        return true;
    }
    return false;
}

bool knight(int i1, int j1, int i2, int j2) {
    if (((mod(i1 - i2) == 2) && (mod(j1 - j2) == 1)) || ((mod(i1 - i2) == 1) && (mod(j1 - j2) == 2))) {
        return true;
    }
    return false;
}

void knight2(int i1, int j1, int i2, int j2, string board[8][8]) {
    ygik = -1;
    ygjk = -1;
    int movesI[] = { i1 + 1, i1 + 1, i1 - 1, i1 - 1, i1 + 2, i1 + 2, i1 - 2, i1 - 2 };
    int movesJ[] = { j1 - 2, j1 + 2, j1 - 2, j1 + 2, j1 - 1, j1 + 1, j1 - 1, j1 + 1 };
    for (int k = 0; k < 8; ++k) {
        if (movesI[k] >= 0 && movesI[k] < 8 && movesJ[k] >= 0 && movesJ[k] < 8 && knight(movesI[k], movesJ[k], i2, j2)) {
            ygik = movesI[k];
            ygjk = movesJ[k];
            break;
        }
    }
}

void rook2(int i1, int j1, int i2, int j2, string board[8][8]) {
    ygil = -1;
    ygjl = -1;
    for (int ko = 1; ko < 8; ++ko) {
        if ((i1 + ko) < 8 && (i1 + ko) == i2) {
            ygil = i1 + ko;
            ygjl = j1;
            break;
        }
        if ((j1 + ko) < 8 && (j1 + ko) == j2) {
            ygil = i1;
            ygjl = j1 + ko;
            break;
        }
        if ((i1 - ko) >= 0 && (i1 - ko) == i2) {
            ygil = i1 - ko;
            ygjl = j1;
            break;
        }
        if ((j1 - ko) >= 0 && (j1 - ko) == j2) {
            ygil = i1;
            ygjl = j1 - ko;
            break;
        }
    }
}

void bishop2(int i1, int j1, int i2, int j2, string board[8][8]) {
    ygis = -1;
    ygjs = -1;
    for (int ko = 1; ko < 8; ++ko) {
        int i3 = i1 + ko;
        int j3 = j1 - ko;
        int i4 = i1 + ko;
        int j4 = j1 + ko;
        int i5 = i1 - ko;
        int j5 = j1 - ko;
        int i6 = i1 - ko;
        int j6 = j1 + ko;
        if (i3 >= 0 && i3 < 8 && j3 >= 0 && j3 < 8 && bishop(i3, j3, i2, j2)) {
            ygis = i3;
            ygjs = j3;
            break;
        }
        if (i4 >= 0 && i4 < 8 && j4 >= 0 && j4 < 8 && bishop(i4, j4, i2, j2)) {
            ygis = i4;
            ygjs = j4;
            break;
        }
        if (i5 >= 0 && i5 < 8 && j5 >= 0 && j5 < 8 && bishop(i5, j5, i2, j2)) {
            ygis = i5;
            ygjs = j5;
            break;
        }
        if (i6 >= 0 && i6 < 8 && j6 >= 0 && j6 < 8 && bishop(i6, j6, i2, j2)) {
            ygis = i6;
            ygjs = j6;
            break;
        }
    }
}

int main() {
    string continueChoice;
    do {
        cout << "                                    Welcome to the 'Chess' program" << endl << endl;
        cout << "This program checks whether the piece on square 1 threatens the piece on square 2," << endl;
        cout << "and whether it can create such a threat in one move." << endl;
        cout << "It also checks whether the two given squares are of the same color." << endl;
        cout << "Please enter two chessboard square addresses using English letters (e.g., A1, H8)." << endl << endl;

        string board[8][8] = {
            {"A8","B8","C8","D8","E8","F8","G8","H8"},
            {"A7","B7","C7","D7","E7","F7","G7","H7"},
            {"A6","B6","C6","D6","E6","F6","G6","H6"},
            {"A5","B5","C5","D5","E5","F5","G5","H5"},
            {"A4","B4","C4","D4","E4","F4","G4","H4"},
            {"A3","B3","C3","D3","E3","F3","G3","H3"},
            {"A2","B2","C2","D2","E2","F2","G2","H2"},
            {"A1","B1","C1","D1","E1","F1","G1","H1"}
        };
        string display[8][8];
        // Копируем board в display
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                display[i][j] = board[i][j];

        string K1, K2;
        int i1, j1, i2, j2;

        // Ввод и валидация K1 и K2
        cout << "Enter the address of square 1 (e.g., A1): ";
        cin >> K1;
        while (true) {
            int k = 0, b = 0;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (K1 == board[i][j]) {
                        k++;
                        i1 = i;
                        j1 = j;
                    }
                    if (K2 == board[i][j] && (K1 != K2)) {
                        b++;
                        i2 = i;
                        j2 = j;
                    }
                }
            }
            if ((k == 1 && b != 1 && K2 != "") || (K1 == K2)) {
                cout << "You entered the second square incorrectly or it is already occupied by the first piece. Please try again below." << endl;
                cout << "Enter the address of square 2 (e.g., F3): ";
                cin >> K2;
                cout << endl;
            }
            else if (k == 1 && K2 == "") {
                cout << "Enter the address of square 2 (e.g., F3): ";
                cin >> K2;
                cout << endl;
            }
            else if (k != 1) {
                cout << endl;
                cout << "You entered the first square incorrectly. Please try again below." << endl;
                cout << "Enter the address of square 1 (e.g., A1): ";
                cin >> K1;
            }
            else if (k == 1 && b == 1) {
                break;
            }
        }

        string F;
        while (true) {
            cout << "Choose a piece to test (1 - queen, 2 - rook, 3 - bishop, 4 - knight): ";
            cin >> F;
            if (F == "1" || F == "2" || F == "3" || F == "4") {
                break;
            }
            else {
                cout << endl;
                cout << "Invalid piece selection. Please try again below." << endl;
            }
        }

        cout << endl;
        cout << "FS - position of the first square." << endl;
        cout << "SS - position of the second square." << endl;
        cout << " -----------------------------------------" << endl;

        // Обновляем display для отображения SC и TC
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                display[i][j] = board[i][j];

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (K1 == board[i][j]) {
                    display[i][j] = "SC";
                }
                if (K2 == board[i][j]) {
                    display[i][j] = "TC";
                }
                if (j < 7) {
                    cout << " | " << display[i][j];
                }
                else {
                    cout << " | " << display[i][j] << " |";
                }
            }
            cout << endl << " -----------------------------------------" << endl;
        }

        // Цвет клеток
        int color1 = ((i1 + j1) % 2 == 0) ? 0 : 1;
        int color2 = ((i2 + j2) % 2 == 0) ? 0 : 1;
        if (color1 == color2) {
            cout << "1) The entered squares are of the same color." << endl << endl;
        }
        else {
            cout << "1) The entered squares are of different colors." << endl << endl;
        }

        // Проверка угрозы
        if (F == "1") {
            if (queen(K1, K2, i1, j1, i2, j2)) {
                cout << "2) The queen on square 1 threatens the piece on square 2." << endl;
            } else {
                cout << "2) The queen on square 1 does not threaten the piece on square 2." << endl;
            }
        } else if (F == "2") {
            if (rook(K1, K2)) {
                cout << "2) The rook on square 1 threatens the piece on square 2." << endl;
            } else {
                cout << "2) The rook on square 1 does not threaten the piece on square 2." << endl;
            }
        } else if (F == "3") {
            if (bishop(i1, j1, i2, j2)) {
                cout << "2) The bishop on square 1 threatens the piece on square 2." << endl;
            } else {
                cout << "2) The bishop on square 1 does not threaten the piece on square 2." << endl;
            }
        } else if (F == "4") {
            if (knight(i1, j1, i2, j2)) {
                cout << "2) The knight on square 1 threatens the piece on square 2." << endl;
            } else {
                cout << "2) The knight on square 1 does not threaten the piece on square 2." << endl;
            }
        }
        cout << endl;

        // Расчёт возможности создать угрозу за один ход
        knight2(i1, j1, i2, j2, board);
        rook2(i1, j1, i2, j2, board);
        bishop2(i1, j1, i2, j2, board);

        if (F == "4") {
            if (knight(i1, j1, i2, j2)) {
                cout << "3) You do not need to move the piece—you are already threatening it." << endl << endl;
            } else if (ygik >= 0 && ygjk >= 0) {
                cout << "3) You can create a threat in one move by moving the piece to square: " << board[ygik][ygjk] << "." << endl << endl;
            } else {
                cout << "3) You cannot create a threat in one move by moving the piece." << endl << endl;
            }
        } else if (F == "2") {
            if (rook(K1, K2)) {
                cout << "3) You do not need to move the piece—you are already threatening it." << endl << endl;
            } else if (ygil >= 0 && ygjl >= 0) {
                cout << "3) You can create a threat in one move by moving the piece to square: " << board[ygil][ygjl] << "." << endl << endl;
            } else {
                cout << "3) You cannot create a threat in one move by moving the piece." << endl << endl;
            }
        } else if (F == "3") {
            if (bishop(i1, j1, i2, j2)) {
                cout << "3) You do not need to move the piece—you are already threatening it." << endl << endl;
            } else if (ygis >= 0 && ygjs >= 0) {
                cout << "3) You can create a threat in one move by moving the piece to square: " << board[ygis][ygjs] << "." << endl << endl;
            } else {
                cout << "3) You cannot create a threat in one move by moving the piece." << endl << endl;
            }
        } else if (F == "1") {
            if (queen(K1, K2, i1, j1, i2, j2)) {
                cout << "3) You do not need to move the piece—you are already threatening it." << endl << endl;
            } else {
                ygil = -1; ygjl = -1;
                ygis = -1; ygjs = -1;
                rook2(i1, j1, i2, j2, board);
                bishop2(i1, j1, i2, j2, board);
                if (ygil >= 0 && ygjl >= 0 && ygis >= 0 && ygjs >= 0) {
                    cout << "3) You can create a threat in one move by moving the piece to square: " << board[ygil][ygjl] << " or " << board[ygis][ygjs] << "." << endl << endl;
                } else if (ygil >= 0 && ygjl >= 0) {
                    cout << "3) You can create a threat in one move by moving the piece to square: " << board[ygil][ygjl] << "." << endl << endl;
                } else if (ygis >= 0 && ygjs >= 0) {
                    cout << "3) You can create a threat in one move by moving the piece to square: " << board[ygis][ygjs] << "." << endl << endl;
                } else {
                    cout << "3) You cannot create a threat in one move by moving the piece." << endl << endl;
                }
            }
        }

        // Спрашиваем, продолжать ли
        cout << "Do you want to continue? (y/n): ";
        cin >> continueChoice;
        cout << endl;

    } while (continueChoice == "y" || continueChoice == "Y");

    cout << "Thank you for using the Chess program!" << endl;
    return 0;
}
