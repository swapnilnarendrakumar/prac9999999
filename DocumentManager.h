// Dai(a1837470), Dil(a1825200), Swapnil(a1848855), Duong(a1876928)
#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class DocumentManager {
    private:
        std::unordered_map<std::string, int> mapName;
        std::unordered_map<int, int> mapID;
        std::unordered_map<int , int> mapPatron;

        // unordered_set<int docId, int license_limit> setID;
        // unordered_set<int patronID> setPatron;

    public:
        void addDocument(std::string name, int id, int license_limit);
        void addPatron(int patronID);
        int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection
        bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
        void returnDocument(int docid, int patronID);
};

#endif