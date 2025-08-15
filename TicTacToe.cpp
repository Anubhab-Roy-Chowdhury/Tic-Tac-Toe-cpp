#include<bits/stdc++.h>
using namespace std;
int currentPlayer = 1; // By default player 1 starts
char currentMarker; // Current player's marker
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; // Tic Tac Toe board
 void drawBoard(){
    cout << "Current board:" << endl;
    cout<< "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  -----------" << endl;
    cout<< "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  -----------" << endl;
    cout<< "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    
 }
 bool idavailable(int slot){
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = currentMarker; // Place the marker
        //drawBoard(); // Redraw the board after placing the marker
        return true; // Position is available

    }
    else{
        return false; // Position is not available
    }
 }
 int winner(){
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
           return currentPlayer; // Return the current player if they win
        }
    }
    // Check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer; // Return the current player if they win
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer; // Return the current player if they win
    }
    return 0; // No winner yet
 }
 void swapplayerandmarker(){
    currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch player
    currentMarker = (currentMarker == 'X') ? 'O' : 'X'; // Switch marker
 }
void game(){
    cout<< "Welcome to Tic Tac Toe!" << endl;
    cout<<"Player1,choose your symbol (X or O): ";
    char markerp1;
    cin >> markerp1;
    currentPlayer = 1;
    currentMarker = markerp1;
    int playerwon;
    for(int i = 0;i<9;i++){
        cout << "Player " << currentPlayer << ", it's your turn. Enter the position (1-9): ";
        int slot;
        cin>>slot;
        if(slot < 1 || slot > 9) {
            cout << "Invalid position! Please choose a number between 1 and 9." << endl;
            i--; // Repeat this turn
            continue;
        }
        if(!idavailable(slot)) {
            cout << "Position already taken! Please choose another position." << endl;
            i--; // Repeat this turn
            continue;
        }
        drawBoard();
        // Check for win conditions
        playerwon = winner();
        if(playerwon){ 
            cout << "Player " << currentPlayer << " wins!" << endl;
            return; // End the game if a player wins
                }
                swapplayerandmarker();
                if(playerwon==0 && i == 8) {
                    cout << "It's a draw!" << endl; // If all slots are filled and no winner
                    return; // End the game if it's a draw

                }

    }

    drawBoard();
}

int main() {
   game();
    return 0;
}