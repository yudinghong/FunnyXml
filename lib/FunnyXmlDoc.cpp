//
// Created by J0460 on 2022/5/31.
//

#include "FunnyXmlDoc.h"

FunnyXML::FunnyXmlDoc::FunnyXmlDoc() {
    this->root = new FunnyNode();
}

FunnyXML::FunnyXmlDoc::FunnyXmlDoc(string rootTagName) {
    this->root = new FunnyNode(rootTagName);
}

void FunnyXML::FunnyXmlDoc::setRootTagName(string rootTagName) {
    this->root->setTagName(rootTagName);
}
