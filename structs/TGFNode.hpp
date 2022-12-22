#ifndef TGF_NODE_H_INCLUDED
#define TGF_NODE_H_INCLUDED

#include <string>

struct TGFNode {

    std::string id;
    std::string label;
    TGFNode* next;

    TGFNode() {
        this->next = NULL;
    }

    ~TGFNode() {
        if (this->next != NULL) {
            delete this->next;
        }
    }

};

#endif
