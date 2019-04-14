/* Your code here! */
#pragma once
#include "cs225/PNG.h"
#include "dsets.h"
#include <vector>
#include <utility>
#include <stack>
class SquareMaze
{
  //all vectors are stored as a 1 d array
  public:
    int width;
    int height;
    int size; //width*height
    SquareMaze();
    SquareMaze(int w, int h);
    void makeMaze(int w,int h);
    void setWall(int x, int y, int dir, bool exists);

    int get_coord(int x, int y)const;
    int get_down(int x, int y)const;
    int get_up(int x, int y)const;
    int get_left(int x, int y)const;
    int get_right(int x, int y)const;

    cs225::PNG * drawMaze()const;
    cs225::PNG * drawMazeWithSolution();

    std::vector<int> solveMaze();
    //int help_solve(std::vector<int> * tmp,int,int);
    bool canTravel_helper(int startpoint, int dir);

    void put_length(std::stack<int>,int *);//std::vector<int>);

    std::pair<int,int> get_point(int coord);//gets coordinates in form of a pair given position in 1d array in form coord = y*width + x

    std::vector<std::pair<bool,bool> > walls;//first bool is for right (0) second is for down (1)

    std::vector<bool> visited;//for solving the maze
    bool in_same_tree(DisjointSets &,int,int);
    bool canTravel(int x, int y, int dir) const;

    int traverser; //for traversing during construction
};
