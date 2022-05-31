//
// Created by J0460 on 2022/5/31.
//

#ifndef FUNNY_XML_FUNNYXMLDOC_H
#define FUNNY_XML_FUNNYXMLDOC_H

#include <list>
#include <string>

#include "./FunnyNode.h"
#include <string>

using std::vector;
using std::string;

namespace FunnyXML {
    class FunnyXmlDoc {
    public:
        FunnyXmlDoc();
        FunnyXmlDoc(string rootTagName);
        void setRootTagName(string rootTagName);
        vector<FunnyNode *> getNodesByPath(string pattern);
        FunnyNode *getFirstNodeByPath(string pattern);
        FunnyNode *getNodeById();
        FunnyNode *createNode(string tagName);
        FunnyNode *createNodeByPattern(string pattern);

    private:
        int lastErrCode;
        string lastErrMessage;
        FunnyNode *root;
        int version;
    };
}

#endif //FUNNY_XML_FUNNYXMLDOC_H
