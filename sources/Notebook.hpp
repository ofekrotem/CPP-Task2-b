#include <iostream>
#include <string>
#include "Direction.hpp"
#include <unordered_map>
using namespace std;


struct char_
{
    char cha = '_';
};

namespace ariel
{
    class Notebook{
        public:
        void write(int page, int row, int column, Direction direction, string const &to_write);
        void erase(int page, int row, int column, Direction direction, int len);
        string read(int page, int row, int column, Direction direction, int len);
        void show(int page);

        private:
        unordered_map< int, unordered_map< int, unordered_map< int, char_>>> notebook_data;
        unordered_map< int,  int> last_row_in_use;
        
    };
}