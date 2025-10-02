#include <iostream>

int main() {
    char seating[6][5] = {
        {'0' , '1' , '2' , '3' ,'4'},
        {'1' , 'A' , 'A' , 'A', 'A'},
        {'2' , 'A' , 'A' , 'A', 'A'},
        {'3' , 'A' , 'A' , 'A', 'A'},
        {'4' , 'A' , 'A' , 'A', 'A'},
        {'5' , 'A' , 'A' , 'A', 'A'}
    };
    
    int row;
    int column;
    
    for(int i = 0; i <= 5 ; i++) {
        for (int j=0 ; j <=4 ; j++ ) {
            std::cout << seating[i][j] << " ";
        }
        std::cout << std::endl;
    }
    while (true) {
        std::cout << "Enter a Row and Column to check availability(0-Based Index: )" ;
        std::cin >> row >> column;
        if (row == 0 || column == 0) {
            std::cout << "It's not in the choices" << std::endl;
            continue;
        } else if (seating[row][column] == 'B') {
            std::cout << "Seating not available" << std::endl;
            continue;
        } else {
            seating[row][column] = 'B';
            
            for (int i = 0 ; i <= 5; i++) {
                for (int j=0 ; j <=4 ; j++ ){
                    std::cout << seating[i][j] << ' '; 
                }
                std::cout << std::endl;
            }
            std::cout << "seating booked successfully" << std::endl;
        }
    }
}
