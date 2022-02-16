#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <vector>
#include "Stack.h"
#include "Coordinate.h"

using namespace std;

string replaceToNumber(string str);

void save(vector<int> maze[51], int x, int y, string fileName);

int startI = 1, startJ = 0;         //starting point
int endI = 49, endJ = 51;           //ending point
int sizeX=50,sizeY=50;              // maze size

int main(int argc, char **argv) {
    string openFile = "..\\tests\\";
    openFile.append(argv[1]);
    string saveFile = "..\\solved\\";
    saveFile.append(argv[1]);
    int i = startI;
    int j = startJ;
    Stack stack;
    Stack visited;

    ifstream in(openFile);                  //open file
    string line;

    vector<int> maze[51];


    int column = 0;
    while (getline(in, line)) {
        string newline = replaceToNumber(line);         //read the map as an 2D int array
        int temp;
        for (char number: newline) {
            stringstream ss;
            ss << number;
            ss >> temp;
            maze[column].push_back(temp);
        }
        column++;
    }


    while ((i != endI || j != endJ)) {

        maze[i][j] = 4;     //4 stands for the right route
                            //Detect that direction can go forward, and has not been reached
        if ((maze[i][j + 1] == 0) && !visited.check({i, j + 1})) {
            j = j + 1;
            stack.push({i, j});             //Store the correct route
            visited.push({i, j});           //Store every point visited
        } else if ((maze[i + 1][j] == 0) && !visited.check({i + 1, j})) {
            i = i + 1;
            stack.push({i, j});
            visited.push({i, j});
        } else if ((maze[i][j - 1] == 0) && !visited.check({i, j - 1})) {
            j = j - 1;
            stack.push({i, j});
            visited.push({i, j});
        } else if ((maze[i - 1][j] == 0) && !visited.check({i - 1, j})) {
            i = i - 1;
            stack.push({i, j});
            visited.push({i, j});
        } else {
            maze[i][j] = 5;
            stack.pop();                        //Pop the data of the last point and
                                                // set the i,j to the coordinates of the previous point
            Coordinate temp = stack.peek();
            i = temp.m_x;
            j = temp.m_y;
        }
    }

    save(maze, sizeX, sizeY, saveFile);     //call save file function

    return 0;
}


string replaceToNumber(string str) {
    int pos;
    pos = str.find("+");                    //Convert all symbols to int, 0 represents a passable route
    while (pos != -1) {
        str.replace(pos, string("+").length(), "1");
        pos = str.find("+");
    }

    pos = str.find("-");
    while (pos != -1) {
        str.replace(pos, string("-").length(), "2");
        pos = str.find("-");
    }

    pos = str.find("|");
    while (pos != -1) {
        str.replace(pos, string("|").length(), "3");
        pos = str.find("|");
    }


    pos = str.find(" ");
    while (pos != -1) {
        str.replace(pos, string(" ").length(), "0");
        pos = str.find(" ");
    }

    return str;
}

void save(vector<int> maze[51], int x, int y, string fileName) {
    ofstream outFile(fileName);         //Convert the int to the corresponding symbol and store it in the file
    string sign;
    string temp;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            switch (maze[i][j]) {
                case 1:
                    sign = "+";
                    break;
                case 2:
                    sign = "-";
                    break;
                case 3:
                    sign = "|";
                    break;
                case 4:
                    sign = "#";
                    break;
                default:
                    sign = " ";
            }

            temp.append(sign);
        }
        temp.append("\n");
        outFile << temp;
        temp = "";
    }
}
