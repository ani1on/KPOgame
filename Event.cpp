#include "Event.h"
void OutputIvent(Trader &NewTrader) {

    string FileName = "ivent/";
    switch (NewTrader.GetTraderRarity()) {
    case Common: FileName += "common"; break;
    case Rare:FileName += "rare"; break;
    case Epic: FileName += "epic"; break;
    case Legendary: FileName += "legendary"; break;
    }

    FileName += ".txt";

    ifstream file(FileName);
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
void EventMain(RoomTree NewTree) {
    int RoomCount = NewTree.getSize();


}
void MonsterSpawn(Monster &NewMonster) {
    
}
void TraderEvent(Character& player) { // Добавляем параметр player
    system("cls");
    int sol = 0; // Инициализируем sol
    Trader NewTrader(Legendary);
    NewTrader.CreateInv(); // Сначала создаем инвентарь
    OutputIvent(NewTrader);
    bool OutTrade = false;

}