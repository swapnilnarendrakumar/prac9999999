#include <string>
#include "DocumentManager.h"

using namespace std;

void DocumentManager::addDocument(string name, int id, int license_limit) {
    mapName.insert({name, id});
    mapID.insert({id, license_limit});
}

void DocumentManager::addPatron(int patronID) {
    mapPatron.insert({patronID, NULL});
}

int DocumentManager::search(string name) {
    if(mapName.find(name) == mapName.end()) return 0;

    return mapName.at(name);
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if(mapPatron.find(patronID) == mapPatron.end()) return false;
    if(mapID.find(docid) == mapID.end()) return false;
    

    if (mapID.at(docid) == 0) return false;

    mapID[docid] = mapID[docid] - 1;
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    mapID[docid]++;
    // mapPatron[patronID] = 0;
}