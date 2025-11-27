#pragma once
#include "Utility.h"
#include "Classes.h"

using namespace std;
class RoomTree {
private:
    struct Node {
        set<char> directions;
        int RoomNum;
        vector<Node*> children;
        Node* parent;
        map<char, Node*> connections; // Связи по направлениям

        Node(int NewRoomNum, set<char> NewDir, Node* parentNode = nullptr) :
            directions(NewDir), RoomNum(NewRoomNum), parent(parentNode) {
        }

        Node(Node* parentNode = nullptr) {
            RoomNum = 0;
            parent = parentNode;
        }

        void addChild(Node* child) {
            children.push_back(child);
        }
    };

    Node* root;
    int countRoom;
    int size;
    map<int, set<char>> AllTree;
    map<int, Node*> roomNodes; // Быстрый доступ к узлам по номеру комнаты
    int currentRoom;

public:
    RoomTree() : root(nullptr), countRoom(0), size(0), currentRoom(1) {}
    int getSize() {
        return size;
    }
    void setSize(int NewSize) {
        size = NewSize;
    }

    void createTree() {
        root = new Node(1, set<char>(), nullptr);
        countRoom = 1;
        AllTree[root->RoomNum] = root->directions;
        roomNodes[root->RoomNum] = root;
        currentRoom = 1;

        queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while (countRoom < size && !nodeQueue.empty()) {
            Node* currentNode = nodeQueue.front();
            nodeQueue.pop();

            // ИСПРАВЛЕНО: Добавляем новые направления к существующим
            set<char> newDirs = randomDir();
            for (char dir : newDirs) {
                currentNode->directions.insert(dir);
            }

            AllTree[currentNode->RoomNum] = currentNode->directions;

            for (char c : currentNode->directions) {
                if (countRoom >= size) break;

                // ИСПРАВЛЕНО: Проверяем, нет ли уже связи в этом направлении
                if (currentNode->connections.find(c) != currentNode->connections.end()) {
                    continue;
                }

                countRoom++;
                set<char> childDir;
                childDir.insert(reverseChar(c));

                Node* NewNode = new Node(countRoom, childDir, currentNode);
                currentNode->addChild(NewNode);

                // Устанавливаем двусторонние связи
                currentNode->connections[c] = NewNode;
                NewNode->connections[reverseChar(c)] = currentNode;

                AllTree[NewNode->RoomNum] = NewNode->directions;
                roomNodes[NewNode->RoomNum] = NewNode;
                nodeQueue.push(NewNode);
            }
        }
    }

    bool move(char direction) {
        Node* current = roomNodes[currentRoom];

        // ИСПРАВЛЕНО: Проверяем через connections, а не через directions
        if (current->connections.find(direction) == current->connections.end()) {
            return false;
        }

        Node* nextRoom = current->connections[direction];
        if (nextRoom == nullptr) {
            return false;
        }

        int previousRoom = currentRoom;
        currentRoom = nextRoom->RoomNum;
        return true;
    }

    set<char> getAvailableDirections() {
        if (roomNodes.find(currentRoom) != roomNodes.end()) {
            // ИСПРАВЛЕНО: Возвращаем направления из connections, а не из directions
            Node* current = roomNodes[currentRoom];
            set<char> available;
            for (auto& conn : current->connections) {
                available.insert(conn.first);
            }
            return available;
        }
        return set<char>();
    }

    set<char> randomDir() {
        set<char> Directions;

        int maxDirections = min(4, size - countRoom);
        if (maxDirections <= 0) return Directions;

        int directionCount = RandomInRange(1, maxDirections);

        vector<char> allDirections = { 'u', 'r', 'd', 'l' };
        random_shuffle(allDirections.begin(), allDirections.end());

        for (int i = 0; i < directionCount && i < 4; i++) {
            Directions.insert(allDirections[i]);
        }

        return Directions;
    }

    char reverseChar(char c) {
        switch (c) {
        case 'u':
            return 'd';
        case 'd':
            return 'u';
        case 'r':
            return 'l';
        case 'l':
            return 'r';
        default:
            return 0;
        }
    }

  

    // Получить текущую комнату персонажа
    int getCurrentRoom() {
        return currentRoom;
    }

  
    // Телепортация в конкретную комнату (для отладки)
    bool teleport(int roomNumber) {
        if (roomNodes.find(roomNumber) != roomNodes.end()) {
            currentRoom = roomNumber;
            cout << "Телепортация в комнату " << roomNumber << endl;
            return true;
        }
        cout << "Комната " << roomNumber << " не существует!" << endl;
        return false;
    }
    void debugConnections() {
        cout << "\n=== ДЕБАГ КАРТЫ СВЯЗЕЙ ===" << endl;
        for (map<int, Node*>::iterator it = roomNodes.begin(); it != roomNodes.end(); ++it) {
            cout << "Комната " << it->first << " -> ";
            for (map<char, Node*>::iterator connIt = it->second->connections.begin();
                connIt != it->second->connections.end(); ++connIt) {
                cout << connIt->first << ":" << connIt->second->RoomNum << " ";
            }
            cout << endl;
        }
    }
    map<int, set<char>> getRoomMap() {
        return AllTree;
    }
};
void CreateRoom(int DangeonSize);
char ChoosingPath(int x, int y);
void OutputRoom(RoomTree& Tree);
void RoomTransition(char c, RoomTree& Tree, Character& Player);