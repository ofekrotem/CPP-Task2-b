#include "doctest.h"
#include "Notebook.hpp"
#include <climits>
using namespace ariel;
using namespace std;

Direction horizontal = Direction::Horizontal;
Direction vertical = Direction::Vertical;

TEST_CASE("Good input")
{
    Notebook notebook;
    notebook.write(30, 60, 90, horizontal, "horiz");
    notebook.write(1, 1, 1, vertical, "vert");
    notebook.write(2, 2, 2, horizontal, "whatwillbewhatwillbe");
    CHECK(notebook.read(2, 2, 2, horizontal, 5) == "whatw");
    CHECK(notebook.read(30, 60, 90, horizontal, 5) == "horiz");
    CHECK(notebook.read(1, 1, 1, vertical, 4) == "vert");
    CHECK(notebook.read(200, 100, 50, horizontal, 7) == "_______");
    CHECK(notebook.read(100, 2, 1, vertical, 1) == "_");
}

TEST_CASE("Bad input - negetive args"){
    Notebook notebook;
    CHECK_THROWS(notebook.write(-1, -1, -1, horizontal, "shouldThrow"));
    CHECK_THROWS(notebook.write(-1, -1, 0, horizontal, "shouldThrow"));
    CHECK_THROWS(notebook.write(-1, 0, -1, horizontal, "shouldThrow"));  
    CHECK_THROWS(notebook.write(-1, 0, 0, horizontal, "shouldThrow"));      
    CHECK_THROWS(notebook.write(0, -1, -1, horizontal, "shouldThrow"));
    CHECK_THROWS(notebook.write(0, -1, 0, horizontal, "shouldThrow"));
    CHECK_THROWS(notebook.write(0, 0, -1, horizontal, "shouldThrow"));

    CHECK_THROWS(notebook.erase(-1, -1, -1, horizontal, -1));
    CHECK_THROWS(notebook.erase(-1, -1, -1, horizontal, 0));
    CHECK_THROWS(notebook.erase(-1, -1, 0, horizontal, -1));
    CHECK_THROWS(notebook.erase(-1, -1, 0, horizontal, 0));
    CHECK_THROWS(notebook.erase(-1, 0, -1, horizontal, -1));
    CHECK_THROWS(notebook.erase(-1, 0, -1, horizontal, 0));
    CHECK_THROWS(notebook.erase(-1, 0, 0, horizontal, -1));
    CHECK_THROWS(notebook.erase(-1, 0, 0, horizontal, 0));
    CHECK_THROWS(notebook.erase(0, -1, -1, horizontal, -1));
    CHECK_THROWS(notebook.erase(0, -1, -1, horizontal, 0));
    CHECK_THROWS(notebook.erase(0, -1, 0, horizontal, -1));
    CHECK_THROWS(notebook.erase(0, -1, 0, horizontal, 0));
    CHECK_THROWS(notebook.erase(0, 0, -1, horizontal, -1));
    CHECK_THROWS(notebook.erase(0, 0, -1, horizontal, 0));
    CHECK_THROWS(notebook.erase(0, 0, 0, horizontal, -1));

     CHECK_THROWS(notebook.read(-1, -1, -1, horizontal, -1));
    CHECK_THROWS(notebook.read(-1, -1, -1, horizontal, 0));
    CHECK_THROWS(notebook.read(-1, -1, 0, horizontal, -1));
    CHECK_THROWS(notebook.read(-1, -1, 0, horizontal, 0));
    CHECK_THROWS(notebook.read(-1, 0, -1, horizontal, -1));
    CHECK_THROWS(notebook.read(-1, 0, -1, horizontal, 0));
    CHECK_THROWS(notebook.read(-1, 0, 0, horizontal, -1));
    CHECK_THROWS(notebook.read(-1, 0, 0, horizontal, 0));
    CHECK_THROWS(notebook.read(0, -1, -1, horizontal, -1));
    CHECK_THROWS(notebook.read(0, -1, -1, horizontal, 0));
    CHECK_THROWS(notebook.read(0, -1, 0, horizontal, -1));
    CHECK_THROWS(notebook.read(0, -1, 0, horizontal, 0));
    CHECK_THROWS(notebook.read(0, 0, -1, horizontal, -1));
    CHECK_THROWS(notebook.read(0, 0, -1, horizontal, 0));
    CHECK_THROWS(notebook.read(0, 0, 0, horizontal, -1));
}


TEST_CASE("Bad input - out of bounds")
{
    Notebook notebook;
    string suprt_long_str = "";
    for (int i = 0; i < 102; i++)
    {
        suprt_long_str +="a";
    }
    
    CHECK_THROWS(notebook.write(0, 0, 0, horizontal, suprt_long_str));
    CHECK_THROWS(notebook.write(1, 1, 95, horizontal, "ThrowForOutOfBounds"));
}
