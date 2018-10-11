#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <stdlib.h>
#include <typeinfo>
#include<map>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;
 
const int M = 12;
int house_count =0;
 
struct House{
  int x;
  int y;
  int c;
};
 
struct Water{
  int x;
  int y;
  int c;
};
 
struct Obstacle{
  int x;
  int y;
};
 
struct Point{
  int x;
  int y;
  Point * next;
  int c;
};
 
Point * free_points ;
 
int X = -1;
int Y = -1;
int housesAmmount = -1;
int watersAmmount = -1;
int obstaclesAmmount = -1;
House * houses;
Water * waters;
Obstacle * obstacles;
string pipes;
// gC3ra, dC3E, lewo, prawo   //I1 I2 L1
int symbols_map[M][4] = {{1,1,0,0},{0,0,1,1},{1,0,0,1},{0,1,0,1},{0,1,1,0},{1,0,1,0},
                            {1,0,1,1},{1,1,0,1},{0,1,1,1},{1,1,1,0},{1,1,1,1}, {1,1,1,1}};
 
string pipe1[2] = {"I1", "I2"};
string pipe_l[4] = {"L1", "L2", "L3", "L4"};
string pipe3[4] = {"T1", "T2", "T3", "T4"};
 
 
map<string, int> symbols;
 
 
struct Mapa{
    string** m;
    int c, r;
 
    Mapa(int x, int y) : c(x), r(y)
    {
        m = new string*[c];
        for(int i=0; i<c; i++)
            m[i] = new string[r];
        this->clean();
    }
 
    string getPosition(int x, int y)
    {
        return m[x][y];
    }
 
    void setPosition(int x, int y, string s)
    {
        m[x][y] = string(s);
    }
 
    void clean ()
    {
      for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
          m[i][j] = string("#");
    }
 
    void print ()
    {
      for (int i = 0; i < c; i++)
      {
        for (int j = 0; j < r; j++)
          cout << m[i][j] << " ";
        cout << '\n';
      }
    }
};
 
void modifyMyStruct(Mapa& m) {
  m.clean();
}
 
 
int getOne(std::vector<std::string> v){
 
  for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it){
    return atoi((*it).c_str());
  }
 
}
 
int * getTwo(std::vector<std::string> v){
 
  int * points = new int[2];
  points[0] = 0;
  points[1] = 0;
  int i=0;
  for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it){
    points[i] = atoi((*it).c_str());
   // cout << points[i] << endl;
    i++;
  }
  return points;
}
 
 
size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;
 
        pos = txt.find( ch, initialPos );
    }
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );
 
    return strs.size();
}
 
///////////////////////////////////////////////////////////////////////////////////////////////////////
void readFromFile(const char *  file_){
 
 
  std::string str;
  while (std::getline(std::cin, str))
  {
  //  cout << "Line : " << str << endl;
    std::vector<std::string> v;
 
    if(obstaclesAmmount != -1){
        pipes = str;
      //  cout << pipes << endl;
        return;
    }
 
    split( str, v, ' ' );
    if(X == -1){
        int * tmp = new int[2];
        tmp[0] = 0;
        tmp[0] = 0;
        tmp = getTwo(v);
        Y = tmp[0];
        X = tmp[1];
 
    }
    else if(watersAmmount == -1){
        watersAmmount = getOne(v);
        waters = new Water[watersAmmount];
    //    cout << watersAmmount << endl;
        for(int i=0;i<watersAmmount;i++){
            std::getline(std::cin, str);
            std::vector<std::string> v;
            split( str, v, ' ' );
            int * tmp = new int[2];
            tmp[0] = 0;
            tmp[0] = 0;
            tmp = getTwo(v);
            Water water;
            water.y = tmp[0];
            water.x = tmp[1];
            water.c= 0;
            waters[i] = water;
      //      cout << tmp[0] << " " << tmp[1] <<endl;
        }
 
    }
    else if(housesAmmount == -1){
        housesAmmount = getOne(v);
        houses = new House[housesAmmount];
    //    cout << housesAmmount << endl;
        for(int i=0;i<housesAmmount;i++){
            std::getline(std::cin, str);
            std::vector<std::string> v;
            split( str, v, ' ' );
            int * tmp = new int[2];
            tmp[0] = 0;
            tmp[0] = 0;
            tmp = getTwo(v);
            House house;
            house.y = tmp[0];
            house.x = tmp[1];
            house.c = 0;
            houses[i] = house;
        //    cout << tmp[0] << " " << tmp[1] <<endl;
        }
    }
    else if(obstaclesAmmount == -1 ){
        obstaclesAmmount = getOne(v);
        if(obstaclesAmmount > 0 ){
        obstacles = new Obstacle[obstaclesAmmount];
    //    cout << obstaclesAmmount << endl;
        for(int i=0;i<obstaclesAmmount;i++){
            std::getline(std::cin, str);
            std::vector<std::string> v;
            split( str, v, ' ' );
            int * tmp = new int[2];
            tmp[0] = 0;
            tmp[0] = 0;
            tmp = getTwo(v);
            Obstacle obstacle;
            obstacle.y = tmp[0];
            obstacle.x = tmp[1];
            obstacles[i] = obstacle;
    //        cout << tmp[0] << " " << tmp[1] <<endl;
        }
      }
    }
 
 
//std::cout << '\n';
 
}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string getElem(int i){
 
    char c = pipes[i];
    string s(1, c);
 
    return s;
}
 
 
 
  string intToString(int a){
    std::ostringstream ss;
    ss << a;
    return ss.str();
}
 
 
 
//////////////////////////////////////////////////////////////////////////////////////////////
bool isPossible(int x1, int x2, int y1, int y2, string s1, string s2){
 
    // 0- gC3ra, 1-dC3B3, 2-lewo, 3-prawo
    int direction1;
    int direction2;
    if(x1 == x2+1 && y1 == y2){
        direction1 = 0;
        direction2 = 1;
    }
    else if(x1+1 == x2 && y1 == y2){
        direction1 = 1;
        direction2 = 0;
    }
    else if(y1 == y2+1 && x1 == x2){
        direction1 = 2;
        direction2 = 3;
    }
    else if(y1+1 == y2 && x1 == x2){
        direction1 = 3;
        direction2 = 2;
    }
 
    int symbol1 = symbols.find(s1) ->second;
    int symbol2 = symbols.find(s2)->second;
    if(symbols_map[symbol1][direction1] == symbols_map[symbol2][direction2] ) return true;
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
bool isPossibleConnections(int x1, int x2, int y1, int y2, string s1, string s2){
 
    // 0- gC3ra, 1-dC3B3, 2-lewo, 3-prawo
    int direction1;
    int direction2;
    if(x1 == x2+1 && y1 == y2){
        direction1 = 0;
        direction2 = 1;
    }
    else if(x1+1 == x2 && y1 == y2){
        direction1 = 1;
        direction2 = 0;
    }
    else if(y1 == y2+1 && x1 == x2){
        direction1 = 2;
        direction2 = 3;
    }
    else if(y1+1 == y2 && x1 == x2){
        direction1 = 3;
        direction2 = 2;
    }
 
    int symbol1 = symbols.find(s1) ->second;
    int symbol2 = symbols.find(s2)->second;
    if(symbols_map[symbol1][direction1] == 1 && symbols_map[symbol2][direction2] == 1 ) return true;
    return false;
}
 
 
 
 
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void prepare_map(Mapa& m){
 
 
 
    for(int i=0;i<housesAmmount;i++){
        House house = houses[i];
        m.setPosition(house.x,house.y,"H");
    }
    for(int i=0;i<watersAmmount;i++){
        Water water = waters[i];
        m.setPosition(water.x, water.y, "W");
    }
    for(int i=0;i<obstaclesAmmount;i++){
        Obstacle obstacle = obstacles[i];
        m.setPosition(obstacle.x, obstacle.y, "O");
    }
 
}
/////////////////////////////////////////////////////////////////////////////////////////////////
 
//czy nie EDczymy rury do gEazu
bool canSet(int x, int y, string s, Mapa& m){
 
 
    string symbol = m.getPosition(x,y);
 
    if(symbol != "#") return false;
 
 
    bool b1 =false;
    bool b2 = false;
    bool b3 = false;
    bool b4 = false;
 
    if((x-1 >=0 && m.getPosition(x-1,y) == "#") || x-1 <0) b1 = true;
    if((x+1 < X && m.getPosition(x+1,y) == "#") || x+1 >=X) b2 = true;
    if((y-1 >=0 && m.getPosition(x,y-1) == "#") || y-1 <0) b3 = true;
    if((y+1 < Y && m.getPosition(x,y+1) == "#") || y+1 >=Y) b4 = true;
 
    if(b1 && b2 && b3 && b4) return false;
 
 
 
    if(x-1 >=0 && m.getPosition(x-1,y) == "O" && symbols_map[symbols[s]][0] == 1)return false;
    if(x+1 < X && m.getPosition(x+1,y) == "O" && symbols_map[symbols[s]][1] == 1)return false;
    if(y-1 >=0 && m.getPosition(x,y-1) == "O" && symbols_map[symbols[s]][2] == 1) return false;
    if(y+1 < Y && m.getPosition(x,y+1) == "O" && symbols_map[symbols[s]][3] == 1) return false;
 
 
 
    return true;
}
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////
bool is_pipe(string s){
    return s != "#" && s != "W" && s != "O" && s != "H";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
 
// czy pole x y jest poEaczone jakDE rurD z sDsiednimi polami
 
bool isConnectionWithMiddleField(int x,int y, Mapa &m){
 
    bool flaga = false;
    if(x+1 < X){
        string s = m.getPosition(x +1,y);
        if(s == "I1" || s =="L1" || s == "L4" || s =="T1" || s == "T2" || s == "T4" || s=="X" ) return true;
 
    }
    if( x-1 >=0){
        string s = m.getPosition(x-1,y);
        if(s == "I1" || s=="L2" || s=="L3" || s=="T2" || s== "T3" || s=="T4" || s=="X") return true;
    }
    if(  y+1 < Y){
        string s = m.getPosition(x,y+1);
        if(s == "I2" || s=="L3" || s=="L4" || s=="T1" || s=="T3" || s=="T4" || s =="X") return true;
    }
    if( y-1 >=0){
        string s = m.getPosition(x,y-1);
        if(s == "I2" || s=="L1" || s=="L2" || s=="T1" || s=="T2" || s=="T3" || s =="X") return true;
    }
    return false;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////
 
bool moreThanOneConnectionWithMiddleField(int x,int y, Mapa &m){
 
    int flaga =0;
    if(x+1 < X){
        string s = m.getPosition(x +1,y);
        if(s == "I1" || s =="L1" || s == "L4" || s =="T1" || s == "T2" || s == "T4" || s=="X" ) flaga++;
 
    }
    if( x-1 >=0){
        string s = m.getPosition(x-1,y);
        if(s == "I1" || s=="L2" || s=="L3" || s=="T2" || s== "T3" || s=="T4" || s=="X")flaga++;
    }
    if( y+1 < Y){
        string s = m.getPosition(x,y+1);
        if(s == "I2" || s=="L3" || s=="L4" || s=="T1" || s=="T3" || s=="T4" || s =="X") flaga++;
    }
    if( y-1 >=0){
        string s = m.getPosition(x,y-1);
        if(s == "I2" || s=="L1" || s=="L2" || s=="T1" || s=="T2" || s=="T3" || s =="X") flaga++;
    }
    return flaga >=2;
}
 
/////////////////////////////////////////////////////////////////////////////////////////
 
int getConnectionAmmunt(int x,int y, string type){
 
  if(type == "W"){
 
    for(int i=0;i<watersAmmount;i++){
      if(waters[i].x == x && waters[i].y == y) return waters[i].c;
    }
  }
  if(type == "H"){
 
    for(int i=0;i<housesAmmount;i++){
      if(houses[i].x == x && houses[i].y == y) return houses[i].c;
    }
  }
 
return -1;
 
}
 
void addConnectionAmmount(int x, int y, string type){
 
  if(type == "W"){
 
    for(int i=0;i<watersAmmount;i++){
      if(waters[i].x == x && waters[i].y == y) {waters[i].c = waters[i].c +1;return;}
    }
  }
  if(type == "H"){
 
    house_count++;
    for(int i=0;i<housesAmmount;i++){
      if(houses[i].x == x && houses[i].y == y){houses[i].c = houses[i].c + 1;return;}
    }
  }
}
 
void deleteConnectionAmmount(int x, int y, string type){
 
  if(type == "W"){
 
    for(int i=0;i<watersAmmount;i++){
      if(waters[i].x == x && waters[i].y == y) {waters[i].c = waters[i].c -1;return;}
    }
  }
  if(type == "H"){
 
    house_count--;
    for(int i=0;i<housesAmmount;i++){
      if(houses[i].x == x && houses[i].y == y){houses[i].c = waters[i].c -1;return;}
    }
  }
 
 
 
}
 
bool correct_pipe_or_water(string s){
 
  return (s != "H" && s != "#" && s!="O");
 
}
 
 
////////////////////////////////////////////////////////////////////////////////////
 
bool isCorrectPipeSet(Mapa& m){
 
  int count = 0;
 
    for(int x=0;x<X;x++){
        for(int y=0;y<Y;y++){
            if(is_pipe(m.getPosition(x,y))){
                string s = m.getPosition(x,y);
                //gC3ra czy eni jest pusta
                if(s == "I1" || s=="L1" || s =="L4" || s== "T1" || s == "T2" || s == "T4" || s== "X"){
                   if(x-1 >=0 && m.getPosition(x-1,y) == "#") return false;
                }
                // dC3E czy nie jest pusty
                if(s == "I1" || s == "L2" || s == "L3" || s == "T2" || s == "T3" || s == "T4" || s == "X"){
                    if(x+1 < X && m.getPosition(x+1,y) == "#") return false;
                }
                // lewo czy nie jest puste
                if(s == "I2" || s== "L3" || s== "L4" || s=="T1" || s == "T3" || s=="T4" || s== "X"){
                    if(y-1 >=0 && m.getPosition(x,y-1) == "#" ) return false;
                }
                //prawo czy nie jest puste
                if(s == "I2" || s=="L1" || s == "L2" || s=="T1" || s == "T2" || s=="T3" || s=="X"){
                    if(y+1 < Y  && m.getPosition(x,y+1) == "#") return false;
                }
 
 
 
        }
            if(m.getPosition(x,y) == "H"){
                if(! isConnectionWithMiddleField(x,y,m)) return false;
                if(moreThanOneConnectionWithMiddleField(x,y,m)) return false;
                count++;
            //    cout << "Jest OK" <<endl;
    }
            if(m.getPosition(x,y) == "W"){
                if(moreThanOneConnectionWithMiddleField(x,y,m)) return false;
            }
 
    }
}
return count == housesAmmount;
}
 
 
 
///////////////////////////////////////////////////////////////////////////////////////////////
bool canSetAllOptions(int x, int y,string s, Mapa &m){
 
    // czy nie wchodzimy w przeszkodD
 
    if(! canSet(x,y,s,m)) return false;
 
 
    //czy nie EDczymy siD z domem lub E:rC3dEem, ktC3B)e ma juE< jedno poEDczenie
 
    if(x-1 >=0 && m.getPosition(x-1,y) == "W" && symbols_map[symbols[s]][0]==1 && getConnectionAmmunt(x-1,y,m.getPosition(x-1,y))==1) return false;
    if(x-1 >=0 && m.getPosition(x-1,y) == "H" && symbols_map[symbols[s]][0]==1 &&  getConnectionAmmunt(x-1,y,m.getPosition(x-1,y))==1 ) return false;
    if(x+1 < X && m.getPosition(x+1,y) == "W" &&  symbols_map[symbols[s]][1]==1 && getConnectionAmmunt(x+1,y,m.getPosition(x+1,y))==1) return false;
    if(x+1 < X && m.getPosition(x+1,y) == "H" && symbols_map[symbols[s]][1]==1 && getConnectionAmmunt(x+1,y,m.getPosition(x+1,y))==1) return false;
    if(y-1 >=0 && m.getPosition(x,y-1) == "W" && symbols_map[symbols[s]][2]==1 &&getConnectionAmmunt(x,y-1,m.getPosition(x,y-1))==1  ) return false;
    if(y-1 >=0 && m.getPosition(x,y-1) == "H" && symbols_map[symbols[s]][2]==1 && getConnectionAmmunt(x,y-1,m.getPosition(x,y-1))==1 ) return false;
    if(y+1 < Y && m.getPosition(x,y+1) == "W" && symbols_map[symbols[s]][3]==1 && getConnectionAmmunt(x,y+1,m.getPosition(x,y+1))==1 ) return false;
    if(y+1 < Y && m.getPosition(x,y+1) == "H" && symbols_map[symbols[s]][3]==1 && getConnectionAmmunt(x,y+1,m.getPosition(x,y+1))==1) return false;
 
    // czy nie zostawiamy rury na kraju
 
    if(x==0 && symbols_map[symbols[s]][0] == 1) return false;
    if(x== X-1 && symbols_map[symbols[s]][1] == 1) return false;
    if(y==0 && symbols_map[symbols[s]][2] == 1) return false;
    if(y== Y-1 && symbols_map[symbols[s]][3] == 1) return false;
 
    // czy nie powodujemy nieszczelnoEci miDdzy dwoma rurami
 
    if(x-1 >=0 && is_pipe(m.getPosition(x-1,y)) && (! isPossible(x,x-1,y,y,s,m.getPosition(x-1,y)))) return false;
    if(x+1 < X && is_pipe(m.getPosition(x+1,y)) && (! isPossible(x,x+1,y,y,s,m.getPosition(x+1,y))))return false;
    if(y-1 >=0 && is_pipe(m.getPosition(x,y-1)) && (! isPossible(x,x,y,y-1,s,m.getPosition(x,y-1))))return false;
    if(y+1 < Y && is_pipe(m.getPosition(x,y+1)) && (! isPossible(x,x,y,y+1,s,m.getPosition(x,y+1))))return false;
 
 
    //czy EDczymy siD z chociaE< jednD rura lub jednym E:rC3dEem
 
    if(x-1 >= 0 && correct_pipe_or_water(m.getPosition(x-1,y)) && isPossibleConnections(x,x-1,y,y,s,m.getPosition(x-1,y)) ) return true;
    if(x+1 < X && correct_pipe_or_water(m.getPosition(x+1,y)) && isPossibleConnections(x,x+1,y,y,s,m.getPosition(x+1,y)) ) return true;
    if(y-1 >=0 && correct_pipe_or_water(m.getPosition(x,y-1)) && isPossibleConnections(x,x,y,y-1,s,m.getPosition(x,y-1)) ) return true;
    if(y+1 < Y && correct_pipe_or_water(m.getPosition(x,y+1)) && isPossibleConnections(x,x,y,y+1,s,m.getPosition(x,y+1)) ) return true;
 
 
 
    return false;
 
 
 
}
////////////////////////////////////////////////////////////////////////////////////////////
 
void addFreePoints(int x,int  y){
 
    if(free_points == NULL){
      Point * new_point = new Point;
      new_point -> x= x;
      new_point -> y = y;
      new_point -> c = 1;
      free_points = new_point;
      free_points->next = NULL;
      return;
    }
    Point * tmp = free_points;
    while(tmp!=NULL){
      if(tmp->x ==x && tmp->y == y){
        tmp->c = 1 + tmp->c;
    //    cout <<"Add " << tmp->c <<endl;
        return;
      }
      tmp = tmp->next;
    }
    Point * new_point = new Point;
    new_point -> x= x;
    new_point -> y = y;
    new_point -> c = 1;
    new_point->next = free_points;
    free_points = new_point;
 
}
 
 
void removeFreePoints(int x, int y){
 
  Point * tmp = free_points;
  while(tmp!=NULL){
    if(tmp->x == x && tmp->y == y){
      tmp->c = 0;
      return;
    }
    tmp = tmp->next;
  }
 
}
 
void shuffleFreePoints(){
 
 
      Point * tmp = free_points;
      Point * x = tmp->next;
      while(tmp!=NULL){
        while(x!=NULL){
          if(rand()%10 < 4){
            int x1 = tmp->x;
            int x2 = x->x;
            int y1 = tmp->y;
            int y2 = x->y;
            int c1 = tmp->c;
            int c2 = x->c;
            tmp->x = x2;
            tmp->y = y2;
            tmp->c = c2;
            x -> x =x1;
            x->y = y1;
            x->c = c2;
          }
          x =x->next;
        }
        tmp = tmp->next;
      }
}
 
bool pointToRemove(int x, int y, Mapa &m){
 
  if((x-1 >=0 && m.getPosition(x-1,y) != "#") || x-1 <0) return false;
  if((x+1 < X && m.getPosition(x+1,y) != "#") || x+1 >=X) return false;
  if((y-1 >=0 && m.getPosition(x,y-1) != "#") || y-1 <0) return false;
  if((y+1 < Y && m.getPosition(x,y+1) != "#") || y+1 >=Y) return false;
  return true;
 
}
 
 
 
 
/////////////////////////////////////////////////////////////////////////////////
 
bool solve(int x, int y, Mapa &m, string pipes, unsigned int index, string result){
 
 
  //  cout << house_count<<endl;
  //  cout << index<<endl;
//    cout << pipes[index]<<endl;
  //  m.print();
  //  cout <<endl;
 
    if(house_count == housesAmmount && isCorrectPipeSet(m)){
    //    m.print();
        std::cout << intToString(index) + "\n" + result;
    //    cout << "OK" <<endl;
  //      cout << "UdaEo siD" <<endl;
        return true;
    }
 
    if(index == pipes.length()){
            return false;
    }
 
    string pipe_types[4];
    int pipe_types_len;
    if(getElem(index) == "I"){
        for(int i=0;i<2;i++){
            pipe_types[i] = pipe1[i];
        }
        pipe_types_len = 2;
 
    }
    else if(getElem(index) == "L"){
        for(int i=0;i<4;i++){
            pipe_types[i] = pipe_l[i];
        }
        pipe_types_len = 4;
    }
    else if(getElem(index) == "T"){
        for(int i=0;i<4;i++){
            pipe_types[i] = pipe3[i];
        }
        pipe_types_len = 4;
    }
    else{
        pipe_types[0] = "X";
        pipe_types_len = 1;
    }
 
//    cout << "Sprawdzanie" << endl;
 
    for(int i=0;i<pipe_types_len;i++){
 
    //    if(rand() %10 < 1) shuffleFreePoints();
 
        Point * tmp = free_points;
      //  cout << "OK" <<endl;
        while(tmp != NULL){
          //  cout << "Pole " << tmp->x << "  " << tmp->y <<endl;
            if( m.getPosition(tmp->x, tmp->y) == "#" && tmp->c > 0 &&  canSetAllOptions(tmp->x, tmp->y, pipe_types[i],m)){
 
            //    cout << "OK"<<endl;
                int x1 = tmp->x;
                int y1 = tmp->y;
                removeFreePoints(x1, y1);
                m.setPosition(x1,y1, pipe_types[i]);
 
                //dodajD poEDczneia z domami i wodami
 
                bool b1 = false;
                bool b2 = false;
                bool b3 = false;
                bool b4 = false;
 
                if(x1+1 < X && (m.getPosition(x1+1,y1) == "W" || m.getPosition(x1+1,y1) == "H")){
 
                  if( symbols_map[symbols[pipe_types[i]]][1] == 1 ){
                    addConnectionAmmount(x1+1,y1,m.getPosition(x1+1,y1));
                    b1 =true;
                  }
 
                }
 
                if(x1-1 >= 0 && (m.getPosition(x1-1,y1) == "W" || m.getPosition(x1-1,y1) == "H")){
 
                  if(symbols_map[symbols[pipe_types[i]]][0] == 1){
                    addConnectionAmmount(x1-1,y1,m.getPosition(x1-1,y1));
                    b2 = true;
                  }
 
                }
 
                if(y1+1 < Y && (m.getPosition(x1,y1+1) == "W" || m.getPosition(x1,y1+1) == "H")){
 
                  if(symbols_map[symbols[pipe_types[i]]][3] == 1){
                    addConnectionAmmount(x1,y1+1,m.getPosition(x1,y1+1));
                    b3 = true;
                  }
 
                }
 
                if(y1-1>=0 && (m.getPosition(x1,y1-1) == "W" || m.getPosition(x1,y1-1) == "H")){
 
                  if(symbols_map[symbols[pipe_types[i]]][2] == 1){
                    addConnectionAmmount(x1,y1-1,m.getPosition(x1,y1-1));
                    b4 =true;
                  }
 
                }
 
 
                if(x1+1 < X && m.getPosition(x1+1,y1) == "#") addFreePoints(x1+1,y1);
                if(y1+1 < Y && m.getPosition(x1,y1+1) == "#") addFreePoints(x1,y1+1);
                if(x1-1 >=0 && m.getPosition(x1-1,y1) == "#") addFreePoints(x1-1,y1);
                if(y1-1 >= 0 && m.getPosition(x1,y1-1) == "#") addFreePoints(x1,y1-1);
 
          //      WywoEanie rekurencyjne
                if(solve(x1,y1,m,pipes, index+1, result + intToString(y1) + " " + intToString(x1) + " " + pipe_types[i] + "\n")) return true;
 
            //   PowrC3t
 
 
            if(b1) deleteConnectionAmmount(x1+1,y1,m.getPosition(x1+1,y1));
            if(b2) deleteConnectionAmmount(x1-1,y1,m.getPosition(x1-1,y1));
            if(b3) deleteConnectionAmmount(x1,y1+1,m.getPosition(x1,y1+1));
            if(b4) deleteConnectionAmmount(x1,y1-1,m.getPosition(x1,y1-1));
 
 
                addFreePoints(x1,y1);
 
                if(x1+1 < X && pointToRemove(x1+1,y,m)) removeFreePoints(x1+1,y1);
                if(y1+1 < Y && pointToRemove(x1,y1+1,m))removeFreePoints(x1,y1+1);
                if(x1-1 >=0 &&  pointToRemove(x1-1,y1,m))removeFreePoints(x1-1,y1);
                if(y1-1 >= 0 && pointToRemove(x1,y1-1,m) )removeFreePoints(x1,y1-1);
 
                m.setPosition(x1,y1,"#");
 
 
 
            }
            tmp = tmp->next;
        }
 
    }
return false;
 
    }
 
 
 
 
 
int main(){
 
    srand(time(NULL));
 
    symbols["I1"] = 0;
    symbols["I2"] = 1;
    symbols["L1"] = 2;
    symbols["L2"] = 3;
    symbols["L3"] = 4;
    symbols["L4"] = 5;
    symbols["T1"] = 6;
    symbols["T2"] = 7;
    symbols["T3"] = 8;
    symbols["T4"] = 9;
    symbols["X"] = 10;
    symbols["W"] = 11;
    string file_ = "plik.txt";
    readFromFile(file_.c_str());
 
 
    Mapa m(X,Y);
   //cout << "Mapa zrobiona" <<endl;
    prepare_map(m);
    int c = symbols.find("I1") ->second;
 
    getElem(2);
    free_points = NULL;
    for(int i=0;i<watersAmmount;i++){
           int x = waters[i].x;
            int y = waters[i].y;
            if(x+1 < X && m.getPosition(x+1,y) == "#") addFreePoints(x+1,y);
            if(y+1 < Y && m.getPosition(x,y+1) == "#") addFreePoints(x,y+1);
            if(x-1 >=0 && m.getPosition(x-1,y) == "#") addFreePoints(x-1,y);
            if(y-1 >= 0 && m.getPosition(x,y-1) == "#") addFreePoints(x,y-1);
 
    }
 
    Point  * tmp = free_points;
    while(tmp!=NULL){
  //    cout << "Punkt " << tmp->x << "  " << tmp->y<<endl;
      tmp = tmp->next;
    }
 
//    cout << "Sprawdzamy rozwiDzanie"<<endl;
    solve(0,0,m, pipes,0,"");
    delete tmp;
  //  m.print();
 
}
