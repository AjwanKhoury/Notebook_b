#include "Direction.hpp"
#include <string>
#include <vector>
#include <map>

// struct emptyC
// {
//     char val='_';
// };
using namespace std;
namespace ariel{
    class Notebook{
    private:
        int min_pages, min_row, min_column;
        int max_pages, max_row, max_column;
        map<int, map< int, char[100]>> notebook;    
    
    public:
    static const int max_row_length = 100;
        Notebook(){
            //min_column=min_row=UINT16_MAX;
           // max_row=max_column=0;
        }
        ~Notebook(){}
    
    
    void write(int page, int row, int column, Direction direction, string const &message);
    std:: string read(int page, int row, int column, Direction direction, int length);
    void erase(int page, int row, int column, Direction direction, int length);
    void show(int page);
    };
}