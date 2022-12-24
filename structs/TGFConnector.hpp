#ifndef TGF_CONNECTOR_H_INCLUDED
#define TGF_CONNECTOR_H_INCLUDED

#include <string>

struct TGFConnector {

    std::string sourceNode;
    std::string targetNode;
    std::string label;
    TGFConnector* next;

    TGFConnector() {
        this->next = NULL;
    }

    ~TGFConnector() {
        if (this->next != NULL) {
            delete this->next;
        }
    }

};

#endif
