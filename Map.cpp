#include "Map.h"
 
void CreateRoom(int DangeonSize) {
   RoomTree Tree;
    Tree.setSize(DangeonSize);
    Tree.createTree();
}

char ChoosingPath(int x, int y) {
    if (x < 5) {
        return 'l';
    }
    else if(x>150){
        return 'r';
    }
    else if (y < 3) {
        return 'u';
    }
    else if (y > 40) {
        return 'd';
    }
    else {
        return 'q';
    }
}
void OutputRoom(RoomTree &Tree) {
    set<char> Dir = Tree.getAvailableDirections();
    string Directions;
    for (char c : Dir) {
        Directions += c;
    }
    sort(Directions.begin(), Directions.end());
    Directions += ".txt";
    string NameFile = "maps/";
    NameFile += Directions;

    ifstream file(NameFile);
    if (!file.is_open()) {
        cerr << "Error opening";
        return;
    }
    char ch;
    while (file.get(ch)) {
        cout << ch;
    }
    file.close();
    return;
}
void RoomTransition(char c,RoomTree &Tree,Character &Player) {
    if (c == 'q') {
        return;
   }
   system("cls");
  
    Tree.move(c);
  OutputRoom(Tree);
    Player.SetRoomNum(Tree.getCurrentRoom());
     int NewX, NewY;
    switch (c) {
    case 'r':
        NewX = 7;
        NewY = 23;
        break;
    case 'l':
        NewX = 148;
        NewY = 23;
        break;
    case'd':
        NewX = 78;
        NewY = 5;
        break;
    case 'u':
        NewX = 78;
        NewY = 40;
        break;

    default:
      
        return;
    } 
    Player.SetCoord(NewX, NewY);
    


}