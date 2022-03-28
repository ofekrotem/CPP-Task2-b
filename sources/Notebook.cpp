#include "Notebook.hpp"

using namespace std;
using namespace ariel;
int const EFES = 0;
int const row_limit = 100;
void Notebook::write(int page, int row, int column, Direction direction, string const &to_write)
{
    this->last_row_in_use[page] = row;
    int const row_limit = 100;
    int const low_ascii_bound = 32;
    int const high_ascii_bound = 126;
    
    if (page<EFES||row<EFES||column<EFES) {__throw_invalid_argument("Negetive args");}

    int str_len = to_write.size();
    if ((str_len+column)>row_limit){__throw_invalid_argument("Out of bounds for row");}        
    int tmpRow = row;
    int tmpColumn = column;
    for (char check_if_good: to_write) {
        if (check_if_good == '\n' || check_if_good == '~' || check_if_good < low_ascii_bound || check_if_good > high_ascii_bound) {__throw_invalid_argument("Invalid string input");}
        if (this->notebook_data[page][row][column].cha != '_') {__throw_runtime_error( "Error in writing - space has already been written on/erased");}
            if (direction == Direction::Vertical) {
                tmpRow++;
            } else {
                tmpColumn++;
            }
    }

    for (char to_put : to_write) {
         this->notebook_data[page][row][column].cha = to_put;
            if (direction == Direction::Vertical) {
                row++;
            } else {
                column++;
            }
    
    }
}

string Notebook::read(int page, int row, int column, Direction direction, int length)
{
    if (page<EFES||row<EFES||column<EFES||length<EFES) {__throw_invalid_argument("Negetive args");}

    if (length+column>row_limit) {__throw_invalid_argument("Out of bounds for row");}

    string ans;
    for (int i = 0; i < length; i++) {
        char to_add = this->notebook_data[page][row][column].cha;
        ans.append(1, to_add);
        if (direction == Direction::Vertical) {
            row++;
        } else {
            column++;
        }
    }
    return ans;
}

void Notebook::erase(int page, int row, int column, Direction direction, int length)
{
    if (page<EFES||row<EFES||column<EFES||length<EFES) {__throw_invalid_argument("Negetive args");}

    if (length+column>row_limit) {__throw_invalid_argument("Out of bounds for row");}

    this->last_row_in_use[page] = row;
    for (int i = 0; i < length; i++) {
        this->notebook_data[page][row][column].cha = '~';
        if (direction == Direction::Vertical) {
            row++;
        } else {
            column++;
        }
    }

}

void Notebook::show(int page)
{
    if (page<EFES) {__throw_invalid_argument("Negetive args");}

    int row = this->last_row_in_use[page];
    Direction dir = Direction::Horizontal;
    int tmpRow = row;
    if (row > 0) {
        for (int i = tmpRow - 1; i <= row + 1; i++) {
            this->read(page, i, 0, dir, row_limit);
        }
    } else {
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j < row; j++) {
                cout << this->notebook_data[page][j][i].cha;
            }
            cout << endl;
        }

    }
}